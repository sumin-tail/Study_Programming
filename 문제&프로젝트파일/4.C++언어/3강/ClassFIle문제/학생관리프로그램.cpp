#include"StudentManager.h" //학생 매니저 헤더 
#include<Windows.h>

// 특수 조건 *배열 대신에 컨테이너로 할것* > 학생 수 제한은 10명
//Student.h, Student.cpp, StudentManager.h, StudentManager.cpp, 학생관리프로그램.cpp 까지 합쳐서 하나의 프로그램(문제)임
//세이브나 빌드에서 제외할 경우 주의

//---------------------------//
//컨테이너-리스트 사용
//열거형 있는곳은 열거형사용하기(직관적임)
//디파인 쓸 수 있으면 쓰기

void main()
{
	int Select;
	StudentManager SManager;
	string strTmp; 
	bool bTmp;
	while (1)
	{
		system("cls");
		cout << "======학생관리 프로그램======" << endl;
		cout << "      1.학생 등록" << endl;
		cout << "      2.학생 목록<번호순>" << endl;
		cout << "      3.학생 목록<학년순>" << endl;
		cout << "      4.학생 검색" << endl;
		cout << "      5.학년 검색" << endl;
		cout << "      6.마지막 학생 삭제" << endl;
		cout << "      7.학생 전체 삭제" << endl;
		cout << "      8.종료" << endl;
		cout << "   (학생 수 : " << SManager.GetStudentCount() << ")" << endl;
		cout << "입력 : ";
		cin >> Select;
		system("cls");
		switch (Select)
		{
		case 1://학생등록
			SManager.AddStudent();
			break;
		case 2://학생목록<번호순>
			SManager.ShowStudentList();//학생전체출력
			break;
		case 3://학생목록<학년순>
			for (int i = CLASS_START; i < CLASS_END; i++)
			{
				bTmp = SManager.ShowClassList(i);
				if (bTmp == false)//false가 나올경우
					cout << i <<"학년 학생이 없습니다." << endl;
			}
			break;
		case 4://학생 검색
			cout << "이름 입력 : ";
			cin >> strTmp;
			bTmp = SManager.FindStudentName(strTmp);//이름 검색을 하고
			if (bTmp == false)//false가 나올경우
				cout << "해당 학생이 없습니다." << endl;
			break;
		case 5://학년 검색 
			cout << "학년 입력 : ";
			cin >> Select;
			bTmp = SManager.ShowClassList(Select);
			if (bTmp == false)//false가 나올경우
				cout << Select << "학년 학생이 없습니다." << endl;
			break;
		case 6://마지막 학생 삭제
			SManager.Delete();
			break;
		case 7://학생 전체 삭제
			SManager.Relese();
			break;
		case 8://종료
			return;
		default://다른 숫자들어왓을때는 그냥 재실행
			break;
		}
		system("pause");
	}
}
