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
	
	Shoe shoe = Shoe();

	for(int i = 0; i < 52*5; ++i){
		std::cout << shoe.deal()->to_string() << "\n";
	}

	shoe.shuffle();

	for(int i = 0; i < 52*5; ++i){
		std::cout << shoe.deal()->to_string() << "\n";
	}


	return 0;
}