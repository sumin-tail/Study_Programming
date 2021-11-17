#include "Snake.h"
#include "Block.h"

Snake::Snake()
{
	snakeMakeTime = clock(); //만들어진 시간 기억
	length = 1; //몸길이
	speed = DEFAULT_SPEED; //속도 
    MakeBody(WIDTH*0.5f, HEIGHT*0.5f); //머리 추가
	direction = 0;
}

void Snake::MakeBody(int x, int y)
{
    Pos add(x,y);
    snakePosList.push_back(add);
}

void Snake::SnakeMoveCheck()
{
	char key;

	if (_kbhit())
	{
		if (key = _getch())
		{
			switch (key) { //입력받은 키를 파악하고 실행  
			case DIRECTION_LEFT:
			case DIRECTION_RIGHT:
			case DIRECTION_UP:
			case DIRECTION_DOWN: //180회전이동을 방지 왼쪽일경우 오른쪽으로는 이동하지 않아야 함 - 정지 상태에서 첫 입력 받았을때 포함
				if ((direction == DIRECTION_LEFT && key != DIRECTION_RIGHT) || (direction == DIRECTION_RIGHT && key != DIRECTION_LEFT) ||
				    (direction == DIRECTION_UP && key != DIRECTION_DOWN) || (direction == DIRECTION_DOWN && key != DIRECTION_UP) || direction == DIRECTION_STOP)
				{
					direction = key; //충족했을경우에 방향 바꿈
				}
				break;
			default:
				break;
			}
		}
	}

	if (clock() - snakeMakeTime >= speed)
	{
		Move();
		snakeMakeTime = clock();
	}
}

bool Snake::SnakeBodyCheck(int x, int y)
{
	//좌표에 뱀이있는지 체크
	for (int i = 1; i < length; i++)
	{
		if (snakePosList[i].x == x && snakePosList[i].y == y)
		{
			return true;
		}
	}
	return false;
}

void Snake::Move()
{
	//꼬리뒤쪽 저장함
	snakeTail.x = snakePosList.back().x;
	snakeTail.y = snakePosList.back().y;

	blockManager.ErasePoint(snakePosList.back().x, snakePosList.back().y); //마지막을 지움 
	//몸통좌표를 한칸씩 옮김 
    for (int i = length - 1; i > 0; i--)
	{
		snakePosList[i].x = snakePosList[i - 1].x;//앞에 있는 좌표를 뒤로 옮김
		snakePosList[i].y = snakePosList[i - 1].y;
    }

	if (length != 1)
	{
		blockManager.DrawSnakeBody(snakePosList.front()); //머리가 있던곳을 몸통으로 고침
	}
    if (direction == DIRECTION_LEFT) 
		snakePosList.front().x--; //방향에 따라 새로운 머리좌표값 변경 
	if (direction == DIRECTION_RIGHT) 
		snakePosList.front().x++;
    if (direction == DIRECTION_UP) 
		snakePosList.front().y--;
    if (direction == DIRECTION_DOWN) 
		snakePosList.front().y++;
	blockManager.DrawSnakeHead(snakePosList.front());//새로운 머리좌표값에 머리를 그림 

}

//몸통길이늘어남
void Snake::EatFood()
{
	MakeBody(snakeTail.x, snakeTail.y);
	blockManager.DrawSnakeBody(snakePosList.back());
	length++;
}

void Snake::SetSpeed()
{
	if (speed > 10)
	{
		speed -= 10;
	}
}

void  Snake::PrintSnakeStart()
{
	blockManager.DrawSnakeHead(snakePosList.front());
}


Pos Snake::GetSnakeHead()
{
	return snakePosList.front();
}