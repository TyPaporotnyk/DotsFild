
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
    bool run = true;
    
    while(window.isOpen())
    {
        // Clear
        if(run) window.clear(sf::Color::White);
        
        sf::Event event;
        
        // Logic
        if(run) fild->newLife();
        
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed){
                sf::Vector2i vector = sf::Mouse::getPosition(window);

                fild->setDot(vector.x, vector.y);
            }
            
            if(event.type == sf::Event::KeyPressed){
                run = !run;
            }
            
        }
        
        // Print
        fild->printDots(window);
        
        // Display
        window.display();
    }
    
    return 0;
}
