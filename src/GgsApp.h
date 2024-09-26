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

	// ��ʾ��ǰѡ��ͼ������Ա�
	void attributeTable(QgsAttributeTableFilterModel::FilterMode filter = QgsAttributeTableFilterModel::ShowAll);

	// ��ʾ��ͼ���ͣ����
	void mapStyleDock(bool enabled);

	// ���õ�ͼ��ʽͣ������ͼ�㡣����ʾ��ʽͣ������
	void setMapStyleDockLayer(QgsMapLayer *layer);

	// ��ʼ��ֹͣͼ��༭
	bool toggleEditing(QgsMapLayer *layer, bool allowCancel = true);

	// ��������Դ�������Ի������Ϣ��������ɼ��������򷵻ػ�������Ϣ����
	QgsMessageBar *visibleMessageBar();

	// ����Ӧ�ó����д򿪵����е�ͼ�������б�
	QList< QgsMapCanvas * > mapCanvases();

	// ��ȡ��ʱ��Ϣ�ĳ�ʱ��Ĭ��ֵΪ5��
	int messageTimeout();

	void updateUndoActions();

	QgsLayerTreeRegistryBridge::InsertionPoint layerTreeInsertionPoint() const;

	// ����ָ���ͼͼ����ָ��
	QgsLayerTreeView *layerTreeView();

	/**
	* ���ع�����ͼ���С�����ͣ��������ΪTRUE���򷵻�ͣ���а����Ĺ�������ͼ���С��
	*/
	QSize iconSize(bool dockedToolbar = false) const;

	void removeLayers(QList<QgsMapLayer *> layers);

	// ����û�����ؼ�
	void addUserInputWidget(QWidget* widget);

