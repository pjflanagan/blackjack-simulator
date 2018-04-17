
#include "Table.h"
#include "Dealer.h"
#include "AI.cpp"
#include "Human.cpp"

Table::Table(){
	shoe = Shoe();
	shoe.shuffle();
	dealer = Dealer(this);
	players.push_back(new AI(this, "Danny Ocean"));
	players.push_back(new AI(this, "Terry Benedict"));
}

void Table::reset(){
	shoe.reset();
	dealer.reset();
	for(int i = 0; i < players.size(); ++i){
		players[i]->reset();
	}
}

void Table::shuffle(){
	std::cout << "Dealer shuffles\n";
	shoe.shuffle();
}

void Table::play(){
	round();
}

Card * Table::upcard(){
	return dealer.get_upcard();
}

void Table::round(){
	std::cout << "\n\n ==== Round ==== \n";
	for(int i = 0; i < players.size(); ++i){
		players[i]->bet();
	}
	deal();

	std::cout << "Dealer is showing " << dealer.get_upcard()->to_string() << "\n";

	//take turns
	for(int i = 0; i < players.size(); ++i){
		players[i]->turn();
	}

	// dealer's turn
	dealer.move();

	// calculate payouts and print final holdings
	// kick the player out if they have less than the min bet
	for(int i = 0; i < players.size(); ++i){
		players[i]->check_beats(dealer.get_hand());
		if(players[i]->is_broke()){
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

Card * Table::draw(){
	return shoe.draw();
}

void Table::deal(){
	std::cout << "\n";
	dealer.shuffle(); // initially shuffle the deck
	dealer.burn();
	for(int i = 0; i < 2; ++i){
		for(int p = 0; p < players.size(); ++p){
			players[p]->add(dealer.deal()); // deal a card to each player
		}
		dealer.add(dealer.deal()); // deal a card to the dealer
	}
}