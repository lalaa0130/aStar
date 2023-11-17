#include "heap.h"

void C_HEAP::init()
{
    m_heapBuffer.push_back({});
}

void C_HEAP::add(S_NODE* pNode)
{
    int nHeapId = (int)m_heapBuffer.size();

    pNode->nHeapId = nHeapId;
    m_heapBuffer.push_back({ pNode });

    nodeUp(nHeapId, nHeapId / 2);
}

void C_HEAP::update(S_NODE* pNode)
{
    //int nId = pNode->nId;
   /* while (nId / 2 > 0)
    {
        nodeSwap(nId, nId / 2);
        nId /= 2;
    }*/

    pop();
    add(pNode);
}

void C_HEAP::nodeUp(int nId, int nUp)
{
    if (nUp == 0 || (m_heapBuffer[nUp].pNode->fF < m_heapBuffer[nId].pNode->fF))
        return;

    nodeSwap(nUp, nId);
    nodeUp(nUp, nUp / 2);
}

void C_HEAP::nodeSwap(int nId1, int nId2)
{
    /* swap(m_heapBuffer[nId1].pNode, m_heapBuffer[nId2].pNode);
     m_heapBuffer[nId1].pNode->nId = nId1;
     m_heapBuffer[nId2].pNode->nId = nId2;
 }*/
}


void C_HEAP::print()
{
    for (int i = 1; i < m_heapBuffer.size(); i++)
    {
        //printf("%d ", m_heapBuffer[i].pNode->nData);
    }
    printf("\n");
}

S_NODE* C_HEAP::top()
{
    return m_heapBuffer[1].pNode;
}

void C_HEAP::pop()
{
    if (m_heapBuffer.size() <= 1)
        return;

    int nLastIndex = (int)m_heapBuffer.size() - 1;

    S_NODE* pPopNode = m_heapBuffer[1].pNode;
    nodeSwap(1, nLastIndex);
    m_heapBuffer.pop_back();
    pPopNode->nHeapId = 0;

    nodeDown(1, 2, 3);
}

void C_HEAP::nodeDown(int nId, int nL, int nR)
{
    int nLastIndex = (int)m_heapBuffer.size() - 1;
    if (nL > nLastIndex)
        return;

    int nSelect = nL;
    if (nR <= nLastIndex && m_heapBuffer[nL].pNode->fF> m_heapBuffer[nR].pNode->fF)
        nSelect = nR;

    if (m_heapBuffer[nId].pNode->fF< m_heapBuffer[nSelect].pNode->fF)
        return;

    nodeSwap(nId, nSelect);
    nodeDown(nSelect, nSelect * 2, nSelect * 2 + 1);
}
