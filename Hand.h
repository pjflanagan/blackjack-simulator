#ifndef HAND_H
#define HAND_H

#include <vector>
#include <string>

class Dealer;

#include "Card.cpp"
#include "Player.h"
#include "Dealer.h"

class Hand {
	public:

	Hand();

	void reset();

	void add(Card * c);

	int sum();

	bool is_bust();

	void set_bust(bool b);

	std::string to_string() const;

	std::string case_type(bool is_first_move);

	bool has_ace();

	protected:
	std::vector<Card *> cards;
	bool bust;

};

// Player Hand extends hand
class PlayerHand : public Hand {
	public:
	PlayerHand();

	void reset();

	void place_bet(int w);

	int get_bet();

	Card * split();

	void double_down();

	private:
	int wager;
	Player * player;

};

// Dealer Hand extends hand
class DealerHand : public Hand {
	public:
	DealerHand();

	Card * get_upcard();

	Card * get_downcard();

	int dealer_sum(){
		if(has_ace())
			return sum() + 10;
		return sum();
	}

	private:
	Dealer * dealer;
};

#endif