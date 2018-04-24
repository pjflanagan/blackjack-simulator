#ifndef HUMAN_CPP
#define HUMAN_CPP

#include <iostream>
#include <string>
#include <vector>

#include "Player.h"
#include "Rules.cpp"
#include "Table.h"

class PlayerHuman : public Player {
	public:

	PlayerHuman(){}

	PlayerHuman(Table * t, std::string n) {
		table = t;
		name = n;
		Player::Player();
	}

	void bet() override {
		std::cout << name << " has " << chips << " chips to wager. Place bet: ";
		int wager;
		std::cin >> wager;
		chips -= wager;
		hand->place_bet(wager);
	}

	void turn() override {
		std::cout << "\n";
		bool is_first_move = true;
		bool end = false;
		while(!end){
			print_hand(hand);
			end = move(hand, is_first_move);
			is_first_move = false;
		}
	}

	protected:

	// returns false if turn is over
	bool move(HandPlayer * h, bool is_first_move) override {
		if(is_first_move){
			//if the player has blackjack then let them win
			//otherwise ask for input
			//if the player asks to double down but cant afford to then ask again
			//if the player asks to split but cant or cant afford to then ask again
			//else do what the player says to
		}
		//if the hand is bust then bust them
		
		return true;
	}
};

#endif