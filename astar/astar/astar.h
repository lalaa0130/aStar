#pragma once

#include"node.h"
#include"heap.h"

class C_ASTAR
{
private:
	C_HEAP m_heap;


private:
	int m_nSize;
	S_NODE** m_ppMap;

private:
	void makeMap(int nX, int nY , char **ppBuffer);
	float calculation(int nX1, int nY1, int nX2, int nY2);

public:
	void load();
	void run();
	void print();
};