
#include "ED.hpp"

int main(int argc, char* argv[]){

	std::string store;
	std::string string_1; 
	std::string string_2;
	std::string answer;
	
	int e_distance;
	sf::Clock clock;
	sf::Time t;
	
	std::cin >> store;
	string_1 = store;
	std::cin >> store;
	string_2 = store; 

	ED temp(string_1,string_2);

	e_distance = temp.optDistance();
	std::cout << "Edit Distance = " << e_distance << std::endl;

	answer = temp.alignment();
	for(unsigned int i = 0; i < answer.size(); i += 3){
		std::cout << answer[i] << " " <<  answer[i+1] << " " << answer[i+2] << std::endl;
	}

	//displays the execution time
	t = clock.getElapsedTime();
	std::cout << t.asSeconds() << "seconds" << std::endl;

	

	return 0;
}