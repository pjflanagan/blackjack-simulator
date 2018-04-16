
#include "Hand.h"
#include "Card.cpp"

Hand::Hand(){};

void Hand::reset(){
	cards.clear();
}

void Hand::add(Card * c){
	cards.push_back(c);
}

std::string Hand::to_string() const {
	std::string str = cards[0]->to_string();
	for(int i = 1; i < cards.size(); ++i){
		str += " | " + cards[i]->to_string();
	}
	return str; 
}

std::ostream& operator<<(std::ostream& os, const Hand& hand)
{
	os << hand.to_string();
    return os;
}


// DEALER HAND

DealerHand::DealerHand(){}

Card * DealerHand::get_upcard(){
	return cards[1]; // second card is the upcard
}


// PLAYER HAND

PlayerHand::PlayerHand(){}

void PlayerHand::reset(){
	Hand::reset();
	wager = 0;
}

void PlayerHand::place_bet(int w){
	wager = w;
}