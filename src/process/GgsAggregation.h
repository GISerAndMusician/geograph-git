#pragma once

class GgsGraphProxy;

class GgsAggregation
{
public:
	GgsAggregation(GgsGraphProxy* graph);

	void aggregate();

private:

	double mTolerance = 0.01;
	double mSearchBuffer = 10;
	GgsGraphProxy* mGraph = nullptr;
};

