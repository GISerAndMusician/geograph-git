/***************************************************************************
                    qgsprovidermetadata.h  -  Metadata class for
                    describing a data provider.
                             -------------------
    begin                : Sat Jan 10 2004
    copyright            : (C) 2004 by Gary E.Sherman
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

#ifndef QGSPROVIDERMETADATA_H
#define QGSPROVIDERMETADATA_H


#include <QString>
#include <QVariantMap>
#include <QMap>
#include <QList>
#include <memory>
#include <QPair>

#include "qgis_sip.h"
#include "qgsdataprovider.h"
#include "qgis_core.h"
#include <functional>
#include "qgsvectorlayerexporter.h"
#include "qgsabstractproviderconnection.h"
#include "qgsabstractdatabaseproviderconnection.h"
#include "qgsfields.h"
#include "qgsexception.h"

class QgsDataItem;
class QgsDataItemProvider;
class QgsTransaction;

class QgsRasterDataProvider;
class QgsMeshDataProvider;
struct QgsMesh;

/**
 * \ingroup core
 * \brief Holds metadata about mesh driver
 *
 * \since QGIS 3.12
 */
class CORE_EXPORT QgsMeshDriverMetadata
{
    Q_GADGET

  public:

    /**
     * Flags for the capabilities of the driver
     */
    enum MeshDriverCapability
    {
      CanWriteFaceDatasets = 1 << 0, //!< If the driver can persist datasets defined on faces
      CanWriteVertexDatasets = 1 << 1, //!< If the driver can persist datasets defined on vertices
      CanWriteEdgeDatasets = 1 << 2, //!< If the driver can persist datasets defined on edges \since QGIS 3.14
      CanWriteMeshData = 1 << 3, //!< If the driver can write mesh data on file \since QGIS 3.16
    };

    Q_ENUM( MeshDriverCapability )
    Q_DECLARE_FLAGS( MeshDriverCapabilities, MeshDriverCapability )
    Q_FLAG( MeshDriverCapabilities )

    //! Constructs default metadata without any capabilities
    QgsMeshDriverMetadata();

    /**
     * Constructs driver metadata with selected capabilities
     *
     * \param name name/key of the driver
     * \param description short description of the driver
     * \param capabilities driver's capabilities
     */
    QgsMeshDriverMetadata( const QString &name,
                           const QString &description,
                           const MeshDriverCapabilities &capabilities,
                           const QString &writeDatasetOnFileSuffix );

    /**
     * Returns the capabilities for this driver.
     */
    MeshDriverCapabilities capabilities() const;

    /**
     * Returns the name (key) for this driver.
     */
    QString name() const;

    /**
     * Returns the description for this driver.
     */
    QString description() const;

    /**
     * Returns the suffix used to write datasets on file
     */
    QString writeDatasetOnFileSuffix() const;

  private:
    QString mName;
    QString mDescription;
    MeshDriverCapabilities mCapabilities;
    QString mWriteDatasetOnFileSuffix;
};

Q_DECLARE_OPERATORS_FOR_FLAGS( QgsMeshDriverMetadata::MeshDriverCapabilities )

/**
 * \ingroup core
 * \brief Holds data provider key, description, and associated shared library file or function pointer information.
 *
 * Provider metadata refers either to providers which are loaded via libraries or
 * which are native providers that are included in the core QGIS installation
 * and accessed through function pointers.
 *
 * For library based providers, the metadata class is used in a lazy load
 * implementation in QgsProviderRegistry.  To save memory, data providers
 * are only actually loaded via QLibrary calls if they're to be used.  (Though they're all
 * iteratively loaded once to get their metadata information, and then
 * unloaded when the QgsProviderRegistry is created.)  QgsProviderMetadata
 * supplies enough information to be able to later load the associated shared
 * library object.
 *
 */
class CORE_EXPORT QgsProviderMetadata : public QObject
{
    Q_OBJECT

  public:

    /**
     * Typedef for data provider creation function.
     * \since QGIS 3.0
     */
    SIP_SKIP typedef std::function < QgsDataProvider*( const QString &, const QgsDataProvider::ProviderOptions &, QgsDataProvider::ReadFlags & ) > CreateDataProviderFunction;

    /**
     * Constructor for provider metadata
     * \param key provider key
     * \param description provider description
     * \param library plugin library file name (empty if the provider is not loaded from a library)
     */
    QgsProviderMetadata( const QString &key, const QString &description, const QString &library = QString() );

