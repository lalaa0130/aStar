#include "astar.h"
#include <stdio.h>

void C_ASTAR::load()
{
	// �� �̰� ����� �ϴ°� ?
	// ���ҽ��� �ι� ���� �ֱ� �Ⱦ sln ���� �̶� exe ������ ��ġ�� �޶� ������ 
	//������ ����
	//����� ���͸� 
	//1.�Ӽ�-> �Ϲ�-> ��� ���͸��� solutionDir �� �ڿ� + "bin\"
	//2.           -> ��� �̸� + _D
	//��� ���� 
	//�Ӽ� -> ����� -> �ַ�� ���͸� �� 1���� �̸� ���� ����


	FILE* pF{};
	// file open �Լ�, ������������ ���� �д� ����� f1�� ���� ã�ƺ���
	errno_t erro = fopen_s(&pF, "map.txt", "rt");

	if (erro > 0 || pF == nullptr)
	{
		printf("%d", erro);
		return;
	}

	int nBufferSize{};
	fscanf_s(pF, "[buffer] = %d\n", &nBufferSize);
	printf("Buffer size: %d\n", nBufferSize);
	
	char** ppBuffer = new char* [nBufferSize] {};
	
	for (int i = 0; i < nBufferSize; i++)
	{
		ppBuffer[i] = new char[nBufferSize]{};
	}

	for (int i = 0; i < nBufferSize; i++)
	{
		fscanf_s(pF, "%s\n", ppBuffer[i], 24);
	}

	for (int i = 0; i < nBufferSize; i++)
	{
		printf("%s\n", ppBuffer[i]);
	}


}
