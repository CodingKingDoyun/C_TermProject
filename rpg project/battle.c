#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

void battleScene(int numberMap, char monsterName[NAME_SIZE], int monsterHp, int monsterAtk, int monsterMtk, int r)
{
	int pos = 0; // 0 - 공격하기, 1 - 주문 시전, 2 - 도망가기
	char NameMenu[3][NAME_SIZE] = { "공격하기","주문시전","도망가기" };
	
	// 현재 맵의 메뉴를 출력함
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

	// 위험레벨 출력함
	gotoxy(30, 6);
	textcolor(WHITE);
	printf("Hazard Level : ");

	if (r <= 39)
		textcolor(GREEN);
	else if (r <= 69)
		textcolor(DarkYellow);
	else
		textcolor(DarkRed);

	printf("%d%%", r);
	textcolor(WHITE);

	// 몬스터의 스텟을 출력함
	gotoxy(30, 2);
	textcolor(RED);
	printf("%s", monsterName);

	gotoxy(30, 3);
	textcolor(GREEN);
	printf("HP : %d", monsterHp);

	gotoxy(30, 4);
	textcolor(DarkRed);
	printf("ATK : %d", monsterAtk);

	gotoxy(30, 5);
	textcolor(SkyBlue);
	printf("MTK : %d", monsterMtk);
	textcolor(WHITE);


	while (monsterHp > 0)
	{
		int key = 0; // 방향키 입력을 확인하기 위한 변수

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
			monsterHp -= Player.atk;

			if (monsterHp > 0)
			{
				Player.hp -= monsterAtk;
			}

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

		// 행동 후 변경된 몬스터의 스텟을 출력함
		gotoxy(30, 3);
		textcolor(GREEN);
		printf("           ");
		gotoxy(30, 3);
		printf("HP : %d", monsterHp);

		gotoxy(30, 4);
		textcolor(DarkRed);
		printf("           ");
		gotoxy(30, 4);
		printf("ATK : %d", monsterAtk);

		gotoxy(30, 5);
		textcolor(SkyBlue);
		printf("           ");
		gotoxy(30, 5);
		printf("MTK : %d", monsterMtk);

		textcolor(WHITE);

		playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk); // 플레이어의 스텟 UI를 불러옴
	}

	gotoxy(55, 2);
	textcolor(YELLOW);
	printf("몬스터를 처치하였습니다!");
	Sleep(1000);

	system("cls");

	switch (numberMap)
	{
	case 0:
		break;
	case 1:
		DarkForest();
	default: break;
	}
}