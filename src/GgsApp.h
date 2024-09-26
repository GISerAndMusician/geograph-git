#pragma once

#include <QtWidgets/QMainWindow>
#include "qgsmapcanvas.h"
#include "ui_GgsApp.h"
#include <QSplashScreen>
#include "qgsattributetablefiltermodel.h"
#include "qgsvectortilelayer.h"
#include "qgslayertreeregistrybridge.h"
#include "qgsmaptoolselect.h"
#include "qgsvectorlayersaveasdialog.h"

class QgisAppStyleSheet;
class QgsLayerTreeView;
class QgsSnappingUtils;
class QgsMessageBar;
class QgsBrowserGuiModel;
class QgsBrowserDockWidget;
class QgsLayerStylingWidget;
class QgsAttributeTableFilterModel;
class QgsDataSourceManagerDialog;
class QgsDockWidget;
class QgsMapLayerConfigWidgetFactory;
class QgsLegendFilterButton;
class QgsLayerTreeMapCanvasBridge;
class QgsCustomLayerOrderWidget;
class QgsLayerTreeRegistryBridge;
class QgsUndoWidget;
class QgsStatusBar;
class QgsStatusBarCoordinatesWidget;
class QgsMapToolIdentifyAction;
class QgsMapToolSelect;
class QgsBearingNumericFormat;
class QgsVectorLayerSaveAsDialog;
class QgsHandleBadLayersHandler;
class QgsStatusBarScaleWidget;
class QgsUserInputWidget;

class GgsFdebWidget;
class GgsMingleWidget;
class GgsKdeebWidget;
class GgsGraphProxy;
class GgsGraphLegendWidget;
class GgsGraphMapToolSelect;
class GgsLwoInteraction;
class GgsLwoInteractionWidget;

class GgsApp : public QMainWindow, public Ui::GgsAppClass
{
    Q_OBJECT

public:

	static const char *GRAPH_ORGANIZATION_NAME;
	static const char *GRAPH_ORGANIZATION_DOMAIN;
	static const char *GRAPH_APPLICATION_NAME;

    GgsApp(QSplashScreen* splashScreen, QWidget *parent = nullptr);
    ~GgsApp();

	static GgsApp *instance() { return sInstance; }

	void showLayerProperties(QgsMapLayer *mapLayer, const QString &page = QString());

	QgsMapLayer *activeLayer();

	// 显示当前选定图层的属性表
	void attributeTable(QgsAttributeTableFilterModel::FilterMode filter = QgsAttributeTableFilterModel::ShowAll);

	// 显示地图风格停靠窗
	void mapStyleDock(bool enabled);

	// 设置地图样式停靠窗的图层。不显示样式停靠窗。
	void setMapStyleDockLayer(QgsMapLayer *layer);

	// 开始或停止图层编辑
	bool toggleEditing(QgsMapLayer *layer, bool allowCancel = true);

	// 返回数据源管理器对话框的消息栏（如果可见），否则返回画布的消息栏。
	QgsMessageBar *visibleMessageBar();

	// 返回应用程序中打开的所有地图画布的列表。
	QList< QgsMapCanvas * > mapCanvases();

	// 获取定时消息的超时：默认值为5秒
	int messageTimeout();

	void updateUndoActions();

	QgsLayerTreeRegistryBridge::InsertionPoint layerTreeInsertionPoint() const;

	// 返回指向地图图例的指针
	QgsLayerTreeView *layerTreeView();

	/**
	* 返回工具栏图标大小。如果停靠工具栏为TRUE，则返回停靠中包含的工具栏的图标大小。
	*/
	QSize iconSize(bool dockedToolbar = false) const;

	void removeLayers(QList<QgsMapLayer *> layers);

	// 添加用户输入控件
	void addUserInputWidget(QWidget* widget);

public slots:
	// 存储当前的地图图层
	QString saveAsFile(QgsMapLayer *layer = nullptr, bool onlySelected = false, bool defaultToAddToMap = true);

