/***************************************************************************
                          qgsmapcanvas.h  -  description
                             -------------------
    begin                : Sun Jun 30 2002
    copyright            : (C) 2002 by Gary E.Sherman
    email                : sherman at mrcc.com
***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSMAPCANVAS_H
#define QGSMAPCANVAS_H

#include "qgsconfig.h"
#include "qgis_sip.h"

#include "qgsexpressioncontext.h"
#include "qgsrectangle.h"
#include "qgsfeatureid.h"
#include "qgsgeometry.h"
#include "qgscustomdrophandler.h"
#include "qgstemporalrangeobject.h"
#include "qgsmapcanvasinteractionblocker.h"
#include "qgsproject.h"

#include <QDomDocument>
#include <QGraphicsView>
#include <QtCore>

#include "qgsmapsettings.h" // TEMPORARY
#include "qgsprevieweffect.h" //for QgsPreviewEffect::PreviewMode

#include <QGestureEvent>
#include "qgis_gui.h"

class QWheelEvent;
class QPixmap;
class QPaintEvent;
class QKeyEvent;
class ResizeEvent;

class QColor;
class QDomDocument;
class QPaintDevice;
class QMouseEvent;
class QRubberBand;
class QGraphicsScene;

class QgsMapToPixel;
class QgsMapLayer;
class QgsHighlight;
class QgsVectorLayer;

class QgsLabelingResults;
class QgsMapRendererCache;
class QgsMapRendererQImageJob;
class QgsMapSettings;
class QgsMapCanvasMap;
class QgsMapOverviewCanvas;
class QgsMapTool;
class QgsSnappingUtils;
class QgsRubberBand;
class QgsMapCanvasAnnotationItem;
class QgsReferencedRectangle;

class QgsTemporalController;

class QMenu;
class QgsMapMouseEvent;


/**
 * \ingroup gui
 * \brief Map canvas is a class for displaying all GIS data types on a canvas.
 */

class GUI_EXPORT QgsMapCanvas : public QGraphicsView, public QgsExpressionContextGenerator
{

#ifdef SIP_RUN
    SIP_CONVERT_TO_SUBCLASS_CODE
    if ( qobject_cast<QgsMapCanvas *>( sipCpp ) != nullptr )
      sipType = sipType_QgsMapCanvas;
    else
      sipType = nullptr;
    SIP_END
#endif

    Q_OBJECT
    Q_PROPERTY( QString theme READ theme WRITE setTheme NOTIFY themeChanged )
    Q_PROPERTY( bool previewJobsEnabled READ previewJobsEnabled WRITE setPreviewJobsEnabled )

  public:

    //! Constructor
    QgsMapCanvas( QWidget *parent SIP_TRANSFERTHIS = nullptr );

    ~QgsMapCanvas() override;

    /**
     * Returns the magnification factor
     * \since QGIS 2.16
     */
    double magnificationFactor() const;

    /**
     * Sets the list of \a layers that should be shown in the canvas.
     *
     * If the map canvas has been associated with a map theme via a call
     * to setTheme(), then any calls to setLayers() are ignored. It is necessary
     * to first clear the theme association by calling setTheme() with an
     * empty string before setLayers() calls can be made.
     *
     * \see layers()
     * \since QGIS 3.0
     */
    void setLayers( const QList<QgsMapLayer *> &layers );

    void setCurrentLayer( QgsMapLayer *layer );

    /**
     * Gets access to properties used for map rendering
     * \since QGIS 2.4
     */
    const QgsMapSettings &mapSettings() const SIP_KEEPREFERENCE;

    /**
     * Sets the temporal controller, tQgsMapCanvasInteractionBlockerhis controller will be used to
     * update the canvas temporal range.
     *
     * \since QGIS 3.14
     */
    void setTemporalController( QgsTemporalController *controller );

    /**
     * Gets access to the temporal controller that will be used to
     * update the canvas temporal range.
     *
     * \since QGIS 3.14
     */
    const QgsTemporalController *temporalController() const;

    /**
     * sets destination coordinate reference system
     * \since QGIS 2.4
     */
    void setDestinationCrs( const QgsCoordinateReferenceSystem &crs );

    /**
     * Resets the \a flags for the canvas' map settings.
     * \since QGIS 3.0
     */
    void setMapSettingsFlags( QgsMapSettings::Flags flags );

    /**
     * Gets access to the labeling results (may be NULLPTR)
     * \since QGIS 2.4
     */
    const QgsLabelingResults *labelingResults() const;

    /**
     * Set whether to cache images of rendered layers
     * \since QGIS 2.4
     */
    void setCachingEnabled( bool enabled );

    /**
     * Check whether images of rendered layers are curerently being cached
     * \since QGIS 2.4
     */
    bool isCachingEnabled() const;

    /**
     * Make sure to remove any rendered images from cache (does nothing if cache is not enabled)
     * \since QGIS 2.4
     */
    void clearCache();

    /**
     * Cancel any rendering job, in a blocking way. Used for application closing.
     * \note not available in Python bindings
     */
    void cancelJobs() SIP_SKIP;

