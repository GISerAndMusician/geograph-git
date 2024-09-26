#pragma once
#include <QObject>
#include <QWidget>
#include "qgsgeometry.h"

class QHBoxLayout;
class QKeyEvent;
class QgsDoubleSpinBox;

class QgsMapCanvas;
class QgsRubberBand;
class QgsSnapIndicator;
class QgsIdentifyMenu;
class QgsMapMouseEvent;

class GgsGraphDistanceWidget : public QWidget
{
	Q_OBJECT

public:

	//! Constrructor
	explicit GgsGraphDistanceWidget(const QString &label = QString(), QWidget *parent = nullptr);

	//! distance setter
	void setDistance(double distance);
	//! distance getter
	double distance();

signals:
	//! distance changed signal
	void distanceChanged(double distance);
	//! distanceEditingFinished signal
	void distanceEditingFinished(double distance, const Qt::KeyboardModifiers &modifiers);
	//! distanceEditingCanceled signal
	void distanceEditingCanceled();

protected:
	bool eventFilter(QObject *obj, QEvent *ev) override;

private:
	QHBoxLayout *mLayout = nullptr;
	QgsDoubleSpinBox *mDistanceSpinBox = nullptr;
};


class GgsGraphMapToolSelectionHandler: public QObject
{
	Q_OBJECT

public:
	enum SelectionMode
	{
		//! SelectSimple - single click or drawing a rectangle, default option
		SelectSimple,
		//! SelectPolygon - drawing a polygon or right-click on existing polygon feature
		SelectPolygon,
		//! SelectFreehand - free hand selection
		SelectFreehand,
		//! SelectRadius - a circle selection
		SelectRadius
	};

	GgsGraphMapToolSelectionHandler(QgsMapCanvas *canvas, 
		GgsGraphMapToolSelectionHandler::SelectionMode selectionMode = GgsGraphMapToolSelectionHandler::SelectionMode::SelectSimple);

	~GgsGraphMapToolSelectionHandler() override;

	SelectionMode selectionMode() const;

	void setSelectionMode(SelectionMode mode);

	//! Deactivates handler (when map tool gets deactivated)
	void deactivate();

	//! Handles mouse move event from map tool
	void canvasMoveEvent(QgsMapMouseEvent *e);
	//! Handles mouse press event from map tool
	void canvasPressEvent(QgsMapMouseEvent *e);
	//! Handles mouse release event from map tool
	void canvasReleaseEvent(QgsMapMouseEvent *e);
	//! Handles escape press event - returns true if the even has been processed
	bool keyReleaseEvent(QKeyEvent *e);

	void setSelectedGeometry(const QgsGeometry &geometry, Qt::KeyboardModifiers modifiers = Qt::NoModifier);

	QgsGeometry selectedGeometry() const;

	double radius() const;

signals:
	void geometryChanged(Qt::KeyboardModifiers modifiers = Qt::NoModifier);

private slots:
	//! cancel selecting (between two click events)
	void cancel();

	void updateRadiusRubberband(double radius);

	void radiusValueEntered(double radius, Qt::KeyboardModifiers modifiers);

private:
	void initRubberBand();

	void createDistanceWidget();
	void deleteDistanceWidget();

	void selectFeaturesMoveEvent(QgsMapMouseEvent *e);
	void selectFeaturesReleaseEvent(QgsMapMouseEvent *e);
	void selectFeaturesPressEvent(QgsMapMouseEvent *e);

	void selectPolygonMoveEvent(QgsMapMouseEvent *e);
	void selectPolygonPressEvent(QgsMapMouseEvent *e);

	void selectFreehandMoveEvent(QgsMapMouseEvent *e);
	void selectFreehandReleaseEvent(QgsMapMouseEvent *e);

	void selectRadiusMoveEvent(QgsMapMouseEvent *e);
	void selectRadiusReleaseEvent(QgsMapMouseEvent *e);

	QgsPointXY toMapCoordinates(QPoint point);

	void updateRadiusFromEdge(QgsPointXY &radiusEdge);

private:
	QgsMapCanvas *mCanvas = nullptr;

	std::unique_ptr<QgsRubberBand> mSelectionRubberBand;

	bool mSelectionActive = false;

	SelectionMode mSelectionMode = SelectSimple;

	std::unique_ptr<QgsSnapIndicator> mSnapIndicator;

	QPoint mInitDragPos;

	QgsPointXY mRadiusCenter;

	double mRadius;

	QColor mFillColor = QColor(254, 178, 76, 63);
	QColor mStrokeColor = QColor(254, 58, 29, 100);

	QgsIdentifyMenu *mIdentifyMenu = nullptr;

	GgsGraphDistanceWidget *mDistanceWidget = nullptr;

	QgsGeometry mSelectionGeometry;
};

