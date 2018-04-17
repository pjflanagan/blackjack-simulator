
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

void Player::check_beats(Hand * h){
	//if player did bust
	if(hand->is_bust());
	//if dealer did bust
	else if(h->is_bust()){
		payout(hand, PAYOUT);
	}
	else {
		// calculate who is higher
		int ps = hand->sum();
		ps = (hand->has_ace() && ps + 10 > 21) ? ps : ps + 10; 
		int ds = h->sum();
		ds = (h->has_ace() && ds + 10 > 21) ? ds : ds + 10;
		if(ps > ds)
			payout(hand, PAYOUT);
		else if(ps == ds)
			payout(hand, PUSH);
		else
			payout(hand, LOSE);
	}

	if(is_split){
		//if player did bust
		if(split_hand->is_bust());
		//if dealer did bust
		else if(h->is_bust()){
			payout(split_hand, PAYOUT);
		}
		else {
			// calculate who is higher
			int ps = split_hand->sum();
			ps = (split_hand->has_ace() && ps + 10 > 21) ? ps : ps + 10; 
			int ds = h->sum();
			ds = (h->has_ace() && ds + 10 > 21) ? ds : ds + 10;
			if(ps > ds)
				payout(split_hand, PAYOUT);
			else if(ps == ds)
				payout(split_hand, PUSH);
			else
				payout(split_hand, LOSE);
		}
	}
}

bool Player::is_broke(){
	return chips < MIN_BET;
}

void Player::bet(){}

void Player::turn(){}

void Player::print_hand(Hand * h){
	std::cout << name << " has " << h->to_string() << "\n";
}

bool Player::move(PlayerHand * h, bool is_first_move){ return false; }

bool Player::double_down(){
	chips -= hand->get_bet();
	hand->double_down();
	return hit(hand);
}; 

void Player::split(){
	is_split = true;
};

bool Player::hit(PlayerHand * h){
	Card * c = table->draw();
	h->add(c);
	std::cout << name << " recieves " << c->to_string() << "\n"; //add names to players
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
	std::cout << name << " busts!\n";
	h->set_bust(true);
}; 

void Player::payout(PlayerHand * h, double rate){
	// add back to chips
	chips += rate * h->get_bet();
	// reset hand wager to 0 to avoid double payout
	h->reset();
}