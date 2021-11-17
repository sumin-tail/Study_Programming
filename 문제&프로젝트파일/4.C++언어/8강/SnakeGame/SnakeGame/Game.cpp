#include "Game.h"

Game::Game()
{
	score = 0;
}


//스코어 출력
void Game::PrintScore()
{
	blockManager.DrawMidText("Score : ", WIDTH, HEIGHT + 2);
	cout << score;
}

//메뉴 출력
void Game::Menu()
{
	char buf[256];
	sprintf_s(buf, "mode con: lines=%d cols=%d", HEIGHT + 5, (WIDTH * 2) + 1);
	system(buf);

	int select;
	while (true)
	{
		system("cls");
		blockManager.WallDraw();//벽을 먼저 그리고
		PrintScore();
		blockManager.DrawMidText("★ ☆ ★ Snake Game ★ ☆ ★", WIDTH, HEIGHT * 0.2f);
		blockManager.DrawMidText("1. 게임 시작", WIDTH, HEIGHT * 0.3f);
		blockManager.DrawMidText("2. 게임 종료", WIDTH, HEIGHT * 0.4f);
		blockManager.DrawMidText("선택 : ", WIDTH, HEIGHT * 0.5f);
		cin >> select;
		switch (select)
		{
		case 1:	//게임시작
			PlaySetting();
			PlayGame();
			break;
		case 2: //게임 종료
			return;
		default: //이외의 숫자 들어오면 다시출력
			GameOver();
			break;
		}
	}

}

//게임 시작 전 세팅
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

//블럭체크
bool Game::BlockCheck(list<Pos> blocklist, int x, int y)
{
	//이미 그자리에 블럭이있으면 true 반환
	for (list<Pos>::iterator iter = blocklist.begin(); iter != blocklist.end(); iter++)
	{
		if (iter->x == x && iter->y == y)
		{
			return true;
		}
	}
	return false;
}

//리스트 원소 제거
void Game::ListErase(list<Pos> *blocklist, int x, int y)
{
	//이미 그자리에 블럭이있으면 true 반환
	for (list<Pos>::iterator iter = blocklist->begin(); iter != blocklist->end(); iter++)
	{
		if (iter->x == x && iter->y == y)
		{
			blocklist->erase(iter);
			break;
		}
	}

}

//벽 만드는 함수
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

//업데이트 함수
void Game::Update()
{
	MakeFood();
	player->SnakeMoveCheck();
	SnakeFoodCheck();
}

void Game::MakeFood()
{
	//음식 만들 시간이 되었고 음식 갯수가 10 개 이하라면
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


//게임 시작
void Game::PlayGame()
{
	while (!GameOverCheck())
	{
		Update();
	}
	GameOver();
}

//게임오버
void Game::GameOver()
{
	system("cls");
	//게임오버 화면 출력
	blockManager.WallDraw();
	PrintScore();
	blockManager.DrawMidText("★ ☆ ★ Game Over ★ ☆ ★", WIDTH, HEIGHT * 0.5f);
	blockManager.DrawMidText("Continue : Space Bar", WIDTH, HEIGHT * 0.6f);

	char select;

	while (true)
	{
		select = _getch();
		switch (select)
		{
		case SPACEBAR:	//컨티뉴
			ResetGame();
			return;
		default: //스페이스바가 아닌 다른게 들어왔을 경우에는 무시
			break;
		}
	}
}

//게임오버 체크
bool Game::GameOverCheck()
{
	//뱀머리 정보 가져옴
	Pos check = player->GetSnakeHead();
	//외각 벽에 부딫침 ||벽에 부딪침 체크 || 플레이어 부딫침 체크
	if (check.x == 0 || check.x == WIDTH-1 || check.y == 0 || check.y == HEIGHT-1 || BlockCheck(wallList, check.x, check.y)|| player->SnakeBodyCheck(check.x, check.y))
	{
		return true;
	}
	return false;
}

//음식 먹었는지 확인
void Game::SnakeFoodCheck()
{
	//뱀머리 정보 가져옴
	Pos check = player->GetSnakeHead();
	//만약 음식을 먹었다면
	if (BlockCheck(foodList, check.x, check.y))
	{
		ListErase(&foodList, check.x, check.y);
		score += 1;
		player->SetSpeed();
		PrintScore();
		player->EatFood();
	}
}

//게임리셋
void Game::ResetGame()
{
	score = 0; //스코어 리셋
	delete player; //플레이어 할당 해제
	wallList.clear(); //벽 리스트 초기화
	foodList.clear(); //음식 리스트 초기화
}