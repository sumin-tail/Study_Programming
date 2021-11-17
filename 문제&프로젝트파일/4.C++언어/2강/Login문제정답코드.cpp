#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//������ �̿��Ұ�!!
#define IDLEN 3
#define PASSWORDLEN 8
#define IDMAX 10

struct ID
{
	string Id;
	string Password;
	string Name;
	int Age;
	string PhonNumber;
	int Mileage;
};

void Menu(int Num)//�޴�
{
	system("cls");
	cout << "=====Login=====(ȸ����[" << Num << "��])" << endl;
	cout << "   1.ȸ�� ����" << endl;
	cout << "   2.�α���" << endl;
	cout << "   3.����" << endl;
	cout << "�Է� : ";
}

//�Լ�ȭ
bool StringCheck(char Start, char End, char Check)//���ڿ� üũ ���۹��ڿ� ������ ���� ���̿� �����ϴ��� üũ��(�ƽ�Ű�ڵ�)
{
	if (Check >= Start && Check <= End)
		return true;
	else return false;
}

void Join(ID* P1, int Id_Count, ID Id_List[])//ȸ������
{
	bool EngCheck, CompareCheck, IDCheck;//����üũ ����üũ �ߺ� üũ
	int CountNum = 0;
	string CheckPassword;//�н����� Ȯ��
	while (1)
	{
		EngCheck = true;
		IDCheck = true;
		system("cls");
		cout << "���̵� �Է�([3���ڡ�] AND [�ѱ�X]) : ";
		cin >> P1->Id;

		for (int i = 0; i < P1->Id.length(); i++)//����(��������) üũ
		{
			if (StringCheck('A', 'Z', P1->Id[i]) == false && StringCheck('a', 'z', P1->Id[i]) == false && StringCheck('0', '9', P1->Id[i]) == false)
			{
				EngCheck = false;
				break;
			}
		}

		for (int i = 0; i < Id_Count; i++) //�ߺ����̵�üũ -���� �����ϴ� ����� ����ŭ ����
		{
			if (Id_List[i].Id == P1->Id)
				IDCheck = false;
		}

		if (!IDCheck)//������ ���̵� �����Ѵٸ�
		{
			cout << "������ ���̵� �����մϴ�." << endl;
		}
		if (EngCheck && IDCheck && P1->Id.length() >= IDLEN)//���� ID�� ��������� �����Ѵٸ� break
			break;
		if (!EngCheck)
			cout << "id�� ������ �ƴմϴ�." << endl;
		if (P1->Id.length() < IDLEN)
			cout << "id�� ������ ���� �Դϴ�." << endl;
		system("pause");
	}
	while (1)
	{
		EngCheck = true; //����(����)Ȯ��
		CompareCheck = true;//�ߺ�üũ
		system("cls");
		cout << "��й�ȣ �Է�([8���ڡ�]AND[����]AND[���� ����]) : ";
		cin >> P1->Password;
		CountNum = 0;
		for (int i = 0; i < P1->Password.length(); i++)
		{
			if (StringCheck('A', 'Z', P1->Password[i]) == false && StringCheck('a', 'z', P1->Password[i]) == false)//������ üũ
			{
				if (P1->Password[i] >= '0' && P1->Password[i] <= '9')//���� ���°��� ���ڶ��
					CountNum++;//���� ī��Ʈ����
				else
					EngCheck = false;
			}
		}
		cout << "��й�ȣ Ȯ�� : ";
		cin >> CheckPassword;
		if (CheckPassword != P1->Password)//���� �н����尡 ���� �ʴٸ�
			CompareCheck = false;
		if (EngCheck && CompareCheck && P1->Password.length() >= PASSWORDLEN && CountNum >= 1)//�н����� ������ ��� �����Ұ�� break;
			break;
		if (!EngCheck)
			cout << "password�� ������ �ƴմϴ�." << endl;
		if (P1->Password.length() < PASSWORDLEN)
			cout << "Password�� �������� ���� �Դϴ�." << endl;
		if (CountNum == 0)
			cout << "���ڰ� ���ԵǾ� ���� �ʽ��ϴ�." << endl;
		if (!CompareCheck)
			cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
		system("pause");
	}
	system("cls");
	cout << "�г��� �Է� : ";
	cin >> P1->Name;
	cout << "���� �Է� :";
	cin >> P1->Age;
	cout << "�޴��� ��ȣ �Է� : ";
	cin >> P1->PhonNumber;
	cout << "ȸ������ ���� !! ���ϸ��� 1000�� ���" << endl;
	P1->Mileage = 1000;
	system("pause");
}

