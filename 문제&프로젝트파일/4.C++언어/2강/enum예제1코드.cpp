#include <iostream>
#include<Windows.h>
using namespace std;

enum PLAYER //플레이어
{
	PLAYER_START = 1, //스타트는 시작과 같게 하고
	PLAYER_ARCHER = 1,
	PLAYER_MAGICIAN,
	PLAYER_WARRIOR,
	PLAYER_END = PLAYER_WARRIOR //엔드는 마지막과 같게 했음
};

enum PLAYPATTERN //플레이어 턴에 할 행동
{
	PLAYPATTERN_ATTACK = 1,
	PLAYPATTERN_MOVE,
	PLAYPATTERN_DEFENCE
};

struct Player //플레이어 구조체
{
	PLAYER PlayerType;
	int Damage;
	int Speed;
	int Defend;
};

void Attack(Player p)
{
	switch (p.PlayerType)
	{
	case PLAYER_ARCHER:
		cout << "궁수가 원거리에서 화살공격!(데미지 :" << p.Damage << ")" << endl;
		break;
	case PLAYER_MAGICIAN:
		cout << "마법사가 원거리에서 마법공격!(데미지 :" << p.Damage << ")" << endl;
		break;
	case PLAYER_WARRIOR:
		cout << "전사가 근거리에서 근접공격!(데미지 :" << p.Damage << ")" << endl;
		break;
	}
}

void Defence(Player p)
{
	switch (p.PlayerType)
	{
	case PLAYER_ARCHER:
		cout << "궁수가 활집을 사용하여 방어(상쇄데미지 :" << p.Defend << ")" << endl;
		break;
	case PLAYER_MAGICIAN:
		cout << "마법사가 마법서를 사용하여 방어(상쇄데미지 :" << p.Defend << ")" << endl;
		break;
	case PLAYER_WARRIOR:
		cout << "전사가 방패를 사용하여 방어(상쇄데미지 :" << p.Defend << ")" << endl;
		break;
	}
}

void Move(Player p)
{
	switch (p.PlayerType)
	{
	case PLAYER_ARCHER:
		cout << "궁수가 점프하여 이동(이동속도 :" << p.Speed << ")" << endl;
		break;
	case PLAYER_MAGICIAN:
		cout << "마법사가 텔레포트하여 이동(이동속도 :" << p.Speed << ")" << endl;
		break;
	case PLAYER_WARRIOR:
		cout << "전사가 돌진하여 이동(이동속도 :" << p.Speed << ")" << endl;
		break;
	}
}

void main()
{
	Player player;
	int Choice;
	while (1)
	{
		system("cls");
		cout << "=====직업 선택=====" << endl;
		cout << "  1.궁수" << endl;
		cout << "  2.마법사" << endl;
		cout << "  3.전사" << endl;
		cout << "선택 : ";
		cin >> Choice;
		if (Choice >= PLAYER_START && Choice <= PLAYER_END)//만약 선택한 것이 PLAYER_START부터 PLAYER_END 사이라면 
		{
			player.PlayerType = (PLAYER)Choice; //형변환해서 넣어줌
			break;
		}
		cout << "직업을 잘못 선택 하셧습니다." << endl;
		system("pause");
	}
	switch (player.PlayerType) //플레이어 타입에 맞춰서 나머지 변수값 초기화
	{
	case PLAYER_ARCHER:
		player.Damage = 50;
		player.Defend = 10;
		player.Speed = 50;
		break;
	case PLAYER_MAGICIAN:
		player.Damage = 100;
		player.Defend = 5;
		player.Speed = 30;
		break;
	case PLAYER_WARRIOR:
		player.Damage = 30;
		player.Defend = 20;
		player.Speed = 20;
		break;
	}

	while (1)
	{
		system("cls");
		cout << "=====행동 선택=====" << endl;
		cout << "  1.공격" << endl;
		cout << "  2.이동" << endl;
		cout << "  3.방어" << endl;
		cout << "선택 : ";
		cin >> Choice;
		switch (Choice)
		{
		case PLAYPATTERN_ATTACK:
			Attack(player);
			break;
		case PLAYPATTERN_MOVE:
			Move(player);
			break;
		case PLAYPATTERN_DEFENCE:
			Defence(player);
			break;
		default:
			cout << "잘못 선택 하셧습니다." << endl;
			break;
		}
		system("pause");
	}
}