/*
  Name: Albara Mehene
  Date: 4/14/2016
  Computing III

*/
#include <string>
#include <iostream>
#include <utility>
#include <list>
#include "Lab5_2.h"

using namespace std;

int main() {
  HashTable h;

  string s1 = "John"; 
  string s2 = "Jake";
  string s3 = "Jane";
  string s4 = "Joanne";


  h.insert(s1, 18); 
  h.insert(s2, 21);
  h.insert(s3, 19);
  h.insert(s4, 20);

  /*
    pair <string, int> jopair(s4,20);
    list <pair <string,int >> joList;
    joList.push_back(joPair);
    h[s4] = joList;


    */

  cout << "John: " << h.get(s1) << endl;

  //h[s4] = 20;
  cout << "Joanne: " << h.get(s4) << endl;
  //cout << "Joanne: " << h[s4] << endl;
  
  int count = 0;
  for (auto item : h.info){
    cout << count++ << " " << item << endl;
  }
}