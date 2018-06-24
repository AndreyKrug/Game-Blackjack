#include "desk.h"
#include<iostream>
using namespace std;
char *title[] = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
desk::desk(){
	int i = 0;
	mas = new card[kol];
	int t = chirwa;
	while (t <= peak) {
		for (int k = 0; k < 13; k++) {
			if (k >= 0 && k <= 8) mas[i++].set_card(title[k], k + 2, t);
			else if (k > 8 && k <= 11) mas[i++].set_card(title[k], 10, t);
			else mas[i++].set_card(title[k], 11, t);
		}
		t++;
	}
	//перетасовка карт до начала игры
	card temp;
	for (i = 0; i < kol; i++) {
		int t = rand() % kol;
		temp = mas[t];
		mas[t] = mas[i];
		mas[i] = temp;
	}
	i = 0;
}

desk::~desk(){
	delete[]mas;
}

card  desk::get_card(){
	//выдать карту из колоды
	if (i == kol) i = 0;
	return mas[i++];
}

void desk::print_desk(){
	//печать колоды
	for (int i = 0; i < kol; i++) {
		cout << i << ")\t";
		mas[i].print_card();
	}
}