    /**
     * Blocks until the rendering job has finished.
     *
     * In almost all cases you do NOT want to call this, as it will hang the UI
     * until the rendering job is complete. It's included in API solely for
     * unit testing and standalone Python scripts.
     *
     * \since QGIS 3.0
     */
    void waitWhileRendering();

    /**
     * Set whether the layers are rendered in parallel or sequentially
     * \since QGIS 2.4
     */
    void setParallelRenderingEnabled( bool enabled );

    /**
     * Check whether the layers are rendered in parallel or sequentially
     * \since QGIS 2.4
     */
    bool isParallelRenderingEnabled() const;

    /**
     * Set how often map preview should be updated while it is being rendered (in milliseconds)
     * \since QGIS 2.4
     */
    void setMapUpdateInterval( int timeMilliseconds );

    /**
     * Find out how often map preview should be updated while it is being rendered (in milliseconds)
     * \since QGIS 2.4
     */
    int mapUpdateInterval() const;

    /**
     * Returns the last reported scale of the canvas.
     * The \a scale value indicates the scale denominator, e.g. 1000.0 for a 1:1000 map.
     */
    double scale() const;

    //! Returns the mapUnitsPerPixel (map units per pixel) for the canvas
    double mapUnitsPerPixel() const;

    //! Returns the current zoom extent of the map canvas
    QgsRectangle extent() const;
    //! Returns the combined extent for all layers on the map canvas
    QgsRectangle fullExtent() const;

    /**
     * Sets the extent of the map canvas to the specified rectangle.
     *
     * The \a magnified argument dictates whether existing canvas constraints such
     * as a scale lock should be respected or not during the operation. If \a magnified is
     * TRUE then an existing scale lock constraint will be applied. This means that the final
     * visible canvas extent may not match the specified extent.
     *
     * If \a magnified is FALSE then scale lock settings will be ignored, and the specified
     * rectangle will ALWAYS be visible in the canvas.
     */
    void setExtent( const QgsRectangle &r, bool magnified = false );

    /**
     * Sets the canvas to the specified \a extent.
     *
     * \returns TRUE if the zoom was successful.
     *
     * \throws QgsCsException if a transformation error occurred.
     * \since QGIS 3.10
     */
    bool setReferencedExtent( const QgsReferencedRectangle &extent ) SIP_THROW( QgsCsException );

    /**
     * Gets the current map canvas rotation in clockwise degrees
     * \since QGIS 2.8
     */
    double rotation() const;

    /**
     * Set the rotation of the map canvas in clockwise degrees
     * \since QGIS 2.8
     */
    void setRotation( double degrees );

    /**
     * Set the center of the map canvas, in geographical coordinates
     * \since QGIS 2.8
     */
    void setCenter( const QgsPointXY &center );

    /**
     * Gets map center, in geographical coordinates
     * \since QGIS 2.8
     */
    QgsPointXY center() const;

    //! Zoom to the full extent of all layers
    void zoomToFullExtent();

    //! Zoom to the previous extent (view)
    void zoomToPreviousExtent();

    //! Zoom to the next extent (view)
    void zoomToNextExtent();

    //! Clears the list of extents and sets current extent as first item
    void clearExtentHistory();


    /**
     * Set canvas extent to the bounding box of a set of features
     * \param layer the vector layer
     * \param ids the feature ids
    */
    void zoomToFeatureIds( QgsVectorLayer *layer, const QgsFeatureIds &ids );

    /**
     * Centers canvas extent to feature ids
     * \param layer the vector layer
     * \param ids the feature ids
     * \param alwaysRecenter if FALSE, the canvas is recentered only if the bounding box is not contained within the current extent
     */
    void panToFeatureIds( QgsVectorLayer *layer, const QgsFeatureIds &ids, bool alwaysRecenter = true );

    //! Pan to the selected features of current (vector) layer keeping same extent.
    void panToSelected( QgsVectorLayer *layer = nullptr );

    /**
     * Causes a set of features with matching \a ids from a vector \a layer to flash
     * within the canvas.
     *
     * The \a startColor and \a endColor can be specified, along with the number of
     * \a flashes and \a duration of each flash (in milliseconds).
     *
     * \note If the features or geometries are already available, flashGeometries() is much more efficient.
     *
     * \see flashGeometries()
     * \since QGIS 3.0
     */
    void flashFeatureIds( QgsVectorLayer *layer, const QgsFeatureIds &ids,
                          const QColor &startColor = QColor( 255, 0, 0, 255 ), const QColor &endColor = QColor( 255, 0, 0, 0 ),
                          int flashes = 3, int duration = 500 );

    /**
     * Causes a set of \a geometries to flash within the canvas.
     *
     * If \a crs is a valid coordinate reference system, the geometries will be automatically
     * transformed from this CRS to the canvas CRS.
     *
     * The \a startColor and \a endColor can be specified, along with the number of
     * \a flashes and \a duration of each flash (in milliseconds).
     *
     * \see flashFeatureIds()
     * \since QGIS 3.0
     */
    void flashGeometries( const QList< QgsGeometry > &geometries, const QgsCoordinateReferenceSystem &crs = QgsCoordinateReferenceSystem(),
                          const QColor &startColor = QColor( 255, 0, 0, 255 ), const QColor &endColor = QColor( 255, 0, 0, 0 ),
                          int flashes = 3, int duration = 500 );

