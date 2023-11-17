#pragma once

#include<map>

struct S_NODE
{

	int nX;
	int nY;
	bool isBlock;

	std::map<S_NODE*, float> children;

	float fF, fG, fH;
	S_NODE* pParent;
	bool isClosed;
	
	int nHeapId;
	int nTmp
};