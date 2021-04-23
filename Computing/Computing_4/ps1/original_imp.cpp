#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "original.hpp"


void Fractal::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(square, states);
	fractal_rec(square, depth, target);
}

Fractal::Fractal(int N, int size_frac){
	side = size_frac;
	depth = N;

	square.setPointCount(4);
	square.setPoint(0, sf::Vector2f(side/2, 0));//top
	square.setPoint(1, sf::Vector2f(0, side/2));//left
	square.setPoint(2, sf::Vector2f(side/2, side));//bottom
	square.setPoint(3, sf::Vector2f(side, side/2));//right

	square.setFillColor(sf::Color::Red);
	square.setOutlineColor(sf::Color::White);
	square.setOutlineThickness(5);
}
void Fractal::fractal_rec(sf::ConvexShape fractal_shape, int recursion, sf::RenderTarget &target) const{
	sf::Vector2f left,top,right,bottom;
	sf::Vector2f mid_lefttop, mid_topright, mid_rightbottom, mid_bottomleft;
	
	sf::ConvexShape temp1_sqr, temp2_sqr, temp3_sqr, temp4,sqr;

	if(recursion == 0){
		return;
	}
	else{
		top = fractal_shape.getPoint(0);
		left = fractal_shape.getPoint(1);
		bottom = fractal_shape.getPoint(2);
		right = fractal_shape.getPoint(3);

		mid_lefttop.x = (left.x + top.x)/2;
		mid_lefttop.y = (left.y + top.y)/2;

		mid_topright.x = (top.x + right.x)/2;
		mid_topright.y = (top.y + right.y)/2;

		mid_rightbottom.x = (right.x + bottom.x)/2;
		mid_rightbottom.y = (right.y + bottom.y)/2;

		mid_bottomleft.x = (left.x + bottom.x)/2;
		mid_bottomleft.y = (left.y + bottom.y)/2;

		temp1_sqr = filledFractal(mid_lefttop, mid_topright, mid_rightbottom, mid_bottomleft, target);

		fractal_rec(temp1_sqr, recursion - 1, target);
	}

}
sf::ConvexShape Fractal::filledFractal(sf::Vector2f point1,sf::Vector2f point2, sf::Vector2f point3, sf::Vector2f point4,sf::RenderTarget &target) const{
	sf::ConvexShape mini_square;

	mini_square.setPointCount(4);
	mini_square.setPoint(0, point1);
	mini_square.setPoint(1, point2);
	mini_square.setPoint(2, point3);
	mini_square.setPoint(3, point4);

	mini_square.setFillColor(sf::Color::Black);
	mini_square.setOutlineColor(sf::Color::White);
	mini_square.setOutlineThickness(5);

	target.draw(mini_square);

	return mini_square;

}

Fractal::~Fractal(){

}