    //! Sets the map tool currently being used on the canvas
    void setMapTool( QgsMapTool *mapTool, bool clean = false );

    /**
     * \brief Unset the current map tool or last non zoom tool
     *
     * This is called from destructor of map tools to make sure
     * that this map tool won't be used any more.
     * You don't have to call it manually, QgsMapTool takes care of it.
     */
    void unsetMapTool( QgsMapTool *mapTool );

    //! Returns the currently active tool
    QgsMapTool *mapTool();

    /**
     * Sets the \a project linked to this canvas.
     *
     * \since QGIS 3.14
     */
    void setProject( QgsProject *project );

    /**
     * Returns the project linked to this canvas.
     * The returned value may be NULLPTR.
     *
     * \since QGIS 3.14
     */
    QgsProject *project();

    //! Write property of QColor bgColor.
    void setCanvasColor( const QColor &_newVal );
    //! Read property of QColor bgColor.
    QColor canvasColor() const;

    /**
     * Set color of selected vector features
     * \since QGIS 2.4
     */
    void setSelectionColor( const QColor &color );

    /**
     * Returns color for selected features
     * \since QGIS 3.0
     */
    QColor selectionColor() const;

    //! Emits signal scaleChanged to update scale in main window
    void updateScale();

    //! Returns the map layer at position index in the layer stack
    QgsMapLayer *layer( int index );

    //! Returns number of layers on the map
    int layerCount() const;

    /**
     * Returns the list of layers shown within the map canvas.
     * \see setLayers()
     */
    QList<QgsMapLayer *> layers() const;

    /**
     * Freeze/thaw the map canvas. This is used to prevent the canvas from
     * responding to events while layers are being added/removed etc.
     * \param frozen Boolean specifying if the canvas should be frozen (TRUE) or
     * thawed (FALSE). Default is TRUE.
     * \see isFrozen()
     * \see setRenderFlag(). freeze() should be used to programmatically halt map updates,
     * while setRenderFlag() should only be used when users disable rendering via GUI.
     */
    void freeze( bool frozen = true );

    /**
     * Returns TRUE if canvas is frozen.
     * \see renderFlag(). isFrozen() should be used to determine whether map updates
     * have been halted programmatically, while renderFlag() should be used to
     * determine whether a user has disabled rendering via GUI.
     * \see freeze()
     */
    bool isFrozen() const;

    /**
     * Returns TRUE if canvas render is disabled as a result of user disabling
     * renders via the GUI.
     * \see setRenderFlag()
     * \see isFrozen(). isFrozen() should be used to determine whether map updates
     * have been halted programmatically, while renderFlag() should be used to
     * determine whether a user has disabled rendering via GUI.
     */
    bool renderFlag() const { return mRenderFlag; }

    /**
     * Convenience function for returning the current canvas map units. The map units
     * are dictated by the canvas' destinationCrs() map units.
     */
    QgsUnitTypes::DistanceUnit mapUnits() const;

    /**
     * Returns the stored overrides of styles for layers.
     * \see setLayerStyleOverrides().
     * \since QGIS 2.12
     */
    QMap<QString, QString> layerStyleOverrides() const;

    /**
     * Sets the stored overrides of styles for rendering layers.
     *
     * If the map canvas has been associated with a map theme via a call
     * to setTheme(), then any calls to setLayerStyleOverrides() are ignored. It is necessary
     * to first clear the theme association by calling setTheme() with an
     * empty string before setLayerStyleOverrides() calls can be made.
     *
     * \see layerStyleOverrides()
     * \since QGIS 2.12
     */
    void setLayerStyleOverrides( const QMap<QString, QString> &overrides );

    /**
     * Sets a map \a theme to show in the canvas. The theme name must match
     * a theme present in the associated project's QgsMapThemeCollection.
     *
     * When the canvas is associated to a map theme, it will automatically follow
     * the layer selection and layer styles from that theme. Calls to setLayers()
     * or setLayerStyleOverrides() will have no effect, and canvases associated
     * with a QgsLayerTreeMapCanvasBridge will no longer synchronize their
     * state with the layer tree. In these cases it is necessary to call
     * setTheme() with an empty string to clear the theme association and
     * allow map updates with setLayers(), setLayerStyleOverrides(), or via
     * QgsLayerTreeMapCanvasBridge.
     *
     * If an empty string is passed then the current theme association will be
     * cleared.
     * \see theme()
     * \since QGIS 3.0
     */
    void setTheme( const QString &theme );

    /**
     * Returns the map's theme shown in the canvas, if set.
     * \see setTheme()
     * \since QGIS 3.0
     */
    QString theme() const { return mTheme; }

    //! Gets the current coordinate transform
    const QgsMapToPixel *getCoordinateTransform();

    //! Find out whether rendering is in progress
    bool isDrawing();

    //! returns current layer (set by legend widget)
    QgsMapLayer *currentLayer();

    //! Sets wheel zoom factor (should be greater than 1)
    void setWheelFactor( double factor );

