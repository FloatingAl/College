#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <thread>


class Card{
private:
	int face;
	int suit;
public:
	//constructor
	Card (int face_, int suit_){
		face = face_;
		suit = suit_;
	}
	//default constructor
	Card(){

	}
	friend bool operator< (const Card &card1, const Card &card2){
		return card1.getFace() < card2.getFace();
}
	void setFace(int sFace);
	int getFace() const;
	void setSuit(int sSuit);
	int getSuit() const;
	

	std::string toString ();
};

#endif