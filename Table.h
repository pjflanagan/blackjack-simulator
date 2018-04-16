#ifndef TABLE_H
#define TABLE_H

#include <vector>

#include "Shoe.cpp"
#include "Dealer.h"
#include "Player.h"


class Table {
	public:
	Table();

	private:
	Shoe shoe;
	std::vector<Player *> players;
	Dealer dealer;

};

#endif