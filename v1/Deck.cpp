#ifndef DECK_CPP
#define DECK_CPP

#include <string>

#include "Card.cpp"
#include "Table.cpp"

class Deck{
	public:
	Deck(){
		for(int suit = 0; suit < 4; ++suit){
			for(int face = 0; face < 13; ++face){
				cards[suit*13 + face] = new Card(FACES[face], SUITS[suit], VALUES[face]);
			}
		}
	}

	Card * at(int i){
		return cards[i];
	}

	private:
	Card * cards[52];
};

#endif