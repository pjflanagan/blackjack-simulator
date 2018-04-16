
#include "Dealer.h"

Dealer::Dealer(){}

Dealer::Dealer(Table * t) : table(t) {
	hand = new Hand;
}

void Dealer::shuffle() {
	table->shuffle();
}

void Dealer::burn(){
	deal();
}

Card * Dealer::deal(){
	return table->draw();
}

void Dealer::add(Card * c){
	hand->add(c);
}