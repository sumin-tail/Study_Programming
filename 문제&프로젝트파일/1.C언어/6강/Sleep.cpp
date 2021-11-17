#include<stdio.h>
#include<Windows.h>

void Draw(int Map[][10]);
void Update(int Map[][10]);

void main()
{
	//�� �迭�� 0 ���� �ʱ�ȭ
	int Map[10][10] = { 0 };
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			//�� �� �� ��ĭ���� 1�� �־���
			if (x == 9) 
			{
				Map[y][x] = 1;
			}
		}
	}
	while (1)
	{
		Draw(Map);
		//0.5 �� ���
		Sleep(500);
		Update(Map);
	}
}

void Draw(int Map[][10])
{
	//ȭ�� ����
	system("cls");
	//�迭 ���鼭 ���� 1 �ΰ�쿡 �� ��� 0�� ��쿡�� ����� ���
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (Map[y][x] == 1)
			{
				printf("��");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
}

void Update(int Map[][10])
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			//���� ���ٰ� ���� 1�� ������ ����ġ��
			if (Map[y][x] == 1)
			{
				//��ĭ�� ���� 0���� �ٲ���
				Map[y][x] = 0;
				//�׸��� X��° ĭ�� �� -1 �� 0 ���� ������� 
				//�ش� ���� �� ��ĭ�� �ٽú���(���� ���� ������)  
				if (x - 1 < 0) 
				{
					Map[y][9] = 1;
				}
				else//�ƴҰ�� ���� ��ġ�� ��ĭ������ 
				{
					Map[y][x-1] = 1;
				}
				break;
			}

		}
	}
}

//�׿� ��

//16���� 1�ڸ� = 2���� 4�ڸ�
//2 4 8 16
//16���� 2�ڸ�= 1����Ʈ
//�޸𸮴� 16���� 8�ڸ� == 4����Ʈ