    /**
     * Zooms the canvas to a specific \a scale.
     * The scale value indicates the scale denominator, e.g. 1000.0 for a 1:1000 map.

     * If \a ignoreScaleLock is set to TRUE, then any existing constraint on the map scale
     * of the canvas will be ignored during the zoom operation.
     */
    void zoomScale( double scale, bool ignoreScaleLock = false );

    /**
     * Zoom with the factor supplied. Factor > 1 zooms out, interval (0,1) zooms in
     * If point is given, re-center on it.
     *
     * If \a ignoreScaleLock is set to TRUE, then any existing constraint on the map scale
     * of the canvas will be ignored during the zoom operation.
     */
    void zoomByFactor( double scaleFactor, const QgsPointXY *center = nullptr, bool ignoreScaleLock = false );

    //! Zooms in/out with a given center
    void zoomWithCenter( int x, int y, bool zoomIn );

    /**
     * Zooms to feature extent. Adds a small margin around the extent
     * and does a pan if rect is empty (point extent)
     */
    void zoomToFeatureExtent( QgsRectangle &rect );

    /**
     * Returns whether the scale is locked, so zooming can be performed using magnication.
     * \see setScaleLocked()
     * \since QGIS 2.16
     */
    bool scaleLocked() const { return mScaleLocked;}

    //! used to determine if anti-aliasing is enabled or not
    void enableAntiAliasing( bool flag );

    //! TRUE if antialiasing is enabled
    bool antiAliasingEnabled() const { return mSettings.testFlag( QgsMapSettings::Antialiasing ); }

    //! sets map tile rendering flag
    void enableMapTileRendering( bool flag );

    // following 2 methods should be moved elsewhere or changed to private
    // currently used by pan map tool
    //! Ends pan action and redraws the canvas.
    void panActionEnd( QPoint releasePoint );

#ifndef SIP_RUN

    /**
     * Starts a pan action.
     * \note Not available in Python bindings
     * \since QGIS 3.12
     */
    void panActionStart( QPoint releasePoint );
#endif

    //! Called when mouse is moving and pan is activated
    void panAction( QMouseEvent *event );

    //! returns last position of mouse cursor
    QPoint mouseLastXY();

    /**
     * Enables a preview mode for the map canvas
     * \param previewEnabled set to TRUE to enable a preview mode
     * \see setPreviewMode
     * \since QGIS 2.3
    */
    void setPreviewModeEnabled( bool previewEnabled );

    /**
     * Returns whether a preview mode is enabled for the map canvas
     * \returns TRUE if a preview mode is currently enabled
     * \see setPreviewModeEnabled
     * \see previewMode
     * \since QGIS 2.3
    */
    bool previewModeEnabled() const;

    /**
     * Sets a preview mode for the map canvas. This setting only has an effect if
     * previewModeEnabled is TRUE.
     * \param mode preview mode for the canvas
     * \see previewMode
     * \see setPreviewModeEnabled
     * \see previewModeEnabled
     * \since QGIS 2.3
    */
    void setPreviewMode( QgsPreviewEffect::PreviewMode mode );

    /**
     * Returns the current preview mode for the map canvas. This setting only has an effect if
     * previewModeEnabled is TRUE.
     * \returns preview mode for map canvas
     * \see setPreviewMode
     * \see previewModeEnabled
     * \since QGIS 2.3
    */
    QgsPreviewEffect::PreviewMode previewMode() const;

    /**
     * Returns snapping utility class that is associated with map canvas.
     *  If no snapping utils instance has been associated previously, an internal will be created for convenience
     *  (so map tools do not need to test for existence of the instance).
     *
     * Main canvas in QGIS returns an instance which is always up-to-date with the project's snapping configuration.
     *  \since QGIS 2.8
     */
    QgsSnappingUtils *snappingUtils() const;

    /**
     * Assign an instance of snapping utils to the map canvas.
     * The instance is not owned by the canvas, so it is possible to use one instance in multiple canvases.
     *
     * For main canvas in QGIS, do not associate a different instance from the existing one (it is updated from
     * the project's snapping configuration).
     * \since QGIS 2.8
     */
    void setSnappingUtils( QgsSnappingUtils *utils );

    /**
     * Sets an expression context scope for the map canvas. This scope is injected into the expression
     * context used for rendering the map, and can be used to apply specific variable overrides for
     * expression evaluation for the map canvas render. This method will overwrite the existing expression
     * context scope for the canvas.
     * \param scope new expression context scope
     * \see expressionContextScope()
     * \see defaultExpressionContextScope()
     * \since QGIS 2.12
     */
    void setExpressionContextScope( const QgsExpressionContextScope &scope ) { mExpressionContextScope = scope; }

    /**
     * Returns a reference to the expression context scope for the map canvas. This scope is injected
     * into the expression context used for rendering the map, and can be used to apply specific variable
     * overrides for expression evaluation for the map canvas render.
     * \see setExpressionContextScope()
     * \see defaultExpressionContextScope()
     * \since QGIS 2.12
     */
    QgsExpressionContextScope &expressionContextScope() { return mExpressionContextScope; }

