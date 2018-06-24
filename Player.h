#pragma once
#include"card.h"
#define ocko 21
class player
{
	char name[20];
	card *mas;
	int cashbox;
	int kol_kard;
	int sum_value;
	void smena();
	
public:
	player(char *str, int cashbox);
	int newgame(card &a, card &b, int dan);
	int operator+(const card &a);
	void print_cards(bool who=true);
	void money(int zn);
	~player();
};
