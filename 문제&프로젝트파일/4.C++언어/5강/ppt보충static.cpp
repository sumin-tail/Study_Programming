#include <iostream>
using namespace std;

class A
{
private:
	int Num;
public:
	//�׽�Ʈ ���ǻ� public ������ ������. ����ƽ �����̱� ������ ���Ⱑ ������ �ƴ�
	//�� ������ Ŭ������ ���̶�� ���� �˷��ִ� ��Ȱ
	static int count; 
	A()
	{
		Num = 10;
		cout << ++count << endl;
	}

	static void Print() //����ƽ �Լ��������� ����ƽ ������ ����� �����ϴ�.
	{
		cout << "count : " << count << endl;
		//cout << "Num : " << Num << endl;
	}
};
int A::count = 0; //count ����ƽ ������ ����� -> h���ϰ� cpp ������ cpp���������� ���� �Ѵ�.

void counter()
{
	static int count = 0; 
	cout << ++count << endl;
}

void main()
{
	for (int i = 0; i < 10; i++)
		counter();
	//count = 20; //����ƽ ������ ������ �����ϴ� ���� �������� ����� �����ϴ�.

	A a1;
	A a2;
	A::count = 10; 
	A a3;
	A a4;
	A a5;
	a5.Print();
	A::Print(); //Ŭ������ ����ƽ ����(�ۺ��̶��)�� �Լ��� Ŭ������ ��(����) �̱� ������ Ŭ������ ������ �����ϴ� 
	//ex) Ŭ�����̸�::����ƽ�Լ�(); < �� ����� ����
}
