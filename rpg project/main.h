/* https://blog.naver.com/ifthe1201/221056588399 ��ũ�� �ִ� 1��(���ȭ�� ���� ��� ����)�� �ο��� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

// ����� ���� �������
#include "menu.h" // �޴��� ���� �Լ��� ���� �������
#include "map.h" // ���� �����ϴ� �Լ��� ���� �������
#include "battle.h" // ������ ���� �Լ��� ���� �������

#define NAME_SIZE 32 // �̸��� �ִ� ũ�� ����

enum ColorType // enum �Լ��� ������ ������
{
	BLACK,
	DarkBLUE,
	DarkGreen,
	DarkSkyBlue,
	DarkRed,
	DarkPurple,
	DarkYellow,
	GRAY,
	DarkGray,
	BLUE,
	GREEN,
	SkyBlue,
	RED,
	PURPLE,
	YELLOW,
	WHITE
} COLOR;

enum locationMap // �� ���� ��ȣ�� enum �Լ��� ������
{
	Loc_Town,
	Loc_DarkForest,
};

struct _Player
{
	int hp;
	int mp;
	int atk;
	int mtk;
} Player;

typedef struct _Monster
{
	char name[NAME_SIZE];
	int hp;
	int atk;
	int mtk;
} Monster;

Monster Pig;
Monster Slime;
Monster Goblin;


void gotoxy(int x, int y);
void SetConsole();
void textcolor(int colorNum);