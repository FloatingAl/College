#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "hand.h"

using namespace std;

//Geters and Seters
bool Hand::getFace_down(){
	return mFace_down;
}
vector<Card> Hand::getHand(){
	return mHand;
}
//Function swaps the cards from the oldCard and NewCard
void Hand::swapCard(Card oldCard, Card newCard){
	for(int i = 0; i < 5; i++){
		if(mHand.at(i).getFace() == oldCard.getFace() && mHand.at(i).getSuit() == oldCard.getSuit()){
			mHand.at(i).setFace(newCard.getFace());
			mHand.at(i).setSuit(newCard.getSuit());
		}
	}
}