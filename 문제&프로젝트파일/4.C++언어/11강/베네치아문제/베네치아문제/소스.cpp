#include "Mecro.h"
#include "Play.h"


//����� ����
//���ӽ��� ȭ�� �����->����̾߱� ��ũ�� �����->�ܾ� ����Ʈ����->�ܾ� ���߱�(��������)->Stage��� �����->Rank�ý��� �����
//->�����۱�� �߰�
void main()
{
	system("mode con: cols=130 lines=35"); //�ܼ�â ������ ����
	Play game;
	game.MainMenu();
}