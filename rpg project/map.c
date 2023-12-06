#include "main.h"

/* 앞으로 나오는 함수들은 모두 https://blog.naver.com/ifthe1201/221056588399 링크에 있는 3번(메뉴를 선택하자!)을 인용함
   코드를 모듈화하기 위해서 아래와 같은 부분을 수정함
   1. while문으로 메뉴를 선택하는 함수는 "menu.h" 헤더파일에 따로 정의하여 코드가 간결해짐
   2. switch문으로 메뉴를 출력하는 부분에서 반복되는 문자열 부분을 함수로 정의하여 코드가 간결해짐
   3. pos의 개수가 많아질 수도 있기 때문에 if문을 사용하지 않고 switch문을 사용함 */

void Town()
{
	int key = 0; // 방향키 입력을 확인하기 위한 변수
	int pos = 0; // 0 - 이동하기, 1 - 인벤토리, 2 - 휴식하기
	char NameMenu[3][NAME_SIZE] = { "이동하기","상점가기","휴식하기" };

	numberMap = Loc_Town; // '돌아가기' 를 선택하였을 때, 이전 맵으로 돌아가기 위해 현재 맵의 넘버를 저장

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("현재 위치 : 마을");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk); // 플레이어의 스텟 UI를 불러옴

	setTown(); // Town 의 메뉴를 전부 출력하는 함수
	gotoxy(5, 10);
	selectMenu(NameMenu[pos]);

	while (1) // 메뉴 고르는 무한 while문
	{
		key = _getch();
		if (key == 13) // 엔터를 눌렀을 때
			break;

		pos = controlMenu(pos, 3); // pos 변수와 고를 수 있는 메뉴의 개수를 적음
		switch (pos)
		{
		case 0:
			setTown(); // Town 의 메뉴를 전부 출력하는 함수
			gotoxy(5, 10);
			selectMenu(NameMenu[pos]);
			break;

		case 1:
			setTown();
			gotoxy(5, 15);
			selectMenu(NameMenu[pos]);
			break;

		case 2:
			setTown();
			gotoxy(5, 20);
			selectMenu(NameMenu[pos]);
			break;
		default: break;
		}
		Sleep(100); // getch 함수가 입력받는 속도 제어
	}

	switch (pos)
	{
	case 0:
		system("cls");
		moveMap();
		break;
	case 1:
		inventory();
		break;
	case 2:
		gotoxy(30, 2);
		printf("휴식하는중");
		for (int i = 0; i < 3; i++)
		{
			Sleep(500);
			printf(".");
		}
		Sleep(500);
		gotoxy(30, 2);
		printf("             "); // 출력한 것을 지우기 위해 공백 출력

		Player.hp = 100;
		Player.mp = 30;
		Town();
		break;
	default: break;
	}
}

void moveMap()
{
	int key = 0; // 방향키 입력을 확인하기 위한 변수
	int pos = 0; // 0 - 어두운 숲, 1 - 고요한 동굴, 2 - 파괴된 유적, 3 - 돌아가기
	char NameMenu[4][NAME_SIZE] = { "어두운 숲","고요한 동굴","파괴된 유적","돌아가기" };

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("이동할 맵을 선택하세요..");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk); // 플레이어의 스텟 UI를 불러옴

	setmoveMap(); // Move 의 메뉴를 전부 출력하는 함수
	gotoxy(5, 10);
	selectMenu(NameMenu[pos]);

	while (1)
	{
		key = _getch();
		if (key == 13) // 엔터를 눌렀을 때
			break;

		pos = controlMenu(pos, 4); // pos 변수와 고를 수 있는 메뉴의 개수를 적음
		switch (pos)
		{
		case 0:
			setmoveMap();
			gotoxy(5, 10);
			selectMenu(NameMenu[pos]);
			break;

		case 1:
			setmoveMap();
			gotoxy(5, 15);
			selectMenu(NameMenu[pos]);
			break;

		case 2:
			setmoveMap();
			gotoxy(5, 20);
			selectMenu(NameMenu[pos]);
			break;
		case 3:
			setmoveMap();
			gotoxy(5, 25);
			selectMenu(NameMenu[pos]);
			break;
		default: break;
		}
		Sleep(100); // getch 함수가 입력받는 속도 제어
	}

	switch (pos)
	{
	case 0: // 어두운 숲
		system("cls");
		DarkForest();
		break;
	case 1: // 고요한 동굴
		system("cls");
		break;
	case 2: // 파괴된 유적
		system("cls");
		break;
	case 3: // 돌아가기
		system("cls");
		previousMap();
		break;
	default: break;
	}
}

