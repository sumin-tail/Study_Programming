#pragma once
#include<iostream>
#include<string>
using namespace std;

enum GENDER //열거형-성별
{
	GENDER_MAN,
	GENDER_WOMAN
};

enum CLASS //열거형-학년
{
	CLASS_START = 1,
	CLASS_1 = 1,
	CLASS_2,
	CLASS_3,
	CLASS_END
};

class Student
{
private:
	string m_strName; //이름
	int m_iAge; //나이
	GENDER m_eGender;//성별
	CLASS m_eClass;//학년
	int m_iNumber; //번호
public:
	void SetStudent(int Number); //학생정보입력
	void ShowStudent();//학생출력
	inline string GetName() //학생이름 리턴-인라인
	{
		return m_strName;
	}
	inline CLASS GetClass()//학생학년 리턴-인라인
	{
		return m_eClass;
	}
	Student(); //생성자
	~Student(); //소멸자
};


