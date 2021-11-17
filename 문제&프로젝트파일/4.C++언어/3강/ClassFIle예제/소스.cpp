#include"StudentManager.h" //학생 매니저 헤더 
#include<Windows.h>

//*배열 대신에 컨테이너로 할것*
//Student.h, Student.cpp, StudentManager.h, StudentManager.cpp, 학생관리프로그램.cpp 까지 합쳐서 하나의 프로그램(문제)임
//세이브나 빌드에서 제외할경우 주의

void main()
{
	int Select;
	StudentManager SManager;//
	string strTmp;
	bool bTmp;
	while (1)
	{
		system("cls");
		cout << "======학생관리 프로그램======" << endl;
		cout << "      1.학생 등록" << endl;
		cout << "      2.학생 목록" << endl;
		cout << "      3.학생 이름 검색" << endl;
		cout << "      4.종료" << endl;
		cout << "   (학생 수 : " << SManager.GetStudentCount() << ")" << endl;
		cout << "입력 : ";
		cin >> Select;
		system("cls");
		switch (Select)
		{
		case 1:
			SManager.AddStudent();//학생 추가
			break;
		case 2:
			SManager.ShowStudentList();//학생전체출력
			break;
		case 3:
			cout << "이름 입력 : ";
			cin >> strTmp;
			bTmp = SManager.FindStudentName(strTmp);//이름 검색을 하고
			if (bTmp == false)//false가 나올경우
				cout << "해당 학생이 없습니다." << endl;
			break;
		case 4:
			return;
		}
		system("pause");
	}
}
