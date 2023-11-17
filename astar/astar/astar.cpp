#include <stdio.h>
#include "astar.h"

void C_ASTAR::load()
{
	FILE* pF{};
	errno_t errNo = fopen_s(&pF, "map.txt", "rt");

	if (errNo > 0 || pF == nullptr)
	{
		printf("%d\n", errNo);
		return;
	}
	
	fscanf_s(pF, "[buffer]=%d\n", &m_nSize);
	printf("bufferSize %d\n" , m_nSize);

	char** ppBuffer = new char* [m_nSize] {};
	m_ppMap = new S_NODE * [m_nSize] {};
	for (int i = 0; i < m_nSize; i++)
	{
		ppBuffer[i] = new char[m_nSize] {};
		m_ppMap[i] = new S_NODE[m_nSize] {};
	}

	for (int i = 0; i < m_nSize; i++)
	{
		fscanf_s(pF, "%s\n", ppBuffer[i], m_nSize);
	}

	for (int i = 0; i < m_nSize; i++)
	{
		for (int j = 0; j < m_nSize; j++)
		{
			makeMap(j, i, ppBuffer);
		}
	}

	for (int i = 0; i < m_nSize; i++)
	{
		delete  [] ppBuffer[i];
	}
	delete[] ppBuffer;

	m_heap.init();
}


void C_ASTAR::makeMap(int nX, int nY, char** ppBuffer)
{
	int arOffSet[8][2]{ {-1,-1},{0,-1},{1,-1}  ,  {-1,0},{1,0}  ,  {-1,1},{0,1},{1,1} };
	float arDistance[8]{ 1.414f , 1.0f, 1.414f,   1.0f, 1.0f ,   1.414f, 1.0f, 1.414f };
	m_ppMap[nY][nX].nX = nX;
	m_ppMap[nY][nX].nY = nY;

	if (ppBuffer[nY][nX] == '1')
	{
		m_ppMap[nY][nX].isBlock = true;
		m_ppMap[nY][nX].nTmp = 1;
		return; 
	}

	for (int i = 0; i < 8; i++)
	{
		int nChildX = nX + arOffSet[i][0];
		int nChildY = nY + arOffSet[i][1];

		if (nChildX >= 0 && nChildX < m_nSize && nChildY >= 0 && nChildY < m_nSize && ppBuffer[nChildY][nChildX] == '.')
		{
			//m_ppMap[nY][nX].children.push_back(&m_ppMap[nChildY][nChildX]);
			m_ppMap[nY][nX].children.insert({ &m_ppMap[nChildX][nChildY], arDistance[i] });

		}
	}
}

float C_ASTAR::calculation(int nX1, int nY1, int nX2, int nY2)
{
	return sqrtf((float)((nX1- nX2)* (nX1 - nX2) + (nY1 - nY2)* (nY1 - nY2)));
}

void C_ASTAR::print()
{
	for (int i = 0; i < m_nSize; i++)
	{
		for (int j = 0; j < m_nSize; j++)
		{
			printf("%d", m_ppMap[i][j].nTmp);
		}
		printf("\n");
	}
	printf("\n");
}

void C_ASTAR::run()
{
	int nBx = 1;
	int nBy = 1;
	int nEx = 20;
	int nEy = 10;

	m_heap.add(&m_ppMap[nBy][nBx]);

	S_NODE* pNode = m_heap.top();
	pNode->isClosed = true;
	pNode->nTmp = 2;
	m_heap.pop();
	
	for (auto iter = pNode->children.begin(); iter != pNode->children.end(); iter++)
	{
		if (!iter->first->isClosed)
		{
			iter->first->fG = pNode->fG + iter->second;
			iter->first->fH = calculation(pNode->nX, iter->first->nX, pNode->nY, iter->first->nY);
			iter->first->fF = iter->first->fH + iter->first->fG;
			iter->first->pParent = pNode;
			m_heap.add(iter->first);
		}
	}

	m_heap.top();





}