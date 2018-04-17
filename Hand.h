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

	std::string to_string() const;

	std::string case_type(bool is_first_move);

	protected:
	std::vector<Card *> cards;

	bool has_ace();

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

	private:
	Dealer * dealer;
};

#endif