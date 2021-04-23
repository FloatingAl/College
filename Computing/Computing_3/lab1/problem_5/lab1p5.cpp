/*
Name: Albara Mehene
Date: 1/27/2016
 */
#include <iostream>
#include <cmath>

//This program is to ask the user for the base and exponet. Then computes as a power. 
int main()
{
  int base = 0;
  int expo = 0;
  int answer = 0;

  std::cout << "Please pick base number:" << std::endl;
  std::cin >> base;
  std::cout << "Please pick exponent for the base:" << std::endl;
  std::cin >> expo;

  answer = std::pow(base,expo);
  std::cout << "The answer is " << answer << std::endl;
  

}
