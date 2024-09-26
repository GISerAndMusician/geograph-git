#include "GgsGraphMapToolSelectionHandler.h"
#include <QBoxLayout>
#include <QKeyEvent>
#include <QLabel>

#include "qgsdoublespinbox.h"
#include "qgsmapcanvas.h"
#include "qgsmapmouseevent.h"
#include "qgsrubberband.h"
#include "qgssnapindicator.h"
#include "qgsidentifymenu.h"

#include "GgsApp.h"

GgsGraphDistanceWidget::GgsGraphDistanceWidget(const QString &label /*= QString()*/, QWidget *parent /*= nullptr*/)
	: QWidget(parent)
{
	mLayout = new QHBoxLayout(this);
	mLayout->setContentsMargins(0, 0, 0, 0);
	mLayout->setAlignment(Qt::AlignLeft);
	setLayout(mLayout);

	if (!label.isEmpty())
	{
		QLabel *lbl = new QLabel(label, this);
		lbl->setAlignment(Qt::AlignRight | Qt::AlignCenter);
		mLayout->addWidget(lbl);
	}

	mDistanceSpinBox = new QgsDoubleSpinBox(this);
	mDistanceSpinBox->setSingleStep(1);
	mDistanceSpinBox->setValue(0);
	mDistanceSpinBox->setMinimum(0);
	mDistanceSpinBox->setMaximum(1000000000);
	mDistanceSpinBox->setDecimals(6);
	mDistanceSpinBox->setShowClearButton(false);
	mDistanceSpinBox->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
	mLayout->addWidget(mDistanceSpinBox);

	// connect signals
	mDistanceSpinBox->installEventFilter(this);
	connect(mDistanceSpinBox, static_cast <void (QgsDoubleSpinBox::*)(double)> (&QgsDoubleSpinBox::valueChanged), this, &GgsGraphDistanceWidget::distanceChanged);

	// config focus
	setFocusProxy(mDistanceSpinBox);
}

void GgsGraphDistanceWidget::setDistance(double distance)
{
	mDistanceSpinBox->setValue(distance);
	mDistanceSpinBox->selectAll();
}

double GgsGraphDistanceWidget::distance()
{
	return mDistanceSpinBox->value();
}

bool GgsGraphDistanceWidget::eventFilter(QObject *obj, QEvent *ev)
{
	if (obj == mDistanceSpinBox && ev->type() == QEvent::KeyPress)
	{
		QKeyEvent *event = static_cast<QKeyEvent *>(ev);
		if (event->key() == Qt::Key_Escape)
		{
			emit distanceEditingCanceled();
			return true;
		}
		if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
		{
			emit distanceEditingFinished(distance(), event->modifiers());
			return true;
		}
	}

	return false;
}

GgsGraphMapToolSelectionHandler::GgsGraphMapToolSelectionHandler(QgsMapCanvas *canvas, 
	SelectionMode selectionMode /*= SelectionMode::SelectSimple*/)
	: mCanvas(canvas)
	, mSelectionMode(selectionMode)
	, mSnapIndicator(qgis::make_unique< QgsSnapIndicator >(canvas))
	, mIdentifyMenu(new QgsIdentifyMenu(mCanvas))
{
	mIdentifyMenu->setAllowMultipleReturn(false);
	mIdentifyMenu->setExecWithSingleResult(true);
}

GgsGraphMapToolSelectionHandler::~GgsGraphMapToolSelectionHandler()
{
	cancel();
}

GgsGraphMapToolSelectionHandler::SelectionMode GgsGraphMapToolSelectionHandler::selectionMode() const
{
	return mSelectionMode;
}

void GgsGraphMapToolSelectionHandler::setSelectionMode(SelectionMode mode)
{
	mSelectionMode = mode;
}

void GgsGraphMapToolSelectionHandler::deactivate()
{
	cancel();
}

