#pragma once

#define NAME_SIZE 32 // 이름의 최대 크기 설정

int numberMap;

void playerStatsUI(int Player_hp, int Player_mp, int Player_atk, int Player_mtk, double Player_gold);
int controlMenu(int numberPos, int numberMenu);

void selectMenu(char* NameMenu, int x, int y);
void selectBuy(char* NameMenu, int price, int x, int y, int color);
void selectSpell(char* NameMenu, int needMp, int x, int y);
void selectNotUseSpell(char* NameMenu, int x, int y);
void selectBoughtSpell(char* NameMenu, int x, int y);

void setmoveMap();

void setTown();
void setShop();
void setbuyPotion();
void setbuySpell();

void setDarkForest();
void setSilentCave();
void setDestroyedRuins();

void setBattleScene();
void Spell(int numberMap, char monsterName[NAME_SIZE], int monsterHp, int monsterAtk, int monsterMtk, int monsterGold, char level[NAME_SIZE]);

void Town();

void shop();
int getcount();

void checkGold(int PotionPrice, int count, int shopNumber);
void checkSpell();
void checkMp();

void buyPotion();
void buySpell();

void moveMap();

void DarkForest();
void SilentCave();
void DestroyedRuins();

void battleScene(int numberMap, char monsterName[NAME_SIZE], int monsterHp, int monsterAtk, int monsterMtk, int monsterGold, char level[NAME_SIZE]);