#include <stdio.h>
#include <map>
#include<stdlib.h>
#include <time.h>
#include <string>

typedef struct Student
{
	char name[256]; //이름
	int age; //나이
}Student;

char* CreateName() 
{
	switch (rand() % 5)
	{
	case 0:
		return (char*)"김철수";
	case 1:
		return (char*)"이민수";
	case 2:
		return (char*)"황수정";
	case 3:
		return (char*)"김현";
	case 4:
		return (char*)"이설";
	default:
		return (char*)"이화";
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
		printf("%s(%d) : %d살\n", iter->second.name, iter->first, iter->second.age);//first에는 키 값이 second에는 밸류 값이 들어있음
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

	studentMap[20210001] = CreateStudent();//이미 있는 키값에 정보를 넣으면 수정이 되어버림
	PrintStudentALL(studentMap);

	studentMap.find(20210001); //iter리턴함 못찾으면 studentMap.end() 리턴함
	studentMap.erase(20210001); //키값 기준 삭제
	PrintStudentALL(studentMap);
}