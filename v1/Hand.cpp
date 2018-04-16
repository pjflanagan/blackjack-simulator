#ifndef HAND_CPP
#define HAND_CPP

#include <vector>

#include "Table.cpp"
#include "Dealer.cpp"
#include "Card.cpp"
#include "Player.cpp"

class Hand {
	public:

	Hand();

	Hand(Dealer * d): dealer(d){}

	Hand(Player * p): player(p){}

	int sum(){
		int val;
		for(int i = 0; i < cards.size(); ++i){
			val += cards[i]->value();
		}

		// if there are aces and can be used
		// to equal over 17 and less than 21
		// then use an ace as an 11
		if(any_ace() && val >= 7 && val <= 11){
			val += 10;
		}

		return val;
	}

	bool check_bust(){
		if(sum() > 21){
			wager = 0;
			return true;
		}
		return false;
	}

	bool blackjack(){
		return cards.size() == 2 && sum() == 21;
	}

	void reset(){
		cards.clear();
	}

	bool is_pair(){
		return cards[0] == cards[1];
	}

	int front(){
		return cards[0]->value();
	}

	bool any_ace(){
		for(int i = 0; i < cards.size(); ++i)
			if(cards[i]->is_ace())
				return true;
	}

	bool has_ace(){
		return cards[0]->is_ace() || cards[1]->is_ace();
	}

	int non_ace(){
		if(cards[0]->is_ace())
			return cards[1]->value();
		return cards[0]->value();
	}

	void add_card(Card * card){
		cards.push_back(card);
	}

	Card * split(){
		cards.pop_back();
		return cards[1];
	}

	void reset_wager(){
		wager = 0;
	}

	void place_wager(int w){
		wager = w;
	}

	void push(){
		player->give_chips(wager);
		wager = 0;
	}

	int get_wager(){
		return wager;
	}

	int beats(Hand & dealer){
		if(check_bust())
			return LOSE;
		if(dealer.check_bust())
			return WIN;
		if(sum() > dealer.sum())
			return WIN;
		if(sum() == dealer.sum())
			return PUSH;
		return LOSE;
	}

	private:
	std::vector<Card *> cards;
	int wager;
	Player * player;
	Dealer * dealer;
};

#endif