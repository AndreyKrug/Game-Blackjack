#include "card.h"
#include<iostream>
using namespace std;
card::card(){
}

card::card(char name[], int value, char suit){
	strcpy_s(this->name, name);
		this->value = value;
		this->suit = suit;
	}

void card::set_card(char *str, int value, char suit){
	strcpy_s(this->name, str);
	this->value = value;
	this->suit = suit;
}

void card::print_card(){
	cout << (char)218 << (char)196 << (char)196 << (char)196 << (char)191 << endl;
	if (_stricmp(name, "10") == 0) cout << (char)179 << " " << name << (char)179 << endl;
	else cout << (char)179 << " " << name << " " << (char)179 << endl;
	cout << (char)179 << "   " << (char)179 << endl;
	cout << (char)179 << " " << (char)suit << " " << (char)179 << endl;
	cout << (char)179 << "   " << (char)179 << endl;
	if (_stricmp(name, "10") == 0) cout << (char)179 << " " << name << (char)179 << endl;
	else cout << (char)179 << " " << name << " " << (char)179 << endl;
	cout << (char)192 << (char)196 << (char)196 << (char)196 << (char)217 << endl;
}

int card::get_value(){
	return value;
}

void card::set_value(int value){
	//если сумма карт у игрока больше 21 и в колоде нахожу туз предыдущей функцией,
	//этой функцией передаю значение тузу равным единице
	this->value = value;
}

card::~card()
{
}