    /**
     * Metadata for provider with direct provider creation function pointer, where
     * no library is involved.
     * \since QGIS 3.0
     * \deprecated QGIS 3.10
     */
    SIP_SKIP Q_DECL_DEPRECATED QgsProviderMetadata( const QString &key, const QString &description, const QgsProviderMetadata::CreateDataProviderFunction &createFunc );

    //! dtor
    virtual ~QgsProviderMetadata();

    /**
     * This returns the unique key associated with the provider
     *
     * This key string is used for the associative container in QgsProviderRegistry
     */
    QString key() const;

    /**
     * This returns descriptive text for the provider
     *
     * This is used to provide a descriptive list of available data providers.
     */
    QString description() const;

    /**
     * This returns the library file name
     *
     * This is used to QLibrary calls to load the data provider (only for dynamically loaded libraries)
     *
     * \deprecated QGIS 3.10 - providers may not need to be loaded from a library (empty string returned)
     */
    Q_DECL_DEPRECATED QString library() const SIP_DEPRECATED;

    /**
     * Returns a pointer to the direct provider creation function, if supported
     * by the provider.
     * \note not available in Python bindings
     * \since QGIS 3.0
     * \deprecated QGIS 3.10
     */
    SIP_SKIP Q_DECL_DEPRECATED CreateDataProviderFunction createFunction() const;

    /**
      * Initialize the provider
      * \since QGIS 3.10
      */
    virtual void initProvider();

    /**
     * Cleanup the provider
     * \since QGIS 3.10
     */
    virtual void cleanupProvider();

    /**
     * Type of file filters
     * \since QGIS 3.10
     */
    enum class FilterType
    {
      FilterVector = 1,
      FilterRaster,
      FilterMesh,
      FilterMeshDataset
    };

    /**
     * Builds the list of file filter strings (supported formats)
     *
     * Suitable for use in a QFileDialog::getOpenFileNames() call.
     *
     * \since QGIS 3.10
     */
    virtual QString filters( FilterType type );

    /**
     * Builds the list of available mesh drivers metadata
     *
     * \since QGIS 3.12
     */
    virtual QList<QgsMeshDriverMetadata> meshDriversMetadata();

    /**
     * Class factory to return a pointer to a newly created QgsDataProvider object
     *
     * \param uri the datasource uri
     * \param options creation options
     * \param flags creation flags, sing QGIS 3.16
     *
     * \since QGIS 3.10
     */
    virtual QgsDataProvider *createProvider( const QString &uri,
        const QgsDataProvider::ProviderOptions &options,
        QgsDataProvider::ReadFlags flags = QgsDataProvider::ReadFlags() ) SIP_FACTORY;

    /**
     * Sets the \a value into the \a uri \a parameter as a bool.
     * eg. "yes" value will be saved as TRUE, 0 will be saved as FALSE
     *
     * \since QGIS 3.14
     */
    static void setBoolParameter( QVariantMap &uri, const QString &parameter, const QVariant &value );

    /**
     * Returns the \a parameter value in the \a uri as a bool.
     * eg. "yes" value will be returned as TRUE, 0 will be returned as FALSE
     *
     * \since QGIS 3.14
     */
    static bool boolParameter( const QVariantMap &uri, const QString &parameter, bool defaultValue = false );


#ifndef SIP_RUN

    /**
     * Creates new empty vector layer
     * \note not available in Python bindings
     * \since QGIS 3.10
     */
    virtual QgsVectorLayerExporter::ExportError createEmptyLayer( const QString &uri,
        const QgsFields &fields,
        QgsWkbTypes::Type wkbType,
        const QgsCoordinateReferenceSystem &srs,
        bool overwrite,
        QMap<int, int> &oldToNewAttrIdxMap,
        QString &errorMessage,
        const QMap<QString, QVariant> *options );
#endif

    /**
     * Creates a new instance of the raster data provider.
     * \since QGIS 3.10
     */
    virtual QgsRasterDataProvider *createRasterDataProvider(
      const QString &uri,
      const QString &format,
      int nBands,
      Qgis::DataType type,
      int width,
      int height,
      double *geoTransform,
      const QgsCoordinateReferenceSystem &crs,
      const QStringList &createOptions = QStringList() ) SIP_FACTORY;

    /**
     * Creates mesh data source, that is the mesh frame stored in file, memory or with other way (depending of the provider)
     * \since QGIS 3.16
     */
    virtual bool createMeshData(
      const QgsMesh &mesh,
      const QString uri,
      const QString &driverName,
      const QgsCoordinateReferenceSystem &crs ) const;

