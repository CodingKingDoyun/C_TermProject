#include "main.h"

void playerStatsUI(int Player_hp, int Player_mp, int Player_atk, int Player_mtk, double Player_gold)
{
	gotoxy(5, 2);
	textcolor(DarkYellow);
	printf("Traveler");

	gotoxy(5, 3);
	textcolor(GREEN);
	printf("           ");
	gotoxy(5, 3);
	printf("HP : %d", Player_hp);

	gotoxy(5, 4);
	textcolor(BLUE);
	printf("           ");
	gotoxy(5, 4);
	printf("MP : %d", Player_mp);

	gotoxy(5, 5);
	textcolor(DarkRed);
	printf("           ");
	gotoxy(5, 5);
	printf("ATK : %d", Player_atk);

	gotoxy(5, 6);
	textcolor(SkyBlue);
	printf("           ");
	gotoxy(5, 6);
	printf("MTK : %d", Player_mtk);

	gotoxy(5, 7);
	textcolor(YELLOW);
	printf("           ");
	gotoxy(5, 7);
	printf("GOLD : %.lf", Player_gold);

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

void selectMenu(char *NameMenu, int x, int y) // 선택한 메뉴를 표시해주는 함수
{
	gotoxy(x, y);
	textcolor(GREEN);
	printf("> %s", NameMenu);
	textcolor(WHITE);
}

void selectBuy(char *NameMenu, int price, int x, int y, int color) // 선택한 구매 메뉴를 표시해주는 함수
{
	textcolor(color);
	gotoxy(x, y);
	printf("> %s", NameMenu);
	gotoxy(x, y + 1);
	textcolor(YELLOW);
	printf("  %d Gold", price);
	textcolor(WHITE);
}

void selectBoughtSpell(char *NameMenu, int x, int y)
{
	gotoxy(x, y);
	textcolor(DarkGray);
	printf("> %s", NameMenu);
	gotoxy(x, y + 1);
	printf("  이미 습득한 주문입니다..");
}

void selectSpell(char* NameMenu, int needMp, int x, int y) // 선택한 사용 가능한 주문 메뉴를 표시해주는 함수
{
	textcolor(DarkRed);
	gotoxy(x, y);
	printf("> %s", NameMenu);
	gotoxy(x, y + 1);
	textcolor(SkyBlue);
	printf("  %d MP", needMp);
	textcolor(WHITE);
}

void selectNotUseSpell(char* NameMenu, int x, int y) // 선택한 사용 불가능한 주문 메뉴를 표시해주는 함수
{
	textcolor(DarkGray);
	gotoxy(x, y);
	printf("> %s", NameMenu);
	textcolor(WHITE);
}

void setTown() // Town 의 메뉴를 전부 출력하는 함수
{
	int NumberMenu = 0;
	char NameMenu[3][NAME_SIZE] = { "이동하기","상점가기","휴식하기" };

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("현재 위치 : 마을");

	gotoxy(5, 10);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 15);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 20);
	printf(" %s ", NameMenu[NumberMenu++]);
}

void setShop() // Shop 의 메뉴를 전부 출력하는 함수
{
	int NumberMenu = 0;
	char NameMenu[3][NAME_SIZE] = { "강화 물약 구매","주문 구매","마을로 돌아가기" };

	gotoxy(5, 10);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 15);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 20);
	printf(" %s ", NameMenu[NumberMenu++]);
}

void setbuyPotion()
{
	int NumberMenu = 0;
	char NameMenu[5][NAME_SIZE] = { "HP 강화 물약","MP 강화 물약","ATK 강화 물약","MTK 강화 물약","돌아가기" };
	int PotionPrice[5] = { 50,150,20,100 };

	gotoxy(30, 10);
	textcolor(GREEN);
	printf(" %s ", NameMenu[NumberMenu]);
	gotoxy(30, 11);
	textcolor(YELLOW);
	printf(" %d Gold  ", PotionPrice[NumberMenu++]);

	gotoxy(30, 15);
	textcolor(BLUE);
	printf(" %s ", NameMenu[NumberMenu]);
	gotoxy(30, 16);
	textcolor(YELLOW);
	printf(" %d Gold  ", PotionPrice[NumberMenu++]);

	gotoxy(30, 20);
	textcolor(DarkRed);
	printf(" %s ", NameMenu[NumberMenu]);
	gotoxy(30, 21);
	textcolor(YELLOW);
	printf(" %d Gold  ", PotionPrice[NumberMenu++]);

	gotoxy(30, 25);
	textcolor(SkyBlue);
	printf(" %s ", NameMenu[NumberMenu]);
	gotoxy(30, 26);
	textcolor(YELLOW);
	printf(" %d Gold  ", PotionPrice[NumberMenu++]);

	gotoxy(30, 30);
	textcolor(WHITE);
	printf(" %s ", NameMenu[NumberMenu]);
}

