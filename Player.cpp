
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

bool Player::move(int m){return false;};