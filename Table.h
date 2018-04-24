#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <iostream>

#include "Shoe.cpp"
#include "Dealer.h"
#include "Player.h"


class Table {
	public:
	Table();

	void reset();

	// starts the game
	void play();

	// shuffles the shoe
	void shuffle();

	// draws a card
	Card * draw();

	Card * upcard();

	private:

	// goes around the table and plays each turn
	void round();

	// dealing portion of the round
	void deal();

	Shoe shoe;
	std::vector<Player *> players;
	Dealer dealer;
	int round_count;

};



#endif