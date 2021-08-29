
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "Fild.h"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 1200

int main(){
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Simple Window");
    window.setFramerateLimit(50);
    Fild *fild = new Fild(SCREEN_WIDTH);
    
//    fild->printFild();
    
 // sf::Window::setMouseCursor(false);
    
    while(window.isOpen())
    {
        sf::Event event;
        
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            
//            if(event.type == sf::Event::Resized){
//                std::cout << "New window width => " << event.size.width << std::endl;
//                std::cout << "New window height => " << event.size.height << std::endl;
//                std::cout << std::endl;
//            }
//
//            if(event.type == sf::Event::MouseMoved){
//                sf::Vector2i vector = sf::Mouse::getPosition(window);
//
//                std::cout << "Mouse pos x => " << vector.x << std::endl;
//                std::cout << "Mouse pos y => " << vector.y << std::endl;
//
//                circle.setPosition(vector.x - circle.getRadius(), vector.y - circle.getRadius());
//                std::cout << std::endl;
//            }
            
        }

        window.clear(sf::Color::White);
        
        //
        
        fild->printDots(window);
        
        //
        window.display();
    }
    
    return 0;
}