	// 存储为栅格文件
	QString saveAsRasterFile(QgsRasterLayer *layer = nullptr, bool defaultAddToCanvas = true);

	// 保存当前图层风格为qml文件
    void saveStyleFile( QgsMapLayer *layer = nullptr );

	/**
	 * 通过提示用户将内存层保存为基于磁盘的（OGR）格式，然后替换该层的数据源，使内存层永久化。
	 */
	void makeMemoryLayerPermanent(QgsVectorLayer *layer);

	void layerProperties();

	QgsMessageBar *messageBar();

	//确保新图层的插入点与图层树视图中的当前项目最新
	void updateNewLayerInsertionPoint();

	//! 连接到图层树注册表bridge，选择第一个新添加的地图图层
	void autoSelectAddedLayer(QList<QgsMapLayer *> layers);

	// 返回当前应用的地图画布
	QgsMapCanvas *mapCanvas();

	/**
	  * 检查可用的数据转换，并询问用户是否有多个可用的转换，并且没有选择。仅当相应地设置了全局选项时，才会显示对话框。
	  * \returns 如果用户专门选择了基准变换或只有一个可用，则为TRUE。
	  * \since 3.0
	  */
	bool askUserForDatumTransform(const QgsCoordinateReferenceSystem &sourceCrs, const QgsCoordinateReferenceSystem &destinationCrs, const QgsMapLayer *layer = nullptr);

	/**
	* 此方法将打开一个对话框，用户可以选择要加载的OGR子层，然后返回这些层的列表。它会破坏过程中经过的层
	*/
	QList< QgsMapLayer * > askUserForOGRSublayers(QgsVectorLayer *&layerTransferOwnership, const QStringList &subLayers);

	/**
	 * 此方法将打开一个对话框，用户可以选择要加载的GDAL子层
	 * \returns 如果加载了任何项目，则为TRUE
	 */
	bool askUserForZipItemLayers(const QString &path);

	/**
	 * 此方法将验证GDAL层是否包含子层
	 */
	bool shouldAskUserForGDALSublayers(QgsRasterLayer *layer);

	/**
	* 该方法将打开一个对话框，以便用户可以选择要加载的GDAL子层，
	* 然后返回这些层的列表。
	*/
	QList< QgsMapLayer * > askUserForGDALSublayers(QgsRasterLayer *layer);

	QList<QgsMapLayer *> loadGDALSublayers(const QString &uri, const QStringList &list);

	/**
	* 冻结所有画布
	*/
	void freezeCanvases(bool frozen = true);

	void showStatusMessage(const QString &message);

	QAction *actionShowAllLayers() { return mActionShowAllLayers; }
	QAction *actionHideAllLayers() { return mActionHideAllLayers; }
	QAction *actionShowSelectedLayers() { return mActionShowSelectedLayers; }
	QAction *actionHideSelectedLayers() { return mActionHideSelectedLayers; }
	QAction *actionToggleSelectedLayers() { return mActionToggleSelectedLayers; }
	QAction *actionToggleSelectedLayersIndependently() { return mActionToggleSelectedLayersIndependently; }
	QAction *actionHideDeselectedLayers() { return mActionHideDeselectedLayers; }

public slots:
	/**
	 * \brief dataSourceManager打开dataSourceManager对话框
	 * \param pageName页面名称，通常是提供者名称或“浏览器”（对于浏览器面板）或“ogr”（矢量层）或“光栅”（光栅层）
	 */
	void dataSourceManager(const QString &pageName = QString());

	/**
	 * 向地图添加栅格图层
	 * 它不会强制刷新
	 */
	bool addRasterLayer(QgsRasterLayer *rasterLayer);

	bool addRasterLayers(const QStringList &layerQStringList, bool guiWarning = true);

