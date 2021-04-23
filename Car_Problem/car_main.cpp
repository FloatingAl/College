#include "car.h"




int main (int argc, char* argv[]){

std::string car_name;

std::cout << "What is the car you would like to drive ? " << std::endl;

cin >> car_name;


Car brand(car_name);






	return 0;
}