
Player::Player(){
	hand = new Hand;
}

void Player::add(Card * c){
	hand->add(c);
}

void Player::print_hand(){
	std::cout << hand->to_string() << "\n";
}