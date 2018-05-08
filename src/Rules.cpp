#ifndef RULES_CPP
#define RULES_CPP

#include <string>

// MOVES
static const char STAND = 'S';
static const char HIT = 'H';
static const char SPLIT = 'P';
static const char DOUBLE = 'D';
static const char BLACKJACK = 'B';
static const char BUST = 'X';

// CHIPS
static const int MIN_BET = 10;
static const int MAX_BET = 50;
static const int AI_CASHOUT = 250;
static const int COUNTER_CASHOUT = 250;
//static const double BLACKJACK_PAYOUT = 1.2; // DO NOT PLAY
static const double BLACKJACK_PAYOUT = 1.5;
//static const double BLACKJACK_PAYOUT = 2; // DOES NOT HAPPEN
static const double PAYOUT = 2;
static const double PUSH = 1;
static const double LOSE = 0;

// CARDS
static const int DECKS = 5;
static const std::string SUITS[4] = {"Spades", "Hearts", "Clubs", "Diamonds"};
static const std::string FACES[13] = {
	"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};
static const int VALUES[13] = {1,2,3,4,5,6,7,8,9,10,10,10,10};
// static const std::string FACES[13] = {
// 	"ACE","ACE","ACE","ACE","ACE","ACE","Ten","Ten","Ten","Ten","Ten","Ten","Ten"
// };
// static const int VALUES[13] = {1,1,1,1,1,1,10,10,10,10,10,10,10};


// DEALER
//static const bool HIT_ON_SOFT_17 = false;
static const int DEALER_STOP = 17;
//static const bool SPLIT_BY_FACE = true; // when false this means you cant split 10 - Q
//surrender
//double down after split


#endif