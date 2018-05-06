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
		std::cout << cards.size() << " cards in the shoe.\n";
		// shuffle the deck
		shuffle();
	}

	void shuffle(){
		reset();

  		// obtain a time-based seed:
  		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  		std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
	}

	Card * draw(){
		Card * card = cards.front(); // get the front card
		cards.erase(cards.begin()); // remove it from the array
		in_play.push_back(card); // store it in play
		return card; // return the card pointer
	}

	void reset(){
		cards.insert(cards.end(), in_play.begin(), in_play.end()); // insert all the cards in play back into the deck
		in_play.clear(); // clear the cards that are in play for the array to be used again
	}

	private:

	std::vector<Card *> cards;
	std::vector<Card *> in_play;
};

#endif