    /**
     * Returns a const reference to the expression context scope for the map canvas.
     * \see setExpressionContextScope()
     * \see defaultExpressionContextScope()
     * \note not available in Python bindings
     * \since QGIS 2.12
     */
    const QgsExpressionContextScope &expressionContextScope() const { return mExpressionContextScope; } SIP_SKIP

    /**
     * Creates a new scope which contains default variables and functions relating to the map canvas.
     * \see expressionContextScope()
     * \see setExpressionContextScope()
     * \since QGIS 3.4
     */
    QgsExpressionContextScope *defaultExpressionContextScope() const SIP_FACTORY;

    QgsExpressionContext createExpressionContext() const override;

    /**
     * Sets the segmentation tolerance applied when rendering curved geometries
     * \param tolerance the segmentation tolerance
    */
    void setSegmentationTolerance( double tolerance );

    /**
     * Sets segmentation tolerance type (maximum angle or maximum difference between curve and approximation)
     * \param type the segmentation tolerance typename
    */
    void setSegmentationToleranceType( QgsAbstractGeometry::SegmentationToleranceType type );

    /**
     * Returns a list of all annotation items in the canvas.
     * \since QGIS 3.0
     */
    QList< QgsMapCanvasAnnotationItem *> annotationItems() const;

    /**
     * Returns TRUE if annotations are visible within the map canvas.
     * \see setAnnotationsVisible()
     * \since QGIS 3.0
     */
    bool annotationsVisible() const { return mAnnotationsVisible; }

    /**
     * Sets whether annotations are \a visible in the canvas.
     * \see annotationsVisible()
     * \since QGIS 3.0
     */
    void setAnnotationsVisible( bool visible );

    /**
     * Sets global labeling engine settings in the internal map settings
     * \since QGIS 3.0
     */
    void setLabelingEngineSettings( const QgsLabelingEngineSettings &settings );

    /**
     * Returns global labeling engine settings from the internal map settings
     * \since QGIS 3.0
     */
    const QgsLabelingEngineSettings &labelingEngineSettings() const;

    /**
     * Returns TRUE if canvas map preview jobs (low priority render jobs which render portions
     * of the view just outside of the canvas extent, to allow preview of these
     * out-of-canvas areas when panning or zooming out the map) are enabled
     * for the canvas.
     * \see setPreviewJobsEnabled()
     * \since QGIS 3.0
     */
    bool previewJobsEnabled() const;

    /**
     * Sets whether canvas map preview jobs (low priority render jobs which render portions
     * of the view just outside of the canvas extent, to allow preview of these
     * out-of-canvas areas when panning or zooming out the map) are \a enabled
     * for the canvas.
     * \see previewJobsEnabled()
     * \since QGIS 3.0
     */
    void setPreviewJobsEnabled( bool enabled );

    /**
     * Sets a list of custom drop \a handlers to use when drop events occur on the canvas.
     * \note Not available in Python bindings
     * \since QGIS 3.10
     */
    void setCustomDropHandlers( const QVector<QPointer<QgsCustomDropHandler >> &handlers ) SIP_SKIP;

    /**
     * Set datetime \a range for the map canvas.
     *
     * The temporalRangeChanged() signal will be emitted if the temporal range has been changed.
     *
     * \note Calling setTemporalRange() does not automatically trigger a map refresh.
     *
     * \see temporalRange()
     * \since QGIS 3.14
    */
    void setTemporalRange( const QgsDateTimeRange &range );

    /**
     * Returns map canvas datetime range.
     *
     * \see setTemporalRange()
     * \since QGIS 3.14
    */
    const QgsDateTimeRange &temporalRange() const;

    /**
     * Installs an interaction \a blocker onto the canvas, which may prevent certain map canvas
     * interactions from occurring.
     *
     * The caller retains ownership of \a blocker, and must correctly call removeInteractionBlocker()
     * before deleting the object.
     *
     * \see allowInteraction()
     * \see removeInteractionBlocker()
     * \since QGIS 3.14
     */
    void installInteractionBlocker( QgsMapCanvasInteractionBlocker *blocker );

    /**
     * Removes an interaction \a blocker from the canvas.
     *
     * \see allowInteraction()
     * \see installInteractionBlocker()
     * \since QGIS 3.14
     */
    void removeInteractionBlocker( QgsMapCanvasInteractionBlocker *blocker );

    /**
     * Returns TRUE if the specified \a interaction is currently permitted on the canvas.
     *
     * \since QGIS 3.14
     */
    bool allowInteraction( QgsMapCanvasInteractionBlocker::Interaction interaction ) const;

  public slots:

    //! Repaints the canvas map
    void refresh();

    /**
     * Reload all layers (including refreshing layer properties from their data sources),
     * clears the cache and refreshes the canvas.
     *
     * \note Consider using the less expensive redrawAllLayers() method if a layer reload
     * from the data provider is not required.
     *
     * \since QGIS 2.9
     */
    void refreshAllLayers();

    /**
     * Clears all cached images and redraws all layers.
     *
     * \note Unlike refreshAllLayers(), this does NOT reload layers themselves, and accordingly
     * is more "lightweight". Use this method when only an update of the layer's renderers is required.
     *
     * \since QGIS 3.10
     */
    void redrawAllLayers();

