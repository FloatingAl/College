/*
Name: Albara Mehene
Date:9/8/2016
Computing IV
To move the sprite use arrow keys. To rotate it, use the A and S keys.
*/




#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    /*sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);*/
    sf::Texture texture;
    //This sprite source is from a game called Overwatch. All credit goes to Blizzard Entertainment & Overwatch.http://Overwatch.com
    if(!texture.loadFromFile("sprite.png"))
            return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    int x ,y;
    x = 200;
    y = 200;
    sprite.setPosition(x,y);
                                            
    //loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)){
            
            if (event.type == sf::Event::Closed)
                window.close();
        }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            sprite.move(0,-3);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            sprite.move(0,3);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            sprite.move(-3,0);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            sprite.move(3,0);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            sprite.rotate(-3);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            sprite.rotate(3);

        window.clear();
        window.draw(sprite);
        window.display();


        

    }

    return 0;
}
