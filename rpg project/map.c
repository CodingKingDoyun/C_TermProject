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
	char NameMenu[3][NAME_SIZE] = { "이동하기","인벤토리","휴식하기" };

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
		playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk);
		rest();
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
		Sleep(400);
		printf(".");
		Sleep(400);
		printf(".");
		Sleep(400);
		gotoxy(30, 2);
		printf("            ");

		srand(time(NULL));
		int r = rand() % 100;
		if (r <= 39) // 40% 확률로 돼지가 나옴
			battleScene(numberMap, Pig.name, Pig.hp, Pig.atk, Pig.mtk, r); // 돼지
		else if (r <= 69) // 30% 확률로 슬라임이 나옴
			battleScene(numberMap, Slime.name, Slime.hp, Slime.atk, Slime.mtk, r); // 슬라임
		else // 30% 확률로 고블린이 나옴
			battleScene(numberMap, Goblin.name, Goblin.hp, Goblin.atk, Goblin.mtk, r); // 고블린
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