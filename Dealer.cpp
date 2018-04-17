
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
	std::cout << "Dealer burns\n";
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

Hand * Dealer::get_hand(){
	return hand;
}

void Dealer::move(){
	bool end = false;
	std::cout << "\nDealer reveals " << hand->get_upcard()->to_string() << "\n";
	while(!end){
		if(hand->sum() > 21){
			// if the dealer busts
			std::cout << "Dealer busts!\n";
			end = true;
		}
		else {
			// will always reach here on the first pass
			std::cout << "Dealer has " << hand->to_string() << "\n";

			// if the sum with aces is over 17 and less than 21 then stop
			if(hand->dealer_sum() >= DEALER_STOP && hand->dealer_sum() <= 21){
				std::cout << "Dealer stands\n";
				end = true;
			}
			// else if the dealer's ace goes over then use the regular sum
			else if(hand->sum() >= DEALER_STOP){
				std::cout << "Dealer stands\n";
				end = true;
			}
			else {
				std::cout << "Dealer hits\n";
				Card * c = deal();
				std::cout << "Dealer recieves " << c->to_string() << "\n";
				hand->add(c);
			}
		}
	}
}