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
		Player::init();
	}

	void bet() override {
		std::cout << name << " has " << chips << " chips to wager\n";
		int wager = 0;
		while(!valid_bet(wager)){
			std::cout << "Place bet [" << MIN_BET << "-" << MAX_BET << "]: "; //[0 to quit]: ";
			std::cin >> wager;
			//if(wager == 0){
			//	std::cout << name << " has left the table";
			//}
		}
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

	bool is_done() override {
		if(chips < MIN_BET){
			std::cout << name << " is broke\n";
			return true;
		}
		char response = '!';
		while(response == '!'){
			std::cout << "\nContinue [Y/N]: ";
			std::cin >> response;
			if(response != 'Y')
				if(response != 'N')
					response = '!';
		}
		return response == 'N'; //player is done if they reply No
	}

	protected:

	// returns false if turn is over
	bool move(HandPlayer * h, bool is_first_move) override {
		char m = '!';
		if(is_first_move){
			//if the player has blackjack then let them win
			if(h->is_blackjack()){
				std::cout << name << " has blackjack! Winner, winner, chicken dinner!\n";
				Player::payout(h, BLACKJACK_PAYOUT);
				return true;
			}
		}
		//otherwise ask for input
		while(!valid_move(m, h, is_first_move)){
			if(is_first_move) // could also determine if Double and sPlit are available
				std::cout << "Make move [Stand, Hit, Double, sPlit]: ";
			else
				std::cout << "Make move [Stand, Hit]: ";
			std::cin >> m;
		}

		switch(m){
			case SPLIT:
				std::cout << name << " splits\n";
				this->split();
				return true;
			case HIT:
				std::cout << name << " hits\n";
				return hit(h); 
			case STAND:
				std::cout << name << " stands\n";
				return true;
			case DOUBLE:
				std::cout << name << " doubles down\n";
				double_down();
				return true;
		}
		
		return true;
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

	bool valid_bet(int a){
		return a >= MIN_BET && a <= chips && a <= MAX_BET;
	}

	bool valid_move(char m, HandPlayer * h, bool is_first_move){
		switch(m){
			case STAND:
				return true;
			case SPLIT:
				if(is_first_move && chips >= h->get_bet() && h->splitable())
					return true;
				break;
			case HIT:
				if(h->sum() < 21)
					return true;
				break;
			case DOUBLE:
				if(is_first_move && chips >= h->get_bet())
					return true;
				break;
		}
		return false;
	}
};

#endif