void GgsGraphMapToolSelectionHandler::canvasMoveEvent(QgsMapMouseEvent *e)
{
	switch (mSelectionMode)
	{
	case GgsGraphMapToolSelectionHandler::SelectSimple:
		selectFeaturesMoveEvent(e);
		break;
	case GgsGraphMapToolSelectionHandler::SelectPolygon:
		selectPolygonMoveEvent(e);
		break;
	case GgsGraphMapToolSelectionHandler::SelectFreehand:
		selectFreehandMoveEvent(e);
		break;
	case GgsGraphMapToolSelectionHandler::SelectRadius:
		selectRadiusMoveEvent(e);
		break;
	}
}

void GgsGraphMapToolSelectionHandler::canvasPressEvent(QgsMapMouseEvent *e)
{
	switch (mSelectionMode)
	{
	case GgsGraphMapToolSelectionHandler::SelectSimple:
		selectFeaturesPressEvent(e);
		break;
	case GgsGraphMapToolSelectionHandler::SelectPolygon:
		selectPolygonPressEvent(e);
		break;
	case GgsGraphMapToolSelectionHandler::SelectFreehand:
		break;
	case GgsGraphMapToolSelectionHandler::SelectRadius:
		break;
	}
}

void GgsGraphMapToolSelectionHandler::canvasReleaseEvent(QgsMapMouseEvent *e)
{
	switch (mSelectionMode)
	{
	case GgsGraphMapToolSelectionHandler::SelectSimple:
		selectFeaturesReleaseEvent(e);
		break;
	case GgsGraphMapToolSelectionHandler::SelectPolygon:
		break;
	case GgsGraphMapToolSelectionHandler::SelectFreehand:
		selectFreehandReleaseEvent(e);
		break;
	case GgsGraphMapToolSelectionHandler::SelectRadius:
		selectRadiusReleaseEvent(e);
		break;
	}
}

bool GgsGraphMapToolSelectionHandler::keyReleaseEvent(QKeyEvent *e)
{
	if (mSelectionActive && e->key() == Qt::Key_Escape)
	{
		cancel();
		return true;
	}
	return false;
}

void GgsGraphMapToolSelectionHandler::setSelectedGeometry(const QgsGeometry &geometry, Qt::KeyboardModifiers modifiers /*= Qt::NoModifier*/)
{
	mSelectionGeometry = geometry;
	emit geometryChanged(modifiers);
}

QgsGeometry GgsGraphMapToolSelectionHandler::selectedGeometry() const
{
	return mSelectionGeometry;
}

double GgsGraphMapToolSelectionHandler::radius() const
{
	return mRadius;
}

void GgsGraphMapToolSelectionHandler::cancel()
{
	deleteDistanceWidget();
	mSnapIndicator->setMatch(QgsPointLocator::Match());
	mSelectionRubberBand.reset();
	mSelectionActive = false;
}

void GgsGraphMapToolSelectionHandler::updateRadiusRubberband(double radius)
{
	if (!mSelectionRubberBand)
		initRubberBand();

	const int RADIUS_SEGMENTS = 80;

	mSelectionRubberBand->reset(QgsWkbTypes::PolygonGeometry);
	for (int i = 0; i <= RADIUS_SEGMENTS; ++i)
	{
		double theta = i * (2.0 * M_PI / RADIUS_SEGMENTS);
		QgsPointXY radiusPoint(mRadiusCenter.x() + radius * std::cos(theta),
			mRadiusCenter.y() + radius * std::sin(theta));
		mSelectionRubberBand->addPoint(radiusPoint, false);
	}
	mSelectionRubberBand->closePoints(true);

	mRadius = radius;
}

void GgsGraphMapToolSelectionHandler::radiusValueEntered(double radius, Qt::KeyboardModifiers modifiers)
{
	if (!mSelectionRubberBand)
		return;

	updateRadiusRubberband(radius);
	setSelectedGeometry(mSelectionRubberBand->asGeometry(), modifiers);
	cancel();
}

void GgsGraphMapToolSelectionHandler::initRubberBand()
{
	mSelectionRubberBand = qgis::make_unique<QgsRubberBand>(mCanvas, QgsWkbTypes::PolygonGeometry);
	mSelectionRubberBand->setFillColor(mFillColor);
	mSelectionRubberBand->setStrokeColor(mStrokeColor);
}

