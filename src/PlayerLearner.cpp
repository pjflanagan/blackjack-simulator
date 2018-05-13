#ifndef LEARNER_CPP
#define LEARNER_CPP

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

class PlayerLearner : public Player {
	public:

	PlayerLearner(){}

	PlayerLearner(Table * t, std::string n) {
		table = t;
		name = n;
		Player::init();
		cases = Cases();
	}

	void bet() override {
		hand->place_bet(0);
		//std::cout << name << " wagers " << wager << " of " << chips << " chips\n";
		//chips -= wager;
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
		return rounds == MAX_ROUNDS;
	}

	protected:

	// returns false if turn is over
	bool move(HandPlayer * h, bool is_first_move) override {
		// DO A RANDOM THING
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

	// OVERRIDE PAYOUT TO SEE IF SUCCESSFUL

	private:
	Cases cases; // make extension that takes cases and edits them
	int rounds; // once at max then quit


};

#endif