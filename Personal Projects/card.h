#pragma once
#include <string>

using namespace std;

class Card {
private:
	int value;
	string suit;

public:
	Card() { value = -1; suit = "Empty"; }
	void setVal(int v) { value = v; return; }
	void setSuit(string s) { suit = s; return; }

	int getVal() { return value; }
	string getSuit() { return suit; }
};
