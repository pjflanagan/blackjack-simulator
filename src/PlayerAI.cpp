#ifndef AI_CPP
#define AI_CPP

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <chrono>
#include <string>
#include <vector>
#include <unistd.h>

#include "Player.h"
#include "Rules.cpp"
#include "Cases.cpp"
#include "Table.h"

class PlayerAI : public Player {
	public:

	PlayerAI(){}

	PlayerAI(Table * t, std::string n) {
		table = t;
		name = n;
		Player::init();
		cases = Cases();
	}

	void bet() override {
		int wager;
		if(chips == MIN_BET){
			wager = MIN_BET;
		}
		else {
			int max = (MAX_BET > chips) ? chips : MAX_BET;
			auto now = std::chrono::high_resolution_clock::now(); // get precice time
			auto now_micro = std::chrono::time_point_cast<std::chrono::microseconds>(now); 
			auto value = now_micro.time_since_epoch();
			long duration = value.count(); // convert to a long
			std::srand(duration); // use as random seed
			
			//std::srand(std::time(NULL));
			wager = (std::rand() % static_cast<int>(max-MIN_BET)) + MIN_BET;
		}
		hand->place_bet(wager);
		std::cout << name << " wagers " << wager << " of " << chips << " chips\n";
		chips -= wager;
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

	bool is_done() override {
		if(chips < MIN_BET){
			std::cout << name << " is broke\n";
			return true;
		}
		if (chips > AI_CASHOUT){
			std::cout << name << " cashes out\n";
			return true;
		}
		return false;
	}

	protected:

	// returns false if turn is over
	bool move(HandPlayer * h, bool is_first_move) override {
		// if it's the first move consider pair splits
		// and doubling down
		switch(cases.action(h->case_type(is_first_move), table->upcard()->value())){
			case SPLIT:
				if(chips >= h->get_bet()){
					std::cout << name << " splits\n";
					split();
					return true;
				}
				return false;
			case HIT:
				std::cout << name << " hits\n";
				return hit(h); 
			case STAND:
				std::cout << name << " stands\n";
				return true;
			case DOUBLE:
				if(is_first_move && chips >= h->get_bet()){
					std::cout << name << " doubles down\n";
					double_down();
					return true;
				}
				std::cout << name <<  " hits\n";
				return hit(h); // if not enough money to double down treat it like turn 2
			case BLACKJACK:
				std::cout << name << " has blackjack!\n";
				payout(h, BLACKJACK_PAYOUT);
				return true;
		}

		return false;
	}

	void split(){
		Player::split();
		bool end = hand->has_ace(); // if the split was aces then only hit once
		hand->add(table->draw(false));
		while(!end){
			print_hand(hand);
			end = this->move(hand, false);
		}
		end = split_hand->has_ace();
		split_hand->add(table->draw(false));
		while(!end){
			print_hand(split_hand);
			end = this->move(split_hand, false);
		}
	}


	private:
	Cases cases;

};

#endif