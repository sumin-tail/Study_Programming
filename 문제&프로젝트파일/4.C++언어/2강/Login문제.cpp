#include <iostream>
#include <string>
#include <list> 

//아직 함수화가 조금 부족함
//디파인 이용할 것
using namespace std;

//-회원정보는 구조체 자료형으로 만들고 맴버변수는 아이디, 비밀번호, 닉네임, 나이, 휴대폰번호, 마일리지
//- 최대 회원가입 수는 10명(컨테이너 관리)
//- 로그인 후 회원정보 변경 기능 

typedef struct Profile
{
	string id; //아이디
	string password; //비밀번호
	string nickname; //닉네임
	int age; //나이
	string phone_number;//휴대폰 번호
	int mileage; //마일리지
}Profile;

//함수 존
void MainMenu(int mamberNum);//메인메뉴
void Menu();//메뉴
string ID_Check(list<Profile> profileList); //아이디 체크
string Password_Check(); //패스워드 체크
Profile NewMember(list<Profile> profileList); //회원가입
void Login(list<Profile>* profileList);//로그인
void ProfileRead(list<Profile>::iterator iter); //회원정보 출력
void ProfileRetouch(list<Profile>::iterator iter);//회원정보 수정
void LoginPage(list<Profile>::iterator iter);//로그인 페이지
//

void MainMenu(int mamberNum)//메인메뉴
{
	cout <<"====Login====<회원수[" << mamberNum <<"명]>" << endl;
	cout <<"1.회원 가입" << endl;
	cout <<"2.로그인" << endl;
	cout <<"3.종료" << endl;
	cout <<"====================" << endl;
	cout << "입력 : ";
}

void Menu()//메뉴
{
	cout << "====Menu====" << endl;
	cout << "1.회원 정보" << endl;
	cout << "2.회원 정보 변경" << endl;
	cout << "3.로그아웃" << endl;
	cout << "====================" << endl;
	cout << "입력 : ";
}

