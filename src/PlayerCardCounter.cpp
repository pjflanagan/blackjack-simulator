#ifndef CARDCOUNT_CPP
#define CARDCOUNT_CPP

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

#include "Player.h"
#include "Rules.cpp"
#include "Cases.cpp"
#include "Table.h"
#include "PlayerAI.cpp"

class PlayerCardCounter : public PlayerAI {
	public:

	PlayerCardCounter(Table * t, std::string n){
		table = t;
		name = n;
		Player::init();
	};

	// just overwrite bet to bet min every time until count is high enough
	void bet() override {
		int true_count = table->get_count();
		int betting_unit = chips / 10; // should be 1/1000 of total bankroll but we will do less
		int wager = (true_count - 1) * betting_unit;

		if(wager > chips) wager = chips;

		if(wager < MIN_BET) wager = MIN_BET;
		else if(wager > MAX_BET) wager = MAX_BET;

		//int wager = (true_count > 8) ? MAX_BET : MIN_BET;

		hand->place_bet(wager);
		std::cout << name << " wagers " << wager << " of " << chips << " chips on a count of ";
		if(true_count > 0)
			std::cout << "+" << true_count << "\n";
		else
			std::cout << true_count << "\n";
		chips -= wager;
	}

	bool is_done() override {
		if(chips < MIN_BET){
			std::cout << name << " is broke\n";
			return true;
		}
		if(table->get_count() < COUNTER_QUIT){
			std::cout << name << " cashes out because the table is cold\n";
			return true;
		}
		if(chips > COUNTER_CASHOUT){
			std::cout << name << " cashes out\n";
			return true;
		}
		return false;
	}

};

#endif