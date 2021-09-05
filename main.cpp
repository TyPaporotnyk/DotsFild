
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>

#include "Fild.h"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 1200

#define PATH_TO_FILE "/Users/daniil/Desktop/SimleGame/SimleGame/evolution.txt"
#define PATH_TO_FONT_FILE "/Users/daniil/Desktop/SimleGame/SimleGame/Font/arial.ttf"

//void fontInit(sf::Font &font);

int main(){
    bool run = true;
    bool write = true;
    int colony = 0;
    int age = 0;
    
    std::ofstream writeToFile(PATH_TO_FILE, std::ios::out | std::ios::trunc);
    if(!writeToFile.is_open()) write = false;
    // Window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game Life");
    window.setFramerateLimit(10);
    
    // Init
    // Font
//    sf::Font font;
//    fontInit(font);
//
//    sf::Text colonyText("Colony: " + colony, font, 50);
//    sf::Text ageText("Age: " + age, font, 50);
//
//    colonyText.setFillColor(sf::Color::Black);
//    ageText.setFillColor(sf::Color::Black);

    //Fild
    Fild *fild = new Fild(SCREEN_WIDTH);
    
    
    while(window.isOpen())
    {
        // Clear
        if(run) window.clear(sf::Color::White);
        
        sf::Event event;
        
        // Logic
        if(run) fild->newLife(age, colony);
        
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
        
        // Draw text
        if(run && write) writeToFile << age << "    " << colony << "\n";
//        ageText.setString("Age: " + age);
//
//        window.draw(ageText);
//        window.draw(colonyText);
        
        // Display
        window.display();
    }
    
    writeToFile.close();
    
    delete fild;
    
    return 0;
}

void fontInit(sf::Font &font)
{
    if(!font.loadFromFile(PATH_TO_FONT_FILE))
    {
        std::cout << "Font not Loaded!" << std::endl;
        return -1;
    }
    std::cout << "Load sucsesful!" << std::endl;
}
