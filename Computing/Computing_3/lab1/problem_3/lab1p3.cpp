/*
Name: Albara Mehene
Date:1/27/2015
 */
#include <iostream>
//function header
int factorial(int value);
//main asks the user for the number and then factorial is called
int main()
{
  int number = 0; 
  int answer = 0;
  std::cout << " Enter a postive number " << std::endl;
  std::cin >> number;
  answer = factorial(number);
  std::cout << " The factorial of "<< number << " is "<< answer <<  std::endl;

    return 0;

}
//This function recursivly computes the number factorial
int factorial(int value)
{
  //Base case to stop
  if(value == 0)
    return 1;
  return value * factorial(value-1);
}

