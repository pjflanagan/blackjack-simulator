
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

std::string Hand::case_type(bool is_first_move){
	std::string type;
	int value = 0;

	if(is_first_move && cards[0] == cards[1]){ // pair
		type = "pair";
		value = cards[0]->value();
	}
	else if(has_ace()){ // ace
		type = "ace";
		value = sum()-1;
	}
	else {
		type = "sum";
		value = sum();
	}
	return type + std::to_string(value);
}

int Hand::sum(){
	int val = 0;
	for(int i = 0; i < cards.size(); ++i)
		val += cards[i]->value();
	return val;
}

bool Hand::has_ace(){
	for(int i = 0; i < cards.size(); ++i)
		if(cards[i]->is_ace())
			return true;
	return false;
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

void PlayerHand::double_down(){
	wager *= 2;
}

int PlayerHand::get_bet(){
	return wager;
}

Card * PlayerHand::split(){
	// store the second card
	Card * c = cards.back();
	// remove the second card
	cards.pop_back();
	// return the second card
	return c;
}