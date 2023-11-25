#include "main.h"

/* https://blog.naver.com/ifthe1201/221056588399 링크에 있는 1번(API를 추가)을 인용함 */
void gotoxy(int x, int y)
{
	COORD cursorPOS = { x,y }; // 커서 위치를 저장하는 구조체
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPOS); // 커서 위치 이동 함수
}

void SetConsole() // 콘솔창 세팅 함수
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	system("mode con cols=150 lines=50"); // 콘솔창 크기 변경
	SetConsoleTitle(TEXT("RPG")); // 콘솔창 제목 변경
}

void textcolor(int colorNum) // https://dev-with-precious-dreams.tistory.com/5의 코드를 인용함
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}
