
#include "Table.h"

Table::Table(){
	shoe = Shoe();
	dealer = new Dealer();
}

void Table::shuffle(){
	shoe.shuffle();
}