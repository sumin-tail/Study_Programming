#include"StudentManager.h"
#include<Windows.h>

//Ŭ���� ���� ������ ������� �迭���� STL�� �̿��϶�� ������ ������ �ɾ���
//�׷��� �����ڵ�� ������ ���� �迭�� �̿��� ��
void main()
{
	int Select;
	StudentManager SManager;
	string strTmp;
	bool bTmp;
	int iTmp;
	while (1)
	{
		system("cls");
		cout << "======�л����� ���α׷�======" << endl;
		cout << "      1.�л� ���" << endl;
		cout << "      2.�л� ���<��ȣ��>" << endl;
		cout << "      3.�л� ���<�г��>" << endl;
		cout << "      4.�л� �˻�" << endl;
		cout << "      5.�г� �˻�" << endl;
		cout << "      6.������ �л� ����" << endl;
		cout << "      7.�л� ��ü ����" << endl;
		cout << "      8.����" << endl;
		cout << "   (�л� �� : " << SManager.GetStudentCount() << ")" << endl;
		cout << "�Է� : ";
		cin >> Select;
		system("cls");
		switch (Select)
		{
		case 1:
			SManager.AddStudent();
			break;
		case 2:
			SManager.ShowStudentList();
			break;
		case 3:
			for (int i = CLASS_START; i < CLASS_END; i++)
			{
				bTmp = SManager.ShowStudentClass((CLASS)i);
				if (!bTmp)
					cout << i << "�г� �л��� �����ϴ�." << endl;
			}
			break;
		case 4:
			cout << "�̸� �Է� : ";
			cin >> strTmp;
			bTmp = SManager.FindStudentName(strTmp);
			if (bTmp == false)
				cout << "�ش� �л��� �����ϴ�." << endl;
			break;
		case 5:
			cout << "�г� �Է� : ";
			cin >> iTmp;
			bTmp = SManager.ShowStudentClass((CLASS)iTmp);
			if (!bTmp)
				cout << iTmp << "�г� �л��� �����ϴ�." << endl;
			break;
		case 6:
			SManager.DeleteStudent();
			break;
		case 7:
			SManager.ClearStudent();
			break;
		case 8:
			SManager.ClearStudent();
			return;
		}
		system("pause");
	}
}