void setbuySpell()
{
	int NumberMenu = 0;
	char NameMenu[4][NAME_SIZE] = { "파이어 캐논","파이어 스톰","헬파이어","돌아가기" };
	int SpellPrice[4] = { 300,800,1600,3000 };

	if (FireCannon)
	{
		gotoxy(30, 10);
		textcolor(DarkGray);
		printf(" %s ", NameMenu[NumberMenu++]);
		gotoxy(30, 11);
		printf(" 이미 습득한 주문입니다..  ");
	}
	else
	{
		gotoxy(30, 10);
		textcolor(RED);
		printf(" %s ", NameMenu[NumberMenu]);
		gotoxy(30, 11);
		textcolor(YELLOW);
		printf(" %d Gold  ", SpellPrice[NumberMenu++]);
	}

	if (FireStorm)
	{
		gotoxy(30, 15);
		textcolor(DarkGray);
		printf(" %s ", NameMenu[NumberMenu++]);
		gotoxy(30, 16);
		printf(" 이미 습득한 주문입니다..  ");
	}
	else
	{
		gotoxy(30, 15);
		textcolor(RED);
		printf(" %s ", NameMenu[NumberMenu]);
		gotoxy(30, 16);
		textcolor(YELLOW);
		printf(" %d Gold  ", SpellPrice[NumberMenu++]);
	}

	if (HellFire)
	{
		gotoxy(30, 20);
		textcolor(DarkGray);
		printf(" %s ", NameMenu[NumberMenu++]);
		gotoxy(30, 21);
		printf(" 이미 습득한 주문입니다..  ");
	}
	else
	{
		gotoxy(30, 20);
		textcolor(RED);
		printf(" %s ", NameMenu[NumberMenu]);
		gotoxy(30, 21);
		textcolor(YELLOW);
		printf(" %d Gold  ", SpellPrice[NumberMenu++]);
	}

	gotoxy(30, 25);
	textcolor(WHITE);
	printf(" %s ", NameMenu[NumberMenu]);
}

void setmoveMap() // Move 의 메뉴를 전부 출력하는 함수
{
	int NumberMenu = 0;
	char NameMenu[4][NAME_SIZE] = { "어두운 숲","고요한 동굴","파괴된 유적","돌아가기" };

	gotoxy(5, 10);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 15);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 20);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 25);
	printf(" %s ", NameMenu[NumberMenu++]);
}

void setDarkForest() // DarkForest 의 메뉴를 전부 출력하는 함수
{
	int NumberMenu = 0;
	char NameMenu[2][NAME_SIZE] = { "탐험하기","마을로 돌아가기" };

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("현재 위치 : 어두운 숲");

	gotoxy(5, 10);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 15);
	printf(" %s ", NameMenu[NumberMenu++]);
}

void setSilentCave()
{
	int NumberMenu = 0;
	char NameMenu[2][NAME_SIZE] = { "탐험하기","마을로 돌아가기" };

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("현재 위치 : 고요한 동굴");

	gotoxy(5, 10);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 15);
	printf(" %s ", NameMenu[NumberMenu++]);
}

void setDestroyedRuins()
{
	int NumberMenu = 0;
	char NameMenu[2][NAME_SIZE] = { "탐험하기","마을로 돌아가기" };

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("현재 위치 : 파괴된 유적");

	gotoxy(5, 10);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 15);
	printf(" %s ", NameMenu[NumberMenu++]);
}

void setBattleScene() // BattleScene 의 메뉴를 전부 출력하는 함수
{
	int NumberMenu = 0;
	char NameMenu[3][NAME_SIZE] = { "공격하기","주문시전","도망가기" };

	gotoxy(30, 10);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(30, 15);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(30, 20);
	printf(" %s ", NameMenu[NumberMenu++]);
}

void setSpell()
{
	int NumberMenu = 0;
	char NameMenu[5][NAME_SIZE] = { "파이어 볼","파이어 캐논 (MTK x2)","파이어 스톰 (MTK x4)","헬파이어 (MTK x10)","돌아가기" };
	int needMp[4] = { 3,6,12,30 };

	// 파이어 볼
	gotoxy(55, 10);
	textcolor(DarkRed);
	printf(" %s  ", NameMenu[NumberMenu]);
	gotoxy(55, 11);
	textcolor(SkyBlue);
	printf(" %d MP  ", needMp[NumberMenu++]);

	// 파이어 캐논
	gotoxy(55, 15);
	if (FireCannon)
	{
		textcolor(DarkRed);
		printf(" %s ", NameMenu[NumberMenu]);
		gotoxy(55, 16);
		textcolor(SkyBlue);
		printf(" %d MP  ", needMp[NumberMenu++]);
	}
	else
	{
		textcolor(DarkGray);
		printf(" %s  ", NameMenu[NumberMenu++]);
	}

	// 파이어 스톰
	gotoxy(55, 20);
	if (FireStorm)
	{
		textcolor(DarkRed);
		printf(" %s  ", NameMenu[NumberMenu]);
		gotoxy(55, 21);
		textcolor(SkyBlue);
		printf(" %d MP  ", needMp[NumberMenu++]);
	}
	else
	{
		textcolor(DarkGray);
		printf(" %s  ", NameMenu[NumberMenu++]);
	}

	// 헬파이어
	gotoxy(55, 25);
	if (HellFire)
	{
		textcolor(DarkRed);
		printf(" %s  ", NameMenu[NumberMenu]);
		gotoxy(55, 26);
		textcolor(SkyBlue);
		printf(" %d MP  ", needMp[NumberMenu++]);
	}
	else
	{
		textcolor(DarkGray);
		printf(" %s  ", NameMenu[NumberMenu++]);
	}

	gotoxy(55, 30);
	textcolor(WHITE);
	printf(" %s ", NameMenu[NumberMenu++]);
}

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

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // 플레이어의 스텟 UI를 불러옴

	setTown(); // Town 의 메뉴를 전부 출력하는 함수
	selectMenu(NameMenu[pos], 5, 10);

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
			selectMenu(NameMenu[pos], 5, 10);
			break;

		case 1:
			setTown();
			selectMenu(NameMenu[pos], 5, 15);
			break;

		case 2:
			setTown();
			selectMenu(NameMenu[pos], 5, 20);
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
		shop();
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

		Player.hp = Player_maxHp;
		Player.mp = Player_maxMp;
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

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // 플레이어의 스텟 UI를 불러옴

	setmoveMap(); // Move 의 메뉴를 전부 출력하는 함수
	selectMenu(NameMenu[pos], 5, 10);

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
			selectMenu(NameMenu[pos], 5, 10);
			break;

		case 1:
			setmoveMap();
			selectMenu(NameMenu[pos], 5, 15);
			break;

		case 2:
			setmoveMap();
			selectMenu(NameMenu[pos], 5, 20);
			break;
		case 3:
			setmoveMap();
			selectMenu(NameMenu[pos], 5, 25);
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
		SilentCave();
		break;
	case 2: // 파괴된 유적
		system("cls");
		DestroyedRuins();
		break;
	case 3: // 돌아가기
		system("cls");
		Town();
		break;
	default: break;
	}
}

