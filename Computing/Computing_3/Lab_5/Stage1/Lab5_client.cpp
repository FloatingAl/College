#include <vector>
#include <string>
#include <iostream>
#include "Lab5.h"

using namespace std;

int main() {
  HashTable h;

  string s1 = "John"; 
  string s2 = "Jake";
  string s3 = "Jane";
  string s4 = "Joanne";

  cout << h.insert(s1, 18) << endl;
  cout << h.insert(s2, 21) << endl;
  cout << h.insert(s3, 19) << endl;
  cout << h.insert(s4, 20) << endl;

  cout << "John: " << h.get(s1) << endl;
  cout << "Jake: " << h.get(s2) << endl;
  cout << "Jane: " << h.get(s3) << endl; 
  cout << "Joanne: " << h.get(s4) << endl;
  
  int count = 0;
  for (auto item : h.info){
    cout << count++ << " " << item << endl;
  }
}