	/**
	 * Add a raster layer directly without prompting user for location
	  The caller must provide information compatible with the provider plugin
	  using the \a uri and \a baseName. The provider can use these
	  parameters in any way necessary to initialize the layer. The \a baseName
	  parameter is used in the Map Legend so it should be formed in a meaningful
	  way.
	  */
	QgsRasterLayer *addRasterLayer(QString const &uri, QString const &baseName, QString const &providerKey);

	/**
	 * 直接添加矢量层而不提示用户输入位置
	 * 调用者必须提供与提供程序插件兼容的信息使用vectorLayerPath和baseName。
	 * 提供者可以使用这些初始化层所需的任何方式的参数。baseName参数在Map Legend中使用，因此它应该以有意义的方法
	 */
	QgsVectorLayer *addVectorLayer(const QString &vectorLayerPath, const QString &baseName, const QString &providerKey);

	/**
	 * \brief 私有addLayer方法的重载版本，它采用文件名列表，而不是用对话框提示用户。
	 * \param enc 层的编码类型
	 * \param dataSourceType ogr datasource类型
	 * \returns 如果成功添加图层，则为TRUE
	 */
	bool addVectorLayers(const QStringList &layerQStringList, const QString &enc, const QString &dataSourceType);

	/*
	 * \brief 添加切片图层
	 * \param url 切片服务地址
	 * \param baseName 
	 */
	QgsVectorTileLayer *addVectorTileLayer(const QString &url, const QString &baseName);

	/*
	 * 更改图层的数据源，将打开数据源选择对话框，如果接受，将应用所选数据源。
	 *
	 * 如果层最初是无效的，并且它具有原始的XML层属性，则将应用这些属性。
	 */
	void changeDataSource(QgsMapLayer *layer);

	// 添加虚拟图层
	void addVirtualLayer();

	// 从地图和图例中删除图层
	void removeLayer();

	// 设置当前图例中组的CRS
	void legendGroupSetCrs();

	// 将当前图层保存为qrl图层定义文件
	void saveAsLayerDefinition();

	// 将当前图层的CRS设置给工程
	void setProjectCrsFromLayer();
	// 设置图层CRS
	void setLayerCrs();

	// 取消所有选中
	void deselectAll();

private slots:

	void addRasterLayer();

	void setAppStyleSheet(const QString &stylesheet );

	void layerTreeViewDoubleClicked(const QModelIndex &index);

	void activateDeactivateLayerRelatedActions(QgsMapLayer *layer);

	void onActiveLayerChanged(QgsMapLayer *layer);

	void updateFilterLegend();
	void toggleFilterLegendByExpression(bool checked);

	void zoomIn();
	void zoomOut();
	void pan();
	void identify();
	void selectFeatures();
	void selectByPolygon();
	void selectByFreehand();
	void selectByRadius();

	void showPanMessage(double distance, QgsUnitTypes::DistanceUnit unit, double bearing);
	void selectionModeChanged(QgsMapToolSelect::Mode mode);

	void SelectNode(bool bChecked);
	void selectEdge(bool bChecked);
	void selectNodeAndEdge(bool bChecked);
	void selectNodeAndAdjEdges(bool bChecked);
	void clearSelection();

	// 刷新地图画布
	void refreshMapCanvas(bool redrawAllLayers = false);

	void updateMouseCoordinatePrecision();

	bool fileNew(bool promptToSaveFlag, bool forceBlank = false);

	// 添加CSV图数据
	void addCSVGraphLayer();
	void addODDataLayer();

	// 导出图数据
	void exportGraphFile();
	void exportCSVGraphFile();

	// 基类方法的实现
	void showAllLayers();
	void hideAllLayers();
	void showSelectedLayers();
	void hideSelectedLayers();
	void toggleSelectedLayers();
	void toggleSelectedLayersIndependently();
	void hideDeselectedLayers();

	// 编辑
	void removeGraphElements();

