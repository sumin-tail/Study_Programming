#include <iostream>
using namespace std;

template <typename Type>
Type Plus(Type n1)
{
	return ++n1;
}

template <typename Type>
Type Small(Type n1, Type n2)
{
	//return (n1 > n2) ? n2 : n1;
	if (n1 > n2)
	{
		return n2;
	}
	else
	{
		return n1;
	}
}

template <typename Type>
Type Big(Type n1, Type n2, Type n3)
{
	if (n1>= n2 && n1>=n3)
	{
		return	n1;
	}
	else if(n2 >= n1 && n2 >= n3)
	{
		return	n2;
	}
	else
	{
		return n3;
	}
}

void main()
{
	int su1,su2,su3;
	float fsu2;

	cout << "정수 입력 : ";
	cin >> su1;
	cout << Plus(su1) << endl;
	cout << "실수 입력 : ";
	cin >> fsu2;
	cout << Plus(fsu2) << endl;

	cout << "두 정수 입력 : ";
	cin >> su1 >> su3;
	cout << "작은 값 : " << Small(su1, su3) << endl;

	cout << "세 정수 입력 : ";
	cin >> su1 >> su2 >>su3;
	cout << "큰 값 : " << Big(su1,su2, su3) << endl;
}

