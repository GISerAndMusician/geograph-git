#include "GgsGraphStatisticDialog.h"
#include <QGroupBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QPalette>
#include "GgsGraphProxy.h"
#include "GgsGraphStatistic.h"

#pragma execution_character_set("utf-8") 

GgsGraphStatisticDialog::GgsGraphStatisticDialog(QList<GgsGraphProxy*> graphs, QWidget* parent /*= nullptr*/)
	: QDialog(parent)
{
	setupUi(this);
	mGraphs = graphs;
	
	initStyleUi();

	connect(this->okButton, &QPushButton::clicked, this, &GgsGraphStatisticDialog::onOK);
}

void GgsGraphStatisticDialog::onColor()
{
	QObject* sdr =  sender();
	int index = sdr->property("index").toInt();
	
	QColor color;
	color = mColorDialog[index]->getColor();
	if (color.isValid())
	{
		QPalette palette;
		palette.setColor(QPalette::Button, color);
		mColorToolButtons[index]->setPalette(palette);
	}
}

void GgsGraphStatisticDialog::onOK()
{
	QStringList labelNames, pointSymbols, lineSymbols, colors, opacities;
	for (int i=0; i<mGraphs.size(); i++)
	{
		labelNames << mLabelNames[i]->text();
		pointSymbols << mPointSymbols[i]->currentText();
		lineSymbols << mLineSymbols[i]->currentText();
		colors << mColorToolButtons[i]->palette().button().color().name();
		opacities << QString::number(mOpacities[i]->value());
	}

	GgsGraphStatistic gs(mGraphs,
		labelNames,
		pointSymbols,
		lineSymbols,
		colors,
		opacities
	);

	gs.statistic(this->checkBox_coverData->isChecked());
}

