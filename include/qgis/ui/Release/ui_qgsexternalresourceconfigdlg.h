/********************************************************************************
** Form generated from reading UI file 'qgsexternalresourceconfigdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSEXTERNALRESOURCECONFIGDLG_H
#define UI_QGSEXTERNALRESOURCECONFIGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgspropertyoverridebutton.h"
#include "qgsscrollarea.h"
#include "qgsspinbox.h"

QT_BEGIN_NAMESPACE

class Ui_QgsExternalResourceConfigDlg
{
public:
    QVBoxLayout *verticalLayout_2;
    QgsScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *mRootPath;
    QLineEdit *mRootPathExpression;
    QToolButton *mRootPathButton;
    QgsPropertyOverrideButton *mRootPathPropertyOverrideButton;
    QGroupBox *mRelativeGroupBox;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *mRelativeProject;
    QRadioButton *mRelativeDefault;
    QGroupBox *mStorageGroupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *mStoreFilesButton;
    QRadioButton *mStoreDirsButton;
    QGroupBox *mFileWidgetGroupBox;
    QGridLayout *gridLayout_3;
    QGroupBox *mUseLink;
    QFormLayout *formLayout;
    QCheckBox *mFullUrl;
    QGroupBox *mFileWidgetButtonGroupBox;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLineEdit *mFileWidgetFilterLineEdit;
    QGroupBox *mDocumentViewerGroupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QComboBox *mDocumentViewerContentComboBox;
    QSpacerItem *horizontalSpacer;
    QWidget *mDocumentViewerContentSettingsWidget;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QLabel *label_12;
    QgsSpinBox *mDocumentViewerHeight;
    QgsSpinBox *mDocumentViewerWidth;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_2;
    QgsPropertyOverrideButton *mDocumentViewerContentPropertyOverrideButton;
    QLineEdit *mDocumentViewerContentExpression;
    QSpacerItem *verticalSpacer;
    QButtonGroup *mRelativeButtonGroup;
    QButtonGroup *mStorageButtonGroup;

    void setupUi(QWidget *QgsExternalResourceConfigDlg)
    {
        if (QgsExternalResourceConfigDlg->objectName().isEmpty())
            QgsExternalResourceConfigDlg->setObjectName(QString::fromUtf8("QgsExternalResourceConfigDlg"));
        QgsExternalResourceConfigDlg->resize(481, 690);
        QgsExternalResourceConfigDlg->setWindowTitle(QString::fromUtf8("Form"));
        verticalLayout_2 = new QVBoxLayout(QgsExternalResourceConfigDlg);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QgsScrollArea(QgsExternalResourceConfigDlg);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 467, 715));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        mRootPath = new QLineEdit(groupBox);
        mRootPath->setObjectName(QString::fromUtf8("mRootPath"));
        mRootPath->setEnabled(true);
        mRootPath->setAutoFillBackground(false);

        horizontalLayout->addWidget(mRootPath);

        mRootPathExpression = new QLineEdit(groupBox);
        mRootPathExpression->setObjectName(QString::fromUtf8("mRootPathExpression"));
        mRootPathExpression->setEnabled(true);
        mRootPathExpression->setReadOnly(true);

        horizontalLayout->addWidget(mRootPathExpression);

        mRootPathButton = new QToolButton(groupBox);
        mRootPathButton->setObjectName(QString::fromUtf8("mRootPathButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mRootPathButton->sizePolicy().hasHeightForWidth());
        mRootPathButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(mRootPathButton);

        mRootPathPropertyOverrideButton = new QgsPropertyOverrideButton(groupBox);
        mRootPathPropertyOverrideButton->setObjectName(QString::fromUtf8("mRootPathPropertyOverrideButton"));

        horizontalLayout->addWidget(mRootPathPropertyOverrideButton);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        mRelativeGroupBox = new QGroupBox(groupBox);
        mRelativeGroupBox->setObjectName(QString::fromUtf8("mRelativeGroupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mRelativeGroupBox->sizePolicy().hasHeightForWidth());
        mRelativeGroupBox->setSizePolicy(sizePolicy1);
        mRelativeGroupBox->setFlat(false);
        mRelativeGroupBox->setCheckable(true);
        mRelativeGroupBox->setChecked(false);
        verticalLayout_3 = new QVBoxLayout(mRelativeGroupBox);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        mRelativeProject = new QRadioButton(mRelativeGroupBox);
        mRelativeButtonGroup = new QButtonGroup(QgsExternalResourceConfigDlg);
        mRelativeButtonGroup->setObjectName(QString::fromUtf8("mRelativeButtonGroup"));
        mRelativeButtonGroup->addButton(mRelativeProject);
        mRelativeProject->setObjectName(QString::fromUtf8("mRelativeProject"));
        mRelativeProject->setChecked(true);

        verticalLayout_3->addWidget(mRelativeProject);

        mRelativeDefault = new QRadioButton(mRelativeGroupBox);
        mRelativeButtonGroup->addButton(mRelativeDefault);
        mRelativeDefault->setObjectName(QString::fromUtf8("mRelativeDefault"));
        mRelativeDefault->setEnabled(false);

        verticalLayout_3->addWidget(mRelativeDefault);


        gridLayout_2->addWidget(mRelativeGroupBox, 1, 0, 1, 1);


        verticalLayout_4->addWidget(groupBox);

        mStorageGroupBox = new QGroupBox(scrollAreaWidgetContents);
        mStorageGroupBox->setObjectName(QString::fromUtf8("mStorageGroupBox"));
        sizePolicy1.setHeightForWidth(mStorageGroupBox->sizePolicy().hasHeightForWidth());
        mStorageGroupBox->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(mStorageGroupBox);
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mStoreFilesButton = new QRadioButton(mStorageGroupBox);
        mStorageButtonGroup = new QButtonGroup(QgsExternalResourceConfigDlg);
        mStorageButtonGroup->setObjectName(QString::fromUtf8("mStorageButtonGroup"));
        mStorageButtonGroup->addButton(mStoreFilesButton);
        mStoreFilesButton->setObjectName(QString::fromUtf8("mStoreFilesButton"));
        mStoreFilesButton->setChecked(true);

        verticalLayout->addWidget(mStoreFilesButton);

        mStoreDirsButton = new QRadioButton(mStorageGroupBox);
        mStorageButtonGroup->addButton(mStoreDirsButton);
        mStoreDirsButton->setObjectName(QString::fromUtf8("mStoreDirsButton"));

        verticalLayout->addWidget(mStoreDirsButton);


        verticalLayout_4->addWidget(mStorageGroupBox);

        mFileWidgetGroupBox = new QGroupBox(scrollAreaWidgetContents);
        mFileWidgetGroupBox->setObjectName(QString::fromUtf8("mFileWidgetGroupBox"));
        mFileWidgetGroupBox->setCheckable(true);
        gridLayout_3 = new QGridLayout(mFileWidgetGroupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        mUseLink = new QGroupBox(mFileWidgetGroupBox);
        mUseLink->setObjectName(QString::fromUtf8("mUseLink"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mUseLink->sizePolicy().hasHeightForWidth());
        mUseLink->setSizePolicy(sizePolicy2);
        mUseLink->setCheckable(true);
        mUseLink->setChecked(false);
        formLayout = new QFormLayout(mUseLink);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        mFullUrl = new QCheckBox(mUseLink);
        mFullUrl->setObjectName(QString::fromUtf8("mFullUrl"));

        formLayout->setWidget(0, QFormLayout::LabelRole, mFullUrl);


        gridLayout_3->addWidget(mUseLink, 1, 0, 1, 1);

        mFileWidgetButtonGroupBox = new QGroupBox(mFileWidgetGroupBox);
        mFileWidgetButtonGroupBox->setObjectName(QString::fromUtf8("mFileWidgetButtonGroupBox"));
        mFileWidgetButtonGroupBox->setCheckable(true);
        formLayout_2 = new QFormLayout(mFileWidgetButtonGroupBox);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_4 = new QLabel(mFileWidgetButtonGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        mFileWidgetFilterLineEdit = new QLineEdit(mFileWidgetButtonGroupBox);
        mFileWidgetFilterLineEdit->setObjectName(QString::fromUtf8("mFileWidgetFilterLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, mFileWidgetFilterLineEdit);


        gridLayout_3->addWidget(mFileWidgetButtonGroupBox, 0, 0, 1, 1);


        verticalLayout_4->addWidget(mFileWidgetGroupBox);

        mDocumentViewerGroupBox = new QGroupBox(scrollAreaWidgetContents);
        mDocumentViewerGroupBox->setObjectName(QString::fromUtf8("mDocumentViewerGroupBox"));
        mDocumentViewerGroupBox->setCheckable(false);
        gridLayout = new QGridLayout(mDocumentViewerGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(mDocumentViewerGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        mDocumentViewerContentComboBox = new QComboBox(mDocumentViewerGroupBox);
        mDocumentViewerContentComboBox->setObjectName(QString::fromUtf8("mDocumentViewerContentComboBox"));

        gridLayout->addWidget(mDocumentViewerContentComboBox, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 5, 1, 1);

        mDocumentViewerContentSettingsWidget = new QWidget(mDocumentViewerGroupBox);
        mDocumentViewerContentSettingsWidget->setObjectName(QString::fromUtf8("mDocumentViewerContentSettingsWidget"));
        gridLayout_4 = new QGridLayout(mDocumentViewerContentSettingsWidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(mDocumentViewerContentSettingsWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setWordWrap(true);

        gridLayout_4->addWidget(label_2, 0, 2, 2, 1);

        label_12 = new QLabel(mDocumentViewerContentSettingsWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 0, 0, 1, 1);

        mDocumentViewerHeight = new QgsSpinBox(mDocumentViewerContentSettingsWidget);
        mDocumentViewerHeight->setObjectName(QString::fromUtf8("mDocumentViewerHeight"));
        mDocumentViewerHeight->setMaximum(10000);

        gridLayout_4->addWidget(mDocumentViewerHeight, 1, 1, 1, 1);

        mDocumentViewerWidth = new QgsSpinBox(mDocumentViewerContentSettingsWidget);
        mDocumentViewerWidth->setObjectName(QString::fromUtf8("mDocumentViewerWidth"));
        mDocumentViewerWidth->setMaximum(10000);

        gridLayout_4->addWidget(mDocumentViewerWidth, 0, 1, 1, 1);

        label_13 = new QLabel(mDocumentViewerContentSettingsWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_4->addWidget(label_13, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 3, 1, 1);


        gridLayout->addWidget(mDocumentViewerContentSettingsWidget, 1, 1, 1, 5);

        mDocumentViewerContentPropertyOverrideButton = new QgsPropertyOverrideButton(mDocumentViewerGroupBox);
        mDocumentViewerContentPropertyOverrideButton->setObjectName(QString::fromUtf8("mDocumentViewerContentPropertyOverrideButton"));

        gridLayout->addWidget(mDocumentViewerContentPropertyOverrideButton, 0, 4, 1, 1);

        mDocumentViewerContentExpression = new QLineEdit(mDocumentViewerGroupBox);
        mDocumentViewerContentExpression->setObjectName(QString::fromUtf8("mDocumentViewerContentExpression"));
        mDocumentViewerContentExpression->setEnabled(true);
        mDocumentViewerContentExpression->setReadOnly(true);

        gridLayout->addWidget(mDocumentViewerContentExpression, 0, 3, 1, 1);


        verticalLayout_4->addWidget(mDocumentViewerGroupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        QWidget::setTabOrder(scrollArea, mRootPath);
        QWidget::setTabOrder(mRootPath, mRelativeGroupBox);
        QWidget::setTabOrder(mRelativeGroupBox, mRelativeProject);
        QWidget::setTabOrder(mRelativeProject, mRelativeDefault);
        QWidget::setTabOrder(mRelativeDefault, mStoreFilesButton);
        QWidget::setTabOrder(mStoreFilesButton, mStoreDirsButton);
        QWidget::setTabOrder(mStoreDirsButton, mFileWidgetGroupBox);
        QWidget::setTabOrder(mFileWidgetGroupBox, mFileWidgetButtonGroupBox);
        QWidget::setTabOrder(mFileWidgetButtonGroupBox, mFileWidgetFilterLineEdit);
        QWidget::setTabOrder(mFileWidgetFilterLineEdit, mUseLink);
        QWidget::setTabOrder(mUseLink, mFullUrl);
        QWidget::setTabOrder(mFullUrl, mDocumentViewerGroupBox);
        QWidget::setTabOrder(mDocumentViewerGroupBox, mDocumentViewerContentComboBox);

        retranslateUi(QgsExternalResourceConfigDlg);

        QMetaObject::connectSlotsByName(QgsExternalResourceConfigDlg);
    } // setupUi

    void retranslateUi(QWidget *QgsExternalResourceConfigDlg)
    {
        groupBox->setTitle(QApplication::translate("QgsExternalResourceConfigDlg", "Path", nullptr));
        label->setText(QApplication::translate("QgsExternalResourceConfigDlg", "Default path", nullptr));
#ifndef QT_NO_TOOLTIP
        mRootPath->setToolTip(QApplication::translate("QgsExternalResourceConfigDlg", "<html><head/><body><p>When not empty, always open the file selector at the root of this path for searching new files. If empty, the last used path of this editor widget will be used. If this editor widget has never been used by the user, the project path will be used.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        mRootPath->setPlaceholderText(QString());
        mRootPathButton->setText(QApplication::translate("QgsExternalResourceConfigDlg", "\342\200\246", nullptr));
        mRootPathPropertyOverrideButton->setText(QApplication::translate("QgsExternalResourceConfigDlg", "\342\200\246", nullptr));
#ifndef QT_NO_TOOLTIP
        mRelativeGroupBox->setToolTip(QApplication::translate("QgsExternalResourceConfigDlg", "<html><head/><body><p>If you want to make the attribute to store only relative paths, toggle one of these options.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        mRelativeGroupBox->setTitle(QApplication::translate("QgsExternalResourceConfigDlg", "Relative paths", nullptr));
#ifndef QT_NO_TOOLTIP
        mRelativeProject->setToolTip(QApplication::translate("QgsExternalResourceConfigDlg", "<html><head/><body><p>If possible, this option makes the storage of the filenames with relative paths from the current QGIS project path.</p><p>For example, if your QGIS project is in <span style=\" font-style:italic;\">&quot;/home/user/my_project.qgs&quot;</span> and your filename is <span style=\" font-style:italic;\">&quot;/home/user/data/files/test.pdf&quot;</span>, the attribute will only store <span style=\" font-style:italic;\">&quot;data/files/test.pdf&quot;</span>.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        mRelativeProject->setText(QApplication::translate("QgsExternalResourceConfigDlg", "Relative to project path", nullptr));
#ifndef QT_NO_TOOLTIP
        mRelativeDefault->setToolTip(QApplication::translate("QgsExternalResourceConfigDlg", "<html><head/><body><p>If possible, this option makes the storage of the filenames with relative paths from the default path set just above.</p><p>For example, if your default path is <span style=\" font-style:italic;\">&quot;/home/user/data/&quot;</span> and your filename is <span style=\" font-style:italic;\">&quot;/home/user/data/files/test.pdf&quot;</span>, the attribute will only store <span style=\" font-style:italic;\">&quot;files/test.pdf&quot;</span>.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        mRelativeDefault->setText(QApplication::translate("QgsExternalResourceConfigDlg", "Relative to default path", nullptr));
#ifndef QT_NO_TOOLTIP
        mStorageGroupBox->setToolTip(QApplication::translate("QgsExternalResourceConfigDlg", "<html><head/><body><p>Set exclusive file selection methods.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        mStorageGroupBox->setTitle(QApplication::translate("QgsExternalResourceConfigDlg", "Storage Mode", nullptr));
#ifndef QT_NO_TOOLTIP
        mStoreFilesButton->setToolTip(QApplication::translate("QgsExternalResourceConfigDlg", "<html><head/><body><p>If this option is checked, the attribute can only store filenames (this is the default choice).</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        mStoreFilesButton->setText(QApplication::translate("QgsExternalResourceConfigDlg", "File paths", nullptr));
#ifndef QT_NO_TOOLTIP
        mStoreDirsButton->setToolTip(QApplication::translate("QgsExternalResourceConfigDlg", "<html><head/><body><p>If this option is checked, the attribute can only store directories and not filenames. The file selector will let you choose only directories and not files.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        mStoreDirsButton->setText(QApplication::translate("QgsExternalResourceConfigDlg", "Directory paths", nullptr));
        mFileWidgetGroupBox->setTitle(QApplication::translate("QgsExternalResourceConfigDlg", "Display Resource Path", nullptr));
#ifndef QT_NO_TOOLTIP
        mUseLink->setToolTip(QApplication::translate("QgsExternalResourceConfigDlg", "<html><head/><body><p>This option displays file paths as clickable hyperlinks. When you click on the file path, the file should normally be opened by the default viewer defined in your operating system.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        mUseLink->setTitle(QApplication::translate("QgsExternalResourceConfigDlg", "Use a hyperlink for document path (read-only)", nullptr));
#ifndef QT_NO_TOOLTIP
        mFullUrl->setToolTip(QApplication::translate("QgsExternalResourceConfigDlg", "<html><head/><body><p>By default, the hyperlink is only displayed with the name of the file and not the full path. If you check this option, hyperlinks will be displayed with the complete path.</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        mFullUrl->setText(QApplication::translate("QgsExternalResourceConfigDlg", "Display the full path", nullptr));
        mFileWidgetButtonGroupBox->setTitle(QApplication::translate("QgsExternalResourceConfigDlg", "Display button to open file dialog", nullptr));
        label_4->setText(QApplication::translate("QgsExternalResourceConfigDlg", "Filter", nullptr));
#ifndef QT_NO_TOOLTIP
        mFileWidgetFilterLineEdit->setToolTip(QApplication::translate("QgsExternalResourceConfigDlg", "<html><head/><body><p>Filter syntax is borrowed from Qt <a href=\"http://doc.qt.io/qt-4.8/qfiledialog.html#getOpenFileName\"><span style=\" text-decoration: underline; color:#0000ff;\">QFileDialog::getOpenFileName</span></a><span style=\" font-family:'Courier New,courier';\">.</span></p><p>If you want simple filter on all pdf files, just use:</p><p><span style=\" font-family:'Courier New,courier';\">*.pdf</span></p><p>If you want one filter for multiple file extensions (on .pdf, .odt and .doc files):</p><p><span style=\" font-family:'Courier New,courier';\">*.pdf *.odt *.doc</span></p><p>If you want to describe your filter, use parentheses:</p><p><span style=\" font-family:'Courier New,courier';\">Text documents (*.pdf, *.odt, *.doc)</span></p><p>If you want multiple filters, separate them with ';;':</p><p><span style=\" font-family:'Courier New,courier';\">&quot;Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)&quot;</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        mFileWidgetFilterLineEdit->setPlaceholderText(QString());
        mDocumentViewerGroupBox->setTitle(QApplication::translate("QgsExternalResourceConfigDlg", "Integrated Document Viewer", nullptr));
        label_3->setText(QApplication::translate("QgsExternalResourceConfigDlg", "Type", nullptr));
        label_2->setText(QApplication::translate("QgsExternalResourceConfigDlg", "Specify the size of the preview. If you leave it set to Auto, an optimal size will be calculated.", nullptr));
        label_12->setText(QApplication::translate("QgsExternalResourceConfigDlg", "Width", nullptr));
        mDocumentViewerHeight->setSpecialValueText(QApplication::translate("QgsExternalResourceConfigDlg", "Auto", nullptr));
        mDocumentViewerHeight->setSuffix(QApplication::translate("QgsExternalResourceConfigDlg", " px", nullptr));
        mDocumentViewerHeight->setPrefix(QString());
        mDocumentViewerWidth->setSpecialValueText(QApplication::translate("QgsExternalResourceConfigDlg", "Auto", nullptr));
        mDocumentViewerWidth->setSuffix(QApplication::translate("QgsExternalResourceConfigDlg", " px", nullptr));
        label_13->setText(QApplication::translate("QgsExternalResourceConfigDlg", "Height", nullptr));
        mDocumentViewerContentPropertyOverrideButton->setText(QApplication::translate("QgsExternalResourceConfigDlg", "\342\200\246", nullptr));
        Q_UNUSED(QgsExternalResourceConfigDlg);
    } // retranslateUi

};

namespace Ui {
    class QgsExternalResourceConfigDlg: public Ui_QgsExternalResourceConfigDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSEXTERNALRESOURCECONFIGDLG_H
