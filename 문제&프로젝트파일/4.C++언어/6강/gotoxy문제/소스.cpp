#include"Mecro.h"
#include"MapDraw.h"
#include"Map.h"
#include "Player.h"

void main()
{
	Map map; //�� ��ǥ�� ũ�� ����
	Player player;
	system("cls");
	map.MapDraw(); //�� ��ο�
	player.PlayerStartDraw(map.StartPlayerX(), map.StartPlayerY()); //ó�� �÷��̾� �߾� ��ο�
	char ctrl;
	//2)����Ű �Է��� ������ �����δ�. + �� �ٱ����δ� ������ ���� > ��������� 10 10 �̶�� �̵������� 8 8
	while (true)
	{
		ctrl = _getch();
		switch (ctrl) //�� �Ʒ� ���� ������ ����
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
			player.PlayerMove(-2, 0, map); //Ư�����ڶ� �ѹ��� 2ĭ��
			break;
		case 'D':
		case 'd':
			player.PlayerMove(2, 0, map);
			break;
		default: //������ Ű�Է��� �н�
			break;
		}
	}

}