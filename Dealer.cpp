#ifndef DEALER_CPP
#define DEALER_CPP

#include "Table.cpp"
#include "Card.cpp"
#include "Hand.cpp"
#include "Shoe.cpp"
#include "Player.cpp"

class Dealer {

	public:

	Dealer();

	Dealer(Shoe & s): shoe(s){
		hand = new Hand(this);
	};
	
	Card * get_upcard(){
		return upcard;
	}

	void shuffle(){
		shoe.shuffle();
	}

	void burn(){
		shoe.deal();
	}

	Card * deal(){
		return shoe.deal();
	}

	void facedown(){
		downcard = shoe.deal();
		hand->add_card(downcard);
	}

	void faceup(){
		upcard = shoe.deal();
		hand->add_card(upcard);
	}

	void action(){
		bool end = false;
		while(!end){
			//TODO: add this
			end = true;
		}
	};

	void reset(){
		hand->reset();
	}

	Hand * get_hand(){
		return hand;
	}


	private:

	Card * hit(){
		hand->add_card(shoe.deal());
	}


	Card * downcard;
	Card * upcard;
	Shoe shoe;
	Hand * hand;
};

#endif