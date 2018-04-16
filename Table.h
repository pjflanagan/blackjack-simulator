#ifndef TABLE_H
#define TABLE_H

#include <vector>

#include "Shoe.cpp"
#include "Dealer.h"
#include "Player.h"


class Table {
	public:
	Table();

	// starts the game
	void play();

	// shuffles the shoe
	void shuffle();

	// draws a card
	Card * draw();

	private:

	// goes around the table and plays each turn
	void round();

	// dealing portion of the round
	void deal();

	Shoe shoe;
	std::vector<Player *> players;
	Dealer dealer;

};



#endif