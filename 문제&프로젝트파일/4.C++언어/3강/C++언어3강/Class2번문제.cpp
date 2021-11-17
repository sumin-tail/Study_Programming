#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

#define MIN 1

typedef class Square
{
private:
	int width; //����
	int length; //����
public:
	void SetLen(int _width, int _length);
	void Print();
	void check();
}Square;

void Square::check()
{
	int width;
	int length;
	while (1)
	{
		cout << "���� �Է� :";
		cin >> width;
		cout << "���� �Է� :";
		cin >> length;

		if (width < MIN || length < MIN)
		{
			cout << "���� �Ǵ� ���ΰ� 1���� �۽��ϴ�." << endl;
		}
		else
		{
			SetLen(width, length);
			return;
		}
		system("pause");
	}

}

void Square::SetLen(int _width, int _length)
{
	width = _width;
	length = _length;
}

void Square::Print()
{
	for (int i = MIN; i <= length; i++)//����
	{
		for (int j = MIN; j <= width; j++)//����
		{
			if (i == MIN && j == MIN) //(1,1)
			{
				cout << "��";
			}
			else if(i == MIN && j == width) //(1, end)
			{
				cout << "��" ;
			}
			else if (i == length && j == MIN)//(end, 1)
			{
				cout << "��" ;
			}
			else if (i == length && j == width)//(end,end)
			{
				cout << "��" ;
			}
			else if ((i == MIN || i == length) && j>MIN) //(1, ?) ,(end, ?)
			{
				cout << "��";
			}
			else if ((j == MIN || j == width)&& i>MIN) //(?, 1) ,(?, end)
			{
				cout << "��";
			}
			else
			{
				printf(" ");
			}
		}
		cout <<" "<< endl;
	}
}

void main()
{
	Square s1;
	s1.check();
	s1.Print();
}
