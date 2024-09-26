/***************************************************************************
                         qgsprocessingmodelchildparametersource.h
                         ----------------------------------------
    begin                : June 2017
    copyright            : (C) 2017 by Nyall Dawson
    email                : nyall dot dawson at gmail dot com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSPROCESSINGMODELCHILDPARAMETERSOURCE_H
#define QGSPROCESSINGMODELCHILDPARAMETERSOURCE_H

#include "qgis_core.h"
#include "qgis.h"
#include "qgsprocessing.h"
class QgsProcessingParameterDefinition;
class QgsProcessingModelAlgorithm;

///@cond NOT_STABLE

/**
 * \brief Source for the value of a parameter for a child algorithm within a model.
 * \ingroup core
 * \since QGIS 3.0
 */
class CORE_EXPORT QgsProcessingModelChildParameterSource
{
  public:

    //! Possible parameter value sources
    enum Source
    {
      ModelParameter, //!< Parameter value is taken from a parent model parameter
      ChildOutput, //!< Parameter value is taken from an output generated by a child algorithm
      StaticValue, //!< Parameter value is a static value
      Expression, //!< Parameter value is taken from an expression, evaluated just before the algorithm runs
      ExpressionText, //!< Parameter value is taken from a text with expressions, evaluated just before the algorithm runs
      ModelOutput, //!< Parameter value is linked to an output parameter for the model
    };

    /**
     * Constructor for QgsProcessingModelChildParameterSource. It is recommended that the static methods
     * fromStaticValue(), fromModelParameter(), fromChildOutput() and fromExpression() are used instead.
     */
    QgsProcessingModelChildParameterSource() = default;

    bool operator==( const QgsProcessingModelChildParameterSource &other ) const;
    bool operator!=( const QgsProcessingModelChildParameterSource &other ) const
    {
      return !operator==( other );
    }

    /**
     * Returns a new QgsProcessingModelChildParameterSource which takes its value from a static \a value.
     * \see fromModelParameter()
     * \see fromChildOutput()
     * \see fromExpression()
     * \see fromExpressionText()
     */
    static QgsProcessingModelChildParameterSource fromStaticValue( const QVariant &value );

    /**
     * Returns a new QgsProcessingModelChildParameterSource which takes its value from a parent model parameter.
     * \see fromStaticValue()
     * \see fromChildOutput()
     * \see fromExpression()
     * \see fromExpressionText()
     */
    static QgsProcessingModelChildParameterSource fromModelParameter( const QString &parameterName );

    /**
     * Returns a new QgsProcessingModelChildParameterSource which takes its value from an output generated by a child algorithm.
     * \see fromStaticValue()
     * \see fromModelParameter()
     * \see fromExpression()
     * \see fromExpressionText()
     */
    static QgsProcessingModelChildParameterSource fromChildOutput( const QString &childId, const QString &outputName );

    /**
     * Returns a new QgsProcessingModelChildParameterSource which takes its value from an expression. The expression
     * is evaluated just before the child algorithm executes, and can use functions available
     * in its expression context to include results calculated from the child algorithms already
     * executed by the model.
     * \see fromStaticValue()
     * \see fromChildOutput()
     * \see fromModelParameter()
     * \see fromExpressionText()
     * \since QGIS 3.2
     */
    static QgsProcessingModelChildParameterSource fromExpression( const QString &expression );

    /**
     * Returns a new QgsProcessingModelChildParameterSource which takes its
     * value from a text with expressions. Expressions are evaluated just before
     * the child algorithm executes, and can use functions available
     * in its expression context to include results calculated from the child
     * algorithms already executed by the model.
     * \see fromStaticValue()
     * \see fromChildOutput()
     * \see fromModelParameter()
     * \see fromExpression()
     * \since QGIS 3.2
     */
    static QgsProcessingModelChildParameterSource fromExpressionText( const QString &text );

    /**
     * Returns the parameter value's source.
     */
    Source source() const;

    /**
     * Sets the parameter's source.
     *
     * \since QGIS 3.14
     */
    void setSource( Source source );

    /**
     * Returns the source's static value. This is only used when the source() is StaticValue.
     * \see setStaticValue()
     */
    QVariant staticValue() const { return mStaticValue; }

