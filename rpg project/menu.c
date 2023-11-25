#include "main.h"

void playerStatsUI(int Player_hp, int Player_mp, int Player_atk, int Player_mtk)
{
	gotoxy(5, 3);
	textcolor(GREEN);
	printf("HP : %d", Player_hp);

	gotoxy(5, 4);
	textcolor(BLUE);
	printf("MP : %d", Player_mp);

	gotoxy(5, 5);
	textcolor(DarkRed);
	printf("ATK : %d", Player_atk);

	gotoxy(5, 6);
	textcolor(SkyBlue);
	printf("MTK : %d", Player_mtk);

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

void selectMenu(char NameMenu[]) // ������ �޴��� ǥ�����ִ� �Լ�
{
	textcolor(GREEN);
	printf("> %s", NameMenu);
	textcolor(WHITE);
}

void setTown() // Town �� �޴��� ���� ����ϴ� �Լ�
{
	int NumberMenu = 0;
	char NameMenu[3][NAME_SIZE] = { "�̵��ϱ�","�κ��丮","�޽��ϱ�" };

	gotoxy(5, 10);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(5, 15);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(5, 20);
	printf(" %s", NameMenu[NumberMenu++]);
}

void setmoveMap() // Move �� �޴��� ���� ����ϴ� �Լ�
{
	int NumberMenu = 0;
	char NameMenu[4][NAME_SIZE] = { "��ο� ��","����� ����","�ı��� ����","���ư���" };

	gotoxy(5, 10);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(5, 15);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(5, 20);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(5, 25);
	printf(" %s", NameMenu[NumberMenu++]);
}

void setDarkForest() // DarkForest �� �޴��� ���� ����ϴ� �Լ�
{
	int NumberMenu = 0;
	char NameMenu[3][NAME_SIZE] = { "Ž���ϱ�","�κ��丮","������ ���ư���" };

	gotoxy(5, 10);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(5, 15);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(5, 20);
	printf(" %s", NameMenu[NumberMenu++]);
}

void setBattleScene() // BattleScene �� �޴��� ���� ����ϴ� �Լ�
{
	int NumberMenu = 0;
	char NameMenu[3][NAME_SIZE] = { "�����ϱ�","�ֹ�����","��������" };

	gotoxy(30, 10);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(30, 15);
	printf(" %s", NameMenu[NumberMenu++]);
	gotoxy(30, 20);
	printf(" %s", NameMenu[NumberMenu++]);
}