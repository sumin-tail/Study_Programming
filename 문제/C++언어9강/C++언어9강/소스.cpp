#include <iostream>
#include <string>
using namespace std;

//성별, 나이, 이름을 저장하고 출력하는 Person Class 와
//학년, 반, 번호 를 저장하고 출력하는 School Class를 만들고
//위의 두Class를 상속받은 Student Class를 만들어 출력하시오.
//(단 Person Class와 School Class의 맴버함수는 Student Class에서만 호출가능)

class Person
{
	string gender;//성별
	int age; //나이
	string name; //이름
protected:

	void PersonSettting()
	{
		cout << "나이 입력 : ";
		cin >> age;
		cout << "이름 입력 : ";
		cin >> name;
		cout << "성별 입력 : ";
		cin >> gender;
	}

	void PersonPrint()
	{
		cout << "나이 : " << age <<endl;
		cout << "이름 : " << name <<endl;
		cout << "성별 : " << gender << endl;
	}
};

class School
{
private:
	int grade;//학년
	int group;//반
	int number;//번호

protected:
	void SchoolSettting()
	{
		cout << "학년 입력 : ";
		cin >> grade;
		cout << "반 입력 : ";
		cin >> group;
		cout << "학생 번호 입력 : ";
		cin >> number;
	}

	void SchoolPrint()
	{
		cout << grade<< " 학년 " << group << " 반 "<< number << "번 학생" << endl;
	}
};

class Student : public Person , public School
{
public:

	void SetStudent()
	{
		SchoolSettting();
		PersonSettting();
	}

	void Print()
	{
		SchoolPrint();
		PersonPrint();
	}
};

void main()
{
	Student add;
	//설정
	add.SetStudent();
	system("cls");
	add.Print();
}