public slots:
	// �洢��ǰ�ĵ�ͼͼ��
	QString saveAsFile(QgsMapLayer *layer = nullptr, bool onlySelected = false, bool defaultToAddToMap = true);

	// �洢Ϊդ���ļ�
	QString saveAsRasterFile(QgsRasterLayer *layer = nullptr, bool defaultAddToCanvas = true);

	// ���浱ǰͼ����Ϊqml�ļ�
    void saveStyleFile( QgsMapLayer *layer = nullptr );

	/**
	 * ͨ����ʾ�û����ڴ�㱣��Ϊ���ڴ��̵ģ�OGR����ʽ��Ȼ���滻�ò������Դ��ʹ�ڴ�����û���
	 */
	void makeMemoryLayerPermanent(QgsVectorLayer *layer);

	void layerProperties();

	QgsMessageBar *messageBar();

	//ȷ����ͼ��Ĳ������ͼ������ͼ�еĵ�ǰ��Ŀ����
	void updateNewLayerInsertionPoint();

	//! ���ӵ�ͼ����ע���bridge��ѡ���һ������ӵĵ�ͼͼ��
	void autoSelectAddedLayer(QList<QgsMapLayer *> layers);

	// ���ص�ǰӦ�õĵ�ͼ����
	QgsMapCanvas *mapCanvas();

	/**
	  * �����õ�����ת������ѯ���û��Ƿ��ж�����õ�ת��������û��ѡ�񡣽�����Ӧ��������ȫ��ѡ��ʱ���Ż���ʾ�Ի���
	  * \returns ����û�ר��ѡ���˻�׼�任��ֻ��һ�����ã���ΪTRUE��
	  * \since 3.0
	  */
	bool askUserForDatumTransform(const QgsCoordinateReferenceSystem &sourceCrs, const QgsCoordinateReferenceSystem &destinationCrs, const QgsMapLayer *layer = nullptr);

	/**
	* �˷�������һ���Ի����û�����ѡ��Ҫ���ص�OGR�Ӳ㣬Ȼ�󷵻���Щ����б������ƻ������о����Ĳ�
	*/
	QList< QgsMapLayer * > askUserForOGRSublayers(QgsVectorLayer *&layerTransferOwnership, const QStringList &subLayers);

	/**
	 * �˷�������һ���Ի����û�����ѡ��Ҫ���ص�GDAL�Ӳ�
	 * \returns ����������κ���Ŀ����ΪTRUE
	 */
	bool askUserForZipItemLayers(const QString &path);

	/**
	 * �˷�������֤GDAL���Ƿ�����Ӳ�
	 */
	bool shouldAskUserForGDALSublayers(QgsRasterLayer *layer);

	/**
	* �÷�������һ���Ի����Ա��û�����ѡ��Ҫ���ص�GDAL�Ӳ㣬
	* Ȼ�󷵻���Щ����б�
	*/
	QList< QgsMapLayer * > askUserForGDALSublayers(QgsRasterLayer *layer);

	QList<QgsMapLayer *> loadGDALSublayers(const QString &uri, const QStringList &list);

	/**
	* �������л���
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
	 * \brief dataSourceManager��dataSourceManager�Ի���
	 * \param pageNameҳ�����ƣ�ͨ�����ṩ�����ƻ���������������������壩��ogr����ʸ���㣩�򡰹�դ������դ�㣩
	 */
	void dataSourceManager(const QString &pageName = QString());

	/**
	 * ���ͼ���դ��ͼ��
	 * ������ǿ��ˢ��
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
	 * ֱ�����ʸ���������ʾ�û�����λ��
	 * �����߱����ṩ���ṩ���������ݵ���Ϣʹ��vectorLayerPath��baseName��
	 * �ṩ�߿���ʹ����Щ��ʼ����������κη�ʽ�Ĳ�����baseName������Map Legend��ʹ�ã������Ӧ����������ķ���
	 */
	QgsVectorLayer *addVectorLayer(const QString &vectorLayerPath, const QString &baseName, const QString &providerKey);

	/**
	 * \brief ˽��addLayer���������ذ汾���������ļ����б��������öԻ�����ʾ�û���
	 * \param enc ��ı�������
	 * \param dataSourceType ogr datasource����
	 * \returns ����ɹ����ͼ�㣬��ΪTRUE
	 */
	bool addVectorLayers(const QStringList &layerQStringList, const QString &enc, const QString &dataSourceType);

	/*
	 * \brief �����Ƭͼ��
	 * \param url ��Ƭ�����ַ
	 * \param baseName 
	 */
	QgsVectorTileLayer *addVectorTileLayer(const QString &url, const QString &baseName);

	/*
	 * ����ͼ�������Դ����������Դѡ��Ի���������ܣ���Ӧ����ѡ����Դ��
	 *
	 * ������������Ч�ģ�����������ԭʼ��XML�����ԣ���Ӧ����Щ���ԡ�
	 */
	void changeDataSource(QgsMapLayer *layer);

	// �������ͼ��
	void addVirtualLayer();

	// �ӵ�ͼ��ͼ����ɾ��ͼ��
	void removeLayer();

	// ���õ�ǰͼ�������CRS
	void legendGroupSetCrs();

	// ����ǰͼ�㱣��Ϊqrlͼ�㶨���ļ�
	void saveAsLayerDefinition();

	// ����ǰͼ���CRS���ø�����
	void setProjectCrsFromLayer();
	// ����ͼ��CRS
	void setLayerCrs();

	// ȡ������ѡ��
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

	// ˢ�µ�ͼ����
	void refreshMapCanvas(bool redrawAllLayers = false);

	void updateMouseCoordinatePrecision();

	bool fileNew(bool promptToSaveFlag, bool forceBlank = false);

	// ���CSVͼ����
	void addCSVGraphLayer();
	void addODDataLayer();

	// ����ͼ����
	void exportGraphFile();
	void exportCSVGraphFile();

	// ���෽����ʵ��
	void showAllLayers();
	void hideAllLayers();
	void showSelectedLayers();
	void hideSelectedLayers();
	void toggleSelectedLayers();
	void toggleSelectedLayersIndependently();
	void hideDeselectedLayers();

	// �༭
	void removeGraphElements();

	// �������㷨
	void showFDEBDockWidget();
	void showMINGLEDockWidget();
	void showKDEEBDockWidget();

	// ����
	void onLocalWindowTriggered(bool bChecked);

	// ����
	void cluster();
	void aggregation();
	void backbone();
	void kcore();
	void convexHull();

	// ͳ��
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
	 * �򿪸�����դ��ͼ��
	 */
	QgsRasterLayer *addRasterLayer(const QString &rasterFile, const QString &baseName, bool guiWarning = true);

	/*
	 * \brief �����Ƭͼ��
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

	// ��ǰͼ�㷢���仯ʱ����
	void activeLayerChanged(QgsMapLayer *layer);

	// ��ͼ�㱻���Ϊʱ��Ӷ
	void layerSavedAs(QgsMapLayer *l, const QString &path);

	/**
	 * �����ӱ�providerѡ��Ի�����ӻ�ɾ��ʱ����
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

	// ״̬��
	QgsStatusBar *mStatusBar = nullptr;
	// ����״̬������ʾ�ͱ༭�����С����
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

	// ���������ֹ����activeLayerChanged�źţ���ΪTrue
	bool mBlockActiveLayerChanged = false;

	QgsUndoWidget *mUndoWidget = nullptr;

	// ��ͼ�������ͼ��������������������
	QgsLayerTreeMapCanvasBridge *mLayerTreeCanvasBridge = nullptr;
	// ���������ͼͼ���Ŀ¼��ͼ����
	QgsCustomLayerOrderWidget *mMapLayerOrder = nullptr;

	QgsDockWidget *mLayerTreeDock = nullptr;
	QgsDockWidget *mLayerOrderDock = nullptr;

	QAction *mActionFilterLegend = nullptr;

	QgsBrowserGuiModel *mBrowserModel = nullptr;
	QgsBrowserDockWidget *mBrowserWidget = nullptr;

	QgsHandleBadLayersHandler *mAppBadLayersHandler = nullptr;

	QDateTime mProjectLastModified;

	QgsUserInputWidget *mUserInputDockWidget = nullptr;
	
	// �������㷨UI����
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

	// ����
	GgsLwoInteraction* mLWOInteraction = nullptr;
};