void SimpleShowID(ID id)
{
	cout << "============ȸ�� ����============" << endl;
	cout << "ID : " << id.Id << "   �г��� : " << id.Name << endl;
}

void ShowID(ID id)//ȸ������
{
	system("cls");
	SimpleShowID(id);
	cout << " ���� : " << id.Age << "��" << "   �޴��� ��ȣ : " << id.PhonNumber << endl;
	cout << "���ϸ��� : " << id.Mileage << "��" << endl;
}

//�Լ�ȭ
void Setstring(string* str, string tmp)//string �迭 ������ ���� (������ ������ �ּ� , ������ �������� �̸�(�г��� ��))
{
	string tmpstr;
	tmpstr = *str; //������ �����͸� tmpstr�� ���
	cout << "���� " << tmp << ": " << tmpstr << endl;
	cout << "������ " << tmp << "�Է� : ";
	cin >> *str; //������ �ٷ� ����
	cout << tmpstr << " -> " << *str << endl; //���� �� ������ -> ���� �� ������
	system("pause");
}

//�Լ�ȭ
void Setint(int* num, string tmp)//int �迭 ������ ����
{
	int tmpint;
	tmpint = *num;
	cout << "���� " << tmp << " : " << tmpint << endl;
	cout << "������ " << tmp << "�Է� : ";
	cin >> *num;
	cout << tmpint << " -> " << *num << endl;
	system("pause");
}

void SetID(ID* id)
{
	int Select;
	while (1)
	{
		ShowID(*id);
		cout << "===================" << endl;
		cout << "1.�г��� ����" << endl;
		cout << "2.���� ����" << endl;
		cout << "3.�޴��� ��ȣ ����" << endl;
		cout << "4.���ư���" << endl;
		cout << "�Է� : ";
		cin >> Select;
		switch (Select)
		{
		case 1:
			Setstring(&id->Name, "�г���");
			break;
		case 2:
			Setint(&id->Age, "����");
			break;
		case 3:
			Setstring(&id->PhonNumber, "�޴��� ��ȣ");
			break;
		case 4:
			return;
		}
	}
}

void Display(ID* id)//�α��� ȭ��
{
	int Select;
	while (1)
	{
		system("cls");
		cout << "========Menu========" << endl;
		cout << "  1.ȸ�� ����" << endl;
		cout << "  2.ȸ�� ���� ����" << endl;
		cout << "  3.�α׾ƿ�" << endl;
		cout << "�Է� : ";
		cin >> Select;
		switch (Select)
		{
		case 1:
			ShowID(*id);
			system("pause");
			break;
		case 2:
			SetID(id);
			break;
		case 3:
			return;
		}
	}
}

void main()
{
	int Id_Count = 0; //����� ��
	ID Id_List[IDMAX]; //����� �� ����
	string TmpId, TmpPassword;//�α��� ���̵�, �н����� �Է¿�
	int Select; //����
	bool Id_Flag, PasswordFlag, LoginFlag;
	while (1)
	{
		LoginFlag = false;
		Menu(Id_Count);
		cin >> Select;
		switch (Select)
		{
		case 1:
			if (Id_Count >= IDMAX)
			{
				cout << "���̻� ȸ���� ����� �� �����ϴ�." << endl;
				system("pause");
				break;
			}
			Join(&Id_List[Id_Count], Id_Count, Id_List);
			Id_Count++;
			break;
		case 2:
			while (!LoginFlag)//�α��ο� �����Ѵٸ� ��� ����
			{
				Id_Flag = false;
				PasswordFlag = false;
				system("cls");
				cout << "���̵� �Է� : ";
				cin >> TmpId;
				cout << "��й�ȣ �Է� : ";
				cin >> TmpPassword;
				for (int i = 0; i < Id_Count; i++)//����� ����ŭ ����
				{
					if (TmpId == Id_List[i].Id) //���� ���̵� �߰��ϸ�
					{
						Id_Flag = true; //���̵� ã��
						if (TmpPassword == Id_List[i].Password)//�н�������� ���ٸ�
						{
							PasswordFlag = true; //�н����� ã��
							Display(&Id_List[i]);//�α��� �������� �Ѿ
							LoginFlag = true; //�α��� ����
							break; //�극��ũ
						}
					}
				}
				if (!Id_Flag)
					cout << "�ش� ���̵� �����ϴ�." << endl;
				else if (!PasswordFlag)
					cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
			}
			break;
		case 3:
			return;
		}
	}
}

