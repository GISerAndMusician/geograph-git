#include "GgsGraphMapToolSelect.h"
#include "qgsapplication.h"
#include "qgsmapcanvas.h"

#include "GgsGraphMapToolSelectUtils.h"
#include "GgsGraphProject.h"
#include "GgsGraphProxy.h"

GgsGraphMapToolSelect::GgsGraphMapToolSelect(QgsMapCanvas* canvas)
	: QgsMapTool(canvas)
{
	this->mToolName = tr("Select Graph Elements");

	mSelectionHandler = qgis::make_unique<GgsGraphMapToolSelectionHandler>(canvas);
	connect(mSelectionHandler.get(), &GgsGraphMapToolSelectionHandler::geometryChanged, this, &GgsGraphMapToolSelect::selectGraphFeatures);

	setSelectionMode(GgsGraphMapToolSelectionHandler::SelectRadius);
}

void GgsGraphMapToolSelect::canvasPressEvent(QgsMapMouseEvent *e)
{
	mSelectionHandler->canvasPressEvent(e);
}

void GgsGraphMapToolSelect::canvasMoveEvent(QgsMapMouseEvent *e)
{
	mSelectionHandler->canvasMoveEvent(e);
}

void GgsGraphMapToolSelect::canvasReleaseEvent(QgsMapMouseEvent *e)
{
	mSelectionHandler->canvasReleaseEvent(e);
}

void GgsGraphMapToolSelect::keyPressEvent(QKeyEvent *e)
{
	if (!e->isAutoRepeat())
	{
		switch (e->key())
		{
		case Qt::Key_Shift:
		case Qt::Key_Control:
		case Qt::Key_Alt:
		case Qt::Key_Meta:
			//note -- if ctrl and shift are already depressed, pressing alt reports the "meta" key eventZ
			modifiersChanged(e->modifiers() & Qt::ControlModifier || e->key() == Qt::Key_Control,
				e->modifiers() & Qt::ShiftModifier || e->key() == Qt::Key_Shift,
				e->modifiers() & Qt::AltModifier || e->key() == Qt::Key_Alt ||
				(e->modifiers() & Qt::ControlModifier && e->modifiers() & Qt::ShiftModifier && e->key() == Qt::Key_Meta));
			break;

		default:
			break;
		}
	}

	QgsMapTool::keyPressEvent(e);
}

void GgsGraphMapToolSelect::keyReleaseEvent(QKeyEvent *e)
{
	if (!e->isAutoRepeat())
	{
		switch (e->key())
		{
		case Qt::Key_Shift:
		case Qt::Key_Control:
		case Qt::Key_Alt:
		case Qt::Key_Meta:
			//note -- if ctrl and shift are already depressed, pressing alt reports the "meta" key eventZ
			modifiersChanged(e->modifiers() & Qt::ControlModifier || e->key() == Qt::Key_Control,
				e->modifiers() & Qt::ShiftModifier || e->key() == Qt::Key_Shift,
				e->modifiers() & Qt::AltModifier || e->key() == Qt::Key_Alt ||
				(e->modifiers() & Qt::ControlModifier && e->modifiers() & Qt::ShiftModifier && e->key() == Qt::Key_Meta));
			break;

		default:
			break;
		}
	}

	QgsMapTool::keyPressEvent(e);
}

void GgsGraphMapToolSelect::deactivate()
{
	mSelectionHandler->deactivate();
	QgsMapTool::deactivate();
}

QgsMapTool::Flags GgsGraphMapToolSelect::flags() const
{
	switch (mSelectionHandler->selectionMode())
	{
	case GgsGraphMapToolSelectionHandler::SelectPolygon:
		break;

	case GgsGraphMapToolSelectionHandler::SelectSimple:
	case GgsGraphMapToolSelectionHandler::SelectFreehand:
	case GgsGraphMapToolSelectionHandler::SelectRadius:
		return QgsMapTool::flags() | QgsMapTool::ShowContextMenu;
	}

	return QgsMapTool::flags();
}

void GgsGraphMapToolSelect::setSelectionMode(GgsGraphMapToolSelectionHandler::SelectionMode selectionMode)
{
	mSelectionHandler->setSelectionMode(selectionMode);
	if (selectionMode == GgsGraphMapToolSelectionHandler::SelectSimple)
		mCursor = QgsApplication::getThemeCursor(QgsApplication::Cursor::Select);
	else
		mCursor = Qt::ArrowCursor;
}

