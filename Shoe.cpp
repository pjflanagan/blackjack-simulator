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
		// shuffle the deck
		shuffle();
	}

	void shuffle(){
		reset();

  		// obtain a time-based seed:
  		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  		std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
	}

	Card * deal(){
		Card * card = cards.front(); // get the front card
		cards.erase(cards.begin()); // remove it from the array
		in_play.push_back(card); // store it in play
		return card; // return the card pointer
	}

	private:

	void reset(){
		cards.insert(cards.end(), in_play.begin(), in_play.end());
	}

	std::vector<Card *> cards;
	std::vector<Card *> in_play;
};

#endif