#include "main.h"

/* https://blog.naver.com/ifthe1201/221056588399 ��ũ�� �ִ� 1��(API�� �߰�)�� �ο��� */
void gotoxy(int x, int y)
{
	COORD cursorPOS = { x,y }; // Ŀ�� ��ġ�� �����ϴ� ����ü
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPOS); // Ŀ�� ��ġ �̵� �Լ�
}

void SetConsole() // �ܼ�â ���� �Լ�
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	system("mode con cols=150 lines=50"); // �ܼ�â ũ�� ����
	SetConsoleTitle(TEXT("RPG")); // �ܼ�â ���� ����
}

void textcolor(int colorNum) // https://dev-with-precious-dreams.tistory.com/5�� �ڵ带 �ο���
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}
