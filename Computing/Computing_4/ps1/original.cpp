/*
	Name: Albara Mehene
	Date:9/18/2016
	Computing IV
*/

#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "original.hpp" 

int main(int argc, char* argv[]){

	if(argc < 3){

			std::cout<<"Fractal [recursion-depth] [side-length]"<< std::endl;
			return -1;
	}
	//Atoi connverts strings to integers
	int depth_ = atoi(argv[1]);
	int side_ = atoi(argv[2]);
	 
	 sf::RenderWindow window(sf::VideoMode(side_,side_), "Original Fractal");

    	Fractal frac(depth_, side_);

		window.setFramerateLimit(1);

		 while(window.isOpen())
		 {
			  sf::Event event;
			  while(window.pollEvent(event))
			  {
					if(event.type == sf::Event::Closed)
						 window.close();
			  }
			  window.clear();
			  window.draw(frac);
			  window.display();
		 }

	 	return 0;
	}