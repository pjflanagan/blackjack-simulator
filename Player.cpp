

#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "Hand.cpp"
#include "Card.cpp"
#include "Table.cpp"
#include "Dealer.cpp"

struct Pair {
	int logic[10][10] = {
		//	A		2		3		4		5		6		7		8		9		10	
		{ 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT }, 	// A
		{ 	HIT,	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	HIT, 	HIT, 	HIT }, 		// 2
		{ 	HIT,	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	HIT, 	HIT, 	HIT, 	HIT }, 		// 3
		{ 	HIT,	HIT, 	HIT, 	HIT, 	SPLIT, 	SPLIT, 	HIT, 	HIT, 	HIT, 	HIT }, 		// 4
		{ 	HIT,	DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, HIT }, 		// 5
		{ 	HIT,	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	HIT, 	HIT, 	HIT, 	HIT }, 		// 6
		{ 	HIT,	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	HIT, 	HIT, 	HIT, 	HIT }, 		// 7
		{ 	SPLIT,	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT }, 	// 8
		{ 	STAND,	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	STAND, 	SPLIT, 	SPLIT, 	STAND }, 	// 9
		{ 	STAND, 	STAND, 	STAND, 	STAND, 	STAND, 	STAND, 	STAND, 	STAND, 	STAND, 	STAND } 	// 10
	};

	int think(int pair, int upcard){
		return logic[pair-1][upcard-1];
	}

};

struct Ace {

	int think(int non_ace, int upcard){
		return 0;
	}
};

struct Normal {

	int think(int sum, int upcard){
		return 0;
	}
};

class Player {
	public:
	Player(Dealer & d) : dealer(d){};

	//wager = rando min to max
	void bet();

	bool action(){
		int turn = 0;
		bool end = false;
		while(!end){
			switch (think(&hand, dealer.get_upcard(), turn)){
				case HIT:
					end = hit();
					break;
				case DOUBLE:
					doubleDown();
					end = true;
					break;
				case SPLIT:
					split();
					end = true;
					break;
				case STAND:
					end = true;
					break;
			}
		}
		
	};

	private:

	bool split(){

	}

	bool doubleDown(){

	}

	bool hit(){

	}

	bool stand(){

	}

	int think(Hand * hand, Card * upcard, int turn){
		if(turn == 0 && hand->is_pair()){
			return pair.think(hand->front(), upcard->value());
		}
		else if(turn == 0 && hand->has_ace()){
			return ace.think(hand->non_ace(), upcard->value());
		}
		return normal.think(hand->sum(), upcard->value());
	}

	Dealer dealer;
	Hand hand;
	Hand split;

	Pair pair;
	Ace ace;
	Normal normal;
	
	int chips;
	int wager;
};

#endif