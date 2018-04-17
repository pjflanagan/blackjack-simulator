#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class PlayerHand;
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

	bool is_broke();

	virtual void bet();

	virtual void turn();

	protected:
	virtual bool move(PlayerHand * h, bool is_first_move);
	virtual void split();

	bool double_down(); 

	bool hit(PlayerHand * h); 
	bool check_bust(PlayerHand * h);
	void bust(PlayerHand * h); // reset hand wager to 0 to avoid double payout
	void payout(PlayerHand * h, double rate); // reset hand wager to 0 to avoid double payout


	std::string name;
	int chips;
	bool is_split;
	PlayerHand * hand;
	PlayerHand * split_hand;
	Table * table;

};


#endif