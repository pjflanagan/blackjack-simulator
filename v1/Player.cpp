#ifndef PLAYER_CPP
#define PLAYER_CPP

#include <stdlib.h>
#include <iostream>

class Hand;

#include "Hand.cpp"
#include "Card.cpp"
#include "Table.cpp"
#include "Dealer.cpp"
#include "Brain.cpp"

class Player {
	public:

	Player();

	Player(Dealer & d) : dealer(d){
		hand = Hand(this);
		split_hand = Hand(this);
		is_split = false;
	};

	//wager = rando min to max
	void bet(){
		int max = (MAX_BET > chips) ? chips : MAX_BET;
		int wager = std::rand() % max + MIN_BET;
		hand.place_wager(wager);
		chips -= wager;
	}

	void payout(Hand & h, double payout){
		chips += h.get_wager() * payout;
		h.reset_wager(); // set the wager to 0 so dealer doesn't payout again
	}

	void recieve(Card * card){
		hand.add_card(card);
	}

	void action(){
		// if we have a blackjack payout the player
		if(check_blackjack(&hand)) return;
		
		// otherwise let the player play
		move(true, hand);
		
		// and when they are done let the dealer play
		dealer.action();

		Hand * dealer_hand = dealer.get_hand();

		int result = hand.beats(*dealer_hand);
		if(result == WIN) payout(hand, PAYOUT);
		else if (result == PUSH) hand.push();
		
		if(is_split){
			result = split_hand.beats(*dealer_hand);
			if(result == WIN) payout(split_hand, PAYOUT);
			else if(result == PUSH) split_hand.push();
		}
	}

	void give_chips(int c){
		chips += c;
	}

	void reset(){
		is_split = false;
		split_hand.reset();
		hand.reset();
	}

	private:

	// determines the players next move
	void move(bool first_turn, Hand & h){
		bool end = false;
		while(!end){ // while the turn isn't over
			switch (think(&h, dealer.get_upcard(), first_turn)){
				case HIT: 
					end = hit(h); 
					break;
				case DOUBLE: 
					if(not_enough_funds()) break;
					double_down(h);
					return;
				case SPLIT: 
					if(not_enough_funds()) break;
					split();
					return;
				case STAND:
					return;
			}
			first_turn = false;
		}
	}

	bool check_blackjack(Hand * h){
		if(h->blackjack()){
			payout(*h, BJ_PAYOUT);
		}
	}

	void split(){
		split_hand.add_card(hand.split()); // move card to other hand
		split_hand.place_wager(hand.get_wager()); // add a second wager
		chips -= split_hand.get_wager(); // allocate funds

		check_blackjack(&hand);
		check_blackjack(&split_hand);

		hand.add_card(dealer.deal()); // hit each hand
		split_hand.add_card(dealer.deal());

		is_split = true;
		move(false, hand);
		move(false, split_hand);

	}

	void double_down(Hand & h){
		chips -= h.get_wager(); // allocate funds
		h.place_wager(h.get_wager() * 2); // double the wager
		h.add_card(dealer.deal());
		h.check_bust(); 
	}

	bool hit(Hand & h){
		h.add_card(dealer.deal()); // add a card to the hand
		return h.check_bust(); // check if it busted
	}

	// used when seeing if player can split or double down
	bool not_enough_funds(){
		return chips > hand.get_wager();
	}

	// access player's brain
	int think(Hand * hand, Card * upcard, bool first_turn){
		if(first_turn && hand->is_pair()){
			return pair.think(hand->front(), upcard->value());
		}
		else if(first_turn && hand->has_ace()){
			return ace.think(hand->non_ace(), upcard->value());
		}
		return normal.think(hand->sum(), upcard->value());
	}

	Dealer dealer;
	Hand hand;
	Hand split_hand;
	bool is_split;

	Pair pair;
	Ace ace;
	Normal normal;
	
	int chips;
};

#endif