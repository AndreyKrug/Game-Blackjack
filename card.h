#pragma once
class card
{
	char name[3];
	int value;//значение
	char suit;//масть
public:
	card();
	card(char name[], int value, char suit);
	void set_card(char *str, int value, char suit);
	void print_card();
	int get_value();
	void set_value(int value);
	~card();
};
