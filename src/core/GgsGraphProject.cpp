#include "GgsGraphProject.h"
#include "GgsGraphProxy.h"
#include "qgsvectorlayer.h"

GgsGraphProject* GgsGraphProject::sGraphProject = nullptr;

GgsGraphProject::GgsGraphProject()
{

}

GgsGraphProject::~GgsGraphProject()
{
	QList<GgsGraphProxy*>::iterator iter = mGraphProxys.begin();
	while (iter != mGraphProxys.end())
	{
		GgsGraphProxy* tmp = (*iter);
		if(tmp)
		{
			delete tmp;
			tmp = nullptr;
		}
		iter++;
	}
}

GgsGraphProject* GgsGraphProject::instance()
{
	if (!sGraphProject)
	{
		sGraphProject = new GgsGraphProject;
	}
	
	return sGraphProject;
}

void GgsGraphProject::addGraphProxy(GgsGraphProxy* graphProxy)
{
	mGraphProxys.append(graphProxy);

	emit graphLayerAdded(graphProxy);
}

QList<GgsGraphProxy*> GgsGraphProject::graphProxys()
{
	return mGraphProxys;
}

int GgsGraphProject::indexOfGraphProxy(GgsGraphProxy* graphProxy)
{
	return mGraphProxys.indexOf(graphProxy);
}

GgsGraphProxy* GgsGraphProject::findByName(const QString& name)
{
	for each (GgsGraphProxy* proxy in mGraphProxys)
	{
		if (proxy->getName() == name)
		{
			return proxy;
		}
	}

	return nullptr;
}

GgsGraphProxy* GgsGraphProject::findByLayer(const QgsVectorLayer* layer)
{
	for each (GgsGraphProxy* proxy in mGraphProxys)
	{
		if (proxy->nodeLayerProxy()->nodeLayer() == layer ||
			proxy->edgeLayerProxy()->edgeLayer() == layer)
		{
			return proxy;
		}
	}

	return nullptr;
}

void GgsGraphProject::removeGraphProxyAt(int index)
{
	GgsGraphProxy* g = mGraphProxys.at(index);
	if (g)
	{
		delete g;
		g = nullptr;
	}
	return mGraphProxys.removeAt(index);
}

int GgsGraphProject::size()
{
	return mGraphProxys.size();
}

void GgsGraphProject::clearSelections()
{
	mSelectedGraphProxys.clear();
	mCurrentSelectedGraphProxy = nullptr;
}

QList<GgsGraphProxy*> GgsGraphProject::selections()
{
	return mSelectedGraphProxys;
}

void GgsGraphProject::addSelection(GgsGraphProxy* g)
{
	if (!mSelectedGraphProxys.contains(g)) {
		mSelectedGraphProxys.append(g);
	}
	setCurrentSelection(g);
}

void GgsGraphProject::setCurrentSelection(GgsGraphProxy* g)
{
	if (g != mCurrentSelectedGraphProxy)
	{
		mCurrentSelectedGraphProxy = g;
		emit graphSelectionChanged(mCurrentSelectedGraphProxy);
	}
}

GgsGraphProxy* GgsGraphProject::currentSelection()
{
	return mCurrentSelectedGraphProxy;
}

bool GgsGraphProject::hasSelected(GgsGraphProxy* g)
{
	return mSelectedGraphProxys.contains(g);
}

void GgsGraphProject::removeSelection(GgsGraphProxy* g)
{
	int index = mSelectedGraphProxys.indexOf(g);
	if (index) {
		mSelectedGraphProxys.removeAt(index);
		
		if (mCurrentSelectedGraphProxy == g)
		{
			mCurrentSelectedGraphProxy = nullptr;
		}
	}
}
