#include<stdio.h>
#include<Windows.h>//system("cls"),system("pause")
#include<time.h>//시간 값 사용하는 헤더파일

void main()
{
	//시드값
	srand((unsigned)time(NULL));
	//선택에 사용하는 변수
	int Select;

	int	start_range = 1;
	int	end_range = 100;
	int turn = 10;

	//컴퓨터가 뽑은 랜덤 값 
	int RNum;
	//플레이어가 입력한 값
	int playerNum;

	while (1)
	{
		system("cls");
		printf("=========UpDwon=========\n");
		printf("      1.게임시작\n");
		printf("      2.범위설정\n");
		printf("      3.종료\n");
		printf("입력 : ");
		scanf("%d", &Select);

		switch (Select)
		{
		case 1:
			// 만약 시작값이 5 고 끝값이 10 이라면 5~10이 나와야 함
			// (끝값 - 시작값)+1  + 시작값
			// 나머지 값은 그럼 0~5 가 나옴 거기에 시작값 더하면 5,6,7,8,9,10  원하는 값이 나옴
			RNum = (rand() % ((end_range-start_range)+1)) + start_range; //랜덤 수 결정

			for (int turncount = 1; turncount <= turn; turncount++)
			{
				system("cls");
				printf("범위 : %d ~ %d\n", start_range, end_range);
				printf("제한 Turn : %d\n", turn);
				printf("========%d턴========\n", turncount);
				printf("입력 : ");
				scanf("%d", &playerNum);
				//입력한 값이 정답일 경우 
				if (playerNum == RNum)
				{
					system("cls");
					printf("정답!!  턴 수 : %d",turncount);
					system("pause");
					break;
				} //정답이 아니라면 Up 또는 Down 을 가르쳐주어야 함
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
				//모든 턴을 소모했을경우
				if (turncount == turn)
				{
					system("cls");
					printf("GameOver : Turn 수 초과!!");
					system("pause");
				}
			}
			break;
		case 2:
			while (1)
			{
				system("cls");
				printf("========게임 설정========\n");
				printf("  1.최대,최소범위 설정\n");
				printf("  2.최대 Turn수 설정\n");
				printf("  3.돌아가기\n");;
				printf("입력 : ");
				scanf("%d", &Select);
				switch (Select)
				{
				case 1:
					int start_range_st;
					int end_range_st;
					do {
						system("cls");
						printf("<현재 : %d>최소 값 변경 : ", start_range);
						scanf("%d", &start_range_st);
						printf("<현재 : %d>최대 값 변경 : ", end_range);
						scanf("%d", &end_range_st);
						if (start_range_st < end_range_st)
						{
							start_range = start_range_st;
							end_range = end_range_st;
							break;
						}
						printf("오류 : 최소값이 최대값보다 큽니다 다시입력하세요.");
						system("pause");
					} while(start_range_st >= end_range_st);
					break;
				case 2:
					int turn_st;
					do 
					{
						system("cls");
						printf("<현재 : %d>최대 Turn 값 변경 : ", turn);
						scanf("%d", &turn_st);
						if (turn_st > 0)
						{
							turn = turn_st;
							break;
						}
						printf("오류 : 최대 턴 수가 0보다 작거나 같습니다 다시입력하세요.");
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


