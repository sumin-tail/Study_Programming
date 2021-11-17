#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
//����Ʈ���� �ΰ��� ������ ����Ʈ�� ����
#include <list> 
//����Ʈ - ��ũ�� Ÿ���� ����Ʈ (�޸� �ּҰ� ���������� ����) linked
//����-�������� �߰�&���Ű� ������.
//����-������ ������ ������
#include <vector>
//���� - �迭Ÿ���� ����Ʈ (�޸� �ּҰ� ��������)
//���� - ������ ���� �ӵ��� ������
//���� - �������� �߰�&���Ű� ������

//���ʹ� push_front�� pop_front�� �ȵ� 
//����Ʈ�� �迭ó�� ������ �Ұ��� ex) iList[1]; �ȵ�
#include <algorithm>//�˰���


//����Ʈ ����Ʈ
void PrintList(std::list<int> iList) //iterator == �����Ϳ� ���� ���� (�ش� �����̳� �����ִ� �ڷḦ ����Ŵ)
{
	for (std::list<int>::iterator iter = iList.begin(); iter != iList.end(); iter++) //begin()�� ���� �ּ����� end()�� ������ �����ּ��� (������ �ּ� �ƴ�)
	{
		printf("%d ", *iter);
	}
	printf("\n");
}
//������ ã�� �Լ�
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
//����� �Լ�ȭ
void Search(std::list<int>* iList, int data)
{
	//�Ѵ� ��ȯ���� ����- �� ã���� end��/ã���� ã�� �ּҰ�
	//std::list<int>::iterator iter = FinsData(iList, data); //���� ���� ���ε�
	std::list<int>::iterator iter = std::find(iList->begin(), iList->end(), data); //�˰��� ���ε�
	//�˰��� Find�� ����ü�� �ν����� ����- ������ ���� ������(�Ű��������� �پ���) > �׷����� Find�� ������ �˾ƾ���

	if (iter != iList->end())
	{
		printf("%d�� ã�ҽ��ϴ�!\n", data);
	}
	else
	{
		printf("%d�� ã�� ���߽��ϴ�!\n", data);
	}
}
//������ �߰�
void Add(std::list<int>* iList, int findData, int addData)
{
	std::list<int>::iterator iter = std::find(iList->begin(), iList->end(), findData);
	if (iter != iList->end())
	{
		iList->insert(iter, addData);
	}
	else
	{
		printf("%d�� ã�� ���߽��ϴ�!\n", findData);
	}
}
//������ ����
void Delete(std::list<int>* iList, int findData)
{
	std::list<int>::iterator iter = std::find(iList->begin(), iList->end(), findData);
	if (iter != iList->end())
	{
		iList->erase(iter);
	}
	else
	{
		printf("%d�� ã�� ���߽��ϴ�!\n", findData);
	}
}
//����
void main()
{
	std::list<int> iList;
	for (int i = 1; i <= 10; i++)
	{
		iList.push_back(i);//���� �ڿ��� ������ �߰�
	}
	iList.push_front(11);//���� �տ� ������ �߰�
	PrintList(iList);

	Search(&iList, 6);
	Search(&iList, 20);
	Add(&iList, 6, 25);
	PrintList(iList);

	iList.pop_back();//�ǵڿ��ִ� ������ ����
	iList.pop_front();//�Ǿտ��ִ� ������ ����

	iList.remove(25);//������ - ������� �ƹ� �ϵ� �Ͼ�� ����
	PrintList(iList);
	Delete(&iList, 6);//���� ã�� ������ -���� ��� ���ٰ� ����ϵ��� ���� �Լ�
	PrintList(iList);

	iList.clear();//��ü����
	iList.sort();//�������� ����
	iList.reverse();//���� ex)�������� ���� ���� ���� ��������
}

