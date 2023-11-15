#include "astar.h"
#include <stdio.h>

void C_ASTAR::load()
{
	// 왜 이걸 맞춰야 하는가 ?
	// 리소스를 두번 집어 넣기 싫어서 sln 파일 이랑 exe 파일의 위치가 달라서 통합함 
	//폴더에 들어가서
	//디버깅 디렉터리 
	//1.속성-> 일반-> 출력 디렉터리는 solutionDir 의 뒤에 + "bin\"
	//2.           -> 대상 이름 + _D
	//경로 맞춤 
	//속성 -> 디버깅 -> 솔루션 디렉터리 를 1번의 이름 으로 복붙


	FILE* pF{};
	// file open 함수, 마지막인자인 파일 읽는 방식은 f1을 가서 찾아보기
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