	// 边捆绑算法
	void showFDEBDockWidget();
	void showMINGLEDockWidget();
	void showKDEEBDockWidget();

	// 交互
	void onLocalWindowTriggered(bool bChecked);

	// 处理
	void cluster();
	void aggregation();
	void backbone();
	void kcore();
	void convexHull();

	// 统计
	void graphStatistic();
	void similarity();
	void infoAmount();

private:
	void createMenus();
	void createActions();
	void createCanvasTools();
	void createStatusBar();
	void setupConnections();
	void restoreWindowState();
	bool fileNewBlank(); // prepare empty project, also skips any default templates from loading
	void updateCrsStatusBar();

	void applyDefaultSettingsToCanvas(QgsMapCanvas *canvas);

	void initLayerTreeView();
	void setupLayerTreeViewFromSettings();

	bool addVectorLayersPrivate(const QStringList &layerQStringList, const QString &enc, const QString &dataSourceType, bool guiWarning = true);
	QgsVectorLayer *addVectorLayerPrivate(const QString &vectorLayerPath, const QString &baseName, const QString &providerKey, bool guiWarning = true);
	
	QgsRasterLayer *addRasterLayerPrivate(const QString &uri, const QString &baseName,
		const QString &providerKey, bool guiWarning,
		bool guiUpdate);

	/**
	 * 打开给定的栅格图层
	 */
	QgsRasterLayer *addRasterLayer(const QString &rasterFile, const QString &baseName, bool guiWarning = true);

	/*
	 * \brief 添加瓦片图层
	*/
	QgsVectorTileLayer *addVectorTileLayerPrivate(const QString &uri, const QString &baseName, bool guiWarning = true);

	QString saveAsVectorFileGeneral(QgsVectorLayer *vlayer = nullptr, bool symbologyOption = true, bool onlySelected = false, bool defaultToAddToMap = true);
	QString saveAsVectorFileGeneral(QgsVectorLayer *vlayer, bool symbologyOption, bool onlySelected, bool defaultToAddToMap,
		const std::function< void(const QString &newFilename,
			bool addToCanvas,
			const QString &layerName,
			const QString &encoding,
			const QString &vectorFileName)> &onSuccess, const std::function< void(int error, const QString &errorMessage) > &onFailure,
		int dialogOptions = QgsVectorLayerSaveAsDialog::AllOptions,
		const QString &dialogTitle = QString());

	bool checkTasksDependOnProject();
	bool checkUnsavedLayerEdits();

signals:

	// 当前图层发生变化时发射
	void activeLayerChanged(QgsMapLayer *layer);

	// 当图层被另存为时调佣
	void layerSavedAs(QgsMapLayer *l, const QString &path);

	/**
	 * 当连接被provider选择对话框添加或删除时发出
	 */
	void connectionsChanged();

	void newProject();

private:

	class Tools
	{
	public:

		Tools() = default;

		QgsMapTool *mZoomIn = nullptr;
		QgsMapTool *mZoomOut = nullptr;
		QgsMapTool *mPan = nullptr;
		QgsMapToolIdentifyAction *mIdentify = nullptr;
		QgsMapToolSelect *mSelectFeatures = nullptr;
		QgsMapToolSelect *mSelectPolygon = nullptr;
		QgsMapToolSelect *mSelectFreehand = nullptr;
		QgsMapToolSelect *mSelectRadius = nullptr;

		GgsGraphMapToolSelect* mGraphSelect = nullptr;

	} mMapTools;

	class QgsCanvasRefreshBlocker
	{
	public:

		QgsCanvasRefreshBlocker()
		{
			if (GgsApp::instance()->mFreezeCount++ == 0)
			{
				// going from unfrozen to frozen, so freeze canvases
				GgsApp::instance()->freezeCanvases(true);
			}
		}
		QgsCanvasRefreshBlocker(const QgsCanvasRefreshBlocker &other) = delete;
		QgsCanvasRefreshBlocker &operator=(const QgsCanvasRefreshBlocker &other) = delete;

