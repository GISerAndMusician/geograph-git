/***************************************************************************
    qgsexternalresourcewidgetwrapper.h
     --------------------------------------
 begin                : 16.12.2015
 copyright            : (C) 2015 by Denis Rouzaud
 email                : denis.rouzaud@gmail.com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSEXTERNALRESOURCEWIDGETWRAPPER_H
#define QGSEXTERNALRESOURCEWIDGETWRAPPER_H

class QgsExternalResourceWidget;

class QLabel;
class QLineEdit;

#include "qgseditorwidgetwrapper.h"
#include "qgis_gui.h"
#include "qgsattributeform.h"

SIP_NO_FILE



/**
 * \ingroup gui
 * \brief Wraps a file name widget. Will offer a file browser to choose files.
 * \note not available in Python bindings
 */

/**
 * \brief The QgsExternalResourceWidgetWrapper class wraps a external resource widget
 */
class GUI_EXPORT QgsExternalResourceWidgetWrapper : public QgsEditorWidgetWrapper
{
    Q_OBJECT
  public:

    /**
     * Constructor for QgsExternalResourceWidgetWrapper.
     *
     * The \a layer and \a fieldIdx arguments specify the vector layer field associated with the wrapper.
     *
     * The \a editor argument indicates the editor widget to use with the wrapper. This can be NULLPTR if a
     * new widget should be autogenerated.
     *
     * A \a parent widget for this widget wrapper and the created widget can also be specified.
     */
    explicit QgsExternalResourceWidgetWrapper( QgsVectorLayer *layer, int fieldIdx, QWidget *editor = nullptr, QWidget *parent = nullptr );

    // QgsEditorWidgetWrapper interface
  public:
    QVariant value() const override;
    void showIndeterminateState() override;

  protected:
    QWidget *createWidget( QWidget *parent ) override;
    void initWidget( QWidget *editor ) override;
    bool valid() const override;

  public slots:
    void setFeature( const QgsFeature &feature ) override;
    void setEnabled( bool enabled ) override;

    /**
     * Will be called when a value in the current edited form or table row
     * changes
     *
     * \param attribute         The name of the attribute that changed.
     * \param newValue          The new value of the attribute.
     * \param attributeChanged  If TRUE, it corresponds to an actual change of the feature attribute
     * \since QGIS 3.16
     */
    void widgetValueChanged( const QString &attribute, const QVariant &newValue, bool attributeChanged );


  private:
    void updateValues( const QVariant &value, const QVariantList & = QVariantList() ) override;
    void updateConstraintWidgetStatus() override;
    void updateProperties( const QgsFeature &feature );

    QLineEdit *mLineEdit = nullptr;
    QLabel *mLabel = nullptr;
    QgsAttributeForm *mForm = nullptr;
    QgsExternalResourceWidget *mQgsWidget = nullptr;

    friend class TestQgsExternalResourceWidgetWrapper;

};

#endif // QGSEXTERNALRESOURCEWIDGETWRAPPER_H
