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

int controlMenu(int numberPos, int numberMenu) // �޴��� ����Ű�� �����ϴ� �Լ�
{
	int pos = numberPos;
	int key = 0;

	if (key = 224)
		key = _getch();

	if (key == 72) // ����Ű ���� ������ ��
		if (pos == 0) pos = numberMenu - 1;
		else pos -= 1;

	else if (key == 80) // ����Ű �Ʒ��� ������ ��
		if (pos == numberMenu - 1) pos = 0;
		else pos += 1;

	return pos;
}

void selectMenu(char *NameMenu, int x, int y) // ������ �޴��� ǥ�����ִ� �Լ�
{
	gotoxy(x, y);
	textcolor(GREEN);
	printf("> %s", NameMenu);
	textcolor(WHITE);
}

void selectBuy(char *NameMenu, int price, int x, int y, int color) // ������ ���� �޴��� ǥ�����ִ� �Լ�
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
	printf("  �̹� ������ �ֹ��Դϴ�..");
}

void selectSpell(char* NameMenu, int needMp, int x, int y) // ������ ��� ������ �ֹ� �޴��� ǥ�����ִ� �Լ�
{
	textcolor(DarkRed);
	gotoxy(x, y);
	printf("> %s", NameMenu);
	gotoxy(x, y + 1);
	textcolor(SkyBlue);
	printf("  %d MP", needMp);
	textcolor(WHITE);
}

void selectNotUseSpell(char* NameMenu, int x, int y) // ������ ��� �Ұ����� �ֹ� �޴��� ǥ�����ִ� �Լ�
{
	textcolor(DarkGray);
	gotoxy(x, y);
	printf("> %s", NameMenu);
	textcolor(WHITE);
}

void setTown() // Town �� �޴��� ���� ����ϴ� �Լ�
{
	int NumberMenu = 0;
	char NameMenu[3][NAME_SIZE] = { "�̵��ϱ�","��������","�޽��ϱ�" };

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("���� ��ġ : ����");

	gotoxy(5, 10);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 15);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 20);
	printf(" %s ", NameMenu[NumberMenu++]);
}

void setShop() // Shop �� �޴��� ���� ����ϴ� �Լ�
{
	int NumberMenu = 0;
	char NameMenu[3][NAME_SIZE] = { "��ȭ ���� ����","�ֹ� ����","������ ���ư���" };

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
	char NameMenu[5][NAME_SIZE] = { "HP ��ȭ ����","MP ��ȭ ����","ATK ��ȭ ����","MTK ��ȭ ����","���ư���" };
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
	char NameMenu[4][NAME_SIZE] = { "���̾� ĳ��","���̾� ����","�����̾�","���ư���" };
	int SpellPrice[4] = { 300,800,1600,3000 };

	if (FireCannon)
	{
		gotoxy(30, 10);
		textcolor(DarkGray);
		printf(" %s ", NameMenu[NumberMenu++]);
		gotoxy(30, 11);
		printf(" �̹� ������ �ֹ��Դϴ�..  ");
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
		printf(" �̹� ������ �ֹ��Դϴ�..  ");
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
		printf(" �̹� ������ �ֹ��Դϴ�..  ");
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

void setmoveMap() // Move �� �޴��� ���� ����ϴ� �Լ�
{
	int NumberMenu = 0;
	char NameMenu[4][NAME_SIZE] = { "��ο� ��","����� ����","�ı��� ����","���ư���" };

	gotoxy(5, 10);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 15);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 20);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 25);
	printf(" %s ", NameMenu[NumberMenu++]);
}

void setDarkForest() // DarkForest �� �޴��� ���� ����ϴ� �Լ�
{
	int NumberMenu = 0;
	char NameMenu[2][NAME_SIZE] = { "Ž���ϱ�","������ ���ư���" };

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("���� ��ġ : ��ο� ��");

	gotoxy(5, 10);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 15);
	printf(" %s ", NameMenu[NumberMenu++]);
}

