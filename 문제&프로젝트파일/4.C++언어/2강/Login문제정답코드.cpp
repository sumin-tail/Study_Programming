#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//디파인 이용할것!!
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

void Menu(int Num)//메뉴
{
	system("cls");
	cout << "=====Login=====(회원수[" << Num << "명])" << endl;
	cout << "   1.회원 가입" << endl;
	cout << "   2.로그인" << endl;
	cout << "   3.종료" << endl;
	cout << "입력 : ";
}

//함수화
bool StringCheck(char Start, char End, char Check)//문자열 체크 시작문자와 마지막 문자 사이에 존재하는지 체크함(아스키코드)
{
	if (Check >= Start && Check <= End)
		return true;
	else return false;
}

void Join(ID* P1, int Id_Count, ID Id_List[])//회원가입
{
	bool EngCheck, CompareCheck, IDCheck;//영어체크 길이체크 중복 체크
	int CountNum = 0;
	string CheckPassword;//패스워드 확인
	while (1)
	{
		EngCheck = true;
		IDCheck = true;
		system("cls");
		cout << "아이디 입력([3글자↑] AND [한글X]) : ";
		cin >> P1->Id;

		for (int i = 0; i < P1->Id.length(); i++)//영어(숫자포함) 체크
		{
			if (StringCheck('A', 'Z', P1->Id[i]) == false && StringCheck('a', 'z', P1->Id[i]) == false && StringCheck('0', '9', P1->Id[i]) == false)
			{
				EngCheck = false;
				break;
			}
		}

		for (int i = 0; i < Id_Count; i++) //중복아이디체크 -현재 존재하는 사용자 수만큼 돌림
		{
			if (Id_List[i].Id == P1->Id)
				IDCheck = false;
		}

		if (!IDCheck)//동일한 아이디가 존재한다면
		{
			cout << "동일한 아이디가 존재합니다." << endl;
		}
		if (EngCheck && IDCheck && P1->Id.length() >= IDLEN)//만약 ID가 모든조건을 충족한다면 break
			break;
		if (!EngCheck)
			cout << "id가 영문이 아닙니다." << endl;
		if (P1->Id.length() < IDLEN)
			cout << "id가 세글자 이하 입니다." << endl;
		system("pause");
	}
	while (1)
	{
		EngCheck = true; //영문(숫자)확인
		CompareCheck = true;//중복체크
		system("cls");
		cout << "비밀번호 입력([8글자↑]AND[영문]AND[숫자 포함]) : ";
		cin >> P1->Password;
		CountNum = 0;
		for (int i = 0; i < P1->Password.length(); i++)
		{
			if (StringCheck('A', 'Z', P1->Password[i]) == false && StringCheck('a', 'z', P1->Password[i]) == false)//영문만 체크
			{
				if (P1->Password[i] >= '0' && P1->Password[i] <= '9')//만약 들어온것이 숫자라면
					CountNum++;//숫자 카운트해줌
				else
					EngCheck = false;
			}
		}
		cout << "비밀번호 확인 : ";
		cin >> CheckPassword;
		if (CheckPassword != P1->Password)//만약 패스워드가 같지 않다면
			CompareCheck = false;
		if (EngCheck && CompareCheck && P1->Password.length() >= PASSWORDLEN && CountNum >= 1)//패스워드 조건을 모두 충족할경우 break;
			break;
		if (!EngCheck)
			cout << "password가 영문이 아닙니다." << endl;
		if (P1->Password.length() < PASSWORDLEN)
			cout << "Password가 여덟글자 이하 입니다." << endl;
		if (CountNum == 0)
			cout << "숫자가 포함되어 있지 않습니다." << endl;
		if (!CompareCheck)
			cout << "비밀번호가 일치하지 않습니다." << endl;
		system("pause");
	}
	system("cls");
	cout << "닉네임 입력 : ";
	cin >> P1->Name;
	cout << "나이 입력 :";
	cin >> P1->Age;
	cout << "휴대폰 번호 입력 : ";
	cin >> P1->PhonNumber;
	cout << "회원가입 성공 !! 마일리지 1000원 등록" << endl;
	P1->Mileage = 1000;
	system("pause");
}

