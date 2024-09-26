#pragma once
#include "GgsGraphProxy.h"
#include "GgsPython.h"

class GgsGraphInfoAmount
{
public:
	GgsGraphInfoAmount(GgsGraphProxy* graph);
	~GgsGraphInfoAmount();

	double calcInfoAmount();

private:
	GgsGraphProxy* mGraph = nullptr;

};