#include<stdio.h>

void main()
{
	int Num = 10;
	int* pNum = &Num; //pNum은 Num을 가리키는 포인터
	int* *ppNum = &pNum;//ppNum은 pNum의 주소를 가리키는 포인터
	int** *pppNum = &ppNum;//pppNum은 ppNum의 주소를 가리키는 포인터
	printf("Num = %d\t&Num = %p\n", Num, &Num);
	printf("*pNum = %d\tpNum = %p \t&pNum = %p\n", *pNum, pNum, &pNum);
	printf("**ppNum = %d\t*ppNum = %p\tppNum = %p\t&ppNum = %p\n", **ppNum, *ppNum, ppNum, &ppNum);
	printf("***pppNum = %d\t**pppNum = %p\t*pppNum = %p\tpppNum = %p\t&pppNum = %p\n", ***pppNum, **pppNum, *pppNum, pppNum, &pppNum);
}