
#include "ED.hpp"

int main(int argc, char* argv[]){

	std::string store;
	std::string string_1; 
	std::string string_2;
	std::string answer;
	
	sf::Clock clock;
	sf::Time t;
	
	std::cin >> store;
	string_1 = store;
	std::cin >> store;
	string_2 = store; 

	ED temp(string_1,string_2);

	//displays the execution time
	t = clock.getElapsedTime();
	std::cout << t.asSeconds() << "seconds" << std::endl;

	

	return 0;
}