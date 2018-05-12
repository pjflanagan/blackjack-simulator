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
static const int AI_CASHOUT = 200;
static const int COUNTER_CASHOUT = 200;
static const double PAYOUT = 1; // 1:1
static const double PUSH = 0;
static const double LOSE = -1;
static const double BLACKJACK_PAYOUT = 1.5; // 3:2
//static const double BLACKJACK_PAYOUT = 1.2; // 6:5 DO NOT PLAY


// CARDS
static const int DECKS = 5;
static const std::string SUITS[4] = {"Spades", "Hearts", "Clubs", "Diamonds"};
static const std::string FACES[13] = {
	"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};
static const int VALUES[13] = {1,2,3,4,5,6,7,8,9,10,10,10,10};


// DEALER
static const int DEALER_STOP = 17;
//static const bool HIT_ON_SOFT_17 = false;


// PLAYER
static const double MAX_ROUNDS = 100000;
//static const bool SPLIT_BY_FACE = true; // when false this means you cant split 10 - Q
//surrender
//double down after split


#endif