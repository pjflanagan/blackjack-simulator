#ifndef AI_CPP
#define AI_CPP

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Player.h"
#include "Rules.cpp"

class AI : public Player {
	public:

	AI(){
		Player::Player();
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
		print_hand();
		int m = 0;
		while(move(m)){
			m += 1;
		}
	}

	protected:

	bool move(int m) override {
		if(m == 0){
			
		}

		return false;
	}

	private:

};

#endif