    /**
     * Returns pyramid resampling methods available for provider
     * \since QGIS 3.10
     */
    virtual QList<QPair<QString, QString> > pyramidResamplingMethods();

    /**
     * Breaks a provider data source URI into its component paths (e.g. file path, layer name).
     * \param uri uri string
     * \returns map containing components. Standard components may include:
     *
     * - "path": file path
     * - "layerName"
     * - "url": base URL, for online services
     * - "referer": referrer string, for HTTP requests
     * - "host": hostname, for database services
     * - "bounds": hardcoded layer bounds (as a QgsRectangle)
     * - "crs": CRS definition
     * - "authcfg": authentication configuration ID
     *
     * \note this function may not be supported by all providers, an empty map will be returned in such case
     * \since QGIS 3.10
     */
    virtual QVariantMap decodeUri( const QString &uri );

    /**
     * Reassembles a provider data source URI from its component paths (e.g. file path, layer name).
     * \param parts parts as returned by decodeUri
     * \returns datasource uri string
     * \note this function may not be supported by all providers, an empty string will be returned in such case
     * \see decodeUri()
     * \since QGIS 3.12
     */
    virtual QString encodeUri( const QVariantMap &parts );

    /**
     * Returns data item providers. Caller is responsible for ownership of the item providers
     * \see QgsProviderGuiMetadata::dataItemGuiProviders()
     * \note Ownership of created data item providers is passed to the caller.
     * \since QGIS 3.10
     */
    virtual QList< QgsDataItemProvider * > dataItemProviders() const SIP_FACTORY;

    /**
     * Lists stored layer styles in the provider defined by \a uri
     * \returns -1 if not implemented by provider, otherwise number of styles stored
     * \since QGIS 3.10
     */
    virtual int listStyles( const QString &uri, QStringList &ids, QStringList &names,
                            QStringList &descriptions, QString &errCause );

    /**
     * Gets a layer style defined by \a uri
     * \since QGIS 3.10
     */
    virtual QString getStyleById( const QString &uri, QString styleId, QString &errCause );

    /**
     * Deletes a layer style defined by \a styleId
     * \since QGIS 3.10
     */
    virtual bool deleteStyleById( const QString &uri, QString styleId, QString &errCause );

    /**
     * Saves a layer style to provider
     * \since QGIS 3.10
     */
    virtual bool saveStyle( const QString &uri, const QString &qmlStyle, const QString &sldStyle,
                            const QString &styleName, const QString &styleDescription,
                            const QString &uiFileContent, bool useAsDefault, QString &errCause );

    /**
     * Loads a layer style defined by \a uri
     * \since QGIS 3.10
     */
    virtual QString loadStyle( const QString &uri, QString &errCause );

    /**
     * Creates database by the provider on the path
     * \since QGIS 3.10
     */
    virtual bool createDb( const QString &dbPath, QString &errCause );

    /**
     * Returns new instance of transaction. Ownership is transferred to the caller
     * \since QGIS 3.10
     */
    virtual QgsTransaction *createTransaction( const QString &connString ) SIP_FACTORY;

    /**
     * Returns a dictionary of stored provider connections,
     * the dictionary key is the connection identifier.
     * Ownership is not transferred.
     * Raises a QgsProviderConnectionException if any errors are encountered.
     * \param cached if FALSE connections will be re-read from the settings
     * \throws QgsProviderConnectionException
     * \since QGIS 3.10
     */
    virtual QMap<QString, QgsAbstractProviderConnection *> connections( bool cached = true ) SIP_THROW( QgsProviderConnectionException );

    /**
     * Returns a dictionary of database provider connections,
     * the dictionary key is the connection identifier.
     * Ownership is not transferred.
     * Raises a QgsProviderConnectionException if any errors are encountered.
     * \param cached if FALSE connections will be re-read from the settings
     * \throws QgsProviderConnectionException
     * \since QGIS 3.10
     */
    QMap<QString, QgsAbstractDatabaseProviderConnection *> dbConnections( bool cached = true ) SIP_THROW( QgsProviderConnectionException );

    /**
     * Searches and returns a (possibly NULL) connection from the stored provider connections.
     * Ownership is not transferred.
     * Raises a QgsProviderConnectionException if any errors are encountered.
     * \param name the connection name
     * \param cached if FALSE connections will be re-read from the settings
     * \throws QgsProviderConnectionException
     * \since QGIS 3.10
     */
    QgsAbstractProviderConnection *findConnection( const QString &name, bool cached = true ) SIP_THROW( QgsProviderConnectionException );

#ifndef SIP_RUN

