#include <stdio.h>

//�ݺ����� ����ϴ� �ִ� ����� ���ϱ�
int One(int num1, int num2)
{
	//�⺻������ �� ���� �������� �������� 0�̵Ǵ� ����� ã�ƾ���
	for (int i = 2; i <= num1 && i <= num2; i++)
	{
		if (num1%i == 0 && num2 % i == 0) //���� ���� ����� ã������
		{
			//���� ���� �־ �ٽ� �Լ� ȣ��...
			return i * One(num1 / i, num2 / i);
		}		
	}
	//�� ���� ���μҰ� �ȴٸ�...
	return 1;
}


//�ݺ��� ���� �ִ� ����� ���ϱ�
//�Լ��� �Ű������� �ΰ��� �ʿ�� ����.
int Two(int num1, int num2, int max)
{
	if (max<= num1 && max<=num2)
	{
		if (num1 % max == 0 && num2 % max == 0)
		{
			return max * Two(num1/max, num2/max, max);
		}
		//�ȳ�������
		return Two(num1, num2, max + 1);
	}

	return 1;
}

//����Լ� �ִ����� ���ϱ�
//�� �ڿ����� ����� ��� �� ���� ū ��
//��� � ���� ������ �������� ���� �������� ��
//�� ���� ���� ���μҰ� �� ������ ���� > �� ���� ���ڵ�(���)�� ���� ����
void main()
{
	int num1, num2;
	int max = 2;
	printf("ù��° ���� �Է� : ");
	scanf("%d", &num1);

	printf("�ι�° ���� �Է� : ");
	scanf("%d", &num2);

	//printf("�� ���� �ִ����� :%d", One(num1, num2));
	printf("�� ���� �ִ����� :%d", Two(num1, num2, max));
}
