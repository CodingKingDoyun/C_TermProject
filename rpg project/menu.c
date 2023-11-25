#include "main.h"

void playerStatsUI(int Player_hp, int Player_mp, int Player_atk, int Player_mtk)
{
	gotoxy(5, 3);
	textcolor(GREEN);
	printf("HP : %d", Player_hp);

	gotoxy(5, 4);
	textcolor(BLUE);
	printf("MP : %d", Player_mp);

	gotoxy(5, 5);
	textcolor(DarkRed);
	printf("ATK : %d", Player_atk);

	gotoxy(5, 6);
	textcolor(SkyBlue);
	printf("MTK : %d", Player_mtk);

	textcolor(WHITE);
}

int controlMenu(int numberPos, int numberMenu) // 메뉴를 방향키로 조작하는 함수
{
	int pos = numberPos;
	int key = 0;

	if (key = 224)
		key = _getch();

	if (key == 72) // 방향키 위를 눌렀을 때
		if (pos == 0) pos = numberMenu - 1;
		else pos -= 1;

	else if (key == 80) // 방향키 아래를 눌렀을 때
		if (pos == numberMenu - 1) pos = 0;
		else pos += 1;

	return pos;
}

void selectMenu(char NameMenu[]) // 선택한 메뉴를 표시해주는 함수
{
	textcolor(GREEN);
	printf("> %s", NameMenu);
	textcolor(WHITE);
}

void setTown() // Town 의 메뉴를 전부 출력하는 함수
{
	int NumberMenu = 0;
	char NameMenu[3][NAME_SIZE] = { "이동하기","인벤토리","휴식하기" };

	gotoxy(5, 10);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(5, 15);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(5, 20);
	printf(" %s", NameMenu[NumberMenu++]);
}

void setmoveMap() // Move 의 메뉴를 전부 출력하는 함수
{
	int NumberMenu = 0;
	char NameMenu[4][NAME_SIZE] = { "어두운 숲","고요한 동굴","파괴된 유적","돌아가기" };

	gotoxy(5, 10);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(5, 15);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(5, 20);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(5, 25);
	printf(" %s", NameMenu[NumberMenu++]);
}

void setDarkForest() // DarkForest 의 메뉴를 전부 출력하는 함수
{
	int NumberMenu = 0;
	char NameMenu[3][NAME_SIZE] = { "탐색하기","인벤토리","마을로 돌아가기" };

	gotoxy(5, 10);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(5, 15);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(5, 20);
	printf(" %s", NameMenu[NumberMenu++]);
}

void setBattleScene() // BattleScene 의 메뉴를 전부 출력하는 함수
{
	int NumberMenu = 0;
	char NameMenu[3][NAME_SIZE] = { "공격하기","주문시전","도망가기" };

	gotoxy(30, 10);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(30, 15);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(30, 20);
	printf(" %s", NameMenu[NumberMenu++]);
}