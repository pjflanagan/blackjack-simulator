#ifndef DEALER_H
#define DEALER_H

#include <iostream>

class HandDealer;
class Table;

#include "Hand.h"
#include "Table.h"

class Dealer {
	public:
	Dealer();
	Dealer(Table * t);

	void reset();

	void shuffle();

	// burns a card
	void burn();

	Card * deal();

	Card * get_upcard();

	void add(Card * c);

	void move();

	Hand * get_hand();

	private:
	HandDealer * hand;
	Table * table;
};


#endif