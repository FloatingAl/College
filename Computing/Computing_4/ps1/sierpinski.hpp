







#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Sierpinski : public sf::Drawable
{
	public:
		
		Sierpinski(int N, int size_tri);

		void sierpinski(sf::ConvexShape mid_triangle, int recursion,sf::RenderTarget& target) const; 

		sf::ConvexShape filledtriangle(sf::Vector2f left_tri, sf::Vector2f bottom_tri, sf::Vector2f right_tri,sf::RenderTarget& target) const;
		//destructor;
		~Sierpinski();
		
	private:
		sf::ConvexShape triangle;

		int depth_;
		int side_;
		

		void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
		

};
