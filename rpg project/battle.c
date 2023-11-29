#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

void battleScene(int numberMap, char monsterName[NAME_SIZE], int monsterHp, int monsterAtk)
{
	int key = 0; // ����Ű �Է��� Ȯ���ϱ� ���� ����
	int pos = 0; // 0 - �����ϱ�, 1 - �ֹ� ����, 2 - ��������
	char NameMenu[3][NAME_SIZE] = { "�����ϱ�","�ֹ�����","��������" };

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