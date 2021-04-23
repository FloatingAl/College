#ifndef DECK_H
#define DECK_H 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include "card.h"



using namespace std;

class DeckOfCards{
private:
	vector <Card> deck;
	int currentcard;
public:


//void setCurrentcard(int sCurrentcard);
//int getCurrentcard();
DeckOfCards();
void shuffle();
Card dealCard();
bool moreCards();

};

#endif