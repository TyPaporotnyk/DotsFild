
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "Fild.h"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 1200

int main(){
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Simple Window");
    window.setFramerateLimit(120);
    Fild *fild = new Fild(SCREEN_WIDTH);
    
    while(window.isOpen())
    {
        sf::Event event;
        
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed){
                sf::Vector2i vector = sf::Mouse::getPosition(window);

                fild->setDot(window, vector.x, vector.y);
            }
            
        }

        window.clear(sf::Color::White);
        
        fild->printDots(window);
        
        window.display();
    }
    
    return 0;
}
