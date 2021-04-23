#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "deck.h"

// Constructor 
DeckOfCards::DeckOfCards(){
	//I used srand to be able to have diffrent shuffles each time the program starts
	std::srand(time(0));

	for(int i = 0; i < 13; i++)
		for(int j = 0; j < 4; j++){
			Card card(i,j);
			deck.push_back(card);
		}
}
//Shuffles deck
void DeckOfCards::shuffle(){
	random_shuffle(deck.begin(), deck.end());

}
//Deals card to hands
Card DeckOfCards::dealCard(){
	Card current_card = deck.back();
	deck.pop_back();
	return current_card;
}
//Checks to see if the deck is empty or not
bool DeckOfCards::moreCards(){
	return !deck.empty();
}