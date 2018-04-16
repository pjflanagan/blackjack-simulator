#ifndef DEALER_H
#define DEALER_H

class Hand;
class Table;

#include "Hand.h"
#include "Table.h"

class Dealer {
	public:
	Dealer();
	Dealer(Table * t);

	void shuffle();

	// burns a card
	void burn();

	Card * deal();

	void add(Card * c);

	private:
	Hand * hand;
	Table * table;
};


#endif