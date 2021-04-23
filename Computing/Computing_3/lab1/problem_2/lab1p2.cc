/*
Name: Albara Mehene
Date: 1/27/2016
 */

#include <iostream>

using namespace std;
//This function is print out the command line arguments fiven to it
int main(int argc, char* argv[])
 {
   
   std::cout << argc << endl;
   //loop to store what is inputed from user after typing running program example "./main hello there
  for(int i = 0; i < argc; i++)
  {
   std::cout << argv[i] << endl;
  }
}
