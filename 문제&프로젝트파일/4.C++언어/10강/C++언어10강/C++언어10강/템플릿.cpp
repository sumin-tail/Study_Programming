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

	cout << "���� �Է� : ";
	cin >> su1;
	cout << Plus(su1) << endl;
	cout << "�Ǽ� �Է� : ";
	cin >> fsu2;
	cout << Plus(fsu2) << endl;

	cout << "�� ���� �Է� : ";
	cin >> su1 >> su3;
	cout << "���� �� : " << Small(su1, su3) << endl;

	cout << "�� ���� �Է� : ";
	cin >> su1 >> su2 >>su3;
	cout << "ū �� : " << Big(su1,su2, su3) << endl;
}