void DarkForest()
{
	int key = 0; // 방향키 입력을 확인하기 위한 변수
	int pos = 0; // 0 - 탐색하기, 1 - 인벤토리, 2 - 마을로 돌아가기
	char NameMenu[3][NAME_SIZE] = { "탐험하기","인벤토리","마을로 돌아가기" };

	numberMap = Loc_DarkForest; // '돌아가기' 를 선택하였을 때, 이전 맵으로 돌아가기 위해 현재 맵의 넘버를 저장

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("현재 위치 : 어두운 숲");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk); // 플레이어의 스텟 UI를 불러옴

	setDarkForest(); // DarkForest 의 메뉴를 전부 출력하는 함수
	gotoxy(5, 10);
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
			setDarkForest();
			gotoxy(5, 10);
			selectMenu(NameMenu[pos]);
			break;

		case 1:
			setDarkForest();
			gotoxy(5, 15);
			selectMenu(NameMenu[pos]);
			break;

		case 2:
			setDarkForest();
			gotoxy(5, 20);
			selectMenu(NameMenu[pos]);
			break;
		default: break;
		}
		Sleep(100); // getch 함수가 입력받는 속도 제어
	}

	switch (pos)
	{
	case 0:
		gotoxy(30, 2);
		printf("탐험하는중");
		for (int i = 0; i < 2; i++)
		{
			Sleep(400);
			printf(".");
		}
		Sleep(400);
		gotoxy(30, 2);
		printf("            "); // 출력한 것을 지우기 위해 공백 출력

		srand((unsigned)time(NULL));

		if ((rand() % 100) <= 44) // 45% 확률로 돼지가 나옴
		{
			srand((unsigned)time(NULL));

			if ((rand() % 100) <= 69)
				battleScene(numberMap, Pig.name, Pig.hp, Pig.atk, Pig.mtk, "Normal");

			else if ((rand() % 100) <= 89)
				battleScene(numberMap, Pig.name, Pig.hp * 2, Pig.atk * 2, Pig.mtk * 2, "Hard");

			else
				battleScene(numberMap, Pig.name, Pig.hp * 3, Pig.atk * 3, Pig.mtk * 3, "Extreme");
		}
		else if ((rand() % 100) <= 79) // 35% 확률로 슬라임이 나옴
		{
			srand((unsigned)time(NULL));

			if ((rand() % 100) <= 69)
				battleScene(numberMap, Slime.name, Slime.hp, Slime.atk, Slime.mtk, "Normal");

			else if ((rand() % 100) <= 89)
				battleScene(numberMap, Slime.name, Slime.hp * 2, Slime.atk * 2, Slime.mtk * 2, "Hard");

			else
				battleScene(numberMap, Slime.name, Slime.hp * 3, Slime.atk * 3, Slime.mtk * 3, "Extreme");
		}
		else // 30% 확률로 고블린이 나옴
		{
			srand((unsigned)time(NULL));

			if ((rand() % 100) <= 69)
				battleScene(numberMap, Goblin.name, Goblin.hp, Goblin.atk, Goblin.mtk, "Normal");

			else if ((rand() % 100) <= 89)
				battleScene(numberMap, Goblin.name, Goblin.hp * 2, Goblin.atk * 2, Goblin.mtk * 2, "Hard");

			else
				battleScene(numberMap, Goblin.name, Goblin.hp * 3, Goblin.atk * 3, Goblin.mtk * 3, "Extreme");
		}
	case 1:
		system("cls");
		break;
	case 2:
		system("cls");
		Town();
		break;
	default: break;
	}
}

void previousMap() // 이전 맵으로 돌아가는 함수
{
	switch (numberMap) // 이전 맵의 번호를 확인하여 해당하는 넘버의 맵으로 돌아감
	{
	case 0:
		Town();
		break;
	case 1:
		DarkForest();
		break;
	default: break;
	}
}

void battleScene(int numberMap, char monsterName[NAME_SIZE], int monsterHp, int monsterAtk, int monsterMtk, char level[NAME_SIZE])
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

	gotoxy(30, 6);
	if (strcmp(level, "Normal") == 0)
		textcolor(WHITE);
	else if (strcmp(level, "Hard") == 0)
		textcolor(DarkRed);
	else
		textcolor(DarkPurple);
	printf("%s", level);
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

		if (Player.hp <= 0)
		{
			gotoxy(55, 2);
			textcolor(RED);
			printf("당신은 사망하였습니다..");
			Sleep(1000);

			system("cls");
			Town();
		}
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

void shop()
{

}