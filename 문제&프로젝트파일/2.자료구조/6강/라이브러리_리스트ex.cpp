#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
//리스트에는 두가지 종류의 리스트가 있음
#include <list> 
//리스트 - 링크드 타입의 리스트 (메모리 주소가 연속적이지 않음) linked
//장점-데이터의 추가&제거가 빠르다.
//단점-데이터 접근이 느리다
#include <vector>
//벡터 - 배열타입의 리스트 (메모리 주소가 연속적임)
//장점 - 데이터 접근 속도가 빠르다
//단점 - 데이터의 추가&제거가 느리다

//벡터는 push_front와 pop_front가 안됨 
//리스트는 배열처럼 접근이 불가능 ex) iList[1]; 안됨
#include <algorithm>//알고리즘


//리스트 프린트
void PrintList(std::list<int> iList) //iterator == 포인터와 같은 개념 (해당 컨테이너 내에있는 자료를 가리킴)
{
	for (std::list<int>::iterator iter = iList.begin(); iter != iList.end(); iter++) //begin()은 시작 주소지만 end()는 마지막 다음주소임 (마지막 주소 아님)
	{
		printf("%d ", *iter);
	}
	printf("\n");
}
//데이터 찾는 함수
std::list<int>::iterator FinsData(std::list<int>* iList, int data)
{
	for (std::list<int>::iterator iter = iList->begin(); iter != iList->end(); iter++)
	{
		if (*iter == data)
		{
			return iter;
		}
	}
	return iList->end();
}
//출력을 함수화
void Search(std::list<int>* iList, int data)
{
	//둘다 반환값은 같다- 못 찾으면 end값/찾으면 찾은 주소값
	//std::list<int>::iterator iter = FinsData(iList, data); //직접 만든 파인드
	std::list<int>::iterator iter = std::find(iList->begin(), iList->end(), data); //알고리즘 파인드
	//알고리즘 Find는 구조체는 인식하지 못함- 기준이 없기 때문에(매개변수형이 다양함) > 그럴때는 Find를 만들줄 알아야함

	if (iter != iList->end())
	{
		printf("%d을 찾았습니다!\n", data);
	}
	else
	{
		printf("%d을 찾지 못했습니다!\n", data);
	}
}
//데이터 추가
void Add(std::list<int>* iList, int findData, int addData)
{
	std::list<int>::iterator iter = std::find(iList->begin(), iList->end(), findData);
	if (iter != iList->end())
	{
		iList->insert(iter, addData);
	}
	else
	{
		printf("%d을 찾지 못했습니다!\n", findData);
	}
}
//데이터 삭제
void Delete(std::list<int>* iList, int findData)
{
	std::list<int>::iterator iter = std::find(iList->begin(), iList->end(), findData);
	if (iter != iList->end())
	{
		iList->erase(iter);
	}
	else
	{
		printf("%d을 찾지 못했습니다!\n", findData);
	}
}
//메인
void main()
{
	std::list<int> iList;
	for (int i = 1; i <= 10; i++)
	{
		iList.push_back(i);//제일 뒤에다 데이터 추가
	}
	iList.push_front(11);//제일 앞에 데이터 추가
	PrintList(iList);

	Search(&iList, 6);
	Search(&iList, 20);
	Add(&iList, 6, 25);
	PrintList(iList);

	iList.pop_back();//맨뒤에있는 데이터 삭제
	iList.pop_front();//맨앞에있는 데이터 삭제

	iList.remove(25);//삭제함 - 없을경우 아무 일도 일어나지 않음
	PrintList(iList);
	Delete(&iList, 6);//값를 찾고 삭제함 -없을 경우 없다고 출력하도록 만든 함수
	PrintList(iList);

	iList.clear();//전체삭제
	iList.sort();//오름차순 정렬
	iList.reverse();//역순 ex)오름차순 이후 역순 사용시 내림차순
}

