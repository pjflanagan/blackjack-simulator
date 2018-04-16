
#include "Table.h"
#include "Dealer.h"
#include "AI.cpp"
#include "Human.cpp"

Table::Table(){
	shoe = Shoe();
	shoe.shuffle();
	dealer = Dealer(this);
	players.push_back(new AI());
	players.push_back(new AI());
}

void Table::reset(){
	shuffle();
	dealer.reset();
}

void Table::shuffle(){
	shoe.shuffle();
}

void Table::play(){
	dealer.shuffle(); // initially shuffle the deck
	round();
}

void Table::round(){
	std::cout << "Round begins.\n";
	dealer.burn();
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

	// calculate payouts

	// reset
	reset();
	//rount();
}

Card * Table::draw(){
	return shoe.draw();
}

void Table::deal(){
	for(int i = 0; i < 2; ++i){
		for(int p = 0; p < players.size(); ++p){
			players[p]->add(dealer.deal()); // deal a card to each player
		}
		dealer.add(dealer.deal()); // deal a card to the dealer
	}
}