    /**
     * Returns a dictionary of provider connections of the specified type T,
     * the dictionary key is the connection identifier.
     * \param cached if FALSE connections will be re-read from the settings
     * \note not available in Python bindings
     * \since QGIS 3.10
     */
    template <typename T> QMap<QString, T *>connections( bool cached = true );


#endif

    /**
     * Creates a new connection from \a uri and \a configuration,
     * the newly created connection is not automatically stored in the settings, call
     * saveConnection() to save it.
     * Ownership is transferred to the caller.
     * \throws QgsProviderConnectionException
     * \see saveConnection()
     * \since QGIS 3.10
     */
    virtual QgsAbstractProviderConnection *createConnection( const QString &uri, const QVariantMap &configuration ) SIP_THROW( QgsProviderConnectionException ) SIP_FACTORY;

    /**
     * Creates a new connection by loading the connection with the given \a name from the settings.
     * Ownership is transferred to the caller.
     * \throws QgsProviderConnectionException
     * \see findConnection()
     */
    virtual QgsAbstractProviderConnection *createConnection( const QString &name ) SIP_THROW( QgsProviderConnectionException ) SIP_FACTORY;

    /**
     * Removes the connection with the given \a name from the settings.
     * Raises a QgsProviderConnectionException if any errors are encountered.
     * \throws QgsProviderConnectionException
     * \since QGIS 3.10
     */
    virtual void deleteConnection( const QString &name ) SIP_THROW( QgsProviderConnectionException );

    /**
     * Stores the connection in the settings
     * \param connection the connection to be stored in the settings
     * \param name the name under which the connection will be stored
     * \throws QgsProviderConnectionException
     * \since QGIS 3.10
     */
    virtual void saveConnection( const QgsAbstractProviderConnection *connection, const QString &name ) SIP_THROW( QgsProviderConnectionException );

  signals:

    /**
     * Emitted when a connection with the specified \a name is created.
     *
     * \note Only providers which implement the connection handling API will emit this signal.
     * \since QGIS 3.14
     */
    void connectionCreated( const QString &name );

    /**
     * Emitted when the connection with the specified \a name was deleted.
     *
     * \note Only providers which implement the connection handling API will emit this signal.
     * \since QGIS 3.14
     */
    void connectionDeleted( const QString &name );

    /**
     * Emitted when the connection with the specified \a name is changed, e.g. the settings
     * relating to the connection have been updated.
     *
     * \note Only providers which implement the connection handling API will emit this signal.
     * \since QGIS 3.14
     */
    void connectionChanged( const QString &name );

  protected:

#ifndef SIP_RUN
///@cond PRIVATE

    // Common functionality for connections management, to be moved into the class
    // when all the providers are ready
    // T_provider_conn: subclass of QgsAbstractProviderConnection,
    // T_conn: provider connection class (such as QgsOgrDbConnection or QgsPostgresConn)
    // TODO QGIS4: remove all old provider conn classes and move functionality into QgsAbstractProviderConnection subclasses
    template <class T_provider_conn, class T_conn> QMap<QString, QgsAbstractProviderConnection *> connectionsProtected( bool cached = true )
    {
      if ( ! cached || mProviderConnections.isEmpty() )
      {
        qDeleteAll( mProviderConnections );
        mProviderConnections.clear();
        const auto connNames { T_conn::connectionList() };
        for ( const auto &cname : connNames )
        {
          mProviderConnections.insert( cname, new T_provider_conn( cname ) );
        }
      }
      return mProviderConnections;
    }

    template <class T_provider_conn> void deleteConnectionProtected( const QString &name )
    {
      T_provider_conn conn( name );
      conn.remove( name );
      mProviderConnections.clear();
      emit connectionDeleted( name );
    }
    virtual void saveConnectionProtected( const QgsAbstractProviderConnection *connection, const QString &name );
    //! Provider connections cache
    QMap<QString, QgsAbstractProviderConnection *> mProviderConnections;

/// @endcond
#endif

  private:

    /// unique key for data provider
    QString mKey;

    /// associated terse description
    QString mDescription;

    /// file path
    /// deprecated QGIS 3.10
    QString mLibrary;

    CreateDataProviderFunction mCreateFunction = nullptr;

};

#endif //QGSPROVIDERMETADATA_H
