/*
Name: Albara Mehene
Date: 1/27/2016
 */
#include <iostream>
//Same as problem 3, ask the user for a number, and is factorial. Instead of a function, I used a loop for this one.

int main()
{
  int exit = 1;
  while(exit == 1)
    {
      int number = 0; 
      int final = 1;
      //ask user for input
      std::cout << " Enter a postive number " << std::endl;
      std::cin >> number;
      //loop for the work for factorial
      for(int i = 1; i <= number;i++)
	{
	  final = final * i;
	}
     std::cout << " The factorial of "<< number << " is "<< final <<     std::endl;
     //ask user if they want to continue
     std::cout << "Exit(0) or Continue(1)"<< std::endl;
     std::cin >> exit;
    }

    return 0;

}
