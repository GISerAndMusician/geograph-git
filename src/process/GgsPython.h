#pragma once
#include <QString>
#include <QDebug>
#include <Python.h>

class GgsPython
{
public:
	GgsPython();
	virtual ~GgsPython();

	bool initialize(const QString& path);

	PyObject* importModule(const QString& moduleName);

	PyObject* getFunction(PyObject* pModule, const QString& funcName);

	PyObject* callFunction(PyObject* pFunc, PyObject* pArgs);
};