		void release()
		{
			if (mReleased)
				return;

			mReleased = true;
			if (--GgsApp::instance()->mFreezeCount == 0)
			{
				// going from frozen to unfrozen, so unfreeze canvases
				GgsApp::instance()->freezeCanvases(false);
				GgsApp::instance()->refreshMapCanvas();
			}
		}

		~QgsCanvasRefreshBlocker()
		{
			if (!mReleased)
				release();
		}

	private:

		bool mReleased = false;
	};

	int mFreezeCount = 0;
	friend class QgsCanvasRefreshBlocker;

	static GgsApp *sInstance;

	QgsMapCanvas *mMapCanvas = nullptr;

	QSplashScreen* mSplashScreen;

	QgisAppStyleSheet *mStyleSheetBuilder = nullptr;

	QgsLayerTreeView *mLayerTreeView = nullptr;

	QString mRasterFileFilter;

	// 状态栏
	QgsStatusBar *mStatusBar = nullptr;
	// 将在状态栏中显示和编辑坐标的小部件
	QgsStatusBarCoordinatesWidget *mCoordsEdit = nullptr;
	QgsStatusBarScaleWidget *mScaleWidget = nullptr;
	//! Widget in status bar used to show status of on the fly projection
	QToolButton *mOnTheFlyProjectionStatusButton = nullptr;

	std::unique_ptr< QgsBearingNumericFormat > mBearingNumericFormat;

	QgsSnappingUtils *mSnappingUtils = nullptr;

	QgsMessageBar *mInfoBar = nullptr;

	QgsLayerStylingWidget *mMapStyleWidget = nullptr;

	QgsDockWidget *mMapStylingDock = nullptr;

	QList<QgsMapLayerConfigWidgetFactory *> mMapLayerPanelFactories;

	QgsDataSourceManagerDialog *mDataSourceManagerDialog = nullptr;

	QgsLegendFilterButton *mLegendExpressionFilterButton = nullptr;

	// 如果我们阻止发出activeLayerChanged信号，则为True
	bool mBlockActiveLayerChanged = false;

	QgsUndoWidget *mUndoWidget = nullptr;

	// 将图层树与地图画布连接起来的助手类
	QgsLayerTreeMapCanvasBridge *mLayerTreeCanvasBridge = nullptr;
	// 用于排序地图图层的目录（图例）
	QgsCustomLayerOrderWidget *mMapLayerOrder = nullptr;

	QgsDockWidget *mLayerTreeDock = nullptr;
	QgsDockWidget *mLayerOrderDock = nullptr;

	QAction *mActionFilterLegend = nullptr;

	QgsBrowserGuiModel *mBrowserModel = nullptr;
	QgsBrowserDockWidget *mBrowserWidget = nullptr;

	QgsHandleBadLayersHandler *mAppBadLayersHandler = nullptr;

	QDateTime mProjectLastModified;

	QgsUserInputWidget *mUserInputDockWidget = nullptr;
	
	// 边捆绑算法UI界面
	GgsFdebWidget* mFDEBWidget = nullptr;
	QgsDockWidget* mFDEBDockWidget = nullptr;

	GgsMingleWidget* mMINGLEWidget = nullptr;
	QgsDockWidget* mMINGLEDockWidget = nullptr;

	GgsKdeebWidget* mKDEEBWidget = nullptr;
	QgsDockWidget* mKDEEBDockWidget = nullptr;

	QgsDockWidget* mGraphLegendDockWidget = nullptr;
	GgsGraphLegendWidget* mGraphLegendWgt = nullptr;

	QgsDockWidget* mLwoInteractionDockWidget = nullptr;
	GgsLwoInteractionWidget* mLwoInteractionWidget = nullptr;

	// 交互
	GgsLwoInteraction* mLWOInteraction = nullptr;
};
