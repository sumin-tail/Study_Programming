#include <iostream>
#include <string>
using namespace std;

//����, ����, �̸��� �����ϰ� ����ϴ� Person Class ��
//�г�, ��, ��ȣ �� �����ϰ� ����ϴ� School Class�� �����
//���� ��Class�� ��ӹ��� Student Class�� ����� ����Ͻÿ�.
//(�� Person Class�� School Class�� �ɹ��Լ��� Student Class������ ȣ�Ⱑ��)

class Person
{
	string gender;//����
	int age; //����
	string name; //�̸�
protected:

	void PersonSettting()
	{
		cout << "���� �Է� : ";
		cin >> age;
		cout << "�̸� �Է� : ";
		cin >> name;
		cout << "���� �Է� : ";
		cin >> gender;
	}

	void PersonPrint()
	{
		cout << "���� : " << age <<endl;
		cout << "�̸� : " << name <<endl;
		cout << "���� : " << gender << endl;
	}
};

class School
{
private:
	int grade;//�г�
	int group;//��
	int number;//��ȣ

protected:
	void SchoolSettting()
	{
		cout << "�г� �Է� : ";
		cin >> grade;
		cout << "�� �Է� : ";
		cin >> group;
		cout << "�л� ��ȣ �Է� : ";
		cin >> number;
	}

	void SchoolPrint()
	{
		cout << grade<< " �г� " << group << " �� "<< number << "�� �л�" << endl;
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
	//����
	add.SetStudent();
	system("cls");
	add.Print();
}

