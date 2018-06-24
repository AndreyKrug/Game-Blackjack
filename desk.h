#pragma once
#include "card.h"
#define kol 52

class desk
{
	card *mas;
	enum suit{
		chirwa=3,bubna,chrest,peak};
	int i;//количество выданных карт
public:
	desk();
	~desk();
	card get_card();
	void print_desk();
};

