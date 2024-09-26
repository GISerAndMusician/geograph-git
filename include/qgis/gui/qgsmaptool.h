/***************************************************************************
    qgsmaptool.h  -  base class for map canvas tools
    ----------------------
    begin                : January 2006
    copyright            : (C) 2006 by Martin Dobias
    email                : wonder.sk at gmail dot com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSMAPTOOL_H
#define QGSMAPTOOL_H

#include "qgsconfig.h"
#include "qgis.h"

#include <QCursor>
#include <QString>
#include <QObject>

#include <QGestureEvent>
#include "qgis_gui.h"

class QgsMapLayer;
class QgsMapCanvas;
class QgsRenderContext;
class QKeyEvent;
class QMouseEvent;
class QWheelEvent;
class QgsPoint;
class QgsPointXY;
class QgsRectangle;
class QPoint;
class QAction;
class QAbstractButton;
class QgsMapMouseEvent;
class QMenu;

#ifdef SIP_RUN
% ModuleHeaderCode
// fix to allow compilation with sip 4.7 that for some reason
// doesn't add these includes to the file where the code from
// ConvertToSubClassCode goes.
#include <qgsmaptoolzoom.h>
#include <qgsmaptoolpan.h>
#include <qgsmaptoolemitpoint.h>
#include <qgsmaptoolidentify.h>
% End
#endif

/**
 * \ingroup gui
 * \brief Abstract base class for all map tools.
 * Map tools are user interactive tools for manipulating the
 * map canvas. For example map pan and zoom features are
 * implemented as map tools.
 */
class GUI_EXPORT QgsMapTool : public QObject
{

#ifdef SIP_RUN
    SIP_CONVERT_TO_SUBCLASS_CODE
    if ( dynamic_cast<QgsMapToolZoom *>( sipCpp ) != NULL )
      sipType = sipType_QgsMapToolZoom;
    else if ( dynamic_cast<QgsMapToolPan *>( sipCpp ) != NULL )
      sipType = sipType_QgsMapToolPan;
    else if ( dynamic_cast<QgsMapToolEmitPoint *>( sipCpp ) != NULL )
      sipType = sipType_QgsMapToolEmitPoint;
    else if ( dynamic_cast<QgsMapToolIdentify *>( sipCpp ) != NULL )
      sipType = sipType_QgsMapToolIdentify;
    else
      sipType = NULL;
    SIP_END
#endif

    Q_OBJECT

  public:

    /**
     * Enumeration of flags that adjust the way the map tool operates
     * \since QGIS 2.16
     */
    enum Flag
    {
      Transient = 1 << 1, /*!< Indicates that this map tool performs a transient (one-off) operation.
                               If it does, the tool can be operated once and then a previous map
                               tool automatically restored. */
      EditTool = 1 << 2, //!< Map tool is an edit tool, which can only be used when layer is editable
      AllowZoomRect = 1 << 3, //!< Allow zooming by rectangle (by holding shift and dragging) while the tool is active
      ShowContextMenu = 1 << 4, //!< Show a context menu when right-clicking with the tool (since QGIS 3.14). See populateContextMenu().
    };
    Q_DECLARE_FLAGS( Flags, Flag )

    /**
     * Returns the flags for the map tool.
     * \since QGIS 2.16
     */
    virtual Flags flags() const { return Flags(); }

    ~QgsMapTool() override;

    //! Mouse move event for overriding. Default implementation does nothing.
    virtual void canvasMoveEvent( QgsMapMouseEvent *e );

    //! Mouse double-click event for overriding. Default implementation does nothing.
    virtual void canvasDoubleClickEvent( QgsMapMouseEvent *e );

    //! Mouse press event for overriding. Default implementation does nothing.
    virtual void canvasPressEvent( QgsMapMouseEvent *e );

    //! Mouse release event for overriding. Default implementation does nothing.
    virtual void canvasReleaseEvent( QgsMapMouseEvent *e );

    //! Mouse wheel event for overriding. Default implementation does nothing.
    virtual void wheelEvent( QWheelEvent *e );

    //! Key event for overriding. Default implementation does nothing.
    virtual void keyPressEvent( QKeyEvent *e );

    //! Key event for overriding. Default implementation does nothing.
    virtual void keyReleaseEvent( QKeyEvent *e );

    //! gesture event for overriding. Default implementation does nothing.
    virtual bool gestureEvent( QGestureEvent *e );

    /**
     * Use this to associate a QAction to this maptool. Then when the setMapTool
     * method of mapcanvas is called the action state will be set to on.
     * Usually this will cause e.g. a toolbutton to appear pressed in and
     * the previously used toolbutton to pop out.
    */
    void setAction( QAction *action );

