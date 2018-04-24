#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class HandPlayer;
class Table;
class Hand;

#include "Hand.h"
#include "Table.h"

class Player {
	public:

	Player();

	void reset();

	void add(Card * c);

	void check_beats(Hand * hand);

	void print_hand(Hand * h);

	bool is_done();

	virtual void bet();

	virtual void turn();

	protected:
	virtual bool move(HandPlayer * h, bool is_first_move);
	void split();

	bool double_down(); 

	bool hit(HandPlayer * h); 
	bool check_bust(HandPlayer * h);
	void bust(HandPlayer * h); // reset hand wager to 0 to avoid double payout
	void payout(HandPlayer * h, double rate); // reset hand wager to 0 to avoid double payout


	std::string name;
	int chips;
	bool is_split;
	HandPlayer * hand;
	HandPlayer * split_hand;
	Table * table;

};


#endif