#include"StudentManager.h" //�л� �Ŵ��� ��� 
#include<Windows.h>

//*�迭 ��ſ� �����̳ʷ� �Ұ�*
//Student.h, Student.cpp, StudentManager.h, StudentManager.cpp, �л��������α׷�.cpp ���� ���ļ� �ϳ��� ���α׷�(����)��
//���̺곪 ���忡�� �����Ұ�� ����

void main()
{
	int Select;
	StudentManager SManager;//
	string strTmp;
	bool bTmp;
	while (1)
	{
		system("cls");
		cout << "======�л����� ���α׷�======" << endl;
		cout << "      1.�л� ���" << endl;
		cout << "      2.�л� ���" << endl;
		cout << "      3.�л� �̸� �˻�" << endl;
		cout << "      4.����" << endl;
		cout << "   (�л� �� : " << SManager.GetStudentCount() << ")" << endl;
		cout << "�Է� : ";
		cin >> Select;
		system("cls");
		switch (Select)
		{
		case 1:
			SManager.AddStudent();//�л� �߰�
			break;
		case 2:
			SManager.ShowStudentList();//�л���ü���
			break;
		case 3:
			cout << "�̸� �Է� : ";
			cin >> strTmp;
			bTmp = SManager.FindStudentName(strTmp);//�̸� �˻��� �ϰ�
			if (bTmp == false)//false�� ���ð��
				cout << "�ش� �л��� �����ϴ�." << endl;
			break;
		case 4:
			return;
		}
		system("pause");
	}
}
