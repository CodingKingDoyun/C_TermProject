#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

void battleScene(int numberMap, char monsterName[NAME_SIZE], int monsterHp, int monsterAtk, int monsterMtk, int r)
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

	// ���跹�� �����
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