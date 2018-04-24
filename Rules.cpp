#ifndef RULES_CPP
#define RULES_CPP

#include <string>

// MOVES
const char STAND = 'S';
const char HIT = 'H';
const char SPLIT = 'P';
const char DOUBLE = 'D';
const char BLACKJACK = 'B';
const char BUST = 'X';

// CHIPS
const int MIN_BET = 10;
const int MAX_BET = 50;
const int CASHOUT = 250;
const double BLACKJACK_PAYOUT = 3/2;
const double PAYOUT = 2;
const double PUSH = 1;
const double LOSE = 0;

// CARDS
const int DECKS = 1;
const std::string SUITS[4] = {"Spades", "Hearts", "Clubs", "Diamonds"};
const std::string FACES[13] = {
	"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};
const int VALUES[13] = {1,2,3,4,5,6,7,8,9,10,10,10,10};

// DEALER
const bool HIT_ON_SOFT_17 = false;
const int DEALER_STOP = 17;

#endif