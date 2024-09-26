#pragma once
#include <QString>
#include <QStandardItemModel>
#include <QMap>

class GgsCsvParser
{
public:

	enum Splitter
	{
		COMMA,
		SPACE,
		TAB
	};

	static Splitter SPLITTER;

	GgsCsvParser(Splitter splitter = COMMA);
	
	~GgsCsvParser();

	bool load(const QString& filePath);

	void setSplitter(Splitter splitter) { this->mSplitter = splitter; };
	Splitter getSplitter() { return mSplitter; };

	static QString splitterText(Splitter splitter);

	QStringList headers();

	QMap<QString, QStringList> data();

private:
	// 数据模型
	QStandardItemModel mDataModel;

	// 分隔符
	Splitter mSplitter;
};