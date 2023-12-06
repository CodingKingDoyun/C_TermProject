#define _CRT_SECURE_NO_WARNINGS
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

int main()
{
	srand((unsigned)time(NULL)); // 시드값 초기화

	// 플레이어의 초기 스텟 초기화
	Player.hp = 100;
	Player.mp = 6;
	Player.atk = 5;
	Player.mtk = 8;
	Player.gold = 0;

	// 플레이어의 초기 주문 초기화
	FireBall = 1;
	FireCannon = 0;
	FireStorm = 0;
	HellFire = 0;

	// 플레이어가 휴식하기를 선택할 때, 최대 HP,MP만큼 회복하기 위해 max변수 선언
	Player_maxHp = Player.hp; 
	Player_maxMp = Player.mp;

	// DarkForest 몬스터 스텟
	strcpy(Pig.name, "돼지");
	Pig.hp = 8;
	Pig.atk = 1;
	Pig.mtk = 0;
	Pig.gold = 3;

	strcpy(Slime.name, "슬라임");
	Slime.hp = 20;
	Slime.atk = 4;
	Slime.mtk = 0;
	Slime.gold = 7;

	strcpy(Goblin.name, "고블린");
	Goblin.hp = 35;
	Goblin.atk = 7;
	Goblin.mtk = 0;
	Goblin.gold = 12;

	// SilentCave 몬스터 스텟
	strcpy(Bat.name, "박쥐");
	Bat.hp = 16;
	Bat.atk = 2;
	Bat.mtk = 1;
	Bat.gold = 9;

	strcpy(Troll.name, "트롤");
	Troll.hp = 40;
	Troll.atk = 10;
	Troll.mtk = 0;
	Troll.gold = 21;

	strcpy(Demon.name, "악마");
	Demon.hp = 70;
	Demon.atk = 4;
	Demon.mtk = 12;
	Demon.gold = 36;

	// DestroyedRuins 몬스터 스텟
	strcpy(Guardian.name, "가디언");
	Guardian.hp = 50;
	Guardian.atk = 15;
	Guardian.mtk = 0;
	Guardian.gold = 100;

	strcpy(Livingarmor.name, "살아있는 갑옷");
	Livingarmor.hp = 100;
	Livingarmor.atk = 0;
	Livingarmor.mtk = 8;
	Livingarmor.gold = 250;

	strcpy(Dragon.name, "유적 드래곤");
	Dragon.hp = 150;
	Dragon.atk = 16;
	Dragon.mtk = 12;
	Dragon.gold = 750;


	SetConsole(); // 콘솔창 세팅

	Town();

	system("pause");
	return 0;
}