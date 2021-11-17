#include"MapDraw.h"

MapDraw::MapDraw()
{

}

MapDraw::~MapDraw()
{

}

//바둑판 그리는 함수 (메인메뉴/게임 플레이)
void MapDraw::BoxDraw(int Width, int Height)
{
	for (int y = 0; y < Height; y++) //y는 0 이고 세로보다 작다
	{
		gotoxy(STARTPOS, STARTPOS + y); //그릴 좌표로 이동
		if (y == 0) //맨 첫번째줄일경우 ┌─────┐ < 의 형태여야함
		{
			cout << "┌";
			for (int x = 1; x < Width - 1; x++)
				cout << "┬";
			cout << "┐";
		}
		else if (y == Height - 1) //맨 마지막 줄일경우
		{
			cout << "└";
			for (int x = 1; x < Width - 1; x++)
				cout << "┴";
			cout << "┘";
		}
		else //둘다 아닐경우
		{
			cout << "├";
			for (int x = 1; x < Width - 1; x++)
				cout << "┼";
			cout << "┤";
		}
	}
	return;
}

//상자 그리는 함수(옵션)
void MapDraw::SettingDraw(int Width, int Height)
{
	for (int y = 0; y < Height; y++) //y는 0 이고 세로보다 작다
	{
		gotoxy(STARTPOS, STARTPOS + y); //그릴 좌표로 이동
		if (y == 0) //맨 첫번째줄일경우 ┌─────┐ < 의 형태여야함
		{
			cout << "┌";
			for (int x = 1; x < Width - 1; x++)
				cout << "─";
			cout << "┐";
		}
		else if (y == Height - 1) //맨 마지막 줄일경우
		{
			cout << "└";
			for (int x = 1; x < Width - 1; x++)
				cout << "─";
			cout << "┘";
		}
		else //둘다 아닐경우
		{
			cout << "│";
			for (int x = 1; x < Width - 1; x++)
				cout << "  ";
			cout << "│";
		}
	}
	return;
}

//작은 상자 그리는 함수(메뉴)
void MapDraw::SettingMenuDraw(int Width, int Height, int startY)
{
	for (int y = 0; y < Height; y++) //y는 0 이고 세로보다 작다
	{
		gotoxy(Width, startY + y); //그릴 좌표로 이동
		if (y == 0) //맨 첫번째줄일경우 ┌─────┐ < 의 형태여야함
		{
			cout << "┌";
			for (int x = 1; x < Width - 1; x++)
				cout << "─";
			cout << "┐";
		}
		else if (y == Height - 1) //맨 마지막 줄일경우
		{
			cout << "└";
			for (int x = 1; x < Width - 1; x++)
				cout << "─";
			cout << "┘";
		}
		else //둘다 아닐경우
		{
			cout << "│";
			for (int x = 1; x < Width - 1; x++)
				cout << "  ";
			cout << "│";
		}
	}
	return;
}

//게임플레이 바둑판 빈곳 채우기
void MapDraw::PlayingBoxEmpty(int Width, int Height, int x, int y)
{
	gotoxy(x, y);

	if (y == 0) //맨 첫번째줄일경우 ┌─────┐ < 의 형태여야함
	{
		if (x == 0)
		    cout << "┌";
		if (x < Width - 2)
			cout << "┬";
		if (x == Width - 2)
		    cout << "┐";
	}
	else if (y == Height - 1) //맨 마지막 줄일경우
	{
		if (x == 0)
		    cout << "└";
		if (x < Width - 2)
			cout << "┴";
		if (x == Width - 2)
			cout << "┘";
	}
	else //둘다 아닐경우
	{
		if (x == 0)
	      	cout << "├";
		if (x < Width - 2)
			cout << "┼";
		if (x == Width - 2)
		    cout << "┤";
	}
	return;
}

//벽 제외 클리어
void MapDraw::Erase(int Width, int Height)
{
	for (int y = 1; y < Height-1; y++) 
	{
		gotoxy(STARTPOS + 2, STARTPOS + y); //특수문자는 언제나 2칸
		for (int x = 1; x < Width-1; x++)
		{
			cout << "  ";
		}
	}
	return;
}

//특정 좌표 클리어
void MapDraw::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}

//중간에 텍스트 출력하는 함수
void MapDraw::DrawMidText(string str, int x, int y)
{
	//해당 글자수를 계산해서 중간에 출력 해야함
	//가로 사이즈 절반-출력 글자수 절반  = 글자 출력 시작 지점
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	return;
}

//텍스트 리스트 출력
void MapDraw::DrawMidTextList(const string str[], int x, int y, int len, float margin)
{
	int temp;
	margin -= ((len / 2) * 0.1f);
	for(int j = 0; j<len; j++, margin += 0.1f)
	{
		temp = x;
		if (temp > str[j].size() / 2)
			temp -= str[j].size() / 2;
		gotoxy(temp, y * margin);
		cout << str[j];

	}
}

void MapDraw::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}