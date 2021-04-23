#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <thread>
#include "card.h"


using namespace std;

//Create the values and suits all together
const static string faces[13] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King", "Ace"};
const static string suits[4] = {"Spades", "Clubs", "Hearts", "Dimond"};

void Card::setFace(int sFace) {
	face = sFace;
}
int Card::getFace() const{
	return face;
}
void Card::setSuit(int sSuit) {
	suit = sSuit;
}
int Card::getSuit() const{
	return suit;
}

//combines the face and suit together to print the card 
string Card::toString (){
	return faces[face] + " of " + suits[suit];
}
