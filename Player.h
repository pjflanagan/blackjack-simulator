#ifndef PLAYER_H
#define PLAYER_H

class Table;

class Player {
	public:

	Player();

	protected:
	Table * table;
	int chips;

};

#include "Table.h"

#endif