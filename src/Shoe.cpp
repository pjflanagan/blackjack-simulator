#ifndef SHOE_CPP
#define SHOE_CPP

#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <vector>

#include "Rules.cpp"
#include "Card.cpp"
#include "Deck.cpp"

class Shoe {
	public:
	Shoe(){
		for(int d = 0; d < DECKS; ++d){
			// add a deck of cards to the shoe
			Deck deck = Deck();

			for(int card = 0; card < 52; ++card){
				cards.push_back(deck.at(card));
			}
		}
		std::cout << cards.size() << " cards in the shoe\n";
		// shuffle the deck
		reset();
		shuffle(true);
	}

	bool shuffle(bool first){
		if(!first && current_card < 4 * DECKS * CARDS_IN_DECK / 5) // if we are 4/5 of the way through
			return false;
		std::cout << "Dealer shuffles\n";
		reset();

  		// obtain a time-based seed:
  		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  		std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
		return true;
	}

	Card * draw(bool is_burn){
		Card * card = cards[current_card]; // get the front card
		++current_card;
		if(!is_burn){
			if(card->is_ace() || card->value()==10)
				count--;
			else if(card->value() <= 6)
				++count;
		}
		return card; // return the card pointer
	}

	void reset(){
		current_card = 0;
		count = 0;
	}

	int get_count(){
		int decks = (cards.size() - current_card) / 52; // estimated decks left
		return count / decks;
	}

	private:

	std::vector<Card *> cards;
	int played;
	int count;
	int current_card;
};

#endif