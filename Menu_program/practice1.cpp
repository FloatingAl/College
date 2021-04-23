#include <iostream>
#include <string>
#include <ctype.h>

//Program on ordering food from a fast food resturant.
int main(int argc, char* argv[]){

std::string selection;
int iteration = 1;
int numSelect = 0;
std::cout << "***MENU***" << std::endl;
std::cout << "1.Combos\n"   
          << "2.Sandwitches\n"
          << "3.Sides\n"
          << "4.Drinks\n" 
          << "Please choose any of the selections: "
          << std::endl;

std::getline(std::cin, selection);

while(iteration){

	if(selection == "1"){
		iteration = 0;
		std::cout << "\nCombo function" << std::endl;
	}else if(selection == "2"){
		iteration = 0;
		std::cout << "\nCombo function2" << std::endl;

	}else if(selection == "3"){
		iteration = 0;
		std::cout << "\nCombo function3" << std::endl;

	}else if(selection == "4"){
		iteration = 0;
		std::cout << "\nCombo function4" << std::endl;
	}else{
		iteration = 1;
		std::cout << "\nI'm sorry, that is not a choice.\nPlease try again:"
			<< std::endl;
		std::getline(std::cin, selection);
	}

}

/*while(iteration){

	std::getline(std::cin, selection);

	while(std::isalpha(selection[0])){
		std::cout << "\nI'm sorry, that is not a choice.\nPlease try again:"
			<< std::endl;
		std::getline(std::cin, selection);
	}
	numSelect = std::stoi(selection);
		switch (numSelect) {
	 
			case 1:
				iteration = 0;
				std::cout << "\nCombo function" << std::endl;
				break;

			case 2:
				iteration = 0;
				std::cout << "\nCombo function2" << std::endl;
				break;

			case 3:
				iteration = 0;
				std::cout << "\nCombo function3" << std::endl;
				break;

			case 4:
				iteration = 0;
				std::cout << "\nCombo function4" << std::endl;
				break;
			default:
				iteration = 1;
				std::cout << "\nI'm sorry, that is not a choice.\nPlease try again:"
				<< std::endl;
				break;
		}
}*/




     return 0;


}
