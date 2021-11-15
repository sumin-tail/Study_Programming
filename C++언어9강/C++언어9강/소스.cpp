#include <iostream>
using namespace std;

//성별, 나이, 이름을 저장하고 출력하는 Person Class 와
//학년, 반, 번호 를 저장하고 출력하는 School Class를 만들고
//위의 두Class를 상속받은 Student Class를 만들어 출력하시오.
//(단 Person Class와 School Class의 맴버함수는 Student Class에서만 호출가능)

enum GENDER
{
	GENDER_FEMALE,
	GENDER_MALE 
};

class Person
{
	GENDER gender;//성별
	int age; //나이
	int name; //이름
protected:

	void PersonSettting()
	{

		cout << "나이 입력 : ";
		cin >> age;
		cout << "이름 입력 : ";
		cin >> name;
	}

	void PersonPrint()
	{
		cout << "성별 : " <<gender <<endl;
		cout << "나이 : " << age <<endl;
		cout << "이름 : " << name <<endl;
	}
};

class School
{
	int grade;//학년
	int group;//반
	int number;//번호
protected:

	void SchoolPrint()
	{
		cout << "학년 : " << grade << endl;
		cout << "반 : " << group << endl;
		cout << "번호 : " << number << endl;
	}
};

class Student : public Person , public School
{
public:

	void SetStudent()
	{

	}

	void Print()
	{
		PersonPrint();
		SchoolPrint();
	}
};

void main()
{
	Student add;
	//설정
	add.SetStudent();
	add.Print();
}

