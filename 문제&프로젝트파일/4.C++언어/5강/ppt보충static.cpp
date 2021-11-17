#include <iostream>
using namespace std;

class A
{
private:
	int Num;
public:
	//테스트 편의상 public 구간에 적은것. 스태틱 변수이기 때문에 여기가 선언이 아님
	//이 변수가 클래스의 것이라는 것을 알려주는 역활
	static int count; 
	A()
	{
		Num = 10;
		cout << ++count << endl;
	}

	static void Print() //스태틱 함수내에서는 스태틱 변수만 사용이 가능하다.
	{
		cout << "count : " << count << endl;
		//cout << "Num : " << Num << endl;
	}
};
int A::count = 0; //count 스태틱 변수의 선언부 -> h파일과 cpp 파일중 cpp파일쪽으로 들어가야 한다.

void counter()
{
	static int count = 0; 
	cout << ++count << endl;
}

void main()
{
	for (int i = 0; i < 10; i++)
		counter();
	//count = 20; //스태틱 변수는 변수가 존재하는 공간 내에서만 사용이 가능하다.

	A a1;
	A a2;
	A::count = 10; 
	A a3;
	A a4;
	A a5;
	a5.Print();
	A::Print(); //클래스의 스태틱 변수(퍼블릭이라면)와 함수는 클래스의 것(공용) 이기 때문에 클래스로 접근이 가능하다 
	//ex) 클래스이름::스태틱함수(); < 로 사용이 가능
}
