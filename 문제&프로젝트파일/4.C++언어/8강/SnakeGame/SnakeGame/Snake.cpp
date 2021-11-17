#include "Snake.h"
#include "Block.h"

Snake::Snake()
{
	snakeMakeTime = clock(); //������� �ð� ���
	length = 1; //������
	speed = DEFAULT_SPEED; //�ӵ� 
    MakeBody(WIDTH*0.5f, HEIGHT*0.5f); //�Ӹ� �߰�
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
			switch (key) { //�Է¹��� Ű�� �ľ��ϰ� ����  
			case DIRECTION_LEFT:
			case DIRECTION_RIGHT:
			case DIRECTION_UP:
			case DIRECTION_DOWN: //180ȸ���̵��� ���� �����ϰ�� ���������δ� �̵����� �ʾƾ� �� - ���� ���¿��� ù �Է� �޾����� ����
				if ((direction == DIRECTION_LEFT && key != DIRECTION_RIGHT) || (direction == DIRECTION_RIGHT && key != DIRECTION_LEFT) ||
				    (direction == DIRECTION_UP && key != DIRECTION_DOWN) || (direction == DIRECTION_DOWN && key != DIRECTION_UP) || direction == DIRECTION_STOP)
				{
					direction = key; //����������쿡 ���� �ٲ�
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
	//��ǥ�� �����ִ��� üũ
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
	//�������� ������
	snakeTail.x = snakePosList.back().x;
	snakeTail.y = snakePosList.back().y;

	blockManager.ErasePoint(snakePosList.back().x, snakePosList.back().y); //�������� ���� 
	//������ǥ�� ��ĭ�� �ű� 
    for (int i = length - 1; i > 0; i--)
	{
		snakePosList[i].x = snakePosList[i - 1].x;//�տ� �ִ� ��ǥ�� �ڷ� �ű�
		snakePosList[i].y = snakePosList[i - 1].y;
    }

	if (length != 1)
	{
		blockManager.DrawSnakeBody(snakePosList.front()); //�Ӹ��� �ִ����� �������� ��ħ
	}
    if (direction == DIRECTION_LEFT) 
		snakePosList.front().x--; //���⿡ ���� ���ο� �Ӹ���ǥ�� ���� 
	if (direction == DIRECTION_RIGHT) 
		snakePosList.front().x++;
    if (direction == DIRECTION_UP) 
		snakePosList.front().y--;
    if (direction == DIRECTION_DOWN) 
		snakePosList.front().y++;
	blockManager.DrawSnakeHead(snakePosList.front());//���ο� �Ӹ���ǥ���� �Ӹ��� �׸� 

}

//������̴þ
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