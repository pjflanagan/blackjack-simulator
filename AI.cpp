#ifndef AI_CPP
#define AI_CPP

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
#include <vector>

#include "Player.h"
#include "Rules.cpp"
#include "Cases.cpp"
#include "Table.h"

class AI : public Player {
	public:

	AI(){}

	AI(Table * t, std::string n) {
		table = t;
		name = n;
		Player::Player();
		cases = Cases();
	}

	void bet() override {
		//int max = (MAX_BET > chips) ? chips : MAX_BET;
		//std::srand(std::time(NULL));
		//int wager = (std::rand() % static_cast<int>(max-MIN_BET)) + MIN_BET;
		int wager = 10;
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

	protected:

	// returns false if turn is over
	bool move(PlayerHand * h, bool is_first_move) override {
		// if it's the first move consider pair splits
		// and doubling down
		switch(cases.action(h->case_type(is_first_move), table->upcard()->value())){
			case SPLIT:
				if(chips > h->get_bet()){
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
				if(is_first_move && chips > h->get_bet()){
					std::cout << name << " chooses to double down\n";
					double_down();
					check_bust(h);
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

	void split() override {
		Player::split();
		// move one card to other hand
		// and wager chips in
		split_hand->add(hand->split());
		split_hand->place_bet(hand->get_bet());
		chips -= split_hand->get_bet();

		// add card to each hand
		hand->add(table->draw());
		split_hand->add(table->draw());

		bool end = false;
		while(!end){
			print_hand(hand);
			end = move(hand, false);
		}
		end = false;
		while(!end){
			print_hand(split_hand);
			end = move(split_hand, false);
		}

	}

	private:
	Cases cases;

};

#endif