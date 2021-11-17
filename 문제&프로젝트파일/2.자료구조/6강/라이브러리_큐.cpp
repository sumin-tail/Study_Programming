#include<stdio.h>
#include<queue> //큐
//라이브러리 사용하는 법

//큐
void Queue_Ex()
{
	std::queue<int> iQueue;

	for (int i = 1; i <= 10; i++)
	{
		iQueue.push(i);
		printf("Front : %d\t Rear : %d\n", iQueue.front(), iQueue.back());
	}

	printf("Size : %d\n", iQueue.size());

	while (!iQueue.empty())//empty는 데이터가 남아있지 않을때 참을 반환함
	{
		printf("Front : %d\t Rear : %d\n", iQueue.front(), iQueue.back());
		iQueue.pop();
	}
}
void Queue_Menu()
{
	printf("====Queue System====\n");
	printf("1.Enqueue\n");
	printf("2.Dequeue\n");
	printf("3.Exit\n");
	printf("====================\n");
	printf("입력 : ");
}

void main()
{
	std::queue<int> iQueue;
	int select;
	int num;
	while (1)
	{
		system("cls");
		Queue_Menu();
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("데이터 입력 : ");
			scanf("%d", &num);
			iQueue.push(num);
			printf("Front : %d\t Rear : %d\n", iQueue.front(), iQueue.back());
			system("pause");
			break;
		case 2:
			if (iQueue.empty())
			{
				printf("삭제할 데이터가 없습니다\n");
			}
			else
			{
				printf("Front : %d\t Rear : %d\n", iQueue.front(), iQueue.back());
				iQueue.pop();
			}
			system("pause");
			break;
		case 3: //라이브러리는 알아서 할당 해제 해줌
			printf("할당 해제 완료");
			return;
		}
	}
}