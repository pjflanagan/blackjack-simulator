

// deal function
// shuffle function

#ifndef DEALER_CPP
#define DEALER_CPP

#include "Card.cpp"

class Dealer {

	public:
	Dealer(Shoe & s): shoe(s){};
	
	Card * get_upcard(){
		return upcard;
	}

	void shuffle();
	void burn();
	void deal();
	void facedown();
	void faceup();

	Card * hit();

	private:

	Card * downcard;
	Card * upcard;
	Shoe shoe;

	
};

#endif