    /**
     * Sets the source's static value. Calling this will also change the source() to StaticValue.
     * \see staticValue()
     */
    void setStaticValue( const QVariant &value ) { mStaticValue = value; mSource = StaticValue; }

    /**
     * Returns the source's model parameter name. This is only used when the source() is ModelParameter.
     * \see setParameterName()
     */
    QString parameterName() const { return mParameterName; }

    /**
     * Sets the source's model parameter \a name. Calling this will also change the source() to ModelParameter.
     * \see parameterName()
     */
    void setParameterName( const QString &name ) { mParameterName = name; mSource = ModelParameter; }

    /**
     * Returns the source's child algorithm ID from which the output value will be taken. This is only used when the source() is ChildOutput.
     * \see setOutputChildId()
     * \see outputName()
     */
    QString outputChildId() const { return mChildId; }

    /**
     * Sets the source's child algorithm \a id from which the output value will be taken. Calling this will also change the source() to ChildOutput.
     * \see parameterName()
     * \see setOutputName()
     */
    void setOutputChildId( const QString &id ) { mChildId = id; mSource = ChildOutput; }

    /**
     * Returns the source's child algorithm output name from which the output value will be taken. This is only used when the source() is ChildOutput.
     * \see setOutputName()
     * \see outputChildId()
     */
    QString outputName() const { return mOutputName; }

    /**
     * Sets the source's child algorithm output \a name from which the output value will be taken. Calling this will also change the source() to ChildOutput.
     * \see outputName()
     * \see setOutputChildId()
     */
    void setOutputName( const QString &name ) { mOutputName = name; mSource = ChildOutput; }

    /**
     * Returns the source's expression. This is only used when the source() is Expression.
     * \see setExpression()
     */
    QString expression() const { return mExpression; }

    /**
     * Sets the source's expression. Calling this will also change the source() to Expression.
     * The expression is evaluated just before the child algorithm executes, and can use functions available
     * in its expression context to include results calculated from the child algorithms already
     * executed by the model.
     * \see expression()
     */
    void setExpression( const QString &expression ) { mExpression = expression; mSource = Expression; }

    /**
     * Returns the source's text with expressions. This is only used when the
     * source() is ExpressionText.
     * \see setExpressionText()
     * \since QGIS 3.2
     */
    QString expressionText() const { return mExpressionText; }

    /**
     * Sets the source's text containing expressions. Calling this will also
     * change the source() to ExpressionText. Expressions are evaluated just
     * before the child algorithm executes, and can use functions available
     * in its expression context to include results calculated from the child
     * algorithms already executed by the model.
     * \see expressionText()
     * \since QGIS 3.2
     */
    void setExpressionText( const QString &text ) { mExpressionText = text; mSource = ExpressionText; }

    /**
     * Saves this source to a QVariant.
     * \see loadVariant()
     */
    QVariant toVariant() const;

    /**
     * Loads this source from a QVariantMap.
     * \see toVariant()
     */
    bool loadVariant( const QVariantMap &map );

    /**
     * Attempts to convert the source to executable Python code.
     *
     * The \a friendlyChildNames argument gives a map of child id to a friendly algorithm name, to be used in the code to identify that algorithm instead of the raw child id.
     */
    QString asPythonCode( QgsProcessing::PythonOutputType outputType, const QgsProcessingParameterDefinition *definition, const QMap< QString, QString > &friendlydChildNames ) const;

    /**
     * Returns a user-friendly identifier for this source, given the context of the specified \a model.
     * \since QGIS 3.14
     */
    QString friendlyIdentifier( QgsProcessingModelAlgorithm *model ) const;

  private:

    Source mSource = StaticValue;
    QVariant mStaticValue;
    QString mParameterName;
    QString mChildId;
    QString mOutputName;
    QString mExpression;
    QString mExpressionText;

};

Q_DECLARE_METATYPE( QgsProcessingModelChildParameterSource );
CORE_EXPORT QDataStream &operator<<( QDataStream &out, const QgsProcessingModelChildParameterSource &source );
CORE_EXPORT QDataStream &operator>>( QDataStream &in, QgsProcessingModelChildParameterSource &source );

#ifndef SIP_RUN
//! List of child parameter sources
typedef QList< QgsProcessingModelChildParameterSource > QgsProcessingModelChildParameterSources;
#endif

///@endcond

#endif // QGSPROCESSINGMODELCHILDPARAMETERSOURCE_H