    //! Receives signal about selection change, and pass it on with layer info
    void selectionChangedSlot();

    //! Save the contents of the map canvas to disk as an image
    void saveAsImage( const QString &fileName, QPixmap *QPixmap = nullptr, const QString & = "PNG" );

    //! This slot is connected to the visibility change of one or more layers
    void layerStateChange();

    /**
     * Sets whether a user has disabled canvas renders via the GUI.
     * \param flag set to FALSE to indicate that user has disabled renders
     * \see renderFlag()
     * \see freeze(). freeze() should be used to programmatically halt map updates,
     * while setRenderFlag() should only be used when users disable rendering via GUI.
     */
    void setRenderFlag( bool flag );

    /**
     * stop rendering (if there is any right now)
     * \since QGIS 2.4
     */
    void stopRendering();

    //! called to read map canvas settings from project
    void readProject( const QDomDocument & );

    //! called to write map canvas settings to project
    void writeProject( QDomDocument & );

    /**
     * Sets the factor of magnification to apply to the map canvas. Indeed, we
     * increase/decrease the DPI of the map settings according to this factor
     * in order to render marker point, labels, ... bigger.
     * \param factor The factor of magnification
     * \param center Optional point to re-center the map
     * \since QGIS 2.16
     */
    void setMagnificationFactor( double factor, const QgsPointXY *center = nullptr );

    /**
     * Lock the scale, so zooming can be performed using magnication
     * \see scaleLocked()
     * \since QGIS 2.16
     */
    void setScaleLocked( bool isLocked );

    //! Zoom in with fixed factor
    void zoomIn();

    //! Zoom out with fixed factor
    void zoomOut();

    /**
     * Zoom to the extent of the selected features of provided (vector) layer.
     * \param layer optionally specify different than current layer
     */
    void zoomToSelected( QgsVectorLayer *layer = nullptr );

    /**
     * Set a list of resolutions (map units per pixel) to which to "snap to" when zooming the map
     * \param resolutions A list of resolutions
     * \since QGIS 3.12
     */
    void setZoomResolutions( const QList<double> &resolutions ) { mZoomResolutions = resolutions; }

    /**
     * \returns List of resolutions to which to "snap to" when zooming the map
     * \see setZoomResolutions()
     * \since QGIS 3.12
     */
    const QList<double> &zoomResolutions() const { return mZoomResolutions; }

  private slots:
    //! called when current maptool is destroyed
    void mapToolDestroyed();

    //! called when a renderer job has finished successfully or when it was canceled
    void rendererJobFinished();

    //! called when a preview job has been finished
    void previewJobFinished();

    void mapUpdateTimeout();

    void refreshMap();

    void mapThemeChanged( const QString &theme );
    //! Renames the active map theme called \a theme to \a newTheme
    void mapThemeRenamed( const QString &theme, const QString &newTheme );

  signals:

    /**
     * Emits current mouse position
     * \note changed in 1.3
    */
    void xyCoordinates( const QgsPointXY &p );

    //! Emitted when the scale of the map changes
    void scaleChanged( double );

    /**
     * Emitted when the scale locked state of the map changes
     * \param locked true if the scale is locked
     * \see setScaleLocked
     * \since QGIS 3.16
     */
    void scaleLockChanged( bool locked );


    //! Emitted when the extents of the map change
    void extentsChanged();

    /**
     * Emitted when the rotation of the map changes
     * \since QGIS 2.8
     */
    void rotationChanged( double );

    /**
     * Emitted when the scale of the map changes
     * \since QGIS 2.16
     */
    void magnificationChanged( double );

    /**
     * Emitted when canvas background color changes
     * \since QGIS 3.0
     */
    void canvasColorChanged();

    // TODO: deprecate when decorations are reimplemented as map canvas items

    /**
     * Emitted when the canvas has rendered.
     * Passes a pointer to the painter on which the map was drawn. This is
     * useful for plugins that wish to draw on the map after it has been
     * rendered.  Passing the painter allows plugins to work when the map is
     * being rendered onto a pixmap other than the mapCanvas own pixmap member.
     *
     * - anything related to rendering progress is not visible outside of map canvas
     * - additional drawing shall be done directly within the renderer job or independently as a map canvas item
     */
    void renderComplete( QPainter * );

    // ### QGIS 3: renamte to mapRefreshFinished()
    //! Emitted when canvas finished a refresh request.
    void mapCanvasRefreshed();

    // ### QGIS 3: rename to mapRefreshStarted()
    //! Emitted when the canvas is about to be rendered.
    void renderStarting();

    //! Emitted when a new set of layers has been received
    void layersChanged();

    //! Emit key press event
    void keyPressed( QKeyEvent *e );

    //! Emit key release event
    void keyReleased( QKeyEvent *e );

    /**
     * Emit map tool changed with the old tool
     * \since QGIS 2.3
     */
    void mapToolSet( QgsMapTool *newTool, QgsMapTool *oldTool );


    //! Emitted when selection in any layer gets changed
    void selectionChanged( QgsVectorLayer *layer );

    //! Emitted when zoom last status changed
    void zoomLastStatusChanged( bool );

