/* https://blog.naver.com/ifthe1201/221056588399 링크에 있는 1번(모듈화를 위한 헤더 세팅)을 인용함 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

// 사용자 정의 헤더파일
#include "menu.h" // 메뉴에 관한 함수를 담은 헤더파일
#include "map.h" // 맵을 생성하는 함수를 담은 헤더파일
#include "battle.h" // 전투에 관한 함수를 담은 헤더파일

#define NAME_SIZE 32 // 이름의 최대 크기 설정

enum ColorType // enum 함수로 색상을 열거함
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

enum locationMap // 각 맵의 번호를 enum 함수로 열거함
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