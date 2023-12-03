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
	char NameMenu[3][NAME_SIZE] = { "�̵��ϱ�","�κ��丮","�޽��ϱ�" };

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
		playerStatsUI(Player.hp, Player.mp, Player.atk, Player.mtk);
		rest();
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
		Sleep(400);
		printf(".");
		Sleep(400);
		printf(".");
		Sleep(400);
		gotoxy(30, 2);
		printf("            ");

		srand(time(NULL));
		int r = rand() % 100;
		if (r <= 39) // 40% Ȯ���� ������ ����
			battleScene(numberMap, Pig.name, Pig.hp, Pig.atk, Pig.mtk, r); // ����
		else if (r <= 69) // 30% Ȯ���� �������� ����
			battleScene(numberMap, Slime.name, Slime.hp, Slime.atk, Slime.mtk, r); // ������
		else // 30% Ȯ���� ����� ����
			battleScene(numberMap, Goblin.name, Goblin.hp, Goblin.atk, Goblin.mtk, r); // ���
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