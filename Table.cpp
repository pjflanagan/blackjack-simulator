#ifndef TABLE_CPP
#define TABLE_CPP

#include <string>
#include <iostream>

#include "Player.cpp"
#include "Dealer.cpp"

const int STAND = 0;
const int HIT = 1;
const int SPLIT = 2;
const int DOUBLE = 3;

const int MIN_BET = 10;
const int MAX_BET = 50;

const double BJ_PAYOUT = 3/2;

const int DECKS = 5;

const std::string SUITS[4] = {"Spades", "Hearts", "Clubs", "Diamonds"};
const std::string FACES[13] = {
	"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};
const int VALUES[13] = {1,2,3,4,5,6,7,8,9,10,10,10,10};

const int DEAL = 0;
const int PLAY = 1;
const int END = 2;


class Table{
	public:

	Table(){
		state = 0;
		shoe = Shoe();
		dealer = Dealer(shoe);
		player = Player(dealer);

		std::string in;
		while(std::cin >> in)
			play();
	};

	void play(){
		switch(state){
			case DEAL:
				player.bet();
				dealer.burn();
				player.recieve(dealer.deal());
				dealer.facedown();
				player.recieve(dealer.deal());
				dealer.faceup();
				state = PLAY;
				break;

			case PLAY:
				player.action();
				state = END;
				break;

			case END:
				dealer.shuffle();
				state = DEAL;
				break;
		}
	}

	private:
	int state;
	Player player;
	Dealer dealer;
	Shoe shoe;

};





#endif