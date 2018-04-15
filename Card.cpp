#ifndef CARD_CPP
#define CARD_CPP

#include <string>
#include <ostream>

class Card{
	public:
	Card(std::string f, std::string s, int v): face(f), suit(s), val(v){}

	bool is_ace(){
		return val == 1;
	}

	int value() const{
		return val;
	}

	std::string to_string() const{
		return face + " of " + suit;
	}

	private:
	std::string face;
	std::string suit;
	int val;
};

bool operator==(const Card& lhs, const Card& rhs){
	return lhs.value() == rhs.value();
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
	os << card.to_string();
    return os;
}

#endif