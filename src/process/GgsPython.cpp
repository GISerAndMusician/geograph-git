#include "GgsPython.h"


GgsPython::GgsPython()
{

}

GgsPython::~GgsPython()
{

}

bool GgsPython::initialize(const QString& path)
{
	// 1.初始化python接口
	Py_Initialize();

	// 2.初始化python系统文件路径，确保可以访问到.py文件
	PyRun_SimpleString("import sys");
	QByteArray array = QString("sys.path.append(\"%1\")").arg(path).toLocal8Bit();
	const char* szPath = array.data();
	int iResult = PyRun_SimpleString(szPath);

	return iResult;
}

PyObject* GgsPython::importModule(const QString& moduleName)
{
	// 3.调用python文件名
	PyObject* pModule = PyImport_ImportModule(moduleName.toStdString().c_str());

	if (pModule == NULL)
	{
		qDebug() << "don't find the python file!" << endl;
		return nullptr;
	}

	return pModule;
}

PyObject* GgsPython::getFunction(PyObject* pModule, const QString& funcName)
{
	PyObject* pFunc = PyObject_GetAttrString(pModule, funcName.toStdString().c_str());

	if (pFunc == NULL)
	{
		qDebug() << "don't find the function:" << funcName.toStdString().c_str() << endl;
		return nullptr;
	}

	return pFunc;
}

PyObject* GgsPython::callFunction(PyObject* pFunc, PyObject* pArgs)
{
	PyObject* pResult = PyObject_CallObject(pFunc, pArgs);
	
	if (pResult == NULL)
	{
		qDebug() << "something wrong with function..." << endl;
		return nullptr;
	}

	return pResult;
}


