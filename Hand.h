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

	std::string to_string() const;

	protected:
	std::vector<Card *> cards;

};

// Player Hand extends hand
class PlayerHand : public Hand {
	public:
	PlayerHand();

	void reset();

	void place_bet(int w);

	//dealer to string
	// "Dealer is showing "

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