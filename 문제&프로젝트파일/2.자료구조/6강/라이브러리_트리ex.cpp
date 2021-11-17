#include <stdio.h>
#include <map>
#include<stdlib.h>
#include <time.h>
#include <string>

typedef struct Student
{
	char name[256]; //�̸�
	int age; //����
}Student;

char* CreateName() 
{
	switch (rand() % 5)
	{
	case 0:
		return (char*)"��ö��";
	case 1:
		return (char*)"�̹μ�";
	case 2:
		return (char*)"Ȳ����";
	case 3:
		return (char*)"����";
	case 4:
		return (char*)"�̼�";
	default:
		return (char*)"��ȭ";
	}
}

Student CreateStudent() 
{
	Student st;
	strcpy(st.name, CreateName());
	st.age = rand() % 4 + 20;

	return st;
}

void PrintStudentALL(std::map<int, Student> studentMap)
{
	for (std::map<int, Student>::iterator iter = studentMap.begin(); iter!= studentMap.end(); iter++)
	{
		printf("%s(%d) : %d��\n", iter->second.name, iter->first, iter->second.age);//first���� Ű ���� second���� ��� ���� �������
	}
	printf("----------------------\n");
}

void main() 
{
	srand(time(NULL));
	std::map<int, Student> studentMap;
	int studentNum = 20210001;
	for (int i = 1; i <= 5; i++)
	{
		studentMap[studentNum++] = CreateStudent();
	}
	PrintStudentALL(studentMap);

	studentMap[20210001] = CreateStudent();//�̹� �ִ� Ű���� ������ ������ ������ �Ǿ����
	PrintStudentALL(studentMap);

	studentMap.find(20210001); //iter������ ��ã���� studentMap.end() ������
	studentMap.erase(20210001); //Ű�� ���� ����
	PrintStudentALL(studentMap);
}