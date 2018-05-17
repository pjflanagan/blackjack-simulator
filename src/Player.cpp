
#include "Player.h"

void Player::init(){
	hand = new HandPlayer();
	split_hand = new HandPlayer();
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
	int ds = h->sum();
	if(h->has_ace() && ds + 10 <= 21) ds += 10; //get the dealer's true sum
	
	if(hand->is_bust()); //if player did bust
	else if(h->is_bust()){ //if dealer did bust
		payout(hand, PAYOUT); //payout the player 
	}
	else { // calculate who is higher
		int ps = hand->sum();
		if(hand->has_ace() && ps + 10 <= 21) ps += 10;  //get the player's true sum

		if(ps > ds) payout(hand, PAYOUT);
		else if(ps == ds) payout(hand, PUSH);
		else payout(hand, LOSE);
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
			if(split_hand->has_ace() && ps + 10 <= 21) ps += 10; 
			if(ps > ds)
				payout(split_hand, PAYOUT);
			else if(ps == ds)
				payout(split_hand, PUSH);
			else
				payout(split_hand, LOSE);
		}
	}
}

std::string Player::summary(int round){
	std::string s = name + " ends with " + std::to_string(chips) + " chips in round " + std::to_string(round) + "\n";
	return s;
}

void Player::print_hand(Hand * h){
	std::cout << name << " has " << h->to_string() << "\n";
}

bool Player::double_down(){
	chips -= hand->get_bet();
	hand->double_down();
	return hit(hand);
}; 

void Player::split(){
	is_split = true;
	// move one card to other hand
	// and wager chips in
	split_hand->add(hand->split());
	split_hand->place_bet(hand->get_bet());
	chips -= split_hand->get_bet();
};

bool Player::hit(HandPlayer * h){
	Card * c = table->draw(false);
	h->add(c);
	std::cout << name << " recieves " << c->to_string() << "\n"; //add names to players
	return check_bust(h); 
}

bool Player::check_bust(HandPlayer * h){
	if(h->sum() > 21){
		bust(h);
		return true;
	}
	if(h->sum() == 21 || (h->has_ace() && h->sum() == 11) ){
		std::cout << name << " has 21!\n";
		return true;
	}
	return false;
}

void Player::bust(HandPlayer * h){
	std::cout << name << " busts!\n";
	h->set_bust(true);
}; 

void Player::payout(HandPlayer * h, double rate){
	int bet = h->get_bet();
	int earnings = rate * bet;

	if(bet != 0){
		if(rate == PUSH)
			std::cout << name << " breaks even\n";
		else if(rate == LOSE)
			std::cout << name << " loses " << bet << " chips\n";
		else
			std::cout << name << " earns " << earnings << " chips\n";
	}

	// add bet and earning back to chips
	chips += earnings + bet;
	// reset hand wager to 0 to avoid double payout
	h->reset();
}