void SimpleShowID(ID id)
{
	cout << "============회원 정보============" << endl;
	cout << "ID : " << id.Id << "   닉네임 : " << id.Name << endl;
}

void ShowID(ID id)//회원정보
{
	system("cls");
	SimpleShowID(id);
	cout << " 나이 : " << id.Age << "살" << "   휴대폰 번호 : " << id.PhonNumber << endl;
	cout << "마일리지 : " << id.Mileage << "원" << endl;
}

//함수화
void Setstring(string* str, string tmp)//string 계열 데이터 변경 (변경할 데이터 주소 , 변경할 데이터의 이름(닉네임 등))
{
	string tmpstr;
	tmpstr = *str; //변경할 데이터를 tmpstr에 담고
	cout << "현재 " << tmp << ": " << tmpstr << endl;
	cout << "변경할 " << tmp << "입력 : ";
	cin >> *str; //원본에 바로 대입
	cout << tmpstr << " -> " << *str << endl; //변경 전 데이터 -> 변경 후 데이터
	system("pause");
}

//함수화
void Setint(int* num, string tmp)//int 계열 데이터 변경
{
	int tmpint;
	tmpint = *num;
	cout << "현재 " << tmp << " : " << tmpint << endl;
	cout << "변경할 " << tmp << "입력 : ";
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
		cout << "1.닉네임 변경" << endl;
		cout << "2.나이 변경" << endl;
		cout << "3.휴대폰 번호 변경" << endl;
		cout << "4.돌아가기" << endl;
		cout << "입력 : ";
		cin >> Select;
		switch (Select)
		{
		case 1:
			Setstring(&id->Name, "닉네임");
			break;
		case 2:
			Setint(&id->Age, "나이");
			break;
		case 3:
			Setstring(&id->PhonNumber, "휴대폰 번호");
			break;
		case 4:
			return;
		}
	}
}

void Display(ID* id)//로그인 화면
{
	int Select;
	while (1)
	{
		system("cls");
		cout << "========Menu========" << endl;
		cout << "  1.회원 정보" << endl;
		cout << "  2.회원 정보 변경" << endl;
		cout << "  3.로그아웃" << endl;
		cout << "입력 : ";
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
	int Id_Count = 0; //사용자 수
	ID Id_List[IDMAX]; //사용자 수 제한
	string TmpId, TmpPassword;//로그인 아이디, 패스워드 입력용
	int Select; //선택
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
				cout << "더이상 회원을 등록할 수 없습니다." << endl;
				system("pause");
				break;
			}
			Join(&Id_List[Id_Count], Id_Count, Id_List);
			Id_Count++;
			break;
		case 2:
			while (!LoginFlag)//로그인에 실패한다면 계속 돌림
			{
				Id_Flag = false;
				PasswordFlag = false;
				system("cls");
				cout << "아이디 입력 : ";
				cin >> TmpId;
				cout << "비밀번호 입력 : ";
				cin >> TmpPassword;
				for (int i = 0; i < Id_Count; i++)//사용자 수만큼 돌림
				{
					if (TmpId == Id_List[i].Id) //같은 아이디를 발견하면
					{
						Id_Flag = true; //아이디 찾음
						if (TmpPassword == Id_List[i].Password)//패스워드까지 같다면
						{
							PasswordFlag = true; //패스워드 찾음
							Display(&Id_List[i]);//로그인 페이지로 넘어감
							LoginFlag = true; //로그인 성공
							break; //브레이크
						}
					}
				}
				if (!Id_Flag)
					cout << "해당 아이디가 없습니다." << endl;
				else if (!PasswordFlag)
					cout << "비밀번호가 틀렸습니다." << endl;
			}
			break;
		case 3:
			return;
		}
	}
}

