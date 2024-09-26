#include "GgsApp.h"
#include <QApplication>
#include <QStyleFactory>
#include <QDesktopWidget>
#include <QSplashScreen>
#include <QStyle>
#include <QBitmap>
#include <QDir>
#include "qgsapplication.h"
#include "qgssettings.h"
#include "qgsproxystyle.h"


#include "ogdf/basic/extended_graph_alg.h"

#pragma execution_character_set("utf-8") 

void testOGDF() {

	ogdf::Graph g;
	ogdf::Graph subg;

	

	ogdf::List<ogdf::node> list;
	ogdf::List<ogdf::node>::iterator iterList = list.begin();

	ogdf::List<ogdf::edge> elist;
	(*iterList)->adjEdges(elist);

	list.front();

	ogdf::inducedSubGraph(g, iterList, subg);

}


int main(int argc, char *argv[])
{
	// testOGDF();

	// ����Ϊ��������ǿ��ʹ�÷����ļ�
	QString translationCode;

	{
		QCoreApplication coreApp(argc, argv);
		(void)QgsApplication::resolvePkgPath(); // trigger storing of application path in QgsApplication
	}

	QgsApplication::setOrganizationName(QgsApplication::QGIS_ORGANIZATION_NAME);
	QgsApplication::setOrganizationDomain(QgsApplication::QGIS_ORGANIZATION_DOMAIN);
	QgsApplication::setApplicationName(QgsApplication::QGIS_APPLICATION_NAME);
	QgsApplication::setAttribute(Qt::AA_DontShowIconsInMenus, false);

	{
		QgsSettings settings;
		/* �����ļ�
		*/
		QString myUserTranslation = settings.value(QStringLiteral("locale/userLocale"), "").toString();
		QString myGlobalLocale = settings.value(QStringLiteral("locale/globalLocale"), "").toString();
		bool myShowGroupSeparatorFlag = false; // Default to false
		bool myLocaleOverrideFlag = settings.value(QStringLiteral("locale/overrideFlag"), false).toBool();

		// ���������ȫ�ָ��Ǳ�־���򸲸���ʾ��ָ���
		if (myLocaleOverrideFlag)
		{
			// �ٴ�Ĭ��Ϊfalse 
			myShowGroupSeparatorFlag = settings.value(QStringLiteral("locale/showGroupSeparator"), false).toBool();
		}

		// �����ļ���������Ȩ��
		// - ������
		// - ��ѡ��Ի��������û�ָ��
		// - ϵͳ����
		if (!translationCode.isNull() && !translationCode.isEmpty())
		{
			settings.setValue(QStringLiteral("locale/userLocale"), translationCode);
		}
		else
		{
			if (!myLocaleOverrideFlag || myUserTranslation.isEmpty())
			{
				translationCode = QLocale().name();
				//setting the locale/userLocale when the --lang= option is not set will allow third party
				//plugins to always use the same locale as the QGIS, otherwise they can be out of sync
				settings.setValue(QStringLiteral("locale/userLocale"), translationCode);
			}
			else
			{
				translationCode = myUserTranslation;
			}
		}

		// Global locale settings
		if (myLocaleOverrideFlag && !myGlobalLocale.isEmpty())
		{
			QLocale currentLocale(myGlobalLocale);
			QLocale::setDefault(currentLocale);
		}

		// Number settings
		QLocale currentLocale;
		if (myShowGroupSeparatorFlag)
		{
			currentLocale.setNumberOptions(currentLocale.numberOptions() &= ~QLocale::NumberOption::OmitGroupSeparator);
		}
		else
		{
			currentLocale.setNumberOptions(currentLocale.numberOptions() |= QLocale::NumberOption::OmitGroupSeparator);
		}
		QLocale::setDefault(currentLocale);

		//QgsApplication::setTranslation(translationCode);
		QgsApplication::setTranslation("zh-Hans");
	}

	QString szPath = QgsApplication::i18nPath();
	
	QgsApplication myApp(argc, argv, true);

	QCoreApplication::addLibraryPath(QApplication::applicationDirPath()
		+ QDir::separator() + "qtplugins");

	QgsSettings settings;

	QString desiredStyle = settings.value(QStringLiteral("qgis/style")).toString();
	const QString theme = settings.value(QStringLiteral("UI/UITheme")).toString();
	if (theme != QLatin1String("default"))
	{
		if (QStyleFactory::keys().contains(QStringLiteral("fusion"), Qt::CaseInsensitive))
		{
			desiredStyle = QStringLiteral("fusion");
		}
	}

	const QString activeStyleName = QApplication::style()->metaObject()->className();
	if (desiredStyle.contains(QLatin1String("adwaita"), Qt::CaseInsensitive)
		|| (desiredStyle.isEmpty() && activeStyleName.contains(QLatin1String("adwaita"), Qt::CaseInsensitive)))
	{
		if (QStyleFactory::keys().contains(QStringLiteral("fusion"), Qt::CaseInsensitive))
		{
			desiredStyle = QStringLiteral("fusion");
		}
	}
	if (!desiredStyle.isEmpty())
	{
		QApplication::setStyle(new QgsAppStyle(desiredStyle));

		if (activeStyleName != desiredStyle)
			settings.setValue(QStringLiteral("qgis/style"), desiredStyle);
	}
	else
	{
		QApplication::setStyle(new QgsAppStyle(activeStyleName));
	}

	// ������������
	QPixmap myPixmap(":/graph/bundling/splashscreen.png");

	int w = 600 * qApp->desktop()->logicalDpiX() / 96;
	int h = 300 * qApp->desktop()->logicalDpiY() / 96;

	//QSplashScreen *mypSplash = new QSplashScreen(myPixmap.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	QSplashScreen *mypSplash = new QSplashScreen(myPixmap);
	mypSplash->setMask(myPixmap.mask());
	mypSplash->show();

	// ��������߳�����
	QgsApplication::setMaxThreads(settings.value(QStringLiteral("qgis/max_threads"), -1).toInt());

	// ����QgisAppʵ��������ʾ����Ҫ����һЩ��̬������Ҫ����
	//QgisApp * tempQgisApp = new QgisApp(); 
	
	// ����������ʵ��
	GgsApp* gb = new GgsApp(mypSplash);
	gb->setWindowTitle("����ռ��������ݴ�������ӷ������");
	gb->setObjectName(QStringLiteral("GraphBundling"));
	gb->show();

	mypSplash->finish(gb);

	int retval = myApp.exec();
	delete gb;
	return retval;
}
