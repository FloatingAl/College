#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <list>
#include "Lab5_2.h"

using namespace std;

unsigned long HashTable::my_hash(string &str){
	unsigned long hash = 5381;
	int c;
	for (int i = 0; i < str.length(); i++){
		c = str[i];
		hash = ((hash << 5) + hash)+ c;
	}
	return hash;
}

int HashTable::getSize(){
	return info.size();
}

bool HashTable::insert(string key, int value){
	int offset = my_hash(key) % getSize();

	if(info[offset] == 0){
		info[offset] = value;
		return true;
	}
	else
	{
		return false;
	}


}

int HashTable::get(string key){
	int offset = my_hash(key) % getSize();
	if(info[offset] != 0){
		return info[offset];
	}
	else{
		return (int) 0;
	}
}
/*int &operator[](string key){
	int offset = my_hash(key) % size();
	return vector <int>::operator[](offset);
}*/