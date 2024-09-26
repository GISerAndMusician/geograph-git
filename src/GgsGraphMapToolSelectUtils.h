#pragma once
#include <Qt>
#include <QRect>
#include <QPoint>

#include "qgsvectorlayer.h"

class QgsMapCanvas;

namespace GgsGraphMapToolSelectUtils {

	QgsVectorLayer *getCurrentVectorLayer(QgsMapCanvas *canvas);

	QgsRectangle expandSelectRectangle(QgsPointXY mapPoint, QgsMapCanvas *canvas, QgsVectorLayer *vlayer);

	void selectSingleFeature(QgsMapCanvas *canvas, const QgsGeometry &selectGeometry, Qt::KeyboardModifiers modifiers);

	QgsFeatureIds getMatchingFeatures(QgsMapCanvas *canvas, const QgsGeometry &selectGeometry, bool doContains, bool singleSelect);

	void selectMultipleFeatures(QgsMapCanvas *canvas, const QgsGeometry &selectGeometry, Qt::KeyboardModifiers modifiers);

	void setSelectedFeatures(QgsMapCanvas *canvas,
		const QgsGeometry &selectGeometry,
		QgsVectorLayer::SelectBehavior selectBehavior = QgsVectorLayer::SetSelection,
		bool doContains = true,
		bool singleSelect = false);
}