void setSilentCave()
{
	int NumberMenu = 0;
	char NameMenu[2][NAME_SIZE] = { "Ž���ϱ�","������ ���ư���" };

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("���� ��ġ : ����� ����");

	gotoxy(5, 10);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 15);
	printf(" %s ", NameMenu[NumberMenu++]);
}

void setDestroyedRuins()
{
	int NumberMenu = 0;
	char NameMenu[2][NAME_SIZE] = { "Ž���ϱ�","������ ���ư���" };

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("���� ��ġ : �ı��� ����");

	gotoxy(5, 10);
	printf(" %s ", NameMenu[NumberMenu++]);
	gotoxy(5, 15);
	printf(" %s ", NameMenu[NumberMenu++]);
}

void setBattleScene() // BattleScene �� �޴��� ���� ����ϴ� �Լ�
{
	int NumberMenu = 0;
	char NameMenu[3][NAME_SIZE] = { "�����ϱ�","�ֹ�����","��������" };

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
	char NameMenu[5][NAME_SIZE] = { "���̾� ��","���̾� ĳ�� (MTK x2)","���̾� ���� (MTK x4)","�����̾� (MTK x10)","���ư���" };
	int needMp[4] = { 3,6,12,30 };

	// ���̾� ��
	gotoxy(55, 10);
	textcolor(DarkRed);
	printf(" %s  ", NameMenu[NumberMenu]);
	gotoxy(55, 11);
	textcolor(SkyBlue);
	printf(" %d MP  ", needMp[NumberMenu++]);

	// ���̾� ĳ��
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

	// ���̾� ����
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

	// �����̾�
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

/* ������ ������ �Լ����� ��� https://blog.naver.com/ifthe1201/221056588399 ��ũ�� �ִ� 3��(�޴��� ��������!)�� �ο���
   �ڵ带 ���ȭ�ϱ� ���ؼ� �Ʒ��� ���� �κ��� ������
   1. while������ �޴��� �����ϴ� �Լ��� "menu.h" ������Ͽ� ���� �����Ͽ� �ڵ尡 ��������
   2. switch������ �޴��� ����ϴ� �κп��� �ݺ��Ǵ� ���ڿ� �κ��� �Լ��� �����Ͽ� �ڵ尡 ��������
   3. pos�� ������ ������ ���� �ֱ� ������ if���� ������� �ʰ� switch���� ����� */

void Town()
{
	int key = 0; // ����Ű �Է��� Ȯ���ϱ� ���� ����
	int pos = 0; // 0 - �̵��ϱ�, 1 - �κ��丮, 2 - �޽��ϱ�
	char NameMenu[3][NAME_SIZE] = { "�̵��ϱ�","��������","�޽��ϱ�" };

	numberMap = Loc_Town; // '���ư���' �� �����Ͽ��� ��, ���� ������ ���ư��� ���� ���� ���� �ѹ��� ����

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("���� ��ġ : ����");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // �÷��̾��� ���� UI�� �ҷ���

	setTown(); // Town �� �޴��� ���� ����ϴ� �Լ�
	selectMenu(NameMenu[pos], 5, 10);

	while (1) // �޴� ���� ���� while��
	{
		key = _getch();
		if (key == 13) // ���͸� ������ ��
			break;

		pos = controlMenu(pos, 3); // pos ������ �� �� �ִ� �޴��� ������ ����
		switch (pos)
		{
		case 0:
			setTown(); // Town �� �޴��� ���� ����ϴ� �Լ�
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
		Sleep(100); // getch �Լ��� �Է¹޴� �ӵ� ����
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
		printf("�޽��ϴ���");
		for (int i = 0; i < 3; i++)
		{
			Sleep(500);
			printf(".");
		}
		Sleep(500);
		gotoxy(30, 2);
		printf("             "); // ����� ���� ����� ���� ���� ���

		Player.hp = Player_maxHp;
		Player.mp = Player_maxMp;
		Town();
		break;
	default: break;
	}
}

void moveMap()
{
	int key = 0; // ����Ű �Է��� Ȯ���ϱ� ���� ����
	int pos = 0; // 0 - ��ο� ��, 1 - ����� ����, 2 - �ı��� ����, 3 - ���ư���
	char NameMenu[4][NAME_SIZE] = { "��ο� ��","����� ����","�ı��� ����","���ư���" };

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("�̵��� ���� �����ϼ���..");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // �÷��̾��� ���� UI�� �ҷ���

	setmoveMap(); // Move �� �޴��� ���� ����ϴ� �Լ�
	selectMenu(NameMenu[pos], 5, 10);

	while (1)
	{
		key = _getch();
		if (key == 13) // ���͸� ������ ��
			break;

		pos = controlMenu(pos, 4); // pos ������ �� �� �ִ� �޴��� ������ ����
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
		Sleep(100); // getch �Լ��� �Է¹޴� �ӵ� ����
	}

	switch (pos)
	{
	case 0: // ��ο� ��
		system("cls");
		DarkForest();
		break;
	case 1: // ����� ����
		system("cls");
		SilentCave();
		break;
	case 2: // �ı��� ����
		system("cls");
		DestroyedRuins();
		break;
	case 3: // ���ư���
		system("cls");
		Town();
		break;
	default: break;
	}
}

void DarkForest()
{
	int key = 0; // ����Ű �Է��� Ȯ���ϱ� ���� ����
	int pos = 0; // 0 - Ž���ϱ�, 1 - ������ ���ư���
	char NameMenu[2][NAME_SIZE] = { "Ž���ϱ�","������ ���ư���" };

	numberMap = Loc_DarkForest; // '���ư���' �� �����Ͽ��� ��, ���� ������ ���ư��� ���� ���� ���� �ѹ��� ����

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("���� ��ġ : ��ο� ��");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // �÷��̾��� ���� UI�� �ҷ���

	setDarkForest(); // DarkForest �� �޴��� ���� ����ϴ� �Լ�
	selectMenu(NameMenu[pos], 5, 10);

	while (1)
	{
		key = _getch();
		if (key == 13) // ���͸� ������ ��
			break;

		pos = controlMenu(pos, 2); // pos ������ �� �� �ִ� �޴��� ������ ����
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
		Sleep(100); // getch �Լ��� �Է¹޴� �ӵ� ����
	}

	switch (pos)
	{
	case 0:
		gotoxy(30, 2);
		printf("Ž���ϴ���");
		for (int i = 0; i < 2; i++)
		{
			Sleep(400);
			printf(".");
		}
		Sleep(400);
		gotoxy(30, 2);
		printf("            "); // ����� ���� ����� ���� ���� ���

		if ((rand() % 100) + 1 + 1 <= 40) // 40% Ȯ���� ������ ����
		{
			if ((rand() % 100) + 1 + 1 <= 50)
				battleScene(numberMap, Pig.name, Pig.hp, Pig.atk, Pig.mtk, Pig.gold, "Normal");

			else if ((rand() % 100) + 1 <= 80)
				battleScene(numberMap, Pig.name, Pig.hp * 2, Pig.atk * 2, Pig.mtk * 2, Pig.gold * 3, "Hard");

			else
				battleScene(numberMap, Pig.name, Pig.hp * 3, Pig.atk * 3, Pig.mtk * 3, Pig.gold * 5, "Extreme");
		}
		else if ((rand() % 100) + 1 <= 80) // 40% Ȯ���� �������� ����
		{
			if ((rand() % 100) + 1 <= 50)
				battleScene(numberMap, Slime.name, Slime.hp, Slime.atk, Slime.mtk, Slime.gold, "Normal");

			else if ((rand() % 100) + 1 <= 80)
				battleScene(numberMap, Slime.name, Slime.hp * 2, Slime.atk * 2, Slime.mtk * 2, Slime.gold * 3, "Hard");

			else
				battleScene(numberMap, Slime.name, Slime.hp * 3, Slime.atk * 3, Slime.mtk * 3, Slime.gold * 5, "Extreme");
		}
		else // 30% Ȯ���� ����� ����
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
	int key = 0; // ����Ű �Է��� Ȯ���ϱ� ���� ����
	int pos = 0; // 0 - Ž���ϱ�, 1 - ������ ���ư���
	char NameMenu[2][NAME_SIZE] = { "Ž���ϱ�","������ ���ư���" };

	numberMap = Loc_SilentCave; // '���ư���' �� �����Ͽ��� ��, ���� ������ ���ư��� ���� ���� ���� �ѹ��� ����

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("���� ��ġ : ����� ����");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // �÷��̾��� ���� UI�� �ҷ���

	setSilentCave(); // SilentCave �� �޴��� ���� ����ϴ� �Լ�
	selectMenu(NameMenu[pos], 5, 10);

	while (1)
	{
		key = _getch();
		if (key == 13) // ���͸� ������ ��
			break;

		pos = controlMenu(pos, 2); // pos ������ �� �� �ִ� �޴��� ������ ����
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
		Sleep(100); // getch �Լ��� �Է¹޴� �ӵ� ����
	}

	switch (pos)
	{
	case 0:
		gotoxy(30, 2);
		printf("Ž���ϴ���");
		for (int i = 0; i < 2; i++)
		{
			Sleep(400);
			printf(".");
		}
		Sleep(400);
		gotoxy(30, 2);
		printf("            "); // ����� ���� ����� ���� ���� ���

		if ((rand() % 100) + 1 + 1 <= 40) // 40% Ȯ���� ���㰡 ����
		{
			if ((rand() % 100) + 1 + 1 <= 50)
				battleScene(numberMap, Bat.name, Bat.hp, Bat.atk, Bat.mtk, Bat.gold, "Normal");

			else if ((rand() % 100) + 1 <= 80)
				battleScene(numberMap, Bat.name, Bat.hp * 2, Bat.atk * 2, Bat.mtk * 2, Bat.gold * 3, "Hard");

			else
				battleScene(numberMap, Bat.name, Bat.hp * 3, Bat.atk * 3, Bat.mtk * 3, Bat.gold * 5, "Extreme");
		}
		else if ((rand() % 100) + 1 <= 80) // 40% Ȯ���� Ʈ���� ����
		{
			if ((rand() % 100) + 1 <= 50)
				battleScene(numberMap, Troll.name, Troll.hp, Troll.atk, Troll.mtk, Troll.gold, "Normal");

			else if ((rand() % 100) + 1 <= 80)
				battleScene(numberMap, Troll.name, Troll.hp * 2, Troll.atk * 2, Troll.mtk * 2, Troll.gold * 3, "Hard");

			else
				battleScene(numberMap, Troll.name, Troll.hp * 3, Troll.atk * 3, Troll.mtk * 3, Troll.gold * 5, "Extreme");
		}
		else // 30% Ȯ���� ������ ����
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
	int key = 0; // ����Ű �Է��� Ȯ���ϱ� ���� ����
	int pos = 0; // 0 - Ž���ϱ�, 1 - ������ ���ư���
	char NameMenu[2][NAME_SIZE] = { "Ž���ϱ�","������ ���ư���" };

	numberMap = Loc_DestroyedRuins; // '���ư���' �� �����Ͽ��� ��, ���� ������ ���ư��� ���� ���� ���� �ѹ��� ����

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("���� ��ġ : �ı��� ����");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // �÷��̾��� ���� UI�� �ҷ���

	setDestroyedRuins(); // DestroyedRuins �� �޴��� ���� ����ϴ� �Լ�
	selectMenu(NameMenu[pos], 5, 10);

	while (1)
	{
		key = _getch();
		if (key == 13) // ���͸� ������ ��
			break;

		pos = controlMenu(pos, 2); // pos ������ �� �� �ִ� �޴��� ������ ����
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
		Sleep(100); // getch �Լ��� �Է¹޴� �ӵ� ����
	}

	switch (pos)
	{
	case 0:
		gotoxy(30, 2);
		printf("Ž���ϴ���");
		for (int i = 0; i < 2; i++)
		{
			Sleep(400);
			printf(".");
		}
		Sleep(400);
		gotoxy(30, 2);
		printf("            "); // ����� ���� ����� ���� ���� ���

		if ((rand() % 100) + 1 + 1 <= 40) // 40% Ȯ���� ������� ����
		{
			if ((rand() % 100) + 1 + 1 <= 50)
				battleScene(numberMap, Guardian.name, Guardian.hp, Guardian.atk, Guardian.mtk, Guardian.gold, "Normal");

			else if ((rand() % 100) + 1 <= 80)
				battleScene(numberMap, Guardian.name, Guardian.hp * 2, Guardian.atk * 2, Guardian.mtk * 2, Guardian.gold * 3, "Hard");

			else
				battleScene(numberMap, Guardian.name, Guardian.hp * 3, Guardian.atk * 3, Guardian.mtk * 3, Guardian.gold * 5, "Extreme");
		}
		else if ((rand() % 100) + 1 <= 80) // 40% Ȯ���� ����ִ� ������ ����
		{
			if ((rand() % 100) + 1 <= 50)
				battleScene(numberMap, Livingarmor.name, Livingarmor.hp, Livingarmor.atk, Livingarmor.mtk, Livingarmor.gold, "Normal");

			else if ((rand() % 100) + 1 <= 80)
				battleScene(numberMap, Livingarmor.name, Livingarmor.hp * 2, Livingarmor.atk * 2, Livingarmor.mtk * 2, Livingarmor.gold * 3, "Hard");

			else
				battleScene(numberMap, Livingarmor.name, Livingarmor.hp * 3, Livingarmor.atk * 3, Livingarmor.mtk * 3, Livingarmor.gold * 5, "Extreme");
		}
		else // 30% Ȯ���� ���� �巡���� ����
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
	int pos = 0; // 0 - �����ϱ�, 1 - �ֹ� ����, 2 - ��������
	char NameMenu[3][NAME_SIZE] = { "�����ϱ�","�ֹ�����","��������" };

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // �÷��̾��� ���� UI�� �ҷ���

	// ���� ���� �޴��� �����
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

	setBattleScene(); // BattleScene �� �޴��� ���� ����ϴ� �Լ�
	selectMenu(NameMenu[pos], 30, 10);

	// ������ ������ �����
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
		int key = 0; // ����Ű �Է��� Ȯ���ϱ� ���� ����

		while (1)
		{
			key = _getch();
			if (key == 13) // ���͸� ������ ��
				break;

			pos = controlMenu(pos, 3); // pos ������ �� �� �ִ� �޴��� ������ ����
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
			Sleep(100); // getch �Լ��� �Է¹޴� �ӵ� ����
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

		// �ൿ �� ����� ������ ������ �����
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

		playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // �÷��̾��� ���� UI�� �ҷ���

		if (Player.hp <= 0)
		{
			gotoxy(55, 2);
			textcolor(RED);
			printf("����� ����Ͽ����ϴ�..");
			gotoxy(55, 3);
			printf("���Ͱ� %.f Gold�� ���İ����ϴ�..", Player.gold * 0.4);
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
	printf("���͸� óġ�Ͽ����ϴ�!");
	gotoxy(55, 3);
	printf("�������� %d Gold�� ȹ���Ͽ����ϴ�!", monsterGold);
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
	int pos = 0; // 0 - ���̾� ��, 1 - ���̾� ĳ��, 2 - �����̳�, 3 - �����̾�
	char NameMenu[5][NAME_SIZE] = { "���̾� ��","���̾� ĳ�� (MTK x2)","���̾� ���� (MTK x4)","�����̾� (MTK x10)","���ư���" };
	int needMp[4] = { 3,6,12,30 };

	setBattleScene();
	setSpell();
	selectSpell(NameMenu[pos], needMp[pos], 55, 10); // ������ �ֹ� �޴��� ǥ�����ִ� �Լ�

	while (monsterHp > 0)
	{
		int key = 0; // ����Ű �Է��� Ȯ���ϱ� ���� ����

		while (1)
		{
			key = _getch();
			if (key == 13) // ���͸� ������ ��
				break;

			pos = controlMenu(pos, 5); // pos ������ �� �� �ִ� �޴��� ������ ����
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
			Sleep(100); // getch �Լ��� �Է¹޴� �ӵ� ����
		}

		int PlayerMp = Player.mp;
		switch (pos)
		{
		case 0: // ���̾� ��
			if ((PlayerMp -= needMp[pos]) < 0)
				checkMp(); // ��� ������ ������ ���� ������ Ȯ���ϴ� �Լ�
			else
			{
				monsterHp -= Player.mtk;
				Player.mp -= needMp[pos];
				if (monsterHp > 0)
					Player.hp -= monsterAtk + monsterMtk;
			}
			break;
		case 1: // ���̾� ĳ��
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
		case 2: // ���̾� ����
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
		case 3: // �����̾�
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

		// �ൿ �� ����� ������ ������ �����
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

		playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // �÷��̾��� ���� UI�� �ҷ���

		if (Player.hp <= 0)
		{
			gotoxy(55, 2);
			textcolor(RED);
			printf("����� �����Ͽ����ϴ�..");
			gotoxy(55, 3);
			printf("���Ͱ� %.f Gold�� ���İ����ϴ�..", Player.gold * 0.4);
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
	printf("���͸� óġ�Ͽ����ϴ�!");
	gotoxy(55, 3);
	printf("�������� %d Gold�� ȹ���Ͽ����ϴ�!", monsterGold);
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
	int key = 0; // ����Ű �Է��� Ȯ���ϱ� ���� ����
	int pos = 0; // 0 - �̵��ϱ�, 1 - �κ��丮, 2 - �޽��ϱ�
	char NameMenu[3][NAME_SIZE] = { "��ȭ ���� ����","�ֹ� ����","������ ���ư���" };

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("���� ��ġ : ����");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold); // �÷��̾��� ���� UI�� �ҷ���

	setShop(); // Shop �� �޴��� ���� ����ϴ� �Լ�
	selectMenu(NameMenu[pos], 5, 10);

	while (1) // �޴� ���� ���� while��
	{
		key = _getch();
		if (key == 13) // ���͸� ������ ��
			break;

		pos = controlMenu(pos, 3); // pos ������ �� �� �ִ� �޴��� ������ ����
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
		Sleep(100); // getch �Լ��� �Է¹޴� �ӵ� ����
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
	printf("�����Ͻ� ������ �����ּ���..");
	textcolor(WHITE);
	gotoxy(30, 3);
	printf("���� : ");
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
		printf("���� �����մϴ�..");
		Sleep(500);
		system("cls");

		gotoxy(0, 0);
		textcolor(WHITE);
		printf("���� ��ġ : ����");
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

void checkSpell() // ����Ϸ��� �ֹ��� ������� Ȯ���ϴ� �Լ�
{
	gotoxy(55, 2);
	textcolor(RED);
	printf("�ش� �ֹ��� ����� �ʾҽ��ϴ�..");
	textcolor(WHITE);
	Sleep(500);
	gotoxy(55, 2);
	printf("                               ");
}

void checkMp() // ��� ������ ������ ���� ������ Ȯ���ϴ� �Լ�
{
	gotoxy(55, 2);
	textcolor(RED);
	printf("MP�� �����մϴ�..");
	textcolor(WHITE);
	Sleep(500);
	gotoxy(55, 2);
	printf("                 ");
}

void buyPotion()
{
	int pos = 0; // 0 - HP ��ȭ ����, 1 - MP ��ȭ ����, 2 - ATK ��ȭ ����, 3 - MTK ��ȭ ����, 4 - ���ư���

	char NameMenu[5][NAME_SIZE] = { "HP ��ȭ ����","MP ��ȭ ����","ATK ��ȭ ����","MTK ��ȭ ����","���ư���" };
	int PotionPrice[5] = { 50,150,20,100 };

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("���� ��ġ : ����");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold);	

	setShop();

	setbuyPotion();
	selectBuy(NameMenu[pos], PotionPrice[pos], 30, 10, GREEN);

	while (1)
	{
		int key = 0; // ����Ű �Է��� Ȯ���ϱ� ���� ����

		while (1)
		{
			key = _getch();
			if (key == 13) // ���͸� ������ ��
				break;

			pos = controlMenu(pos, 5); // pos ������ �� �� �ִ� �޴��� ������ ����
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
			Sleep(100); // getch �Լ��� �Է¹޴� �ӵ� ����
		}

		int count;

		switch (pos)
		{
		case 0:
			count = getcount(); // ���� ������ �Է¹޴� �Լ�
			checkGold(PotionPrice[pos], count, 0); // �������� ������ ��带 ������ �ִ��� Ȯ���ϴ� �Լ�

			Player.gold -= ((long long)PotionPrice[pos] * count);
			Player_maxHp += (5 * count);
			Player.hp += (5 * count);

			gotoxy(30, 5);
			textcolor(RED);
			printf("���Ÿ� ���� %d Gold�� ���� �Ͽ����ϴ�..", (PotionPrice[pos] * count));
			gotoxy(30, 6);
			textcolor(GREEN);
			printf("�ִ� ü���� %d��ŭ ����Ͽ����ϴ�!", (5 * count));
			textcolor(WHITE);
			Sleep(1500);

			system("cls");
			buyPotion();
			break;
		case 1:
			count = getcount(); // ���� ������ �Է¹޴� �Լ�
			checkGold(PotionPrice[pos], count, 0); // �������� ������ ��带 ������ �ִ��� Ȯ���ϴ� �Լ�

			Player.gold -= ((long long)PotionPrice[pos] * count);
			Player_maxMp += (3 * count);
			Player.mp += (3 * count);

			gotoxy(30, 5);
			textcolor(RED);
			printf("���Ÿ� ���� %d Gold�� ���� �Ͽ����ϴ�..", (PotionPrice[pos] * count));
			gotoxy(30, 6);
			textcolor(GREEN);
			printf("�ִ� ������ %d��ŭ ����Ͽ����ϴ�!", (3 * count));
			textcolor(WHITE);
			Sleep(1500);

			system("cls");
			buyPotion();
			break;
		case 2:
			count = getcount(); // ���� ������ �Է¹޴� �Լ�
			checkGold(PotionPrice[pos], count, 0); // �������� ������ ��带 ������ �ִ��� Ȯ���ϴ� �Լ�

			Player.gold -= ((long long)PotionPrice[pos] * count);
			Player.atk += (1 * count);

			gotoxy(30, 5);
			textcolor(RED);
			printf("���Ÿ� ���� %d Gold�� ���� �Ͽ����ϴ�..", (PotionPrice[pos] * count));
			gotoxy(30, 6);
			textcolor(GREEN);
			printf("���� ���ݷ��� %d��ŭ ����Ͽ����ϴ�!", (1 * count));
			textcolor(WHITE);
			Sleep(1500);

			system("cls");
			buyPotion();
			break;
		case 3:
			count = getcount(); // ���� ������ �Է¹޴� �Լ�
			checkGold(PotionPrice[pos], count, 0); // �������� ������ ��带 ������ �ִ��� Ȯ���ϴ� �Լ�

			Player.gold -= ((long long)PotionPrice[pos] * count);
			Player.mtk += (1 * count);

			gotoxy(30, 5);
			textcolor(RED);
			printf("���Ÿ� ���� %d Gold�� ���� �Ͽ����ϴ�..", (PotionPrice[pos] * count));
			gotoxy(30, 6);
			textcolor(GREEN);
			printf("���� ���ݷ��� %d��ŭ ����Ͽ����ϴ�!", (1 * count));
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
	int pos = 0; // 0 - ���̾� ĳ��, 1 - ���̾� ����, 2 - �����̾�, 3 - ���ư���

	char NameMenu[4][NAME_SIZE] = { "���̾� ĳ��","���̾� ����","�����̾�","���ư���" };
	int SpellPrice[4] = { 300,800,1600,3000 };

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("���� ��ġ : ����");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk, Player.gold);

	setShop();

	setbuySpell();
	if (FireCannon)
		selectBoughtSpell(NameMenu[pos], 30, 10);
	else
		selectBuy(NameMenu[pos], SpellPrice[pos], 30, 10, RED);

	while (1)
	{
		int key = 0; // ����Ű �Է��� Ȯ���ϱ� ���� ����

		while (1)
		{
			key = _getch();
			if (key == 13) // ���͸� ������ ��
				break;

			pos = controlMenu(pos, 4); // pos ������ �� �� �ִ� �޴��� ������ ����
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
			Sleep(100); // getch �Լ��� �Է¹޴� �ӵ� ����
		}

		int count = 1;
		switch (pos)
		{
		case 0:
			if (FireCannon != 1)
			{
				checkGold(SpellPrice[pos], count, 1); // �������� ������ ��带 ������ �ִ��� Ȯ���ϴ� �Լ�
				Player.gold -= ((long long)SpellPrice[pos] * count);
				FireCannon = 1;

				gotoxy(30, 5);
				textcolor(RED);
				printf("���Ÿ� ���� %d Gold�� ���� �Ͽ����ϴ�..", (SpellPrice[pos] * count));
				gotoxy(30, 6);
				textcolor(GREEN);
				printf("%s �ֹ��� �����Ͽ����ϴ�!", NameMenu[pos]);
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
				printf("�̹� %s �ֹ��� �����Ͽ����ϴ�!", NameMenu[pos]);
				Sleep(500);
				system("cls");
				buySpell();
			}
			break;
		case 1:
			if (FireStorm != 1)
			{
				checkGold(SpellPrice[pos], count, 1); // �������� ������ ��带 ������ �ִ��� Ȯ���ϴ� �Լ�
				Player.gold -= ((long long)SpellPrice[pos] * count);
				FireStorm = 1;

				gotoxy(30, 5);
				textcolor(RED);
				printf("���Ÿ� ���� %d Gold�� ���� �Ͽ����ϴ�..", (SpellPrice[pos] * count));
				gotoxy(30, 6);
				textcolor(GREEN);
				printf("%s �ֹ��� �����Ͽ����ϴ�!", NameMenu[pos]);
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
				printf("�̹� %s �ֹ��� �����Ͽ����ϴ�!", NameMenu[pos]);
				Sleep(500);
				system("cls");
				buySpell();
			}
			break;
		case 2:
			if (HellFire != 1)
			{
				checkGold(SpellPrice[pos], count, 1); // �������� ������ ��带 ������ �ִ��� Ȯ���ϴ� �Լ�
				Player.gold -= ((long long)SpellPrice[pos] * count);
				HellFire = 1;

				gotoxy(30, 5);
				textcolor(RED);
				printf("���Ÿ� ���� %d Gold�� ���� �Ͽ����ϴ�..", (SpellPrice[pos] * count));
				gotoxy(30, 6);
				textcolor(GREEN);
				printf("%s �ֹ��� �����Ͽ����ϴ�!", NameMenu[pos]);
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
				printf("�̹� %s �ֹ��� �����Ͽ����ϴ�!", NameMenu[pos]);
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