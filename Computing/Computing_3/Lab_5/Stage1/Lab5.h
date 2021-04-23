#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HashTable{
public:
	int size;
	int inserted;
	vector < int > info;

HashTable(int size_ = 10) : info(size_){

}
unsigned long my_hash(string &str);
int getSize();
bool insert(string key, int value);
int get(string temp);

};
