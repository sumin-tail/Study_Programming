#include <iostream>
#include <string>
#include <list> 

//���� �Լ�ȭ�� ���� ������
//������ �̿��� ��
using namespace std;

//-ȸ�������� ����ü �ڷ������� ����� �ɹ������� ���̵�, ��й�ȣ, �г���, ����, �޴�����ȣ, ���ϸ���
//- �ִ� ȸ������ ���� 10��(�����̳� ����)
//- �α��� �� ȸ������ ���� ��� 

typedef struct Profile
{
	string id; //���̵�
	string password; //��й�ȣ
	string nickname; //�г���
	int age; //����
	string phone_number;//�޴��� ��ȣ
	int mileage; //���ϸ���
}Profile;

//�Լ� ��
void MainMenu(int mamberNum);//���θ޴�
void Menu();//�޴�
string ID_Check(list<Profile> profileList); //���̵� üũ
string Password_Check(); //�н����� üũ
Profile NewMember(list<Profile> profileList); //ȸ������
void Login(list<Profile>* profileList);//�α���
void ProfileRead(list<Profile>::iterator iter); //ȸ������ ���
void ProfileRetouch(list<Profile>::iterator iter);//ȸ������ ����
void LoginPage(list<Profile>::iterator iter);//�α��� ������
//

void MainMenu(int mamberNum)//���θ޴�
{
	cout <<"====Login====<ȸ����[" << mamberNum <<"��]>" << endl;
	cout <<"1.ȸ�� ����" << endl;
	cout <<"2.�α���" << endl;
	cout <<"3.����" << endl;
	cout <<"====================" << endl;
	cout << "�Է� : ";
}

void Menu()//�޴�
{
	cout << "====Menu====" << endl;
	cout << "1.ȸ�� ����" << endl;
	cout << "2.ȸ�� ���� ����" << endl;
	cout << "3.�α׾ƿ�" << endl;
	cout << "====================" << endl;
	cout << "�Է� : ";
}

string ID_Check(list<Profile> profileList) //���̵� üũ
{
	//- ���̵� 3���� �̻� ������ ���ڸ� ����, ������ ���̵� ���� �Ұ���
	string data;

	while (true)
	{
		bool wordcheck = true;
		bool lengthcheck = true;
		bool samecheck = true;
		system("cls");
		cout << "���̵� �Է�<[3���� �̻�] [�ѱ� X] : ";
		cin >> data;
		for (int i = 0; i < (int)data.length(); i++)
		{
			//�ҹ���, �빮�� Ȯ��
			if (!(('a' <= data[i] && data[i] <= 'z') || ('A' <= data[i] && data[i] <= 'Z') || ('0' <= data[i] && data[i] <= '9')))
			{
				wordcheck = false;
				cout << "id�� ������ �ƴմϴ�." <<endl;
				break;
			}
		}

		if (data.length() < 3)
		{
			lengthcheck = false;
			cout << "id�� ������ ���� �Դϴ�." << endl;
		}

		for (list<Profile>::iterator iter = profileList.begin(); iter != profileList.end(); iter++)
		{
			if (iter->id == data)//�̸������� üũ
			{
				samecheck = false;
				cout << "������ ���̵� ���� �մϴ�." << endl;
				break;
			}
		}

		if (wordcheck && lengthcheck && samecheck)
		{
			return data;
		}

		system("pause");
	}
}

string Password_Check() //�н����� üũ
{
	//- ��й�ȣ 8���� �̻� ���� �ʼ� ���� ������ ����
	string data;
	string samedata;

	while (true)
	{
		bool numdercheck = false;
		bool wordcheck = true;
		bool lengthcheck = true;
		system("cls");
		cout << "��й�ȣ �Է�<[8���� �̻�] [���� �ʼ�] [���� O] : ";
		cin >> data;
		cout << "��й�ȣ Ȯ�� : ";
		cin >> samedata;

		for (int i = 0; i < (int)data.length(); i++)
		{
			//�����ִ��� Ȯ�� -> �ϳ��� ������ �� �ڷδ� üũ����
			if ('0' <= data[i] && data[i] <= '9'&& numdercheck == false)
			{
				numdercheck = true;
			}
			//�ҹ���, �빮��  = ���ڵ� �н� ���Ѿ���
			if (!(('a' <= data[i] && data[i] <= 'z') || ('A' <= data[i] && data[i] <= 'Z') || ('0' <= data[i] && data[i] <= '9')))
			{
				wordcheck = false;
				cout << "password�� ������ �ƴմϴ�." << endl;
				break;
			}
		}

		if (!numdercheck) //�� ���Ҵµ��� ���ڰ� ���ٸ�
		{
			cout << "���ڰ� ���ԵǾ� ���� �ʽ��ϴ�." << endl;
		}

		if (data.length() < 8)
		{
			lengthcheck = false;
			cout << "password�� �������� ���� �Դϴ�." << endl;
		}

		if (numdercheck&&wordcheck&&lengthcheck)
		{
			return data;
		}

		system("pause");
	}

	//-> Ʋ���� ���
	//password�� �������� ���� �Դϴ�.
	//���ڰ� ���ԵǾ� ���� �ʽ��ϴ�.
	//��й�ȣ�� ��ġ���� �ʽ��ϴ�.
	return data;
}