    //! Returns associated action with map tool or NULLPTR if no action is associated
    QAction *action();

    /**
     * Returns if the current map tool active on the map canvas
     * \since QGIS 3.4
     */
    bool isActive() const;

    /**
     * Use this to associate a button to this maptool. It has the same meaning
     * as setAction() function except it works with a button instead of an QAction.
    */
    void setButton( QAbstractButton *button );

    //! Returns associated button with map tool or NULLPTR if no button is associated
    QAbstractButton *button();

    //! Sets a user defined cursor
    virtual void setCursor( const QCursor &cursor );

    //! called when set as currently active map tool
    virtual void activate();

    //! called when map tool is being deactivated
    virtual void deactivate();

    //! convenient method to clean members
    virtual void clean();

    //! returns pointer to the tool's map canvas
    QgsMapCanvas *canvas() const;

    /**
     * Emit map tool changed with the old tool
     * \since QGIS 2.3
     */
    QString toolName() { return mToolName; }

    /**
     * Gets search radius in mm. Used by identify, tip etc.
     *  The values is currently set in identify tool options (move somewhere else?)
     *  and defaults to Qgis::DEFAULT_SEARCH_RADIUS_MM.
     *  \since QGIS 2.3
    */
    static double searchRadiusMM();

    /**
     * Gets search radius in map units for given context. Used by identify, tip etc.
     *  The values is calculated from searchRadiusMM().
     *  \since QGIS 2.3
    */
    static double searchRadiusMU( const QgsRenderContext &context );

    /**
     * Gets search radius in map units for given canvas. Used by identify, tip etc.
     *  The values is calculated from searchRadiusMM().
     *  \since QGIS 2.3
     */
    static double searchRadiusMU( QgsMapCanvas *canvas );

    /**
     * Allows the tool to populate and customize the given \a menu,
     * prior to showing it in response to a right-mouse button click.
     *
     * \a menu will be initially populated with a set of default, generic actions.
     * Any new actions added to the menu should be correctly parented to \a menu.
     *
     * The default implementation does nothing.
     *
     * \note The context menu is only shown when the ShowContextMenu flag
     * is present in flags().
     *
     * \since QGIS 3.14
     */
    virtual void populateContextMenu( QMenu *menu );

  signals:
    //! emit a message
    void messageEmitted( const QString &message, Qgis::MessageLevel = Qgis::Info );

    //! emit signal to clear previous message
    void messageDiscarded();

    //! signal emitted once the map tool is activated
    void activated();

    //! signal emitted once the map tool is deactivated
    void deactivated();

  private slots:
    //! clear pointer when action is destroyed
    void actionDestroyed();

  protected:

    //! constructor takes map canvas as a parameter
    QgsMapTool( QgsMapCanvas *canvas SIP_TRANSFERTHIS );

    //! transformation from screen coordinates to map coordinates
    QgsPointXY toMapCoordinates( QPoint point );

    //! transformation from screen coordinates to layer's coordinates
    QgsPointXY toLayerCoordinates( const QgsMapLayer *layer, QPoint point );

    //! transformation from map coordinates to layer's coordinates
    QgsPointXY toLayerCoordinates( const QgsMapLayer *layer, const QgsPointXY &point );

    //!transformation from layer's coordinates to map coordinates (which is different in case reprojection is used)
    QgsPointXY toMapCoordinates( const QgsMapLayer *layer, const QgsPointXY &point );

    /**
     * transformation from layer's coordinates to map coordinates (which is different in case reprojection is used)
     * \note available in Python bindings as toMapCoordinatesV2
     */
    QgsPoint toMapCoordinates( const QgsMapLayer *layer, const QgsPoint &point ) SIP_PYNAME( toMapCoordinatesV2 );

    //! trnasformation of the rect from map coordinates to layer's coordinates
    QgsRectangle toLayerCoordinates( const QgsMapLayer *layer, const QgsRectangle &rect );

    //! transformation from map coordinates to screen coordinates
    QPoint toCanvasCoordinates( const QgsPointXY &point ) const;

    //! pointer to map canvas
    QgsMapCanvas *mCanvas = nullptr;

    //! cursor used in map tool
    QCursor mCursor;

    /**
     * optionally map tool can have pointer to action
     * which will be used to set that action as active
     */
    QAction *mAction = nullptr;

    /**
     * optionally map tool can have pointer to a button
     * which will be used to set that action as active
     */
    QAbstractButton *mButton = nullptr;

    //! translated name of the map tool
    QString mToolName;

};

Q_DECLARE_OPERATORS_FOR_FLAGS( QgsMapTool::Flags )

#endif
