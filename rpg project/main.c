#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

void inventory()
{
	gotoxy(25, 5);
}

void rest()
{
	printf("휴식하기");
}

int main()
{
	// 플레이어의 초기 스텟 초기화
	Player.hp = 100;
	Player.mp = 100;
	Player.atk = 5;
	Player.mtk = 8;

	SetConsole();

	Town();

	system("pause");
	return 0;
}