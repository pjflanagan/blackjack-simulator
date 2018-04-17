
#include "Player.h"

Player::Player(){
	hand = new PlayerHand();
	split_hand = new PlayerHand();
	is_split = false;
	chips = 100;
}

void Player::reset(){
	hand->reset();
	if(is_split)
		split_hand->reset();
	is_split = false;
}

void Player::add(Card * c){
	hand->add(c);
}

void Player::bet(){}

void Player::turn(){}

void Player::print_hand(){
	std::cout << hand->to_string() << "\n";
}

bool Player::move(PlayerHand * h, bool is_first_move){ return false; }

bool Player::double_down(){
	chips -= hand->get_bet();
	hand->double_down();
	return hit(hand);
}; 

void Player::split(){};

bool Player::hit(PlayerHand * h){
	hand->add(table->draw());
	return check_bust(h); 
}

bool Player::check_bust(PlayerHand * h){
	if(h->sum() > 21){
		bust(h);
		return true;
	}
	return false;
}

void Player::bust(PlayerHand * h){
	h->reset(); //resets wager to 0 and cards to empty
}; 

void Player::payout(PlayerHand * h, double rate){
	// add back to chips
	chips += rate * h->get_bet();
	// reset hand wager to 0 to avoid double payout
	h->reset();
}