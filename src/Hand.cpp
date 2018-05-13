
#include "Hand.h"
#include "Card.cpp"

Hand::Hand(){};

void Hand::reset(){
	cards.clear();
	bust = false;
}

void Hand::add(Card * c){
	cards.push_back(c);
}

bool Hand::is_bust(){
	return bust;
}

void Hand::set_bust(bool b){
	bust = b;
}

std::string Hand::to_string() const {
	std::string str = cards[0]->to_string();
	for(int i = 1; i < cards.size(); ++i){
		str += " | " + cards[i]->to_string();
	}
	return str; 
}

bool Hand::is_blackjack(){
	return has_ace() && sum() == 11;
}

std::string Hand::case_type(bool is_first_move){
	std::string type;
	int value = 0;

	if(is_first_move && cards[0]->equals(cards[1])){ // pair
		type = "pair";
		value = cards[0]->value();
	}
	else if(has_ace()){ // ace
		type = "ace";
		value = sum()-1;
		if(value > 9){
			type = "sum";
			value += 1;
		}
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

HandDealer::HandDealer(){
	bust = false;
}

Card * HandDealer::get_upcard(){
	return cards[0]; // first card is the upcard
}

Card * HandDealer::get_downcard(){
	return cards[1];
}


// PLAYER HAND

HandPlayer::HandPlayer(){
	bust = false;
}

void HandPlayer::reset(){
	Hand::reset();
	wager = 0;
}

void HandPlayer::place_bet(int w){
	wager = w;
}

void HandPlayer::double_down(){
	wager *= 2;
}

int HandPlayer::get_bet(){
	return wager;
}

Card * HandPlayer::split(){
	// store the second card
	Card * c = cards.back();
	// remove the second card
	cards.pop_back();
	// return the second card
	return c;
}

bool HandPlayer::splitable(){
	return cards[0]->equals(cards[1]);
}