void GgsGraphMapToolSelectionHandler::createDistanceWidget()
{
	if (!mCanvas)
	{
		return;
	}

	deleteDistanceWidget();

	mDistanceWidget = new GgsGraphDistanceWidget(tr("Selection radius:"));
	GgsApp::instance()->addUserInputWidget(mDistanceWidget);
	mDistanceWidget->setFocus(Qt::TabFocusReason);

	connect(mDistanceWidget, &GgsGraphDistanceWidget::distanceChanged, this, &GgsGraphMapToolSelectionHandler::updateRadiusRubberband);
	connect(mDistanceWidget, &GgsGraphDistanceWidget::distanceEditingFinished, this, &GgsGraphMapToolSelectionHandler::radiusValueEntered);
	connect(mDistanceWidget, &GgsGraphDistanceWidget::distanceEditingCanceled, this, &GgsGraphMapToolSelectionHandler::cancel);
}

void GgsGraphMapToolSelectionHandler::deleteDistanceWidget()
{
	if (mDistanceWidget)
	{
		mDistanceWidget->releaseKeyboard();
		mDistanceWidget->deleteLater();
	}
	mDistanceWidget = nullptr;
}

void GgsGraphMapToolSelectionHandler::selectFeaturesMoveEvent(QgsMapMouseEvent *e)
{
	if (e->buttons() != Qt::LeftButton)
		return;

	QRect rect;
	if (!mSelectionActive)
	{
		mSelectionActive = true;
		rect = QRect(e->pos(), e->pos());
	}
	else
	{
		rect = QRect(e->pos(), mInitDragPos);
	}

	if (mSelectionRubberBand)
		mSelectionRubberBand->setToCanvasRectangle(rect);
}

void GgsGraphMapToolSelectionHandler::selectFeaturesReleaseEvent(QgsMapMouseEvent *e)
{
	QPoint point = e->pos() - mInitDragPos;
	if (!mSelectionActive || (point.manhattanLength() < QApplication::startDragDistance()))
	{
		mSelectionActive = false;
		setSelectedGeometry(QgsGeometry::fromPointXY(toMapCoordinates(e->pos())), e->modifiers());
	}

	if (mSelectionRubberBand && mSelectionActive)
		setSelectedGeometry(mSelectionRubberBand->asGeometry(), e->modifiers());
	if (mSelectionRubberBand)
		mSelectionRubberBand.reset();

	mSelectionActive = false;
}

void GgsGraphMapToolSelectionHandler::selectFeaturesPressEvent(QgsMapMouseEvent *e)
{
	if (!mSelectionRubberBand)
		initRubberBand();

	mInitDragPos = e->pos();
}

void GgsGraphMapToolSelectionHandler::selectPolygonMoveEvent(QgsMapMouseEvent *e)
{
	if (!mSelectionRubberBand)
		return;

	if (mSelectionRubberBand->numberOfVertices() > 0)
	{
		mSelectionRubberBand->movePoint(toMapCoordinates(e->pos()));
	}
}