Profile NewMember(list<Profile> profileList) //ȸ������
{
	Profile newM;

	newM.id = ID_Check(profileList);
	newM.password = Password_Check();

	system("cls");
	cout << "�г��� �Է� : ";
	cin >> newM.nickname;

	cout << "���� �Է� : ";
	cin >> newM.age;

	cout << "�޴��� ��ȣ �Է� : ";
	cin >> newM.phone_number;

	newM.mileage = 1000;
	cout << "ȸ�� ���� ����!! ���ϸ��� 1000�� ���" << endl;

	return newM;
}

void Login(list<Profile> *profileList)//�α���
{
	string id;
	string password;
	list<Profile>::iterator iter;
	while (true)
	{
		system("cls");
		bool idcheck = false;
		bool passwordcheck = false;

		cout << "���̵� �Է� : ";
		cin >> id;

		cout << "��й�ȣ �Է� : ";
		cin >> password;

		for (iter = profileList->begin(); iter != profileList->end(); iter++)
		{
			if (iter->id == id)//�̸������� üũ
			{
				idcheck = true;
				if (iter->password == password)
				{
					passwordcheck = true;
					LoginPage(iter);
				}
				break;
			}
		}

		if (!idcheck)
		{
			cout << "�ش� ���̵� �����ϴ�." << endl;
		}
		else if (idcheck && passwordcheck == false)
		{
			cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
		}
		else if (idcheck&&passwordcheck)
		{
			return;
		}
		system("pause");

	}
	//-> Ʋ���� ���
	//�ش� ���̵� �����ϴ�.
	//��й�ȣ�� Ʋ�Ƚ��ϴ�.
}

void ProfileRead(list<Profile>::iterator iter) //ȸ������ ���
{
	cout << "===============ȸ�� ����===============" << endl;
	cout << "ID : " << iter->id << "	" << "�г��� : " << iter->nickname << endl;
	cout << "���� : " << iter->age << "��	" << "�޴��� ��ȣ : " << iter->phone_number << endl;
	cout << "���ϸ��� : " << iter->mileage<<"��" << endl;
	cout << "==============================" << endl;
}

void ProfileRetouch(list<Profile>::iterator iter)//ȸ������ ����
{
	int select;
	string data;
	while (1)
	{
		system("cls");
		ProfileRead(iter);

		cout << "1.�г��� ����" << endl;
		cout << "2.���� ����" << endl;
		cout << "3.�޴��� ��ȣ ����" << endl;
		cout << "4.���ư���" << endl;
		cout << "�Է� : ";
		cin >> select;

		switch (select)
		{
		case 1: //�г��� ����
			cout << "���� �г��� : " << iter->nickname << endl;
			cout << "������ �г��� �Է� : ";
			cin >> data;
			cout << iter->nickname << " -> "<< data << endl;
			iter->nickname = data;
			system("pause");
			break;
		case 2: //���� ����
			cout << "���� ���� : " << iter->age << endl;
			cout << "������ ���� �Է� : ";
			cin >> select;
			cout << iter->age << " -> " << select << endl;
			iter->age = select;
			system("pause");
			break;
		case 3: //�޴��� ��ȣ ����
			cout << "���� �޴��� ��ȣ : " << iter->phone_number << endl;
			cout << "������ �޴��� ��ȣ �Է� : ";
			cin >> data;
			cout << iter->phone_number << " -> " << data << endl;
			iter->phone_number = data;
			system("pause");
			break;
		case 4: //���ư���
			return;
		default: 
			break;
		}
	}
}

void LoginPage(list<Profile>::iterator iter)
{
	int select;
	while (1)
	{
		system("cls");
		Menu();
		cin >> select;

		switch (select)
		{
		case 1: //ȸ�� ����
			system("cls");
			ProfileRead(iter);
			system("pause");
			break;
		case 2: //ȸ�� ���� ����
			ProfileRetouch(iter);
			break;
		case 3: //�α׾ƿ�
			return;
		default:
			break;
		}
	}
}

void main()
{
	list<Profile> profileList;
	list<Profile>::iterator iter;
	int select;
	int mamberNum = 0;

	while (1)
	{
		system("cls");
		MainMenu(mamberNum);
		cin >> select;

		switch (select)
		{
		case 1: //ȸ�� ����
			system("cls");
			if (mamberNum < 10)
			{
				profileList.push_back(NewMember(profileList));
				mamberNum++;
			}
			else
			{
				cout << "���̻� ȸ���� ����� �� �����ϴ�." << endl;
			}
			system("pause");
			break;
		case 2: //�α���
			system("cls");
			Login(&profileList);
			break;
		case 3: //����
			return;
		default:
			break;
		}
	}
}