#pragma once
#include <QWidget>
#include "ui_GgsLwoInteractionWidget.h"
#include "GgsLwoInteraction.h"

class GgsLwoInteractionWidget : public QWidget, public Ui::LWOWidget
{
	Q_OBJECT

public:
	GgsLwoInteractionWidget(GgsLwoInteraction* lwo, QWidget* parent = nullptr);
	~GgsLwoInteractionWidget();

private slots:
	void onGraphSelectionChanged(GgsGraphProxy* current);

	void onFillColorBtnClicked();
	void onStrokeColorBtnClicked();
	void onCircleFillColorBtnClicked();
	void onCircleStrokeColorBtnClicked();

	void onOk();
	void onUpdateComboBox();
private:
	void initDockUi();

private:
	GgsLwoInteraction* mLwoInteraction = nullptr;
};
