#pragma once
#include"Mecro.h"
//맵 드로우 클래스
class MapDraw
{
public:
	static void BoxDraw(int Start_x, int Start_y, int Width, int Height) //상자를 그리는 함수
	{
		for (int y = 0; y < Height; y++) //y는 0 이고 세로보다 작다
		{
			gotoxy(Start_x, Start_y + y); //그릴 좌표로 이동
			if (y == 0) //맨 첫번째줄일경우 ┌─────┐ < 의 형태여야함
			{
				cout << "┌";
				for (int x = 1; x < Width - 1; x++)
					cout << "―";//괘선문자 ─ 에서 문장부호 ― 로 바꿈 < 비슷해보이는데 길이차이남
				cout << "┐ ";
			}
			else if (y == Height - 1) //맨 마지막 줄일경우
			{
				cout << "└";
				for (int x = 1; x < Width - 1; x++)
					cout << "―";
				cout << "┘";
			}
			else //둘다 아닐경우
			{
				cout << "│";
				for (int x = 1; x < Width - 1; x++)
					cout << "  ";
				cout << "│ ";
			}
		}
		return;
	}
	static void DrawPoint(string str, int x, int y)
	{
		gotoxy(x * 2, y);
		cout << str; //텍스트 출력
		gotoxy(-1, -1);//커서를 왜 다시 -1, -1 로? 화면상에서 안보이게하려고.
		return;
	}
	static void DrawMidText(string str, int x, int y) //텍스트를 가운데에 출력하는 함수
	{
		if (x > str.size() / 2) //만약에 현재 가로 위치가 출력할 글자의 사이즈 절반보다 높다면 
			x -= str.size() / 2; //출력할 글자의 사이즈만큼 빼준다.
		gotoxy(x, y);//좌표이동하고
		cout << str; //텍스트 출력
		return;
	}
	static void TextDraw(string str, int x, int y)//글자 출력
	{
		gotoxy(x, y); //해당좌표로 이동
		cout << str; //글자출력
	}
	static void ErasePoint(int x, int y)// 지움
	{
		gotoxy(x * 2, y);//해당좌표로 이동
		cout << "  "; //지움(해당 좌표에있는 것에 "  "재출력해서 없앰)
		gotoxy(-1, -1); //좌표복귀
		return;
	}
	MapDraw() {}
	static inline void gotoxy(int x, int y) //스태틱 멤버 함수면서 인라인 함수 
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);//해당 좌표로 이동
	}
	~MapDraw() {}
};