void GgsGraphStatisticDialog::initStyleUi()
{
	for (int i=0; i<mGraphs.size(); i++)
	{
		QGridLayout* gridLayout_style;
		QLabel *label_labelName;
		QLineEdit *lineEdit_labelName;
		QLabel *label_color;
		QToolButton *toolButton_color;
		QLabel *label_opacity;
		QSpinBox *spinBox_opacity;
		QGroupBox *groupBox_graphName;
		QFormLayout *formLayout_graphLayer;

		groupBox_graphName = new QGroupBox(groupBox_style);
		groupBox_graphName->setObjectName(QString::fromUtf8("groupBox_graphName"));
		QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
		sizePolicy.setHorizontalStretch(0);
		sizePolicy.setVerticalStretch(0);
		sizePolicy.setHeightForWidth(groupBox_graphName->sizePolicy().hasHeightForWidth());
		groupBox_graphName->setSizePolicy(sizePolicy);
		formLayout_graphLayer = new QFormLayout(groupBox_graphName);
		formLayout_graphLayer->setObjectName(QString::fromUtf8("formLayout_graphLayer"));
		gridLayout_style = new QGridLayout();
		gridLayout_style->setObjectName(QString::fromUtf8("gridLayout_style"));
		
		label_labelName = new QLabel(groupBox_graphName);
		label_labelName->setObjectName(QString::fromUtf8("label_labelName"));

		gridLayout_style->addWidget(label_labelName, 0, 0, 1, 1);

		lineEdit_labelName = new QLineEdit(groupBox_graphName);
		lineEdit_labelName->setObjectName(QString::fromUtf8("lineEdit_labelName"));
		lineEdit_labelName->setText(mGraphs[i]->getName());
		
		mLabelNames.append(lineEdit_labelName);

		gridLayout_style->addWidget(lineEdit_labelName, 0, 1, 1, 1);

		// 符号布局
		QHBoxLayout* horizontalLayout_pointSymbol = new QHBoxLayout();

		QLabel *label_pointSymbol;
		label_pointSymbol = new QLabel(groupBox_graphName);
		label_pointSymbol->setObjectName(QString::fromUtf8("label_pointSymbol"));
		label_pointSymbol->setText(tr("点符号："));
		horizontalLayout_pointSymbol->addWidget(label_pointSymbol);

		QComboBox *comboBox_pointSymbol;
		comboBox_pointSymbol = new QComboBox(groupBox_graphName);
		comboBox_pointSymbol->setObjectName(QString::fromUtf8("comboBox_pointSymbol"));
		comboBox_pointSymbol->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed));
		comboBox_pointSymbol->insertItems(0, QStringList()<<"."<<","<<"o"<<"v"<<"^"<<"<"<<">"<<"P"<<"1"<<"2"<<"3"<<"4"<<"8"<< "None");
		horizontalLayout_pointSymbol->addWidget(comboBox_pointSymbol);

		mPointSymbols.append(comboBox_pointSymbol);

		QHBoxLayout* horizontalLayout_lineSymbol = new QHBoxLayout();
		QLabel *label_lineSymbol;
		label_lineSymbol = new QLabel(groupBox_graphName);
		label_lineSymbol->setObjectName(QString::fromUtf8("label_lineSymbol"));
		label_lineSymbol->setText(tr("线符号："));
		horizontalLayout_lineSymbol->addWidget(label_lineSymbol);

		QComboBox *comboBox_lineSymbol;
		comboBox_lineSymbol = new QComboBox(groupBox_graphName);
		comboBox_lineSymbol->setObjectName(QString::fromUtf8("comboBox_symbol"));
		comboBox_lineSymbol->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed));
		comboBox_lineSymbol->insertItems(0, QStringList() << "-" << ":" << "--" << "-." << "None");
		horizontalLayout_lineSymbol->addWidget(comboBox_lineSymbol);

		mLineSymbols.append(comboBox_lineSymbol);

		gridLayout_style->addLayout(horizontalLayout_pointSymbol, 0, 2, 1, 1);
		gridLayout_style->addLayout(horizontalLayout_lineSymbol, 0, 3, 1, 1);

		// *\符号布局
		label_color = new QLabel(groupBox_graphName);
		label_color->setObjectName(QString::fromUtf8("label_color"));

		gridLayout_style->addWidget(label_color, 1, 0, 1, 1);

		toolButton_color = new QToolButton(groupBox_graphName);
		toolButton_color->setObjectName(QString::fromUtf8("toolButton_color"));
		sizePolicy.setHeightForWidth(toolButton_color->sizePolicy().hasHeightForWidth());
		toolButton_color->setSizePolicy(sizePolicy);
		toolButton_color->setProperty("index", QVariant(i));
		QPalette palette;
		auto randomValue = []() -> int { return qrand() % 256; };
		palette.setColor(QPalette::Button, QColor(randomValue(), randomValue(), randomValue()));
		toolButton_color->setPalette(palette);
		mColorToolButtons.append(toolButton_color);
		QColorDialog* colorDailog = new QColorDialog(this);
		mColorDialog.append(colorDailog);
 		connect(toolButton_color, &QToolButton::clicked, this, &GgsGraphStatisticDialog::onColor);

		gridLayout_style->addWidget(toolButton_color, 1, 1, 1, 1);

		QHBoxLayout* horizontalLayout_opacity = new QHBoxLayout();

		label_opacity = new QLabel(groupBox_graphName);
		label_opacity->setObjectName(QString::fromUtf8("label_opacity"));

		horizontalLayout_opacity->addWidget(label_opacity);

		spinBox_opacity = new QSpinBox(groupBox_graphName);
		spinBox_opacity->setObjectName(QString::fromUtf8("spinBox_opacity"));
		sizePolicy.setHeightForWidth(spinBox_opacity->sizePolicy().hasHeightForWidth());
		spinBox_opacity->setSizePolicy(sizePolicy);
		spinBox_opacity->setRange(0, 100);
		spinBox_opacity->setValue(100);
		spinBox_opacity->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed));

		mOpacities.append(spinBox_opacity);

		horizontalLayout_opacity->addWidget(spinBox_opacity);

		gridLayout_style->addLayout(horizontalLayout_opacity, 1, 2, 1, 1);


		formLayout_graphLayer->setLayout(0, QFormLayout::FieldRole, gridLayout_style);

		groupBox_graphName->setTitle(mGraphs[i]->getName());
		
		label_labelName->setText("标签名称：");
		label_color->setText(tr("颜色："));
		label_opacity->setText(tr("透明度(%)："));

		formLayout_style->setWidget(i, QFormLayout::SpanningRole, groupBox_graphName);
	}
}
