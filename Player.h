#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Hand;
class Table;

#include "Hand.h"
#include "Table.h"

class Player {
	public:

	Player();

	// lets the player play a turn
	void turn();

	// 
	void add(Card * c);

	void print_hand();

	protected:
	int chips;
	Hand * hand;
	Table * table;

};


#endif