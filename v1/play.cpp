#include <vector>
#include <iostream>

#include "Table.cpp"
#include "Player.cpp"
#include "Dealer.cpp"
#include "Shoe.cpp"



// -----------------------------------------------------------------------------
// MAIN
// -----------------------------------------------------------------------------
int main(int argc, char *argv[]){

	//std::ios_base::sync_with_stdio(false);
	//std::ostringstream os; 
	
	Table table = Table();

	table.play();

	return 0;
}