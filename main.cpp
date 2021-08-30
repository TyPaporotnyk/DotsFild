
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "Fild.h"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 1200

int main(){
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game Life");
    window.setFramerateLimit(10);
    Fild *fild = new Fild(SCREEN_WIDTH);
    
    while(window.isOpen())
    {
        // Clear
        window.clear(sf::Color::White);
        
        sf::Event event;
        
        // Logic
        fild->newLife();
        
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
            {
                fild->newGenerate();
                std::cout << "New Generate" << std::endl;
            }
            
            if(event.type == sf::Event::MouseButtonPressed){
                sf::Vector2i vector = sf::Mouse::getPosition(window);

                fild->setDot(window, vector.x, vector.y);
            }
            
        }
        
        
        
        // Print
        fild->printDots(window);
        
        // Display
        window.display();
    }
    
    return 0;
}
