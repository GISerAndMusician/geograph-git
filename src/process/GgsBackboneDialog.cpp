#include "GgsBackboneDialog.h"

#pragma execution_character_set("utf-8") 

GgsBackboneDialog::GgsBackboneDialog(GgsGraphProxy* graph, QWidget* parent /*= nullptr*/)
	: QDialog(parent),
	mBackboneAlgo(graph)
{
	setupUi(this);
	mGraph = graph;

	progressBar->setVisible(false);
	mBackboneAlgo.setProgressBar(this->progressBar);

	initCombBox();
	connect(this->okButton, &QPushButton::clicked, this, &GgsBackboneDialog::onOk);
}

GgsBackboneDialog::~GgsBackboneDialog()
{

}

void GgsBackboneDialog::onOk()
{
	mBackboneAlgo.create((GgsBackbone::Method)comboBox->currentData().toInt(), this->doubleSpinBox->value() / 100.00);

	this->accept();
}

void GgsBackboneDialog::initCombBox()
{
	this->comboBox->insertItem(0, tr("顾及空间分异和网络结构的提取方法（熵权法）"), QVariant(GgsBackbone::Method::Entropy));
	this->comboBox->insertItem(1, tr("依据节点度的大小进行提取（度值法）"), QVariant(GgsBackbone::Method::Degree));
	this->comboBox->insertItem(2, tr("依据节点介数中心性的大小进行提取（中心性法）"), QVariant(GgsBackbone::Method::BetweenessCentrality));
	this->comboBox->insertItem(3, tr("依据节点接近中心性的大小进行提取（中心性法）"), QVariant(GgsBackbone::Method::ClosenessCentrality));
	this->comboBox->insertItem(4, tr("依据节点特征向量中心性的大小进行提取（中心性法）"), QVariant(GgsBackbone::Method::EigenvectorCentrality));
}
