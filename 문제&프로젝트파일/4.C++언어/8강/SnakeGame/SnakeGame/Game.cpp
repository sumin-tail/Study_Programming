#include "Game.h"

Game::Game()
{
	score = 0;
}


//���ھ� ���
void Game::PrintScore()
{
	blockManager.DrawMidText("Score : ", WIDTH, HEIGHT + 2);
	cout << score;
}

//�޴� ���
void Game::Menu()
{
	char buf[256];
	sprintf_s(buf, "mode con: lines=%d cols=%d", HEIGHT + 5, (WIDTH * 2) + 1);
	system(buf);

	int select;
	while (true)
	{
		system("cls");
		blockManager.WallDraw();//���� ���� �׸���
		PrintScore();
		blockManager.DrawMidText("�� �� �� Snake Game �� �� ��", WIDTH, HEIGHT * 0.2f);
		blockManager.DrawMidText("1. ���� ����", WIDTH, HEIGHT * 0.3f);
		blockManager.DrawMidText("2. ���� ����", WIDTH, HEIGHT * 0.4f);
		blockManager.DrawMidText("���� : ", WIDTH, HEIGHT * 0.5f);
		cin >> select;
		switch (select)
		{
		case 1:	//���ӽ���
			PlaySetting();
			PlayGame();
			break;
		case 2: //���� ����
			return;
		default: //�̿��� ���� ������ �ٽ����
			GameOver();
			break;
		}
	}

}

//���� ���� �� ����
void Game::PlaySetting()
{
	system("cls");
	srand(time(NULL));
	score = DEFAULT_SCORE;
	PlayStartTime = clock();

	player = new Snake;
	player->PrintSnakeStart();

	blockManager.WallDraw();
	MakeWall();
	PrintScore();
}

//��üũ
bool Game::BlockCheck(list<Pos> blocklist, int x, int y)
{
	//�̹� ���ڸ��� ���������� true ��ȯ
	for (list<Pos>::iterator iter = blocklist.begin(); iter != blocklist.end(); iter++)
	{
		if (iter->x == x && iter->y == y)
		{
			return true;
		}
	}
	return false;
}

//����Ʈ ���� ����
void Game::ListErase(list<Pos> *blocklist, int x, int y)
{
	//�̹� ���ڸ��� ���������� true ��ȯ
	for (list<Pos>::iterator iter = blocklist->begin(); iter != blocklist->end(); iter++)
	{
		if (iter->x == x && iter->y == y)
		{
			blocklist->erase(iter);
			break;
		}
	}

}

//�� ����� �Լ�
void Game::MakeWall()
{
	for (int i = 0; i < MAX_WALL; i++)
	{
		while (true)
		{
			int x = rand() % (WIDTH - 2) + 1;
			int y = rand() % (HEIGHT - 2) + 1;

			if (!BlockCheck(wallList, x, y) || !(x == WIDTH * 0.5f && y== HEIGHT*0.5f))
			{
				Pos wall(x, y);
				wallList.push_back(wall);
				blockManager.DrawWall(wall);
				break;
			}
		}
	}
}

//������Ʈ �Լ�
void Game::Update()
{
	MakeFood();
	player->SnakeMoveCheck();
	SnakeFoodCheck();
}

void Game::MakeFood()
{
	//���� ���� �ð��� �Ǿ��� ���� ������ 10 �� ���϶��
	if (clock() - PlayStartTime >= MAKEFOOD && foodList.size() < 10)
	{
		while (true)
		{
			int x = rand() % (WIDTH - 2) + 1;
			int y = rand() % (HEIGHT - 2) + 1;
			if (!(BlockCheck(wallList, x, y) || BlockCheck(foodList, x, y) || player->SnakeBodyCheck(x, y)))
			{
				Pos food(x, y);
				foodList.push_back(food);
				blockManager.DrawFood(food);
				PlayStartTime = clock();
				break;
			}
		}

	}
}


//���� ����
void Game::PlayGame()
{
	while (!GameOverCheck())
	{
		Update();
	}
	GameOver();
}

//���ӿ���
void Game::GameOver()
{
	system("cls");
	//���ӿ��� ȭ�� ���
	blockManager.WallDraw();
	PrintScore();
	blockManager.DrawMidText("�� �� �� Game Over �� �� ��", WIDTH, HEIGHT * 0.5f);
	blockManager.DrawMidText("Continue : Space Bar", WIDTH, HEIGHT * 0.6f);

	char select;

	while (true)
	{
		select = _getch();
		switch (select)
		{
		case SPACEBAR:	//��Ƽ��
			ResetGame();
			return;
		default: //�����̽��ٰ� �ƴ� �ٸ��� ������ ��쿡�� ����
			break;
		}
	}
}

//���ӿ��� üũ
bool Game::GameOverCheck()
{
	//��Ӹ� ���� ������
	Pos check = player->GetSnakeHead();
	//�ܰ� ���� �΋Hħ ||���� �ε�ħ üũ || �÷��̾� �΋Hħ üũ
	if (check.x == 0 || check.x == WIDTH-1 || check.y == 0 || check.y == HEIGHT-1 || BlockCheck(wallList, check.x, check.y)|| player->SnakeBodyCheck(check.x, check.y))
	{
		return true;
	}
	return false;
}

//���� �Ծ����� Ȯ��
void Game::SnakeFoodCheck()
{
	//��Ӹ� ���� ������
	Pos check = player->GetSnakeHead();
	//���� ������ �Ծ��ٸ�
	if (BlockCheck(foodList, check.x, check.y))
	{
		ListErase(&foodList, check.x, check.y);
		score += 1;
		player->SetSpeed();
		PrintScore();
		player->EatFood();
	}
}

//���Ӹ���
void Game::ResetGame()
{
	score = 0; //���ھ� ����
	delete player; //�÷��̾� �Ҵ� ����
	wallList.clear(); //�� ����Ʈ �ʱ�ȭ
	foodList.clear(); //���� ����Ʈ �ʱ�ȭ
}