string ID_Check(list<Profile> profileList) //아이디 체크
{
	//- 아이디 3글자 이상 영문과 숫자만 가능, 동일한 아이디 생성 불가능
	string data;

	while (true)
	{
		bool wordcheck = true;
		bool lengthcheck = true;
		bool samecheck = true;
		system("cls");
		cout << "아이디 입력<[3글자 이상] [한글 X] : ";
		cin >> data;
		for (int i = 0; i < (int)data.length(); i++)
		{
			//소문자, 대문자 확인
			if (!(('a' <= data[i] && data[i] <= 'z') || ('A' <= data[i] && data[i] <= 'Z') || ('0' <= data[i] && data[i] <= '9')))
			{
				wordcheck = false;
				cout << "id가 영문이 아닙니다." <<endl;
				break;
			}
		}

		if (data.length() < 3)
		{
			lengthcheck = false;
			cout << "id가 세글자 이하 입니다." << endl;
		}

		for (list<Profile>::iterator iter = profileList.begin(); iter != profileList.end(); iter++)
		{
			if (iter->id == data)//이름같은지 체크
			{
				samecheck = false;
				cout << "동일한 아이디가 존재 합니다." << endl;
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

string Password_Check() //패스워드 체크
{
	//- 비밀번호 8글자 이상 숫자 필수 포함 영문만 가능
	string data;
	string samedata;

	while (true)
	{
		bool numdercheck = false;
		bool wordcheck = true;
		bool lengthcheck = true;
		system("cls");
		cout << "비밀번호 입력<[8글자 이상] [숫자 필수] [영문 O] : ";
		cin >> data;
		cout << "비밀번호 확인 : ";
		cin >> samedata;

		for (int i = 0; i < (int)data.length(); i++)
		{
			//숫자있는지 확인 -> 하나라도 있으면 그 뒤로는 체크안함
			if ('0' <= data[i] && data[i] <= '9'&& numdercheck == false)
			{
				numdercheck = true;
			}
			//소문자, 대문자  = 숫자도 패스 시켜야함
			if (!(('a' <= data[i] && data[i] <= 'z') || ('A' <= data[i] && data[i] <= 'Z') || ('0' <= data[i] && data[i] <= '9')))
			{
				wordcheck = false;
				cout << "password가 영문이 아닙니다." << endl;
				break;
			}
		}

		if (!numdercheck) //다 돌았는데도 숫자가 없다면
		{
			cout << "숫자가 포함되어 있지 않습니다." << endl;
		}

		if (data.length() < 8)
		{
			lengthcheck = false;
			cout << "password가 여덟글자 이하 입니다." << endl;
		}

		if (numdercheck&&wordcheck&&lengthcheck)
		{
			return data;
		}

		system("pause");
	}

	//-> 틀렸을 경우
	//password가 여덟글자 이하 입니다.
	//숫자가 포함되어 있지 않습니다.
	//비밀번호가 일치하지 않습니다.
	return data;
}

Profile NewMember(list<Profile> profileList) //회원가입
{
	Profile newM;

	newM.id = ID_Check(profileList);
	newM.password = Password_Check();

	system("cls");
	cout << "닉네임 입력 : ";
	cin >> newM.nickname;

	cout << "나이 입력 : ";
	cin >> newM.age;

	cout << "휴대폰 번호 입력 : ";
	cin >> newM.phone_number;

	newM.mileage = 1000;
	cout << "회원 가입 성공!! 마일리지 1000원 등록" << endl;

	return newM;
}

void Login(list<Profile> *profileList)//로그인
{
	string id;
	string password;
	list<Profile>::iterator iter;
	while (true)
	{
		system("cls");
		bool idcheck = false;
		bool passwordcheck = false;

		cout << "아이디 입력 : ";
		cin >> id;

		cout << "비밀번호 입력 : ";
		cin >> password;

		for (iter = profileList->begin(); iter != profileList->end(); iter++)
		{
			if (iter->id == id)//이름같은지 체크
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
			cout << "해당 아이디가 없습니다." << endl;
		}
		else if (idcheck && passwordcheck == false)
		{
			cout << "비밀번호가 틀렸습니다." << endl;
		}
		else if (idcheck&&passwordcheck)
		{
			return;
		}
		system("pause");

	}
	//-> 틀렸을 경우
	//해당 아이디가 없습니다.
	//비밀번호가 틀렸습니다.
}

void ProfileRead(list<Profile>::iterator iter) //회원정보 출력
{
	cout << "===============회원 정보===============" << endl;
	cout << "ID : " << iter->id << "	" << "닉네임 : " << iter->nickname << endl;
	cout << "나이 : " << iter->age << "살	" << "휴대폰 번호 : " << iter->phone_number << endl;
	cout << "마일리지 : " << iter->mileage<<"원" << endl;
	cout << "==============================" << endl;
}

void ProfileRetouch(list<Profile>::iterator iter)//회원정보 수정
{
	int select;
	string data;
	while (1)
	{
		system("cls");
		ProfileRead(iter);

		cout << "1.닉네임 변경" << endl;
		cout << "2.나이 변경" << endl;
		cout << "3.휴대폰 번호 변경" << endl;
		cout << "4.돌아가기" << endl;
		cout << "입력 : ";
		cin >> select;

		switch (select)
		{
		case 1: //닉네임 변경
			cout << "현재 닉네임 : " << iter->nickname << endl;
			cout << "변경할 닉네임 입력 : ";
			cin >> data;
			cout << iter->nickname << " -> "<< data << endl;
			iter->nickname = data;
			system("pause");
			break;
		case 2: //나이 변경
			cout << "현재 나이 : " << iter->age << endl;
			cout << "변경할 나이 입력 : ";
			cin >> select;
			cout << iter->age << " -> " << select << endl;
			iter->age = select;
			system("pause");
			break;
		case 3: //휴대폰 번호 변경
			cout << "현재 휴대폰 번호 : " << iter->phone_number << endl;
			cout << "변경할 휴대폰 번호 입력 : ";
			cin >> data;
			cout << iter->phone_number << " -> " << data << endl;
			iter->phone_number = data;
			system("pause");
			break;
		case 4: //돌아가기
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
		case 1: //회원 정보
			system("cls");
			ProfileRead(iter);
			system("pause");
			break;
		case 2: //회원 정보 변경
			ProfileRetouch(iter);
			break;
		case 3: //로그아웃
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
		case 1: //회원 가입
			system("cls");
			if (mamberNum < 10)
			{
				profileList.push_back(NewMember(profileList));
				mamberNum++;
			}
			else
			{
				cout << "더이상 회원을 등록할 수 없습니다." << endl;
			}
			system("pause");
			break;
		case 2: //로그인
			system("cls");
			Login(&profileList);
			break;
		case 3: //종료
			return;
		default:
			break;
		}
	}
}