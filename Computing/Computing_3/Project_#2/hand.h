#ifndef HAND_H
#define HAND_H
#include "card.h"
class Hand{
private:
	std::vector<Card> mHand;
	bool mFace_down;
public:
	Hand(){

	}

	Hand(std::vector<Card> v, bool face_down = 0){

		mHand = v;
		mFace_down = face_down;
	}

	bool getFace_down();
	std::vector<Card> getHand();
	void swapCard(Card oldCard, Card newCard);

};

#endif 
