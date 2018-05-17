
#include "Table.h"
#include "Dealer.h"
#include "PlayerAI.cpp"
#include "PlayerHuman.cpp"
#include "PlayerCardCounter.cpp"

Table::Table(){
	dealer = Dealer(this);
	players.push_back(new PlayerAI(this, "Terry Benedict"));
	players.push_back(new PlayerCardCounter(this, "Rain Man"));
	players.push_back(new PlayerAI(this, "Danny Ocean")); // make a sit_down() function and have players sit down in Play
	players.push_back(new PlayerCardCounter(this, "Card Counter"));
	//players.push_back(new PlayerHuman(this, "Danny Ocean"));
	round_count = 0;
	//game_count = 0;
	//house_win_count = 0;
}

void Table::reset(){
	dealer.reset();
	for(int i = 0; i < players.size(); ++i){
		players[i]->reset();
	}
}

void Table::summary(){
	std::cout << "\n\n==== Summary ====\n";
	for(int i = 0; i < player_summary.size(); ++i)
		std::cout << player_summary[i];
	std::cout << "\n";
}

void Table::shuffle(){
	if(shoe.shuffle(false)){
		dealer.burn();
	};
}

void Table::play(){
	dealer.burn();
	round();
}

Card * Table::upcard(){
	return dealer.get_upcard();
}

void Table::round(){
	std::cout << "\n\n ==== Round " << ++round_count << " ==== \n";
	for(int i = 0; i < players.size(); ++i){
		players[i]->bet();
	}
	deal();

	std::cout << "Dealer is showing " << dealer.get_upcard()->to_string() << "\n";

	//take turns
	for(int i = 0; i < players.size(); ++i){
		players[i]->turn(); // RECORD IF THEY BUST
	}

	// dealer's turn
	//dealer.reveal(); // move reveal from the move and add a function
	// if bust count < players.size() // if there are no players the dealer doesn't move
		dealer.move();

	std::cout << "\n";

	// calculate payouts and print final holdings
	// kick the player out if they have less than the min bet
	//game_count += players.size(); // not sure if this should count
	for(int i = 0; i < players.size(); ++i){
		players[i]->check_beats(dealer.get_hand()); // record the house wins here
		if(players[i]->is_done()){ 
			player_summary.push_back(players[i]->summary(round_count));
			players.erase(players.begin() + i);
			--i;
		}
	}

	if(players.size() == 0)
		return;

	// reset and start another round
	reset(); 
	round();
}

Card * Table::draw(bool is_burn){
	return shoe.draw(is_burn);
}

int Table::get_count(){
	return shoe.get_count();
}

void Table::deal(){
	std::cout << "\n";
	dealer.shuffle(); // shuffle (only does it if it has to)
	for(int i = 0; i < 2; ++i){
		for(int p = 0; p < players.size(); ++p){
			players[p]->add(dealer.deal(false)); // deal a card to each player
		}
		dealer.add(dealer.deal(false)); // deal a card to the dealer
	}
}