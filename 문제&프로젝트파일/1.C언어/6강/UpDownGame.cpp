#include<stdio.h>
#include<Windows.h>//system("cls"),system("pause")
#include<time.h>//�ð� �� ����ϴ� �������

void main()
{
	//�õ尪
	srand((unsigned)time(NULL));
	//���ÿ� ����ϴ� ����
	int Select;

	int	start_range = 1;
	int	end_range = 100;
	int turn = 10;

	//��ǻ�Ͱ� ���� ���� �� 
	int RNum;
	//�÷��̾ �Է��� ��
	int playerNum;

	while (1)
	{
		system("cls");
		printf("=========UpDwon=========\n");
		printf("      1.���ӽ���\n");
		printf("      2.��������\n");
		printf("      3.����\n");
		printf("�Է� : ");
		scanf("%d", &Select);

		switch (Select)
		{
		case 1:
			// ���� ���۰��� 5 �� ������ 10 �̶�� 5~10�� ���;� ��
			// (���� - ���۰�)+1  + ���۰�
			// ������ ���� �׷� 0~5 �� ���� �ű⿡ ���۰� ���ϸ� 5,6,7,8,9,10  ���ϴ� ���� ����
			RNum = (rand() % ((end_range-start_range)+1)) + start_range; //���� �� ����

			for (int turncount = 1; turncount <= turn; turncount++)
			{
				system("cls");
				printf("���� : %d ~ %d\n", start_range, end_range);
				printf("���� Turn : %d\n", turn);
				printf("========%d��========\n", turncount);
				printf("�Է� : ");
				scanf("%d", &playerNum);
				//�Է��� ���� ������ ��� 
				if (playerNum == RNum)
				{
					system("cls");
					printf("����!!  �� �� : %d",turncount);
					system("pause");
					break;
				} //������ �ƴ϶�� Up �Ǵ� Down �� �������־�� ��
				else if (playerNum < RNum)
				{
					printf("Up!!");
					system("pause");
				}
				else if (playerNum > RNum)
				{
					printf("Down!!");
					system("pause");
				}
				//��� ���� �Ҹ��������
				if (turncount == turn)
				{
					system("cls");
					printf("GameOver : Turn �� �ʰ�!!");
					system("pause");
				}
			}
			break;
		case 2:
			while (1)
			{
				system("cls");
				printf("========���� ����========\n");
				printf("  1.�ִ�,�ּҹ��� ����\n");
				printf("  2.�ִ� Turn�� ����\n");
				printf("  3.���ư���\n");;
				printf("�Է� : ");
				scanf("%d", &Select);
				switch (Select)
				{
				case 1:
					int start_range_st;
					int end_range_st;
					do {
						system("cls");
						printf("<���� : %d>�ּ� �� ���� : ", start_range);
						scanf("%d", &start_range_st);
						printf("<���� : %d>�ִ� �� ���� : ", end_range);
						scanf("%d", &end_range_st);
						if (start_range_st < end_range_st)
						{
							start_range = start_range_st;
							end_range = end_range_st;
							break;
						}
						printf("���� : �ּҰ��� �ִ밪���� Ů�ϴ� �ٽ��Է��ϼ���.");
						system("pause");
					} while(start_range_st >= end_range_st);
					break;
				case 2:
					int turn_st;
					do 
					{
						system("cls");
						printf("<���� : %d>�ִ� Turn �� ���� : ", turn);
						scanf("%d", &turn_st);
						if (turn_st > 0)
						{
							turn = turn_st;
							break;
						}
						printf("���� : �ִ� �� ���� 0���� �۰ų� �����ϴ� �ٽ��Է��ϼ���.");
						system("pause");
					} while (turn_st <= 0);

					break;
				}
				if (Select == 3) 
				{
					break;
				}
			}
			break;
		case 3:
			return;
		}
	}
}


