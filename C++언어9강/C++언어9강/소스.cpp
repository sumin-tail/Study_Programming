#include <iostream>
using namespace std;

//����, ����, �̸��� �����ϰ� ����ϴ� Person Class ��
//�г�, ��, ��ȣ �� �����ϰ� ����ϴ� School Class�� �����
//���� ��Class�� ��ӹ��� Student Class�� ����� ����Ͻÿ�.
//(�� Person Class�� School Class�� �ɹ��Լ��� Student Class������ ȣ�Ⱑ��)

enum GENDER
{
	GENDER_FEMALE,
	GENDER_MALE 
};

class Person
{
	GENDER gender;//����
	int age; //����
	int name; //�̸�
protected:

	void PersonSettting()
	{

		cout << "���� �Է� : ";
		cin >> age;
		cout << "�̸� �Է� : ";
		cin >> name;
	}

	void PersonPrint()
	{
		cout << "���� : " <<gender <<endl;
		cout << "���� : " << age <<endl;
		cout << "�̸� : " << name <<endl;
	}
};

class School
{
	int grade;//�г�
	int group;//��
	int number;//��ȣ
protected:

	void SchoolPrint()
	{
		cout << "�г� : " << grade << endl;
		cout << "�� : " << group << endl;
		cout << "��ȣ : " << number << endl;
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
	//����
	add.SetStudent();
	add.Print();
}

