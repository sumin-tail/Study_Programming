#include"Mecro.h"
#include"MapDraw.h"
#include"Map.h"
#include "Player.h"

void main()
{
	Map map; //맵 좌표와 크기 저장
	Player player;
	system("cls");
	map.MapDraw(); //맵 드로우
	player.PlayerStartDraw(map.StartPlayerX(), map.StartPlayerY()); //처음 플레이어 중앙 드로우
	char ctrl;
	//2)방향키 입력을 받으면 움직인다. + 맵 바깥으로는 나가지 못함 > 실제사이즈가 10 10 이라면 이동가능은 8 8
	while (true)
	{
		ctrl = _getch();
		switch (ctrl) //위 아래 왼쪽 오른쪽 순서
		{
		case 'W':
		case 'w':
			player.PlayerMove(0,-1, map);
			break;
		case 'S':
		case 's':
			player.PlayerMove(0, 1, map);
			break;
		case 'A':
		case 'a':
			player.PlayerMove(-2, 0, map); //특수문자라서 한번에 2칸씩
			break;
		case 'D':
		case 'd':
			player.PlayerMove(2, 0, map);
			break;
		default: //나머지 키입력은 패스
			break;
		}
	}

}