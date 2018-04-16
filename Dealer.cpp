
#include "Dealer.h"

Dealer::Dealer(){}

Dealer::Dealer(Table * t) : table(t) {
	hand = new DealerHand();
}

void Dealer::reset(){
	hand->reset();
}

void Dealer::shuffle() {
	table->shuffle();
}

void Dealer::burn(){
	deal();
	std::cout << "Dealer burns.\n";
}

Card * Dealer::deal(){
	return table->draw();
}

void Dealer::add(Card * c){
	hand->add(c);
}

Card * Dealer::get_upcard(){
	return hand->get_upcard();
}