#pragma once
#include <QList>

class GgsGraphProxy;
class QgsVectorLayer;

class GgsGraphProject: public QObject
{
	Q_OBJECT
public:
	~GgsGraphProject();

	static GgsGraphProject* instance();

	void addGraphProxy(GgsGraphProxy* graphProxy);

	QList<GgsGraphProxy*> graphProxys();

	int indexOfGraphProxy(GgsGraphProxy* graphProxy);

	GgsGraphProxy* findByName(const QString& name);

	GgsGraphProxy* findByLayer(const QgsVectorLayer* layer);

	void removeGraphProxyAt(int index);

	int size();

	void clearSelections();

	QList<GgsGraphProxy*> selections();

	void addSelection(GgsGraphProxy* g);

	void setCurrentSelection(GgsGraphProxy* g);

	GgsGraphProxy* currentSelection();

	bool hasSelected(GgsGraphProxy* g);

	void removeSelection(GgsGraphProxy* g);

protected:
	GgsGraphProject();

signals:
	void graphLayerAdded(GgsGraphProxy* proxy);
	
	void graphSelectionChanged(GgsGraphProxy* current);

private:
	static GgsGraphProject* sGraphProject;

	QList<GgsGraphProxy*> mGraphProxys;

	QList<GgsGraphProxy*> mSelectedGraphProxys;

	GgsGraphProxy* mCurrentSelectedGraphProxy = nullptr;
};

