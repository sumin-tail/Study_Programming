#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

//(main������ �ϳ��� �ɹ��Լ��� ����� ��)
//(��ǻ�� ������ �����ڿ��� �ʱ�ȭ)
//���� ȣ�� ��ɾ� = system("calc");
//�޸��� ȣ�� ��ɾ� = system("notepad");
//�׸��� ȣ�� ��ɾ� = system("mspaint");

//���� Ȱ���ϱ� *�����ؾ� �տ� �ʹ´�

enum POWER
{
	OFF,
	ON
};

class Computer
{
private:
	string name;
	POWER state;
	string graphics_card;
	string cpu;
	int memory;

public:
	//������
	Computer();
	//���۸޴�
	void Menu();
	void Play();
	//����
	void Stats();
	//���
	void Calc();
	void Notepad();
	void Mspaint();
	void End();
};

