#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

void battleScene(int numberMap, char monsterName[NAME_SIZE], int monsterHp, int monsterAtk)
{
	int key = 0; // 방향키 입력을 확인하기 위한 변수
	int pos = 0; // 0 - 공격하기, 1 - 주문 시전, 2 - 도망가기
	char NameMenu[3][NAME_SIZE] = { "공격하기","주문시전","도망가기" };

	switch (numberMap)
	{
	case 0:
		break;
	case 1:
		setDarkForest();
	default: break;
	}

	setBattleScene(); // BattleScene 의 메뉴를 전부 출력하는 함수
	gotoxy(30, 10);
	selectMenu(NameMenu[pos]);
	while (1)
	{
		key = _getch();
		if (key == 13) // 엔터를 눌렀을 때
			break;

		pos = controlMenu(pos, 3); // pos 변수와 고를 수 있는 메뉴의 개수를 적음
		switch (pos)
		{
		case 0:
			setBattleScene();
			gotoxy(30, 10);
			selectMenu(NameMenu[pos]);
			break;

		case 1:
			setBattleScene();
			gotoxy(30, 15);
			selectMenu(NameMenu[pos]);
			break;

		case 2:
			setBattleScene();
			gotoxy(30, 20);
			selectMenu(NameMenu[pos]);
			break;
		default: break;
		}
		Sleep(100); // getch 함수가 입력받는 속도 제어
	}

	switch (pos)
	{
	case 0:
		
		break;
	case 1:

		break;
	case 2:
		system("cls");

		switch (numberMap)
		{
		case 0:
			break;
		case 1:
			DarkForest();
		default: break;
		}
	default: break;
	}
}