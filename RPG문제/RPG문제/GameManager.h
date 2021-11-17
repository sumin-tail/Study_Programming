#pragma once
#include "Mecro.h"
#include "Character.h"
#include "MapDraw.h"
#include "Shop.h"

//������ �����ΰ� enum Ȱ���ϱ�!! 
//����� Ȱ���ϱ� ����- �������� �� Ȱ���ϸ� �ɵ�
//���� �̸� �� ����
class GameManager
{
private:
	//���� �Ŵ����� ���������� ������- �÷��̾� ,����,����,�ʵ�ο�
	//�÷��̾�� ���Ͱ� �������ִ� �������� ���� = ���� ���� Ŭ������ ���� �������� �ʰ� �÷��̾� Ŭ������ Ȱ���ϴ� ������� ->�÷��̾� Ŭ�������ٴ� ĳ���� Ŭ������
	Character* m_Player; //�÷��̾�
	Character* m_Monster; //����
	Shop m_Shop; //����
	MapDraw m_MapDrawManager; //��ο츦 ���� ����

	//--�ٸ������� ���� ���� ���� �Լ���--
	void Menu(); //�޴�
	void GameSetting(STARTTYPE type); //���Ӽ��� - New ���� Load ���� üũ�ؼ� ����
	void PlayerSetting(); //�÷��̾� ����
	void SaveFileList(); //������ ���� ����Ʈ ���
protected:
public:
	void MainMenu(); //����(����) �޴�
};

