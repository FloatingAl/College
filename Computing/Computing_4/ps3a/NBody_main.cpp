#include "NBody.hpp"


int main(int argc, char* argv[]){

    std::string store;//stores the input from the file
    std::string name;//name of planet
    int numberOfPlanets;
    float radius;//radius of window

    //stores the number of planets
    std::cin >> store;
    std::stringstream(store) >> numberOfPlanets;
    
    std::vector<Body> objects(numberOfPlanets);//vector of objects to store all objects

    //stores the radius of the window
    std::cin >> store;
    std::stringstream(store) >> radius;

    //loop that stores all relevant data from the file
    for (int x = 0; x < numberOfPlanets; x++){        
        std::cin >> objects[x];
    }

    //take the data inside the 
    //vector of bodies and print it on the screen using SFML
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Ps3a Universe");
    
    //display window
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)    
                window.close();
        }
        window.clear(sf::Color::Black);
        //display all the planets
        for(int i = 0; i < numberOfPlanets; i++){
            window.draw(objects[i]);
        }
        window.display();
    }

    return 0;
}