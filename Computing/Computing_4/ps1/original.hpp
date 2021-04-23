#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Fractal : public sf::Drawable
{
	public:

	 Fractal(int n, int size_frac);

	 void fractal_rec(sf::ConvexShape fractal_shape, int recursion, sf::RenderTarget &target) const;

	 sf::ConvexShape filledFractal(sf::Vector2f point1,sf::Vector2f point2, sf::Vector2f point3, sf::Vector2f point4,sf::RenderTarget &target) const;

	 ~Fractal();




	private:
	sf::ConvexShape square;

	int depth;
	int side;

	void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;

};