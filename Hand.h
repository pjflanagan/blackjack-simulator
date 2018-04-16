#ifndef HAND_H
#define HAND_H

#include <vector>

#include "Card.cpp"
#include "Player.h"
#include "Dealer.h"

class Hand {
	public:

	protected:
	std::vector<Card *> cards;

};

// Player Hand extends hand
class PlayerHand : public Hand {

	public:

	private:
	int wager;
	Player * player;

};

// Dealer Hand extends hand
class DealerHand : public Hand {
	public:

	private:
	Dealer * dealer;
};

#endif