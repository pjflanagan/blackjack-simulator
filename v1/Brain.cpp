#ifndef BRAIN_CPP
#define BRAIN_CPP

#include "Table.cpp"

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

	int logic[8][10] = {
		//	A		2		3		4		5		6		7		8		9		10	
		{ 	HIT,	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	HIT, 	HIT, 	HIT }, 		// 2
		{ 	HIT,	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	HIT, 	HIT, 	HIT, 	HIT }, 		// 3
		{ 	HIT,	HIT, 	HIT, 	HIT, 	SPLIT, 	SPLIT, 	HIT, 	HIT, 	HIT, 	HIT }, 		// 4
		{ 	HIT,	DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE, HIT }, 		// 5
		{ 	HIT,	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	HIT, 	HIT, 	HIT, 	HIT }, 		// 6
		{ 	HIT,	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	HIT, 	HIT, 	HIT, 	HIT }, 		// 7
		{ 	SPLIT,	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT }, 	// 8
		{ 	STAND,	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	SPLIT, 	STAND, 	SPLIT, 	SPLIT, 	STAND } 	// 9
	};

	int think(int non_ace, int upcard){
		return logic[non_ace-2][upcard-1];
	}
};

struct Normal {

	int logic[4][10] ={
		//	A		2		3		4		5		6		7		8		9		10	
		{ 	HIT,	HIT, 	DOUBLE, DOUBLE, DOUBLE, DOUBLE,	HIT, 	HIT, 	HIT, 	HIT },		// 9
		{ 	HIT,	DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE,	DOUBLE,	DOUBLE,	DOUBLE,	HIT },		// 10
		{ 	HIT,	DOUBLE, DOUBLE, DOUBLE, DOUBLE, DOUBLE,	DOUBLE,	DOUBLE,	DOUBLE, DOUBLE }, 	// 11
		{ 	HIT,	HIT, 	HIT, 	STAND, 	STAND, 	STAND, 	HIT, 	HIT, 	HIT, 	HIT }		// 12
	};

	int think(int sum, int upcard){
		if(sum <= 8)
			return HIT;
		if(sum >= 17)
			return STAND;
		if(sum <= 16 && sum >= 13){
			if(upcard==1)
				return HIT;
			if(upcard<=6)
				return STAND;
			if(upcard>=7)
				return HIT;
		}
		return logic[sum-9][upcard-1];
	}
};

#endif