void DarkForest()
{
	int key = 0; // 방향키 입력을 확인하기 위한 변수
	int pos = 0; // 0 - 탐색하기, 1 - 마을로 돌아가기
	char NameMenu[2][NAME_SIZE] = { "탐험하기","마을로 돌아가기" };

	numberMap = Loc_DarkForest; // '돌아가기' 를 선택하였을 때, 이전 맵으로 돌아가기 위해 현재 맵의 넘버를 저장

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("현재 위치 : 어두운 숲");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // 플레이어의 스텟 UI를 불러옴

	setDarkForest(); // DarkForest 의 메뉴를 전부 출력하는 함수
	selectMenu(NameMenu[pos], 5, 10);

	while (1)
	{
		key = _getch();
		if (key == 13) // 엔터를 눌렀을 때
			break;

		pos = controlMenu(pos, 2); // pos 변수와 고를 수 있는 메뉴의 개수를 적음
		switch (pos)
		{
		case 0:
			setDarkForest();
			selectMenu(NameMenu[pos], 5, 10);
			break;

		case 1:
			setDarkForest();
			selectMenu(NameMenu[pos], 5, 15);
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

		if ((rand() % 100) + 1 + 1 <= 40) // 40% 확률로 돼지가 나옴
		{
			if ((rand() % 100) + 1 + 1 <= 50)
				battleScene(numberMap, Pig.name, Pig.hp, Pig.atk, Pig.mtk, Pig.gold, "Normal");

			else if ((rand() % 100) + 1 <= 80)
				battleScene(numberMap, Pig.name, Pig.hp * 2, Pig.atk * 2, Pig.mtk * 2, Pig.gold * 3, "Hard");

			else
				battleScene(numberMap, Pig.name, Pig.hp * 3, Pig.atk * 3, Pig.mtk * 3, Pig.gold * 5, "Extreme");
		}
		else if ((rand() % 100) + 1 <= 80) // 40% 확률로 슬라임이 나옴
		{
			if ((rand() % 100) + 1 <= 50)
				battleScene(numberMap, Slime.name, Slime.hp, Slime.atk, Slime.mtk, Slime.gold, "Normal");

			else if ((rand() % 100) + 1 <= 80)
				battleScene(numberMap, Slime.name, Slime.hp * 2, Slime.atk * 2, Slime.mtk * 2, Slime.gold * 3, "Hard");

			else
				battleScene(numberMap, Slime.name, Slime.hp * 3, Slime.atk * 3, Slime.mtk * 3, Slime.gold * 5, "Extreme");
		}
		else // 30% 확률로 고블린이 나옴
		{
			if ((rand() % 100) + 1 <= 50)
				battleScene(numberMap, Goblin.name, Goblin.hp, Goblin.atk, Goblin.mtk, Goblin.gold, "Normal");

			else if ((rand() % 100) + 1 <= 80)
				battleScene(numberMap, Goblin.name, Goblin.hp * 2, Goblin.atk * 2, Goblin.mtk * 2, Goblin.gold * 3, "Hard");

			else
				battleScene(numberMap, Goblin.name, Goblin.hp * 3, Goblin.atk * 3, Goblin.mtk * 3, Goblin.gold * 5, "Extreme");
		}
	case 1:
		system("cls");
		Town();
		break;
	default: break;
	}
}

void SilentCave()
{
	int key = 0; // 방향키 입력을 확인하기 위한 변수
	int pos = 0; // 0 - 탐색하기, 1 - 마을로 돌아가기
	char NameMenu[2][NAME_SIZE] = { "탐험하기","마을로 돌아가기" };

	numberMap = Loc_SilentCave; // '돌아가기' 를 선택하였을 때, 이전 맵으로 돌아가기 위해 현재 맵의 넘버를 저장

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("현재 위치 : 고요한 동굴");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // 플레이어의 스텟 UI를 불러옴

	setSilentCave(); // SilentCave 의 메뉴를 전부 출력하는 함수
	selectMenu(NameMenu[pos], 5, 10);

	while (1)
	{
		key = _getch();
		if (key == 13) // 엔터를 눌렀을 때
			break;

		pos = controlMenu(pos, 2); // pos 변수와 고를 수 있는 메뉴의 개수를 적음
		switch (pos)
		{
		case 0:
			setSilentCave();
			selectMenu(NameMenu[pos], 5, 10);
			break;

		case 1:
			setSilentCave();
			selectMenu(NameMenu[pos], 5, 15);
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

		if ((rand() % 100) + 1 + 1 <= 40) // 40% 확률로 박쥐가 나옴
		{
			if ((rand() % 100) + 1 + 1 <= 50)
				battleScene(numberMap, Bat.name, Bat.hp, Bat.atk, Bat.mtk, Bat.gold, "Normal");

			else if ((rand() % 100) + 1 <= 80)
				battleScene(numberMap, Bat.name, Bat.hp * 2, Bat.atk * 2, Bat.mtk * 2, Bat.gold * 3, "Hard");

			else
				battleScene(numberMap, Bat.name, Bat.hp * 3, Bat.atk * 3, Bat.mtk * 3, Bat.gold * 5, "Extreme");
		}
		else if ((rand() % 100) + 1 <= 80) // 40% 확률로 트롤이 나옴
		{
			if ((rand() % 100) + 1 <= 50)
				battleScene(numberMap, Troll.name, Troll.hp, Troll.atk, Troll.mtk, Troll.gold, "Normal");

			else if ((rand() % 100) + 1 <= 80)
				battleScene(numberMap, Troll.name, Troll.hp * 2, Troll.atk * 2, Troll.mtk * 2, Troll.gold * 3, "Hard");

			else
				battleScene(numberMap, Troll.name, Troll.hp * 3, Troll.atk * 3, Troll.mtk * 3, Troll.gold * 5, "Extreme");
		}
		else // 30% 확률로 데몬이 나옴
		{
			if ((rand() % 100) + 1 <= 50)
				battleScene(numberMap, Demon.name, Demon.hp, Demon.atk, Demon.mtk, Demon.gold, "Normal");

			else if ((rand() % 100) + 1 <= 80)
				battleScene(numberMap, Demon.name, Demon.hp * 2, Demon.atk * 2, Demon.mtk * 2, Demon.gold * 3, "Hard");

			else
				battleScene(numberMap, Demon.name, Demon.hp * 3, Demon.atk * 3, Demon.mtk * 3, Demon.gold * 5, "Extreme");
		}
	case 1:
		system("cls");
		Town();
		break;
	default: break;
	}
}

void DestroyedRuins()
{
	int key = 0; // 방향키 입력을 확인하기 위한 변수
	int pos = 0; // 0 - 탐색하기, 1 - 마을로 돌아가기
	char NameMenu[2][NAME_SIZE] = { "탐험하기","마을로 돌아가기" };

	numberMap = Loc_DestroyedRuins; // '돌아가기' 를 선택하였을 때, 이전 맵으로 돌아가기 위해 현재 맵의 넘버를 저장

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("현재 위치 : 파괴된 유적");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // 플레이어의 스텟 UI를 불러옴

	setDestroyedRuins(); // DestroyedRuins 의 메뉴를 전부 출력하는 함수
	selectMenu(NameMenu[pos], 5, 10);

	while (1)
	{
		key = _getch();
		if (key == 13) // 엔터를 눌렀을 때
			break;

		pos = controlMenu(pos, 2); // pos 변수와 고를 수 있는 메뉴의 개수를 적음
		switch (pos)
		{
		case 0:
			setDestroyedRuins();
			selectMenu(NameMenu[pos], 5, 10);
			break;

		case 1:
			setDestroyedRuins();
			selectMenu(NameMenu[pos], 5, 15);
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

		if ((rand() % 100) + 1 + 1 <= 40) // 40% 확률로 가디언이 나옴
		{
			if ((rand() % 100) + 1 + 1 <= 50)
				battleScene(numberMap, Guardian.name, Guardian.hp, Guardian.atk, Guardian.mtk, Guardian.gold, "Normal");

			else if ((rand() % 100) + 1 <= 80)
				battleScene(numberMap, Guardian.name, Guardian.hp * 2, Guardian.atk * 2, Guardian.mtk * 2, Guardian.gold * 3, "Hard");

			else
				battleScene(numberMap, Guardian.name, Guardian.hp * 3, Guardian.atk * 3, Guardian.mtk * 3, Guardian.gold * 5, "Extreme");
		}
		else if ((rand() % 100) + 1 <= 80) // 40% 확률로 살아있는 갑옷이 나옴
		{
			if ((rand() % 100) + 1 <= 50)
				battleScene(numberMap, Livingarmor.name, Livingarmor.hp, Livingarmor.atk, Livingarmor.mtk, Livingarmor.gold, "Normal");

			else if ((rand() % 100) + 1 <= 80)
				battleScene(numberMap, Livingarmor.name, Livingarmor.hp * 2, Livingarmor.atk * 2, Livingarmor.mtk * 2, Livingarmor.gold * 3, "Hard");

			else
				battleScene(numberMap, Livingarmor.name, Livingarmor.hp * 3, Livingarmor.atk * 3, Livingarmor.mtk * 3, Livingarmor.gold * 5, "Extreme");
		}
		else // 30% 확률로 유적 드래곤이 나옴
		{
			if ((rand() % 100) + 1 <= 50)
				battleScene(numberMap, Dragon.name, Dragon.hp, Dragon.atk, Dragon.mtk, Dragon.gold, "Normal");

			else if ((rand() % 100) + 1 <= 80)
				battleScene(numberMap, Dragon.name, Dragon.hp * 2, Dragon.atk * 2, Dragon.mtk * 2, Dragon.gold * 3, "Hard");

			else
				battleScene(numberMap, Dragon.name, Dragon.hp * 3, Dragon.atk * 3, Dragon.mtk * 3, Dragon.gold * 5, "Extreme");
		}
	case 1:
		system("cls");
		Town();
		break;
	default: break;
	}
}

void battleScene(int numberMap, char monsterName[NAME_SIZE], int monsterHp, int monsterAtk, int monsterMtk, int monsterGold, char level[NAME_SIZE])
{
	int pos = 0; // 0 - 공격하기, 1 - 주문 시전, 2 - 도망가기
	char NameMenu[3][NAME_SIZE] = { "공격하기","주문시전","도망가기" };

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // 플레이어의 스텟 UI를 불러옴

	// 현재 맵의 메뉴를 출력함
	switch (numberMap)
	{
	case 0:
		break;
	case 1:
		setDarkForest();
		break;
	case 2:
		setSilentCave();
		break;
	case 3:
		setDestroyedRuins();
		break;
	default: break;
	}

	setBattleScene(); // BattleScene 의 메뉴를 전부 출력하는 함수
	selectMenu(NameMenu[pos], 30, 10);

	// 몬스터의 스텟을 출력함
	gotoxy(30, 2);
	if (strcmp(level, "Normal") == 0)
		textcolor(WHITE);
	else if (strcmp(level, "Hard") == 0)
		textcolor(DarkRed);
	else
		textcolor(DarkPurple);
	printf("%s ", level);
	textcolor(WHITE);

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
				selectMenu(NameMenu[pos], 30, 10);
				break;

			case 1:
				setBattleScene();
				selectMenu(NameMenu[pos], 30, 15);
				break;

			case 2:
				setBattleScene();
				selectMenu(NameMenu[pos], 30, 20);
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
				Player.hp -= monsterAtk + monsterMtk;
			break;
		case 1:
			Spell(numberMap, monsterName, monsterHp, monsterAtk, monsterMtk, monsterGold, level);
			break;
		case 2:
			system("cls");

			switch (numberMap)
			{
			case 0:
				break;
			case 1:
				DarkForest();
				break;
			case 2:
				SilentCave();
				break;
			case 3:
				DestroyedRuins();
				break;
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

		playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // 플레이어의 스텟 UI를 불러옴

		if (Player.hp <= 0)
		{
			gotoxy(55, 2);
			textcolor(RED);
			printf("당신은 사망하였습니다..");
			gotoxy(55, 3);
			printf("몬스터가 %.f Gold를 훔쳐갔습니다..", Player.gold * 0.4);
			Player.gold -= (Player.gold * 0.4);
			Sleep(1000);

			system("cls");
			Player.hp = Player_maxHp;
			Player.mp = Player_maxMp;
			Town();
		}
	}

	gotoxy(55, 2);
	textcolor(YELLOW);
	printf("몬스터를 처치하였습니다!");
	gotoxy(55, 3);
	printf("보상으로 %d Gold를 획득하였습니다!", monsterGold);
	Player.gold += monsterGold;
	Sleep(1200);

	system("cls");

	switch (numberMap)
	{
	case 0:
		break;
	case 1:
		DarkForest();
		break;
	case 2:
		SilentCave();
		break;
	case 3:
		DestroyedRuins();
		break;
	default: break;
	}
}

void Spell(int numberMap, char monsterName[NAME_SIZE], int monsterHp, int monsterAtk, int monsterMtk, int monsterGold, char level[NAME_SIZE])
{
	int pos = 0; // 0 - 파이어 볼, 1 - 파이어 캐논, 2 - 볼케이노, 3 - 헬파이어
	char NameMenu[5][NAME_SIZE] = { "파이어 볼","파이어 캐논 (MTK x2)","파이어 스톰 (MTK x4)","헬파이어 (MTK x10)","돌아가기" };
	int needMp[4] = { 3,6,12,30 };

	setBattleScene();
	setSpell();
	selectSpell(NameMenu[pos], needMp[pos], 55, 10); // 선택한 주문 메뉴를 표시해주는 함수

	while (monsterHp > 0)
	{
		int key = 0; // 방향키 입력을 확인하기 위한 변수

		while (1)
		{
			key = _getch();
			if (key == 13) // 엔터를 눌렀을 때
				break;

			pos = controlMenu(pos, 5); // pos 변수와 고를 수 있는 메뉴의 개수를 적음
			switch (pos)
			{
			case 0:
				setSpell();
				selectSpell(NameMenu[pos], needMp[pos], 55, 10);
				break;

			case 1:
				setSpell();
				if (FireCannon)
					selectSpell(NameMenu[pos], needMp[pos], 55, 15);
				else
					selectNotUseSpell(NameMenu[pos], 55, 15);
				break;

			case 2:
				setSpell();
				if (FireStorm)
					selectSpell(NameMenu[pos], needMp[pos], 55, 20);
				else
					selectNotUseSpell(NameMenu[pos], 55, 20);
				break;

			case 3:
				setSpell();
				if (HellFire)
					selectSpell(NameMenu[pos], needMp[pos], 55, 25);
				else
					selectNotUseSpell(NameMenu[pos], 55, 25);
				break;

			case 4:
				setSpell();
				selectMenu(NameMenu[pos], 55, 30);
				break;
			default: break;
			}
			Sleep(100); // getch 함수가 입력받는 속도 제어
		}

		int PlayerMp = Player.mp;
		switch (pos)
		{
		case 0: // 파이어 볼
			if ((PlayerMp -= needMp[pos]) < 0)
				checkMp(); // 사용 가능한 마나를 보유 중인지 확인하는 함수
			else
			{
				monsterHp -= Player.mtk;
				Player.mp -= needMp[pos];
				if (monsterHp > 0)
					Player.hp -= monsterAtk + monsterMtk;
			}
			break;
		case 1: // 파이어 캐논
			if (FireCannon)
			{
				if ((PlayerMp -= needMp[pos]) < 0)
					checkMp();
				else
				{
					monsterHp -= Player.mtk * 2;
					Player.mp -= needMp[pos];
					if (monsterHp > 0)
						Player.hp -= monsterAtk + monsterMtk;
				}
				break;
			}
			else
				checkSpell();
			break;
		case 2: // 파이어 스톰
			if (FireStorm)
			{
				if ((PlayerMp -= needMp[pos]) < 0)
					checkMp();
				else
				{
					monsterHp -= Player.mtk * 4;
					Player.mp -= needMp[pos];
					if (monsterHp > 0)
						Player.hp -= monsterAtk + monsterMtk;
				}
			}
			else
				checkSpell();
			break;
		case 3: // 헬파이어
			if (HellFire)
			{
				if ((PlayerMp -= needMp[pos]) < 0)
					checkMp();
				else
				{
					monsterHp -= Player.mtk * 10;
					Player.mp -= needMp[pos];
					if (monsterHp > 0)
						Player.hp -= monsterAtk + monsterMtk;
				}
			}
			else
				checkSpell();
			break;
		case 4:
			system("cls");
			battleScene(numberMap, monsterName, monsterHp, monsterAtk, monsterMtk, monsterGold, level);
			break;
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

		playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // 플레이어의 스텟 UI를 불러옴

		if (Player.hp <= 0)
		{
			gotoxy(55, 2);
			textcolor(RED);
			printf("당신은 기절하였습니다..");
			gotoxy(55, 3);
			printf("몬스터가 %.f Gold를 훔쳐갔습니다..", Player.gold * 0.4);
			Player.gold -= (Player.gold * 0.4);
			Sleep(1000);

			system("cls");
			Player.hp = Player_maxHp;
			Player.mp = Player_maxMp;
			Town();
		}
	}

	gotoxy(55, 2);
	textcolor(YELLOW);
	printf("몬스터를 처치하였습니다!");
	gotoxy(55, 3);
	printf("보상으로 %d Gold를 획득하였습니다!", monsterGold);
	Player.gold += monsterGold;
	Sleep(1200);

	system("cls");

	switch (numberMap)
	{
	case 0:
		break;
	case 1:
		DarkForest();
		break;
	case 2:
		SilentCave();
		break;
	case 3:
		DestroyedRuins();
		break;
	default: break;
	}
}

void shop()
{
	int key = 0; // 방향키 입력을 확인하기 위한 변수
	int pos = 0; // 0 - 이동하기, 1 - 인벤토리, 2 - 휴식하기
	char NameMenu[3][NAME_SIZE] = { "강화 물약 구매","주문 구매","마을로 돌아가기" };

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("현재 위치 : 상점");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // 플레이어의 스텟 UI를 불러옴

	setShop(); // Shop 의 메뉴를 전부 출력하는 함수
	selectMenu(NameMenu[pos], 5, 10);

	while (1) // 메뉴 고르는 무한 while문
	{
		key = _getch();
		if (key == 13) // 엔터를 눌렀을 때
			break;

		pos = controlMenu(pos, 3); // pos 변수와 고를 수 있는 메뉴의 개수를 적음
		switch (pos)
		{
		case 0:
			setShop();
			selectMenu(NameMenu[pos], 5, 10);
			break;

		case 1:
			setShop();
			selectMenu(NameMenu[pos], 5, 15);
			break;

		case 2:
			setShop();
			selectMenu(NameMenu[pos], 5, 20);
			break;
		default: break;
		}
		Sleep(100); // getch 함수가 입력받는 속도 제어
	}

	switch (pos)
	{
	case 0:
		buyPotion();
		break;
	case 1:
		buySpell();
		break;
	case 2:
		system("cls");
		Town();
		break;
	default: break;
	}
}

int getcount()
{
	char count[100] = { 0, };

	textcolor(YELLOW);
	gotoxy(30, 2);
	printf("구매하실 수량을 적어주세요..");
	textcolor(WHITE);
	gotoxy(30, 3);
	printf("수량 : ");
	textcolor(DarkYellow);

	scanf("%s", count);

	return atoi(count);
}

void checkGold(int Price, int count, int shopNumber)
{
	double Playergold = Player.gold;
	if ((Playergold -= ((long long)Price * count)) < 0)
	{
		gotoxy(30, 5);
		textcolor(RED);
		printf("돈이 부족합니다..");
		Sleep(500);
		system("cls");

		gotoxy(0, 0);
		textcolor(WHITE);
		printf("현재 위치 : 상점");
		playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold);
		
		switch (shopNumber)
		{
		case 0:
			buyPotion();
			break;
		case 1:
			buySpell();
			break;
		default:break;
		}
	}
}

void checkSpell() // 사용하려는 주문을 배웠는지 확인하는 함수
{
	gotoxy(55, 2);
	textcolor(RED);
	printf("해당 주문을 배우지 않았습니다..");
	textcolor(WHITE);
	Sleep(500);
	gotoxy(55, 2);
	printf("                               ");
}

void checkMp() // 사용 가능한 마나를 보유 중인지 확인하는 함수
{
	gotoxy(55, 2);
	textcolor(RED);
	printf("MP가 부족합니다..");
	textcolor(WHITE);
	Sleep(500);
	gotoxy(55, 2);
	printf("                 ");
}

void buyPotion()
{
	int pos = 0; // 0 - HP 강화 물약, 1 - MP 강화 물약, 2 - ATK 강화 물약, 3 - MTK 강화 물약, 4 - 돌아가기

	char NameMenu[5][NAME_SIZE] = { "HP 강화 물약","MP 강화 물약","ATK 강화 물약","MTK 강화 물약","돌아가기" };
	int PotionPrice[5] = { 50,150,20,100 };

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("현재 위치 : 상점");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold);	

	setShop();

	setbuyPotion();
	selectBuy(NameMenu[pos], PotionPrice[pos], 30, 10, GREEN);

	while (1)
	{
		int key = 0; // 방향키 입력을 확인하기 위한 변수

		while (1)
		{
			key = _getch();
			if (key == 13) // 엔터를 눌렀을 때
				break;

			pos = controlMenu(pos, 5); // pos 변수와 고를 수 있는 메뉴의 개수를 적음
			switch (pos)
			{
			case 0:
				setbuyPotion();
				selectBuy(NameMenu[pos], PotionPrice[pos], 30, 10, GREEN);
				break;

			case 1:
				setbuyPotion();
				selectBuy(NameMenu[pos], PotionPrice[pos], 30, 15, BLUE);
				break;

			case 2:
				setbuyPotion();
				selectBuy(NameMenu[pos], PotionPrice[pos], 30, 20, DarkRed);
				break;

			case 3:
				setbuyPotion();
				selectBuy(NameMenu[pos], PotionPrice[pos], 30, 25, SkyBlue);
				break;

			case 4:
				setbuyPotion();
				selectMenu(NameMenu[pos], 30, 30);
				break;
			default: break;
			}
			Sleep(100); // getch 함수가 입력받는 속도 제어
		}

		int count;

		switch (pos)
		{
		case 0:
			count = getcount(); // 구매 수량을 입력받는 함수
			checkGold(PotionPrice[pos], count, 0); // 아이템을 구매할 골드를 가지고 있는지 확인하는 함수

			Player.gold -= ((long long)PotionPrice[pos] * count);
			Player_maxHp += (5 * count);
			Player.hp += (5 * count);

			gotoxy(30, 5);
			textcolor(RED);
			printf("구매를 위해 %d Gold를 지불 하였습니다..", (PotionPrice[pos] * count));
			gotoxy(30, 6);
			textcolor(GREEN);
			printf("최대 체력이 %d만큼 상승하였습니다!", (5 * count));
			textcolor(WHITE);
			Sleep(1500);

			system("cls");
			buyPotion();
			break;
		case 1:
			count = getcount(); // 구매 수량을 입력받는 함수
			checkGold(PotionPrice[pos], count, 0); // 아이템을 구매할 골드를 가지고 있는지 확인하는 함수

			Player.gold -= ((long long)PotionPrice[pos] * count);
			Player_maxMp += (3 * count);
			Player.mp += (3 * count);

			gotoxy(30, 5);
			textcolor(RED);
			printf("구매를 위해 %d Gold를 지불 하였습니다..", (PotionPrice[pos] * count));
			gotoxy(30, 6);
			textcolor(GREEN);
			printf("최대 마나가 %d만큼 상승하였습니다!", (3 * count));
			textcolor(WHITE);
			Sleep(1500);

			system("cls");
			buyPotion();
			break;
		case 2:
			count = getcount(); // 구매 수량을 입력받는 함수
			checkGold(PotionPrice[pos], count, 0); // 아이템을 구매할 골드를 가지고 있는지 확인하는 함수

			Player.gold -= ((long long)PotionPrice[pos] * count);
			Player.atk += (1 * count);

			gotoxy(30, 5);
			textcolor(RED);
			printf("구매를 위해 %d Gold를 지불 하였습니다..", (PotionPrice[pos] * count));
			gotoxy(30, 6);
			textcolor(GREEN);
			printf("물리 공격력이 %d만큼 상승하였습니다!", (1 * count));
			textcolor(WHITE);
			Sleep(1500);

			system("cls");
			buyPotion();
			break;
		case 3:
			count = getcount(); // 구매 수량을 입력받는 함수
			checkGold(PotionPrice[pos], count, 0); // 아이템을 구매할 골드를 가지고 있는지 확인하는 함수

			Player.gold -= ((long long)PotionPrice[pos] * count);
			Player.mtk += (1 * count);

			gotoxy(30, 5);
			textcolor(RED);
			printf("구매를 위해 %d Gold를 지불 하였습니다..", (PotionPrice[pos] * count));
			gotoxy(30, 6);
			textcolor(GREEN);
			printf("마법 공격력이 %d만큼 상승하였습니다!", (1 * count));
			textcolor(WHITE);
			Sleep(1500);

			system("cls");
			buyPotion();
			break;
		case 4:
			system("cls");
			shop();
			break;
		default: break;
		}

	}
}

void buySpell()
{
	int pos = 0; // 0 - 파이어 캐논, 1 - 파이어 스톰, 2 - 헬파이어, 3 - 돌아가기

	char NameMenu[4][NAME_SIZE] = { "파이어 캐논","파이어 스톰","헬파이어","돌아가기" };
	int SpellPrice[4] = { 300,800,1600,3000 };

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("현재 위치 : 상점");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold);

	setShop();

	setbuySpell();
	if (FireCannon)
		selectBoughtSpell(NameMenu[pos], 30, 10);
	else
		selectBuy(NameMenu[pos], SpellPrice[pos], 30, 10, RED);

	while (1)
	{
		int key = 0; // 방향키 입력을 확인하기 위한 변수

		while (1)
		{
			key = _getch();
			if (key == 13) // 엔터를 눌렀을 때
				break;

			pos = controlMenu(pos, 4); // pos 변수와 고를 수 있는 메뉴의 개수를 적음
			switch (pos)
			{
			case 0:
				setbuySpell();
				if (FireCannon)
					selectBoughtSpell(NameMenu[pos], 30, 10);
				else
					selectBuy(NameMenu[pos], SpellPrice[pos], 30, 10, RED);
				break;

			case 1:
				setbuySpell();
				if (FireStorm)
					selectBoughtSpell(NameMenu[pos], 30, 15);
				else
					selectBuy(NameMenu[pos], SpellPrice[pos], 30, 15, RED);
				break;

			case 2:
				setbuySpell();
				if (HellFire)
					selectBoughtSpell(NameMenu[pos], 30, 20);
				else
					selectBuy(NameMenu[pos], SpellPrice[pos], 30, 20, RED);
				break;

			case 3:
				setbuySpell();
				selectMenu(NameMenu[pos], 30, 25);
				break;
			default: break;
			}
			Sleep(100); // getch 함수가 입력받는 속도 제어
		}

		int count = 1;
		switch (pos)
		{
		case 0:
			if (FireCannon != 1)
			{
				checkGold(SpellPrice[pos], count, 1); // 아이템을 구매할 골드를 가지고 있는지 확인하는 함수
				Player.gold -= ((long long)SpellPrice[pos] * count);
				FireCannon = 1;

				gotoxy(30, 5);
				textcolor(RED);
				printf("구매를 위해 %d Gold를 지불 하였습니다..", (SpellPrice[pos] * count));
				gotoxy(30, 6);
				textcolor(GREEN);
				printf("%s 주문을 습득하였습니다!", NameMenu[pos]);
				textcolor(WHITE);
				Sleep(1500);

				system("cls");
				buySpell();
				break;
			}
			else
			{
				gotoxy(30, 5);
				textcolor(RED);
				printf("이미 %s 주문을 습득하였습니다!", NameMenu[pos]);
				Sleep(500);
				system("cls");
				buySpell();
			}
			break;
		case 1:
			if (FireStorm != 1)
			{
				checkGold(SpellPrice[pos], count, 1); // 아이템을 구매할 골드를 가지고 있는지 확인하는 함수
				Player.gold -= ((long long)SpellPrice[pos] * count);
				FireStorm = 1;

				gotoxy(30, 5);
				textcolor(RED);
				printf("구매를 위해 %d Gold를 지불 하였습니다..", (SpellPrice[pos] * count));
				gotoxy(30, 6);
				textcolor(GREEN);
				printf("%s 주문을 습득하였습니다!", NameMenu[pos]);
				textcolor(WHITE);
				Sleep(1500);

				system("cls");
				buySpell();
				break;
			}
			else
			{
				gotoxy(30, 5);
				textcolor(RED);
				printf("이미 %s 주문을 습득하였습니다!", NameMenu[pos]);
				Sleep(500);
				system("cls");
				buySpell();
			}
			break;
		case 2:
			if (HellFire != 1)
			{
				checkGold(SpellPrice[pos], count, 1); // 아이템을 구매할 골드를 가지고 있는지 확인하는 함수
				Player.gold -= ((long long)SpellPrice[pos] * count);
				HellFire = 1;

				gotoxy(30, 5);
				textcolor(RED);
				printf("구매를 위해 %d Gold를 지불 하였습니다..", (SpellPrice[pos] * count));
				gotoxy(30, 6);
				textcolor(GREEN);
				printf("%s 주문을 습득하였습니다!", NameMenu[pos]);
				textcolor(WHITE);
				Sleep(1500);

				system("cls");
				buySpell();
				break;
			}
			else
			{
				gotoxy(30, 5);
				textcolor(RED);
				printf("이미 %s 주문을 습득하였습니다!", NameMenu[pos]);
				Sleep(500);
				system("cls");
				buySpell();
			}
			break;
		case 3:
			system("cls");
			shop();
			break;
		default: break;
		}

	}
}