#include "main.h"

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

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk); // �÷��̾��� ���� UI�� �ҷ���

	setTown(); // Town �� �޴��� ���� ����ϴ� �Լ�
	gotoxy(5, 10);
	selectMenu(NameMenu[pos]);

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
		Sleep(100); // getch �Լ��� �Է¹޴� �ӵ� ����
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
		printf("�޽��ϴ���");
		for (int i = 0; i < 3; i++)
		{
			Sleep(500);
			printf(".");
		}
		Sleep(500);
		gotoxy(30, 2);
		printf("             "); // ����� ���� ����� ���� ���� ���

		Player.hp = 100;
		Player.mp = 30;
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

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk); // �÷��̾��� ���� UI�� �ҷ���

	setmoveMap(); // Move �� �޴��� ���� ����ϴ� �Լ�
	gotoxy(5, 10);
	selectMenu(NameMenu[pos]);

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
		break;
	case 2: // �ı��� ����
		system("cls");
		break;
	case 3: // ���ư���
		system("cls");
		previousMap();
		break;
	default: break;
	}
}

void DarkForest()
{
	int key = 0; // ����Ű �Է��� Ȯ���ϱ� ���� ����
	int pos = 0; // 0 - Ž���ϱ�, 1 - �κ��丮, 2 - ������ ���ư���
	char NameMenu[3][NAME_SIZE] = { "Ž���ϱ�","�κ��丮","������ ���ư���" };

	numberMap = Loc_DarkForest; // '���ư���' �� �����Ͽ��� ��, ���� ������ ���ư��� ���� ���� ���� �ѹ��� ����

	gotoxy(0, 0);
	textcolor(WHITE);
	printf("���� ��ġ : ��ο� ��");

	playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk); // �÷��̾��� ���� UI�� �ҷ���

	setDarkForest(); // DarkForest �� �޴��� ���� ����ϴ� �Լ�
	gotoxy(5, 10);
	selectMenu(NameMenu[pos]);

	while (1)
	{
		key = _getch();
		if (key == 13) // ���͸� ������ ��
			break;

		pos = controlMenu(pos, 3); // pos ������ �� �� �ִ� �޴��� ������ ����
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

		srand((unsigned)time(NULL));

		if ((rand() % 100) <= 44) // 45% Ȯ���� ������ ����
		{
			srand((unsigned)time(NULL));

			if ((rand() % 100) <= 69)
				battleScene(numberMap, Pig.name, Pig.hp, Pig.atk, Pig.mtk, "Normal");

			else if ((rand() % 100) <= 89)
				battleScene(numberMap, Pig.name, Pig.hp * 2, Pig.atk * 2, Pig.mtk * 2, "Hard");

			else
				battleScene(numberMap, Pig.name, Pig.hp * 3, Pig.atk * 3, Pig.mtk * 3, "Extreme");
		}
		else if ((rand() % 100) <= 79) // 35% Ȯ���� �������� ����
		{
			srand((unsigned)time(NULL));

			if ((rand() % 100) <= 69)
				battleScene(numberMap, Slime.name, Slime.hp, Slime.atk, Slime.mtk, "Normal");

			else if ((rand() % 100) <= 89)
				battleScene(numberMap, Slime.name, Slime.hp * 2, Slime.atk * 2, Slime.mtk * 2, "Hard");

			else
				battleScene(numberMap, Slime.name, Slime.hp * 3, Slime.atk * 3, Slime.mtk * 3, "Extreme");
		}
		else // 30% Ȯ���� ����� ����
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

void previousMap() // ���� ������ ���ư��� �Լ�
{
	switch (numberMap) // ���� ���� ��ȣ�� Ȯ���Ͽ� �ش��ϴ� �ѹ��� ������ ���ư�
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
	int pos = 0; // 0 - �����ϱ�, 1 - �ֹ� ����, 2 - ��������
	char NameMenu[3][NAME_SIZE] = { "�����ϱ�","�ֹ�����","��������" };

	// ���� ���� �޴��� �����
	switch (numberMap)
	{
	case 0:
		break;
	case 1:
		setDarkForest();
	default: break;
	}

	setBattleScene(); // BattleScene �� �޴��� ���� ����ϴ� �Լ�
	gotoxy(30, 10);
	selectMenu(NameMenu[pos]);

	// ������ ������ �����
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
			Sleep(100); // getch �Լ��� �Է¹޴� �ӵ� ����
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

		playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk); // �÷��̾��� ���� UI�� �ҷ���

		if (Player.hp <= 0)
		{
			gotoxy(55, 2);
			textcolor(RED);
			printf("����� ����Ͽ����ϴ�..");
			Sleep(1000);

			system("cls");
			Town();
		}
	}

	gotoxy(55, 2);
	textcolor(YELLOW);
	printf("���͸� óġ�Ͽ����ϴ�!");
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