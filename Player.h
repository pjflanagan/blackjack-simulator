#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class PlayerHand;
class Table;

#include "Hand.h"
#include "Table.h"

class Player {
	public:

	Player();

	void reset();

	void add(Card * c);

	void print_hand();

	virtual void bet();

	virtual void turn();

	protected:
	virtual bool move(int m);

	int chips;
	bool is_split;
	PlayerHand * hand;
	PlayerHand * split_hand;
	Table * table;

};


#endif