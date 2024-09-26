#pragma once
#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <vector>

template <typename T>
struct Point4D
{
	T x, y, z, w;
	int index;
	Point4D() : x(0), y(0), z(0), w(0), index(-1) {};
	Point4D(T a, T b, T c, T d) : x(a), y(b), z(c), w(d), index(-1) {};
	Point4D(T a, T b, T c, T d, int idx) : x(a), y(b), z(c), w(d), index(idx) {};
	inline T &operator[](int i) {
		return i == 0 ? x : i == 1 ? y
			: i == 2 ? z : w;
	};
};

template <typename T>
struct Point3D
{
	T x, y, z;
	int index;
	Point3D() : x(0), y(0), z(0), index(-1) {};
	Point3D(T a, T b, T c) : x(a), y(b), z(c), index(-1) {};
	Point3D(T a, T b, T c, int idx) : x(a), y(b), z(c), index(idx) {};
	inline T &operator[](int i) {
		return i == 0 ? x : i == 1 ? y
			: z;
	};
};

template <typename T>
struct Point2D
{
	T x, y;
	int index;
	Point2D() : x(0), y(0), index(-1) {};
	Point2D(T a, T b) : x(a), y(b), index(-1) {};
	Point2D(T a, T b, int idx) : x(a), y(b), index(idx) {};

	inline T &operator[](int i) { return i == 0 ? x : y; };
};

struct MINGLEKDNode
{
	int index;
	int axis;
	MINGLEKDNode *left;
	MINGLEKDNode *right;
	MINGLEKDNode(int index, int axis, MINGLEKDNode *left = nullptr, MINGLEKDNode *right = nullptr)
	{
		this->index = index;
		this->axis = axis;
		this->left = left;
		this->right = right;
	}
};

template <class T>
class GgsMingleKdTree
{
private:
	int ndim;
	MINGLEKDNode *root;
	MINGLEKDNode *build(std::vector<T> &);
	std::set<int> visited;
	std::stack<MINGLEKDNode *> queueNode;
	std::vector<T> m_data;

	void release(MINGLEKDNode *);
	void printNode(MINGLEKDNode *);
	int chooseAxis(std::vector<T> &);
	void dfs(MINGLEKDNode *, T);
	// 点与点之间的距离
	inline double distanceT(MINGLEKDNode *, T);
	inline double distanceT(int, T);
	// 点与超平面的距离
	inline double distanceP(MINGLEKDNode *, T);
	// 检查父节点超平面是否在超球体中
	inline bool checkParent(MINGLEKDNode *, T, double);

public:
	GgsMingleKdTree(std::vector<T> &, int);
	~GgsMingleKdTree();
	void Print();
	int findNearestPoint(T);
	std::vector<int> findNearestKPoints(T, int k);

};

template <class T>
GgsMingleKdTree<T>::GgsMingleKdTree(std::vector<T> &data, int dim)
{
	ndim = dim;
	m_data = data;
	root = build(data);
}

template <class T>
GgsMingleKdTree<T>::~GgsMingleKdTree()
{
	release(root);
}

template <class T>
void GgsMingleKdTree<T>::Print()
{
	printNode(root);
}

template <class T>
void GgsMingleKdTree<T>::release(MINGLEKDNode *node)
{
	if (node)
	{
		if (node->left)
			release(node->left);
		if (node->right)
			release(node->right);
		delete node;
		node = nullptr;
	}
}

template <class T>
MINGLEKDNode *GgsMingleKdTree<T>::build(std::vector<T> &data)
{
	if (data.empty())
		return nullptr;
	std::vector<T> temp = data;
	int mid_index = static_cast<int>(data.size() / 2);
	int axis = data.size() > 1 ? chooseAxis(temp) : -1;
	std::sort(temp.begin(), temp.end(), [axis](T a, T b)
	{ return a[axis] < b[axis]; });
	std::vector<T> leftData, rightData;
	leftData.assign(temp.begin(), temp.begin() + mid_index);
	rightData.assign(temp.begin() + mid_index + 1, temp.end());
	MINGLEKDNode *leftNode = build(leftData);
	MINGLEKDNode *rightNode = build(rightData);
	MINGLEKDNode *rootNode;
	rootNode = new MINGLEKDNode(temp[mid_index].index, axis, leftNode, rightNode);
	return rootNode;
}

template <class T>
void GgsMingleKdTree<T>::printNode(MINGLEKDNode *node)
{
	if (node)
	{
		std::cout << "Index: " << node->index << "\tAxis: " << node->axis << std::endl;
		printNode(node->left);
		printNode(node->right);
	}
}

