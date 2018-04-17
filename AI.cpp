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

	AI(Table * t) {
		table = t;
		Player::Player();
		cases = Cases();
	}

	void bet() override {
		int max = (MAX_BET > chips) ? chips : MAX_BET;
		std::srand(std::time(NULL));
		int wager = (std::rand() % static_cast<int>(max-MIN_BET)) + MIN_BET;
		hand->place_bet(wager);
		chips -= wager;
		std::cout << "AI wagers " << wager << " chips.\n";
	}

	void turn() override {
		std::cout << "AI has ";
		bool is_first_move = true;
		while(move(hand, is_first_move)){
			print_hand();
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
					std::cout << "AI chooses to split.\n";
					split();
					return true;
				}
				return false;
			case HIT:
				std::cout << "AI chooses to hit.\n";
				return hit(h); 
			case STAND:
				std::cout << "AI chooses to stand.\n";
				return true;
			case DOUBLE:
				if(is_first_move && chips > h->get_bet()){
					std::cout << "AI chooses to double down.\n";
					double_down();
					check_bust(h);
					return true;
				}
				std::cout << "AI chooses to hit.\n";
				return hit(h); // if not enough money to double down treat it like turn 2
			case BLACKJACK:
				std::cout << "AI has blackjack!\n";
				payout(h, BLACKJACK_PAYOUT);
				return true;
		}

		return false;
	}

	void split() override {
		// move one card to other hand
		split_hand->add(hand->split());
		// set wager on other hand to same wager
		split_hand->place_bet(hand->get_bet());
		// subtract wager from chips
		chips -= split_hand->get_bet();

		while(move(hand, false)){}
		while(move(split_hand, false)){}

	}

	private:
	Cases cases;

};

#endif