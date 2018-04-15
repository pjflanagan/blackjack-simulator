#ifndef HAND_CPP
#define HAND_CPP

#include <vector>

#include "Card.cpp"

class Hand {
	public:

	int sum(){
		int val;
		for(int i = 0; i < cards.size(); ++i){
			val += cards[i]->value();
		}
		return val;
	}

	bool is_pair(){
		return cards[0] == cards[1];
	}

	int front(){
		return cards[0]->value();
	}

	bool has_ace(){
		return cards[0]->is_ace() || cards[1]->is_ace();
	}

	int non_ace(){
		if(cards[0]->is_ace())
			return cards[1]->value();
		return cards[0]->value();
	}

	private:
	std::vector<Card *> cards;
};

#endif