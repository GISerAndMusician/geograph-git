/***************************************************************************
  qgsellipsoidutils.h
 --------------------
  Date                 : April 2017
  Copyright            : (C) 2017 by Nyall Dawson
  email                : nyall dot dawson at gmail dot com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSELLIPSOIDUTILS_H
#define QGSELLIPSOIDUTILS_H

#include "qgis_core.h"
#include "qgis_sip.h"
#include "qgscoordinatereferencesystem.h"
#include <QStringList>

/**
 * \class QgsEllipsoidUtils
 * \ingroup core
 * \brief Contains utility functions for working with ellipsoids and querying the ellipsoid database.
 *
 * \since QGIS 3.0
*/
class CORE_EXPORT QgsEllipsoidUtils
{
  public:

    /**
     * Contains parameters for an ellipsoid.
     * \since QGIS 3.0
     */
    struct EllipsoidParameters
    {
      //! Whether ellipsoid parameters are valid
      bool valid{ true };

      //! Semi-major axis
      double semiMajor{ -1.0 };
      //! Semi-minor axis
      double semiMinor{ -1.0 };

      //! Whether custom parameters alone should be used (semiMajor/semiMinor only)
      bool useCustomParameters{ false };

      //! Inverse flattening
      double inverseFlattening{ -1.0 };

      //! Associated coordinate reference system
      QgsCoordinateReferenceSystem crs;
    };

    /**
     * Contains definition of an ellipsoid.
     * \since QGIS 3.0
     */
    struct EllipsoidDefinition
    {
      //! authority:code for QGIS builds with proj version 6 or greater, or custom acronym for ellipsoid for earlier proj builds
      QString acronym;
      //! Description of ellipsoid
      QString description;
      //! Ellipsoid parameters
      QgsEllipsoidUtils::EllipsoidParameters parameters;
    };

    /**
     * Returns the parameters for the specified \a ellipsoid.
     * Results are cached to allow for fast retrieval of parameters.
     */
    static EllipsoidParameters ellipsoidParameters( const QString &ellipsoid );

    /**
     * Returns a list of the definitions for all known ellipsoids from the
     * internal ellipsoid database.
     * \see acronyms()
     */
    static QList< QgsEllipsoidUtils::EllipsoidDefinition > definitions();

    /**
     * Returns a list of all known ellipsoid acronyms from the internal
     * ellipsoid database.
     * \see definitions()
     */
    static QStringList acronyms();

#ifndef SIP_RUN

    /**
     * Clears the internal cache used.
     *
     * If \a disableCache is TRUE then the inbuilt cache will be completely disabled. This
     * argument is for internal use only.
     *
     * \since QGIS 3.10
     */
    static void invalidateCache( bool disableCache = false );
#endif
};

#endif // QGSELLIPSOIDUTILS_H

