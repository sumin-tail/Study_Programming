#include<stdio.h>
#include<stack> //스택
//라이브러리 사용하는 법

//스택
void Stack_Ex()
{
	std::stack<int> iStack;
	//데이터 넣기
	for (int i = 1; i <= 10; i++)
	{
		iStack.push(i);
		printf("Top : %d\n", iStack.top());
	}
	//사이즈
	printf("Size : %d\n", iStack.size());
	//데이터 빼기
	while (!iStack.empty())//empty는 데이터가 남아있지 않을때 참을 반환함
	{
		printf("Top : %d\n", iStack.top());
		iStack.pop();
	}
}

void Stack_Menu()
{
	printf("====Stack System====\n");
	printf("1.Push\n");
	printf("2.Pop\n");
	printf("3.Exit\n");
	printf("====================\n");
	printf("입력 : ");
}

void main() 
{
	std::stack<int> iStack;
	int select;
	int num;
	while (1)
	{
		system("cls");
		Stack_Menu();
		scanf("%d", &select);

		switch (select)
		{
		case 1:
			printf("데이터 입력 : ");
			scanf("%d", &num);
			iStack.push(num);
			break;
		case 2:
			if (iStack.empty())
			{
				printf("삭제할 데이터가 없습니다\n");
			}
			else
			{
				printf("Pop : %d\n", iStack.top());
				iStack.pop();
			}
			system("pause");
			break;
		case 3: //라이브러리는 알아서 할당 해제 해줌
			printf("할당 해제 완료");
			return;
		}
	}
}