    //! Emitted when zoom next status changed
    void zoomNextStatusChanged( bool );

    /**
     * Emitted when map CRS has changed
     * \since QGIS 2.4
     */
    void destinationCrsChanged();

    /**
     * Emitted when the canvas transform context is changed.
     * \since QGIS 3.0
     */
    void transformContextChanged();

    /**
     * Emitted when the current layer is changed
     * \since QGIS 2.8
     */
    void currentLayerChanged( QgsMapLayer *layer );

    /**
     * Emitted when the configuration of overridden layer styles changes
     * \since QGIS 2.12
     */
    void layerStyleOverridesChanged();

    /**
     * Emitted when the canvas has been assigned a different map theme.
     * \see setTheme()
     * \since QGIS 3.0
     */
    void themeChanged( const QString &theme );

    //! emit a message (usually to be displayed in a message bar)
    void messageEmitted( const QString &title, const QString &message, Qgis::MessageLevel = Qgis::Info );

    /**
     * Emitted whenever an error is encountered during a map render operation.
     *
     * The \a layer argument indicates the associated map layer, if available.
     *
     * \since QGIS 3.10.0
     */
    void renderErrorOccurred( const QString &error, QgsMapLayer *layer );

    /**
     * Emitted whenever the distance or bearing of an in-progress panning
     * operation is changed.
     *
     * This signal will be emitted during a pan operation as the user moves the map,
     * giving the total distance and bearing between the map position at the
     * start of the pan and the current pan position.
     *
     * \since QGIS 3.12
     */
    void panDistanceBearingChanged( double distance, QgsUnitTypes::DistanceUnit unit, double bearing );

    /**
     * Emitted whenever a tap and hold \a gesture occurs at the specified map point.
     * \since QGIS 3.12
     */
    void tapAndHoldGestureOccurred( const QgsPointXY &mapPoint, QTapAndHoldGesture *gesture );

    /**
     * Emitted when the map canvas temporal range changes.
     *
     * \since QGIS 3.14
     */
    void temporalRangeChanged();


    /**
     * Emitted before the map canvas context menu will be shown.
     * Can be used to extend the context menu.
     *
     * \since QGIS 3.16
     */
    void contextMenuAboutToShow( QMenu *menu, QgsMapMouseEvent *event );


  protected:

    bool event( QEvent *e ) override;
    void keyPressEvent( QKeyEvent *e ) override;
    void keyReleaseEvent( QKeyEvent *e ) override;
    void mouseDoubleClickEvent( QMouseEvent *e ) override;
    void mouseMoveEvent( QMouseEvent *e ) override;
    void mousePressEvent( QMouseEvent *e ) override;
    void mouseReleaseEvent( QMouseEvent *e ) override;
    void wheelEvent( QWheelEvent *e ) override;
    void resizeEvent( QResizeEvent *e ) override;
    void paintEvent( QPaintEvent *e ) override;
    void dragEnterEvent( QDragEnterEvent *e ) override;

    //! called when panning is in action, reset indicates end of panning
    void moveCanvasContents( bool reset = false );

    void dropEvent( QDropEvent *event ) override;


    /// implementation struct
    class CanvasProperties;

    /// Handle pattern for implementation object
    std::unique_ptr<CanvasProperties> mCanvasProperties;

#if 0

    /**
     * Debugging member
     * invoked when a connect() is made to this object
     */
    void connectNotify( const char *signal ) override;
#endif

  protected slots:
    //! called on resize or changed extent to notify canvas items to change their rectangle
    void updateCanvasItemPositions();

  private slots:

    void layerRepaintRequested( bool deferred );

    void autoRefreshTriggered();

    void updateAutoRefreshTimer();

    void projectThemesChanged();

    void startPreviewJob( int number );

  private:

    // Restore scale RAII
    class ScaleRestorer
    {
      public:
        ScaleRestorer( QgsMapCanvas *canvas ):
          mCanvas( canvas )
        {
          mLockedScale = mCanvas->mapSettings().scale();
        };

        ~ScaleRestorer()
        {
          QgsRectangle newExtent = mCanvas->mapSettings().extent();
          newExtent.scale( mLockedScale / mCanvas->mapSettings().scale() );
          mCanvas->mSettings.setExtent( newExtent );
        };

      private:
        QgsMapCanvas *mCanvas;
        double mLockedScale;
    };

    //! encompases all map settings necessary for map rendering
    QgsMapSettings mSettings;

    //! owns pixmap with rendered map and controls rendering
    QgsMapCanvasMap *mMap = nullptr;

    /**
     * Temporal controller for tracking update of temporal objects
     * which relates with canvas
     */
    QgsTemporalController *mController = nullptr;

    //! Flag indicating if the map canvas is frozen.
    bool mFrozen = false;

    //! Flag that allows squashing multiple refresh() calls into just one delayed rendering job
    bool mRefreshScheduled = false;

    //! Flag that triggers a refresh after an ongoing rendering job triggered by autoRefresh
    bool mRefreshAfterJob = false;

    //! determines whether user has requested to suppress rendering
    bool mRenderFlag = true;

