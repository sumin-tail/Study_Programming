#include"StudentManager.h" //�л� �Ŵ��� ��� 
#include<Windows.h>

// Ư�� ���� *�迭 ��ſ� �����̳ʷ� �Ұ�* > �л� �� ������ 10��
//Student.h, Student.cpp, StudentManager.h, StudentManager.cpp, �л��������α׷�.cpp ���� ���ļ� �ϳ��� ���α׷�(����)��
//���̺곪 ���忡�� ������ ��� ����

//---------------------------//
//�����̳�-����Ʈ ���
//������ �ִ°��� ����������ϱ�(��������)
//������ �� �� ������ ����

void main()
{
	int Select;
	StudentManager SManager;
	string strTmp; 
	bool bTmp;
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
		case 1://�л����
			SManager.AddStudent();
			break;
		case 2://�л����<��ȣ��>
			SManager.ShowStudentList();//�л���ü���
			break;
		case 3://�л����<�г��>
			for (int i = CLASS_START; i < CLASS_END; i++)
			{
				bTmp = SManager.ShowClassList(i);
				if (bTmp == false)//false�� ���ð��
					cout << i <<"�г� �л��� �����ϴ�." << endl;
			}
			break;
		case 4://�л� �˻�
			cout << "�̸� �Է� : ";
			cin >> strTmp;
			bTmp = SManager.FindStudentName(strTmp);//�̸� �˻��� �ϰ�
			if (bTmp == false)//false�� ���ð��
				cout << "�ش� �л��� �����ϴ�." << endl;
			break;
		case 5://�г� �˻� 
			cout << "�г� �Է� : ";
			cin >> Select;
			bTmp = SManager.ShowClassList(Select);
			if (bTmp == false)//false�� ���ð��
				cout << Select << "�г� �л��� �����ϴ�." << endl;
			break;
		case 6://������ �л� ����
			SManager.Delete();
			break;
		case 7://�л� ��ü ����
			SManager.Relese();
			break;
		case 8://����
			return;
		default://�ٸ� ���ڵ��������� �׳� �����
			break;
		}
		system("pause");
	}
}