void GgsGraphMapToolSelectionHandler::selectPolygonPressEvent(QgsMapMouseEvent *e)
{
	// Handle immediate right-click on feature to show context menu
	if (!mSelectionRubberBand && (e->button() == Qt::RightButton))
	{
		QList<QgsMapToolIdentify::IdentifyResult> results;
		QMap< QString, QString > derivedAttributes;

		const QgsPointXY mapPoint = toMapCoordinates(e->pos());
		double x = mapPoint.x(), y = mapPoint.y();
		double sr = QgsMapTool::searchRadiusMU(mCanvas);

		const QList<QgsMapLayer *> layers = mCanvas->layers();
		for (auto layer : layers)
		{
			if (layer->type() == QgsMapLayerType::VectorLayer)
			{
				auto vectorLayer = static_cast<QgsVectorLayer *>(layer);
				if (vectorLayer->geometryType() == QgsWkbTypes::PolygonGeometry)
				{
					QgsFeatureIterator fit = vectorLayer->getFeatures(QgsFeatureRequest()
						.setDestinationCrs(mCanvas->mapSettings().destinationCrs(), mCanvas->mapSettings().transformContext())
						.setFilterRect(QgsRectangle(x - sr, y - sr, x + sr, y + sr))
						.setFlags(QgsFeatureRequest::ExactIntersect));
					QgsFeature f;
					while (fit.nextFeature(f))
					{
						results << QgsMapToolIdentify::IdentifyResult(vectorLayer, f, derivedAttributes);
					}
				}
			}
		}

		QPoint globalPos = mCanvas->mapToGlobal(QPoint(e->pos().x() + 5, e->pos().y() + 5));
		const QList<QgsMapToolIdentify::IdentifyResult> selectedFeatures = mIdentifyMenu->exec(results, globalPos);
		if (!selectedFeatures.empty() && selectedFeatures[0].mFeature.hasGeometry())
			setSelectedGeometry(selectedFeatures[0].mFeature.geometry(), e->modifiers());

		return;
	}

	// Handle definition of polygon by clicking points on cancas
	if (!mSelectionRubberBand)
		initRubberBand();

	if (e->button() == Qt::LeftButton)
	{
		mSelectionRubberBand->addPoint(toMapCoordinates(e->pos()));
		mSelectionActive = true;
	}
	else
	{
		if (mSelectionRubberBand->numberOfVertices() > 2)
		{
			setSelectedGeometry(mSelectionRubberBand->asGeometry(), e->modifiers());
		}
		mSelectionRubberBand.reset();
		mSelectionActive = false;
	}
}

void GgsGraphMapToolSelectionHandler::selectFreehandMoveEvent(QgsMapMouseEvent *e)
{
	if (!mSelectionActive || !mSelectionRubberBand)
		return;

	mSelectionRubberBand->addPoint(toMapCoordinates(e->pos()));
}

void GgsGraphMapToolSelectionHandler::selectFreehandReleaseEvent(QgsMapMouseEvent *e)
{
	if (!mSelectionActive)
	{
		if (e->button() != Qt::LeftButton)
			return;

		if (!mSelectionRubberBand)
			initRubberBand();

		mSelectionRubberBand->addPoint(toMapCoordinates(e->pos()));
		mSelectionActive = true;
	}
	else
	{
		if (e->button() == Qt::LeftButton)
		{
			if (mSelectionRubberBand && mSelectionRubberBand->numberOfVertices() > 2)
			{
				setSelectedGeometry(mSelectionRubberBand->asGeometry(), e->modifiers());
			}
		}

		mSelectionRubberBand.reset();
		mSelectionActive = false;
	}
}

void GgsGraphMapToolSelectionHandler::selectRadiusMoveEvent(QgsMapMouseEvent *e)
{
	QgsPointXY radiusEdge = e->snapPoint();

	mSnapIndicator->setMatch(e->mapPointMatch());

	if (!mSelectionActive)
	{
		return;
	}

	if (!mSelectionRubberBand)
	{
		initRubberBand();
	}

	updateRadiusFromEdge(radiusEdge);
}

void GgsGraphMapToolSelectionHandler::selectRadiusReleaseEvent(QgsMapMouseEvent *e)
{
	if (e->button() == Qt::RightButton)
	{
		cancel();
		return;
	}

	if (e->button() != Qt::LeftButton)
		return;

	if (!mSelectionActive)
	{
		mSelectionActive = true;
		mRadiusCenter = e->snapPoint();
		createDistanceWidget();
	}
	else
	{
		if (mSelectionRubberBand)
		{
			setSelectedGeometry(mSelectionRubberBand->asGeometry(), e->modifiers());
		}
		cancel();
	}
}

QgsPointXY GgsGraphMapToolSelectionHandler::toMapCoordinates(QPoint point)
{
	return mCanvas->getCoordinateTransform()->toMapCoordinates(point);
}

void GgsGraphMapToolSelectionHandler::updateRadiusFromEdge(QgsPointXY &radiusEdge)
{
	double radius = std::sqrt(mRadiusCenter.sqrDist(radiusEdge));
	if (mDistanceWidget)
	{
		mDistanceWidget->setDistance(radius);
		mDistanceWidget->setFocus(Qt::TabFocusReason);
	}
	else
	{
		updateRadiusRubberband(radius);
	}
}


