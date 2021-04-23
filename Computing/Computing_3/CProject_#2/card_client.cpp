/*
Name: Albara Mehene
Computing III
4/30/2016
Professor: Anna Rumshisky
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "deck.h"
#include "hand.h"
#include "card.h"

using namespace std;

bool onepair(vector<Card> &hand);
bool twopair(vector<Card> &hand);
bool threekind(vector<Card> &hand);
bool fourkind(vector<Card> &hand);
bool flush(vector<Card> &hand);
bool straight(vector<Card> &hand);
int determineVal(vector<Card> hand, bool temp);
bool faceCheck(Card &card1, Card &card2);
void dealerAI(vector<Card> &hand,DeckOfCards new_deck);
int checkDealerHand(vector<Card> &hand);
vector<Card> dropNecessary(vector<Card> &hand, int idx, DeckOfCards new_deck); 
bool prompt();
void playerReplace(Hand *temp, Card gemp);

//Global Variable for Dealer AI
#define POSSIBILITY 6
bool DEALER_HAND[POSSIBILITY] = {0,0,0,0,0,0};

int main()
{	
	//Cards and hands for poker game
	DeckOfCards deck2;
	DeckOfCards deck1;
	vector<Card> hand1;
	vector<Card> hand2;

	int hand1value;
	int hand2value;
	deck1.shuffle();
	/*while(deck1.moreCards()){
		cout << deck1.dealCard().toString() << endl;
	}*/
	cout << "Dealer" << endl;
	cout << "*************" << endl;
	cout << "Player cannot see dealers hand\n" << endl;

	//Checks to see if there is more cards in deck if not use another deck
	for(int i = 0; i < 5; i++){
		if(deck1.moreCards()){
			hand1.push_back(deck1.dealCard());
			}
		else {
			deck2.shuffle();
			hand1.push_back(deck2.dealCard());
		}
	}
	//Created dealer of Hand type passes 1 to hide the dealers hand
	Hand dealer(hand1,1);
	
	//Hides Dealers hand for the plater to not see
	if(!dealer.getFace_down()){
		for (unsigned int i = 0; i < dealer.getHand().size(); i++)
		cout << dealer.getHand().at(i).toString() << endl;
	}
	//Calles Dealer AI
	dealerAI(hand1,deck1);

	
	//Checks to see if deck has cards if not, take from other deck
	cout << "\nPlayer Hand" << endl;
	cout << "*************" << endl;
	for(int i = 0; i < 5; i++){
		if(deck1.moreCards()){
			hand2.push_back(deck1.dealCard());
		}
		else{

			deck2.shuffle();
			hand2.push_back(deck2.dealCard());
		}
	}

	Hand player(hand2,0);
	//prints out player hand
	for (unsigned int i = 0; i < player.getHand().size(); i++){
		cout << player.getHand().at(i).toString() << endl;
	}


	//Asks player if they want a card, if so calls the function to do so
	for(int i = 0; i < 3; i++){
		if(prompt()){

			Card newCard = deck1.dealCard();
			playerReplace(&player, newCard);
		cout << "\nNew Player Hand" << endl;
		cout << "*************" << endl;
		for (unsigned int i = 0; i < player.getHand().size(); i++){
			cout << player.getHand().at(i).toString() << endl;
		}
		}else{
			i = 2;
		}
	}

	//prints out new hand for player
	/*cout << "\nFinal Player Hand" << endl;
	cout << "*************" << endl;
	for (unsigned int i = 0; i < player.getHand().size(); i++){
		cout << player.getHand().at(i).toString() << endl;
	}*/

	//reveals Dealers hand
	cout << "\nDealer Hand" << endl;
	cout << "*************" << endl;
	if(dealer.getFace_down()){
		for (unsigned int i = 0; i < dealer.getHand().size(); i++)
		cout << dealer.getHand().at(i).toString() << endl;
	}

	//I showed that each hand has
	cout << "\nDealer has: " << endl;
	hand1value = determineVal(dealer.getHand(),dealer.getFace_down());
	cout << "\nPlayer has: " << endl;
	hand2value = determineVal(player.getHand(), player.getFace_down());

	//Then evalute who wins
	if (hand1value > hand2value){
		cout << "\nDealer hand wins" << endl;
	}
	else if(hand1value < hand2value){
		cout << "\nPlayer hand wins" << endl;
	}
	else{
		cout << "\nTie" << endl;
	}

 	
	

}
//Determines if its one pair
//This function takes the first element and checks the identical by adding one to the other one
bool onepair(vector <Card> &hand){
	for (int i = 0; i < hand.size(); i++){
		for(int j = i+1; j < hand.size(); j++){
			if(hand[i].getFace() == hand[j].getFace()){
				return true;
			}
		}
	}
	return false;
}
//Function to find 2 values of the same value in a pair
bool twopair(vector<Card> &hand){
	int same = 0;
	for (int i = 0; i < hand.size(); i++){
		for(int j = i+1; j < hand.size(); j++){
			if(hand[i].getFace() == hand[j].getFace()){
				same++;
			}
		}
	}
	return same >= 2;
}
//Function that finds three of the same value
bool threekind(vector<Card> &hand){
	int same = 0;
	for (int i = 0; i < hand.size(); i++){
		for(int j = i+1; j < hand.size(); j++){
			if(hand[i].getFace() == hand[j].getFace()){
				same++;
			}
		}
	}
	return same >= 3;
}
//Function that finds four of the same value
bool fourkind(vector<Card> &hand){
	int same = 0;
	for (int i = 0; i < hand.size(); i++){
		for(int j = i+1; j < hand.size(); j++){
			if(hand[i].getFace() == hand[j].getFace()){
				same++;
			}
		}
	}
	return same >= 4;
}
//The flush goes through the loop and finds the idetical suit
bool flush(vector<Card> &hand){
	int same = 0;
	for (int i = 0; i < hand.size(); i++){
		for(int j = i+1; j < hand.size(); j++){
			if(hand[i].getSuit() == hand[j].getSuit()){
				same++;
			}
		}
	}
	return same/2 >= 5;
}
//In the straight function needs sorted first then going through the loop
bool straight(vector<Card> &hand){
	sort(hand.begin(), hand.end());
	int same = 0;
	for (int i = 0; i < hand.size(); i++){
		if(hand[i].getFace()+1 == hand[i+1].getFace()){
			same++;
		}
	}
	return same == 4;
}
//This sets each hand a value so when it returns it can distinguish what hand wins
int determineVal(vector<Card> hand, bool temp){
	int value = 0;

	if(straight(hand)){
		
		cout << "Straight" << endl;

		value = 6;
	}
	else if(flush(hand)){
		
		cout << "Flush" << endl;
		value = 5;
	}
	else if(fourkind(hand)){
		
		cout << "Four of a kind" << endl;
		value = 4;
	}
	else if(threekind(hand)){
		cout << "Three of a kind" << endl;
		value = 3;
	}
	else if(twopair(hand)){
		cout << "Two of a pair" << endl;
		value = 2;
	}
	else if(onepair(hand)){
		cout << "One pair" << endl;
		value = 1;
	}
	else{
		cout << "Nothing" << endl;
		value = 0;
	}

	return value;
}
//Main point for the Ai
void dealerAI(vector<Card> &hand, DeckOfCards new_deck){
	int idx = checkDealerHand(hand);

	hand = dropNecessary(hand,idx,new_deck);

}
//Puts all functions into array for dealer to determine which is better
int checkDealerHand(vector<Card> &hand) {
  DEALER_HAND[0] = onepair(hand);
  DEALER_HAND[1] = twopair(hand);
  DEALER_HAND[2] = threekind(hand);
  DEALER_HAND[3] = fourkind(hand);
  DEALER_HAND[4] = flush(hand);
  DEALER_HAND[5] = straight(hand);

  int idx = -1;
  for (int i = 0; i < 6; i++)
    if (DEALER_HAND[i]) idx = i;

  return idx;
}
//Actually removes cards it doesnt need and replaces it with new ones
vector<Card> dropNecessary(vector<Card> &hand, int idx,DeckOfCards new_deck) {
  sort(hand.begin(), hand.end());
  vector<Card> new_hand;
  vector<Card>::iterator itr;
  switch (idx) {
    case 0:
      itr = adjacent_find(hand.begin(), hand.end(), faceCheck);
      new_hand.push_back(*itr);
      ++itr;
      new_hand.push_back(*itr);

      new_hand.push_back(new_deck.dealCard());
      new_hand.push_back(new_deck.dealCard());
      new_hand.push_back(new_deck.dealCard());
      cout << "Dealer changed 3 cards" << endl;

      return new_hand;
      break;
    case 1:
      itr = adjacent_find(hand.begin(), hand.end(), faceCheck);
      new_hand.push_back(*itr);
      ++itr;
      new_hand.push_back(*itr);
      ++itr;
      itr = adjacent_find(itr, hand.end(), faceCheck);
      new_hand.push_back(*itr);
      ++itr;
      new_hand.push_back(*itr);

      new_hand.push_back(new_deck.dealCard());
      cout << "Dealer changed 1 card" << endl;

      return new_hand;
      break;
    case 2:
      itr = adjacent_find(hand.begin(), hand.end(), faceCheck);
      new_hand.push_back(*itr);
      ++itr;
      new_hand.push_back(*itr);
      ++itr;
      new_hand.push_back(*itr);

      new_hand.push_back(new_deck.dealCard());
      new_hand.push_back(new_deck.dealCard());

      cout << "Dealer changed 2 cards" << endl;
      return new_hand;
      break;
    case 3:
      itr = adjacent_find(hand.begin(), hand.end(), faceCheck);
      new_hand.push_back(*itr);
      ++itr;
      new_hand.push_back(*itr);
      ++itr;
      new_hand.push_back(*itr);
      ++itr;
      new_hand.push_back(*itr);

      new_hand.push_back(new_deck.dealCard());

      cout << "Dealer changed 1 card" << endl;
      return new_hand;
      break;
    case 4:
      return hand;
      break;
    case 5:
      return hand;
    default:
      return hand;
      break;
  }
}
bool faceCheck(Card &card1, Card &card2){
	return card1.getFace() == card2.getFace();
}
//prints prompt for player to change card
bool prompt(){
	int input;
	cout << "\nWould you like another card ?  Yes = 1, No = 0" << endl;
	cin >> input;
	if(input == 1){
		return true;
	}
	else{
		return false;
	}
}
//Replaces the hand by going through loop and then calling the swap function
void playerReplace(Hand *temp, Card gemp){
	int idx;
	cout << "What card do you want to replace ? Note:(Max 3 Cards can be replaced)" << endl;
	cout << "Assume cards starts from 1 - 5 " << endl;
	cin >> idx;
	while(idx < 1 || idx > 5){
		cout << "Which card do you want to replace ? [1-5] " << endl;
		cin >> idx;
	}
	temp->swapCard(temp->getHand().at(--idx), gemp);

}