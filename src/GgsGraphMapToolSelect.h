#pragma once
#include "qgsmaptool.h"
#include "GgsGraphMapToolSelectionHandler.h"

class GgsGraphProxy;

class GgsGraphMapToolSelect: public QgsMapTool
{
	Q_OBJECT

public:
	enum Mode
	{
		GeometryIntersectsSetSelection,
		GeometryIntersectsAddToSelection,
		GeometryIntersectsSubtractFromSelection,
		GeometryIntersectsIntersectWithSelection,
		GeometryWithinSetSelection,
		GeometryWithinAddToSelection,
		GeometryWithinSubtractFromSelection,
		GeometryWithinIntersectWithSelection,
	};

	enum FeatureMode
	{
		NodeOnly,
		EdgeOnly,
		NodeAndEdge,
		NodeAndAdjEdges
	};

	GgsGraphMapToolSelect(QgsMapCanvas* canvas);

	void canvasPressEvent(QgsMapMouseEvent *e) override;
	void canvasMoveEvent(QgsMapMouseEvent *e) override;
	void canvasReleaseEvent(QgsMapMouseEvent *e) override;
	void keyPressEvent(QKeyEvent *e) override;
	void keyReleaseEvent(QKeyEvent *e) override;
	void deactivate() override;
	Flags flags() const override;

	void setSelectionMode(GgsGraphMapToolSelectionHandler::SelectionMode selectionMode);

	void setSelectionFeatureMode(FeatureMode featureMode);

	GgsGraphMapToolSelectionHandler* handler() { return mSelectionHandler.get(); }

signals:
	void modeChanged(Mode mode);
	void graphFeatureSelectionChanged(GgsGraphProxy* g);

private slots:
	void selectGraphFeatures( Qt::KeyboardModifiers modifiers );
	void selectFeatures(Qt::KeyboardModifiers modifiers);

private:
	void modifiersChanged(bool ctrlModifier, bool shiftModifier, bool altModifier);

private:
	std::unique_ptr<GgsGraphMapToolSelectionHandler> mSelectionHandler;
	FeatureMode mFeatureMode = NodeAndEdge;
};

