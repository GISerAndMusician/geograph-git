#include "GgsCsvParser.h"
#include <QFile>
#include <QTextStream>

GgsCsvParser::GgsCsvParser(Splitter splitter)
	: mSplitter(splitter)
{

}

GgsCsvParser::~GgsCsvParser()
{

}

bool GgsCsvParser::load(const QString& filePath)
{
	mDataModel.clear();

	QFile file(filePath);

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		return false;
	}
	QTextStream in(&file);

	for (int i=0; !in.atEnd(); i++)
	{
		QString data = in.readLine();

		// 解析首行标题
		if (i == 0) {
			QStringList headers = data.split(GgsCsvParser::splitterText(mSplitter));
			for (int j = 0; j < headers.size(); j++) {
				mDataModel.setHorizontalHeaderItem(j,
					new QStandardItem(headers[j])
					);
			}
		}
		else { // 解析数据项
			mDataModel.insertRow(i);
			QStringList row = data.split(GgsCsvParser::splitterText(mSplitter));

			for (int j = 0; j < row.size(); j++) {
				mDataModel.setItem(i, j,
					new QStandardItem(row[j])
					);
			}
		}
	}
	
	file.close();

	return true;
}

QString GgsCsvParser::splitterText(Splitter splitter)
{
	switch (splitter)
	{
	case GgsCsvParser::COMMA:
		return ",";
		break;
	case GgsCsvParser::SPACE:
		return "\40";
		break;
	case GgsCsvParser::TAB:
		return "\t";
		break;
	default:
		return QString();
		break;
	}
}

QStringList GgsCsvParser::headers()
{
	QStringList headers;
	int iCount = mDataModel.columnCount();
	for (int i = 0; i < iCount; i++)
	{
		headers << mDataModel.horizontalHeaderItem(i)->text();
	}

	return headers;
}

QMap<QString, QStringList> GgsCsvParser::data()
{
	QMap<QString, QStringList> data;

	int iRowCount = mDataModel.rowCount();
	int iColumnCount = mDataModel.columnCount();
	for (int i = 0; i < iRowCount; i++)
	{
		// 如果是第一行
		if (i == 0)
		{
			for (int j = 0; j < iColumnCount; j++)
			{
				QString header = mDataModel.horizontalHeaderItem(j)->text();
				if (!data.contains(header))
				{
					data.insert(header, QStringList());
				}
			}
			
		}
		else
		{
			for (int j = 0; j < iColumnCount; j++)
			{
				QString header = mDataModel.horizontalHeaderItem(j)->text();
				data[header].push_back(mDataModel.item(i, j)->text());
			}
		}
	}

	return data;
}