template <class T>
int GgsMingleKdTree<T>::chooseAxis(std::vector<T> &data)
{
	int axis = -1;
	double maxVar = -1.0;
	size_t size = data.size();
	for (int i = 0; i < ndim; i++)
	{
		double mean = 0;
		double Var = 0;
		for (int j = 0; j < size; j++)
		{
			mean += static_cast<double>(data[j][i]);
		}
		mean = mean / static_cast<double>(size);
		for (int j = 0; j < size; j++)
		{
			Var += (static_cast<double>(data[j][i]) - mean) * (static_cast<double>(data[j][i]) - mean);
		}
		Var = Var / static_cast<double>(size);
		if (Var > maxVar)
		{
			axis = i;
			maxVar = Var;
		}
	}
	return axis;
}

template <class T>
std::vector<int> GgsMingleKdTree<T>::findNearestKPoints(T pt, int k)
{
	std::vector<std::pair<int, double>> distVector;

	visited.clear();
	while (!queueNode.empty())
		queueNode.pop();
	dfs(root, pt);
	while (!queueNode.empty())
	{
		MINGLEKDNode *curNode = queueNode.top();
		queueNode.pop();

		double dist = distanceT(curNode, pt);
		distVector.push_back(std::make_pair(curNode->index, dist));

		if (!queueNode.empty())
		{
 			MINGLEKDNode *parentNode = queueNode.top();
// 			double distP = distanceP(parentNode, pt);
// 			distVector.push_back(std::make_pair(parentNode->index, distP));

			if (m_data[curNode->index][parentNode->axis] < m_data[parentNode->index][parentNode->axis])
				dfs(parentNode->right, pt);
			else
				dfs(parentNode->left, pt);
		}
	}

	std::sort(distVector.begin(), distVector.end(), [](std::pair<int, double>& a, std::pair<int, double>& b)
	{ return a.second < b.second; });

	std::vector<int> retIndexes;
	int L = distVector.size() < k ? distVector.size() : k;
	for (int i=0; i<L; i++)
	{
		retIndexes.push_back(distVector[i].first);
	}

	return retIndexes;
}

template <class T>
int GgsMingleKdTree<T>::findNearestPoint(T pt)
{
	visited.clear();
	while (!queueNode.empty())
		queueNode.pop();
	double min_dist = DBL_MAX;
	int resNodeIdx = -1;
	dfs(root, pt);
	while (!queueNode.empty())
	{
		MINGLEKDNode *curNode = queueNode.top();
		queueNode.pop();
		double dist = distanceT(curNode, pt);
		if (dist < min_dist)
		{
			min_dist = dist;
			resNodeIdx = curNode->index;
		}

		if (!queueNode.empty())
		{
			MINGLEKDNode *parentNode = queueNode.top();
			int parentAxis = parentNode->axis;
			int parentIndex = parentNode->index;
			if (checkParent(parentNode, pt, min_dist))
			{
				if (m_data[curNode->index][parentNode->axis] < m_data[parentNode->index][parentNode->axis])
					dfs(parentNode->right, pt);
				else
					dfs(parentNode->left, pt);
			}
		}
	}
	return resNodeIdx;
}

template <class T>
void GgsMingleKdTree<T>::dfs(MINGLEKDNode *node, T pt)
{
	if (node)
	{
		if (visited.find(node->index) != visited.end())
			return;
		queueNode.push(node);
		visited.insert(node->index);
		if (pt[node->axis] <= m_data[node->index][node->axis] && node->left)
			dfs(node->left, pt);
		else if (pt[node->axis] >= m_data[node->index][node->axis] && node->right)
			dfs(node->right, pt);
		else if ((node->left == nullptr) ^ (node->right == nullptr))
		{
			dfs(node->left, pt);
			dfs(node->right, pt);
		}
	}
}

template <class T>
double GgsMingleKdTree<T>::distanceT(MINGLEKDNode *node, T pt)
{
	double dist = 0;
	for (int i = 0; i < ndim; i++)
	{
		dist += (m_data[node->index][i] - pt[i]) * (m_data[node->index][i] - pt[i]);
	}
	return sqrt(dist);
}

template <class T>
double GgsMingleKdTree<T>::distanceT(int index, T pt)
{
	double dist = 0;
	for (int i = 0; i < ndim; i++)
	{
		dist += (m_data[index][i] - pt[i]) * (m_data[index][i] - pt[i]);
	}
	return sqrt(dist);
}

template <class T>
double GgsMingleKdTree<T>::distanceP(MINGLEKDNode *node, T pt)
{
	int axis = node->axis;
	double dist = static_cast<double>(pt[axis] - m_data[node->index][axis]);
	return dist >= 0 ? dist : -dist;
}

template <class T>
bool GgsMingleKdTree<T>::checkParent(MINGLEKDNode *node, T pt, double distT)
{
	double distP = distanceP(node, pt);
	return distP <= distT;
}
