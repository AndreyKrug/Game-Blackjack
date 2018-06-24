#include "player.h"
#include<iostream>
using namespace std;

void player::smena(){
	//согласно правилам, если у игрока набралось более 21 очка
	//тузы в его колоде становятся единицами
	if (sum_value > ocko) {
		for (int i = 0; i < kol_kard; i++) {
			if (mas[i].get_value() == 11) mas[i].set_value(1);
		}
	}
	sum_value = 0;
	for (int i = 0; i < kol_kard; i++)
		sum_value += mas[i].get_value();
}

player::player(char* str, int cashbox){
	strcpy_s(name, str);
	mas = nullptr;
	this->cashbox = cashbox;//сумма денег у игрока до начала игры
	kol_kard = 0;
	sum_value = 0;
}

int player::newgame(card & a, card & b, int dan){
	//если денег больше чем ставка(dan), возвращается сумма очков, иначе нуль
	if (dan>cashbox) return 0;
	if (mas != nullptr) {
		free(mas);
		kol_kard = 0;
		sum_value = 0;
	}
	mas = (card*)malloc((kol_kard + 2) * sizeof(card));
	mas[kol_kard] = a;
	sum_value += mas[kol_kard++].get_value();
	mas[kol_kard] = b; 
	sum_value += mas[kol_kard++].get_value();
	cashbox -= dan;
	smena();
	return sum_value;
}

int player::operator+(const card & a){
	//добавляется 1 карта и возвр. сумму очков
	mas = (card*)realloc(mas, (kol_kard + 1) * sizeof(card));
	mas[kol_kard] = a;
	sum_value += mas[kol_kard++].get_value();
	smena();
	return sum_value;
}

void player::print_cards(bool who){
	if (who) {
		for (int i = 0; i < kol_kard; i++)
			mas[i].print_card();
		cout << "\n";
		cout << "Sum of cards: ";
		cout << sum_value << endl;
		cout << "Cashbox: " << cashbox << endl;
	}
	else {
		cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191 << endl;
		cout << (char)179 << (char)35 << (char)35 <<(char)35<< (char)179 << endl;
		cout << (char)179 << (char)35 << (char)35 << (char)35 << (char)179 << endl;
		cout << (char)179 << (char)35 << (char)35 << (char)35 << (char)179 << endl;
		cout << (char)179 << (char)35 << (char)35 << (char)35 << (char)179 << endl;
		cout << (char)179 << (char)35 << (char)35 << (char)35 << (char)179 << endl;
		cout << (char)192 << (char)196 << (char)196 << (char)196 << (char)217 << endl;
		for (int i = 1; i < kol_kard; i++)
			mas[i].print_card();
	}
}

void player::money(int zn){
	//забрать выигрыш
	cashbox += zn;
}

player::~player(){
	free(mas);
}
