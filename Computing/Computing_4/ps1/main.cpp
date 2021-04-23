/*
	Name: Albara Mehene
	Date:9/17/2016
	Computing IV
*/
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "sierpinski.hpp"

int main(int argc, char* argv[]){

	if(argc < 3){

			std::cout<<"sierpinski [recursion-depth] [side-length]"<< std::endl;
			return -1;
	}
	//Atoi connverts strings to integers
	int depth = atoi(argv[1]);
	int side = atoi(argv[2]);
	 
	 sf::RenderWindow
		  window(sf::VideoMode(side,(int)(.5*sqrt(3.)*(float)side)), "Sierpinski Triangle");

	Sierpinski sierpinski(depth, side);


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
		  window.draw(sierpinski);
		  window.display();
	 }

	 return 0;
}