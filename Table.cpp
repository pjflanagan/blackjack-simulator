
#include "Table.h"
#include "Dealer.h"

Table::Table(){
	shoe = Shoe();
	shoe.shuffle();
	dealer = Dealer(this);
	players.push_back(new Player);
	players.push_back(new Player);
}

void Table::shuffle(){
	shoe.shuffle();
}

void Table::play(){
	dealer.shuffle();
	round();
}

void Table::round(){
	dealer.burn();
	deal();
	//take turns
	for(int i = 0; i < players.size(); ++i){
		players[i]->print_hand();
	}
	//reset
}

Card * Table::draw(){
	return shoe.draw();
}

void Table::deal(){
	for(int i = 0; i < 2; ++i){
		for(int p = 0; p < players.size(); ++p){
			players[p]->add(dealer.deal());
		}
		dealer.add(dealer.deal());
	}
}