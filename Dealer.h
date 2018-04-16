#ifndef DEALER_H
#define DEALER_H

#include <iostream>

class DealerHand;
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

	private:
	DealerHand * hand;
	Table * table;
};


#endif