#include<iostream>
#include<time.h>
#include<conio.h>
#include<Windows.h> //используется всего 1 раз функция sleep. Можно отключить
#include"desk.h"
#include"player.h"

#define granica_diller 17
using namespace std;

void main()
{
	//setlocale(LC_ALL, "rus");
	srand(time(0));
	desk h;
	char str[20];
	cout << "Hello, my friend!\n";
	cout << "What is your name? ";
	gets_s(str);
	player Bibop(str, 10000);
	player Diller("Ivan", 999999);
	char ch;
	int rate;//	размер ставки
	enum actions_player{hit_me=1, sufficient};
	int action;
	int sum_value_player, sum_value_diller;
	do {
		system("cls");
		rate = 0;
		sum_value_diller = 0;
		sum_value_player = 0;
		cout << "\nAmount rate: ";
		cin >> rate;
		cin.ignore();
		sum_value_player = Bibop.newgame(h.get_card(), h.get_card(), rate);
		if (sum_value_player) {
			cout << "Your cards\n";
			Bibop.print_cards();
			sum_value_diller = Diller.newgame(h.get_card(), h.get_card(), rate);
			switch (sum_value_player) {
			case ocko://blackjack у игрока
				cout << "Diller cards\n";
				Diller.print_cards();
				if (sum_value_player > sum_value_diller) {
					Bibop.money(rate * 2);
					cout << "You win!\n";
				}
				else {
					cout << "Draw!\n";//ничья
					Bibop.money(rate);
					Diller.money(rate);
				}
				do {
					cout << "Start new game? Y/N: ";
					ch = _getch();
				} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
				break;
			default:
				cout << "Diller cards:\n";
				Diller.print_cards(false);
				do {
					cout << "1. Hit me" << endl;//еще карту
					cout << "2. Sufficient" << endl;//достаточно
					cin >> action;
					if (action == hit_me) {
						sum_value_player = Bibop + h.get_card();
						system("cls");
						cout << "Your cards:\n";
						Bibop.print_cards();
						cout << "Diller cards\n";
						Diller.print_cards(false);
					}
				} while (action != sufficient && sum_value_player < ocko);
				if (sum_value_player > ocko) {
					system("cls");
					cout << "Your cards: " << endl;
					Bibop.print_cards();
					cout << "Diller cards: " << endl;
					Diller.print_cards();
					cout << "You lose!" << endl;
					Diller.money(rate * 2);
					do {
						cout << "Start new game? Y/N";
						ch = _getch();
					} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
				}
				else {
					while (sum_value_diller < granica_diller) {
						sum_value_diller = Diller + h.get_card();
						system("cls");
						cout << "Your cards: " << endl;
						Bibop.print_cards();
						cout << "Diller cards: " << endl;
						Diller.print_cards();
						Sleep(2000);
					}
					if (sum_value_player > sum_value_diller || sum_value_diller > ocko) {
						system("cls");
						cout << "Your cards:\n";
						Bibop.print_cards();
						cout << "Diller cards\n";
						Diller.print_cards();
						cout << "Congratulations! You win!\n";
						Bibop.money(rate * 2);
						do {
							cout << "Start new game? Y/N";
							ch = _getch();
						} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
					}
					else if (sum_value_diller > sum_value_player) {
						system("cls");
						cout << "Your cards: " << endl;
						Bibop.print_cards();
						cout << "Diller cards: " << endl;
						Diller.print_cards();
						cout << "You lose!\n";
						Diller.money(rate * 2);
						do {
							cout << "Start new game? Y/N";;
							ch = _getch();
						} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
					}
					else {
						system("cls");
						cout << "Your cards: " << endl;
						Bibop.print_cards();
						cout << "Diller cards: " << endl;
						Diller.print_cards();
						Bibop.money(rate);
						Diller.money(rate);
						cout << "Draw\n";
						do {
							ch = _getch();
						} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
					}
				}
				break;
			}
		}
		else {
			cout << "You don't have money! Restart game? Y/N";
			do {
				ch = _getch();
			} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
		}
	} while (ch != 'n' && ch!='N');
	system("pause");
}
