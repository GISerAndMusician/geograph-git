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
	this->comboBox->insertItem(0, tr("�˼��ռ���������ṹ����ȡ��������Ȩ����"), QVariant(GgsBackbone::Method::Entropy));
	this->comboBox->insertItem(1, tr("���ݽڵ�ȵĴ�С������ȡ����ֵ����"), QVariant(GgsBackbone::Method::Degree));
	this->comboBox->insertItem(2, tr("���ݽڵ���������ԵĴ�С������ȡ�������Է���"), QVariant(GgsBackbone::Method::BetweenessCentrality));
	this->comboBox->insertItem(3, tr("���ݽڵ�ӽ������ԵĴ�С������ȡ�������Է���"), QVariant(GgsBackbone::Method::ClosenessCentrality));
	this->comboBox->insertItem(4, tr("���ݽڵ��������������ԵĴ�С������ȡ�������Է���"), QVariant(GgsBackbone::Method::EigenvectorCentrality));
}
