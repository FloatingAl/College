/*
Name: ALbara Mehene
Date: 9/25/2016
Computing IV

*/


#include <iostream>
#include <string>
#include <cmath>
#include "LFSR.hpp"

//constructor
LFSR::LFSR(std::string seed_, int tap_){

	seed = seed_;
	tap = tap_;

}


int LFSR::step(){
	int bit;
	int size;

	size = seed.length();//stored the amount of elements

	bit =  seed.at(0) ^ seed [size - tap - 1]; //Took the total elements and subtracted by the tap and by 1 

	
	seed.erase(0, 1); // erased the front element

	if(bit == 1){//condition if its 1, it would return the chracter 1
		seed.push_back('1');
	}
	else{//returns 0 if its anything else
		seed.push_back('0');
	}
	//returns bit to test the test.cpp
	return bit;
}

int LFSR::generate(int k){
	int temp = 0;
	
	//Condition to test the generate function in test.cpp
	for(int i = k - 1; i >= 0; i--){
		if(step() == 1){
			temp += pow(2,i);
		}
	}	
	return temp;
	
}
//prints out the string if I were to use the a main. It was not required in this assigment
std::ostream& operator<< (std::ostream &out, LFSR &lfsr){
	out << lfsr.seed;
	return out;
}



LFSR::~LFSR(){

}




