#pragma once

#define NAME_SIZE 32 // �̸��� �ִ� ũ�� ����

int numberMap;

void previousMap();

void Town();
void inventory();

void moveMap();

void DarkForest();

void battleScene(int numberMap, char monsterName[NAME_SIZE], int monsterHp, int monsterAtk, int monsterMtk, char level[NAME_SIZE]);