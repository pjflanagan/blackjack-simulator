#include <vector>
#include <iostream>

#include "Table.cpp"
#include "Player.cpp"
#include "Dealer.cpp"
#include "Hand.cpp"
#include "PlayerAI.cpp"
#include "PlayerHuman.cpp"

// -----------------------------------------------------------------------------
// MAIN
// -----------------------------------------------------------------------------
int main(int argc, char *argv[]){
	Table table = Table();
	table.play();
	table.summary();
	return 0;
}

// GETOPT
// learner only version
// ai and card counter only version (calculate house edge)
// human and 2 ai's version
// human and card counter version