    //! current layer in legend
    QPointer< QgsMapLayer > mCurrentLayer;

    //! graphics scene manages canvas items
    QGraphicsScene *mScene = nullptr;

    //! pointer to current map tool
    QgsMapTool *mMapTool = nullptr;

    //! previous tool if current is for zooming/panning
    QgsMapTool *mLastNonZoomMapTool = nullptr;

    //! Pointer to project linked to this canvas
    QgsProject *mProject = nullptr;

    //! Context menu
    QMenu *mMenu = nullptr;

    //! recently used extent
    QList <QgsRectangle> mLastExtent;
    int mLastExtentIndex = -1;

    //! Scale factor multiple for default zoom in/out
    double mWheelZoomFactor = 2.0;

    //! Timer that periodically fires while map rendering is in progress to update the visible map
    QTimer mMapUpdateTimer;

    //! Job that takes care of map rendering in background
    QgsMapRendererQImageJob *mJob = nullptr;

    //! Flag determining whether the active job has been canceled
    bool mJobCanceled = false;

    //! Labeling results from the recently rendered map
    QgsLabelingResults *mLabelingResults = nullptr;

    //! Whether layers are rendered sequentially or in parallel
    bool mUseParallelRendering = false;

    //! Whether to add rendering stats to the rendered image
    bool mDrawRenderingStats = false;

    //! Optionally use cache with rendered map layers for the current map settings
    QgsMapRendererCache *mCache = nullptr;

    QTimer *mResizeTimer = nullptr;
    QTimer *mRefreshTimer = nullptr;

    QgsPreviewEffect *mPreviewEffect = nullptr;

    QgsRectangle imageRect( const QImage &img, const QgsMapSettings &mapSettings );

    QgsSnappingUtils *mSnappingUtils = nullptr;

    QList< QgsMapRendererQImageJob * > mPreviewJobs;

    //! lock the scale, so zooming can be performed using magnication
    bool mScaleLocked = false;

    QgsExpressionContextScope mExpressionContextScope;

    //! Stores zoom rect
    QRect mZoomRect;

    //! Flag to indicate a zoom by rectangle operation is taking place
    bool mZoomDragging = false;

    //! Zoom by rectangle rubber band
    std::unique_ptr< QgsRubberBand > mZoomRubberBand;

    QCursor mZoomCursor;

    QTimer mAutoRefreshTimer;

    QTimer mPreviewTimer;
    QMetaObject::Connection mPreviewTimerConnection;

    QString mTheme;

    QgsPointXY mCursorPoint;

    bool mAnnotationsVisible = true;

    bool mUsePreviewJobs = false;

    QHash< QString, int > mLastLayerRenderTime;

    QVector<QPointer<QgsCustomDropHandler >> mDropHandlers;

    QgsDistanceArea mDa;
    QList<double> mZoomResolutions;

    QList< QgsMapCanvasInteractionBlocker * > mInteractionBlockers;

    /**
     * Returns the last cursor position on the canvas in geographical coordinates
     * \since QGIS 3.4
     */
    QgsPointXY cursorPoint() const;

    /**
     * Force a resize of the map canvas item
     * \since QGIS 2.16
     */
    void updateMapSize();

    /**
     * Starts zooming via rectangle
     * \param pos start position for rectangle
     * \since QGIS 2.16
     */
    void beginZoomRect( QPoint pos );

    /**
     * Ends zooming via rectangle
     * \param pos end position for rectangle
     * \since QGIS 2.16
     */
    void endZoomRect( QPoint pos );

    /**
     * Returns bounding box of feature list (in canvas coordinates)
     * \param ids feature id list
     * \param layer the layer
     * \param bbox out: bounding box
     * \param errorMsg error message in case of error
     * \returns TRUE in case of success
    */
    bool boundingBoxOfFeatureIds( const QgsFeatureIds &ids, QgsVectorLayer *layer, QgsRectangle &bbox, QString &errorMsg ) const;

    /**
     * Rerturns the optimal extent for a point \a layer and a given \a center point in canvas CRS.
     * This will return an extent combined of the center and the closest point in the layer.
     * The extent can be scaled with a \a scale factor.
     * The returned extent might be an empty rect if it cannot be determnined.
     */
    QgsRectangle optimalExtentForPointLayer( QgsVectorLayer *layer, const QgsPointXY &center, int scaleFactor = 5 );

    void setLayersPrivate( const QList<QgsMapLayer *> &layers );

    void startPreviewJobs();
    void stopPreviewJobs();
    void schedulePreviewJob( int number );

    /**
     * Returns TRUE if a pan operation is in progress
     */
    bool panOperationInProgress();

    int nextZoomLevel( const QList<double> &resolutions, bool zoomIn = true ) const;
    double zoomInFactor() const;
    double zoomOutFactor() const;

    /**
     * Make sure to remove any rendered images of temporal-enabled layers from cache (does nothing if cache is not enabled)
     * \since QGIS 3.14
     */
    void clearTemporalCache();

    void showContextMenu( QgsMapMouseEvent *event );

    friend class TestQgsMapCanvas;

}; // class QgsMapCanvas

// clazy:excludeall=qstring-allocations

#endif