void GgsGraphMapToolSelect::setSelectionFeatureMode(FeatureMode featureMode)
{
	mFeatureMode = featureMode;
}

void GgsGraphMapToolSelect::selectGraphFeatures(Qt::KeyboardModifiers modifiers)
{
	// 执行选中计算操作
	QList<GgsGraphProxy*> graphs = GgsGraphProject::instance()->selections();

	for each (GgsGraphProxy* g in graphs)
	{
		if (mFeatureMode == NodeOnly || mFeatureMode == NodeAndEdge || mFeatureMode == NodeAndAdjEdges)
		{
			QgsVectorLayer* nodeLayer = g->nodeLayerProxy()->nodeLayer();
			mCanvas->setCurrentLayer(nodeLayer);
			selectFeatures(modifiers);

			if (mFeatureMode == NodeAndAdjEdges)
			{
				QgsFeatureIds ids =  nodeLayer->selectedFeatureIds();
				for each (QgsFeatureId id in ids)
				{
					ogdf::node n = g->nodeLayerProxy()->findNode(id)->node();

					ogdf::List<ogdf::edge> elist;
					n->adjEdges(elist);

					QgsFeatureIds adjEdgeFeatureIds;
					for (int i = 0; i < elist.size(); i++)
					{
						ogdf::edge e = *elist.get(i);
						GgsEdgeProxy* egdeProxy = g->edgeLayerProxy()->findEgde(e);
						adjEdgeFeatureIds << egdeProxy->feature().id();
					}
					g->edgeLayerProxy()->edgeLayer()->select(adjEdgeFeatureIds);
				}
			}
		}
		if (mFeatureMode == EdgeOnly || mFeatureMode == NodeAndEdge)
		{
			QgsVectorLayer* edgeLayer = g->edgeLayerProxy()->edgeLayer();
			mCanvas->setCurrentLayer(edgeLayer);
			selectFeatures(modifiers);
		}

		emit graphFeatureSelectionChanged(g);
	}
}

void GgsGraphMapToolSelect::selectFeatures(Qt::KeyboardModifiers modifiers)
{
	if (mSelectionHandler->selectionMode() == GgsGraphMapToolSelectionHandler::SelectSimple &&
		mSelectionHandler->selectedGeometry().type() == QgsWkbTypes::PointGeometry)
	{
		QgsVectorLayer *vlayer = GgsGraphMapToolSelectUtils::getCurrentVectorLayer(mCanvas);
		QgsRectangle r = GgsGraphMapToolSelectUtils::expandSelectRectangle(mSelectionHandler->selectedGeometry().asPoint(), mCanvas, vlayer);
		GgsGraphMapToolSelectUtils::selectSingleFeature(mCanvas, QgsGeometry::fromRect(r), modifiers);
	}
	else
		GgsGraphMapToolSelectUtils::selectMultipleFeatures(mCanvas, mSelectionHandler->selectedGeometry(), modifiers);
}

void GgsGraphMapToolSelect::modifiersChanged(bool ctrlModifier, bool shiftModifier, bool altModifier)
{
	if (!ctrlModifier && !shiftModifier && !altModifier)
		emit modeChanged(GeometryIntersectsSetSelection);
	else if (!ctrlModifier && !shiftModifier && altModifier)
		emit modeChanged(GeometryWithinSetSelection);
	else if (!ctrlModifier && shiftModifier && !altModifier)
		emit modeChanged(GeometryIntersectsAddToSelection);
	else if (!ctrlModifier && shiftModifier && altModifier)
		emit modeChanged(GeometryWithinAddToSelection);
	else if (ctrlModifier && !shiftModifier && !altModifier)
		emit modeChanged(GeometryIntersectsSubtractFromSelection);
	else if (ctrlModifier && !shiftModifier && altModifier)
		emit modeChanged(GeometryWithinSubtractFromSelection);
	else if (ctrlModifier && shiftModifier && !altModifier)
		emit modeChanged(GeometryIntersectsIntersectWithSelection);
	else if (ctrlModifier && shiftModifier && altModifier)
		emit modeChanged(GeometryWithinIntersectWithSelection);
}
