//
//  Fild.cpp
//  SimleGame
//
//  Created by Даниил on 30.08.2021.
//  Copyright © 2021 Даниил. All rights reserved.
//

#include "Fild.h"

#include <ctime>
#include <iostream>

//#define TEST

void Fild::printDots(sf::RenderWindow &window)
{
    sf::RectangleShape shape(sf::Vector2f(this->lenFild, this->lenFild));
    // sf::CircleShape circle(this->lenFild / 2);
    
    int subLen = lenFild / 2;
    
    for(int i = 0; i < FILD_LEN; i++)
    {
        for(int j = 0; j < FILD_LEN; j++)
        {
            if(this->fild[i][j] == 1)
            {
                shape.setFillColor(sf::Color::Black);
                shape.setPosition((lenFild * ((j + 1)) - lenFild),
                                   (lenFild * ((i + 1)) - lenFild));
                
                window.draw(shape);
            }
        }
    }
}

void Fild::newGenerate()
{
    for(int i = 0; i < FILD_LEN; i++)
    {
        for(int j = 0; j < FILD_LEN; j++)
        {
            this->fild[i][j] = rand() % 2;
        }
    }
}

void Fild::setDot(sf::RenderWindow &window, int mouseX, int mouseY)
{
    sf::RectangleShape shape(sf::Vector2f(this->lenFild, this->lenFild));
    shape.setFillColor(sf::Color::Black);
    
    
    int dotX = mouseX / lenFild;
    int dotY = mouseY / lenFild;
    
#ifdef TEST
    std::cout << "X -> " << mouseX << "; Y -> " << mouseY << std::endl;
    std::cout << "dX -> " << dotX << "; dY -> " << dotY << std::endl;
#endif
    
    if(this->fild[dotY][dotX] == 0)
    {
        this->fild[dotY][dotX] = 1;
    }
    else
    {
        this->fild[dotY][dotX] = 0;
    }
}

Fild::Fild(int len)
{
    lenFild = len / FILD_LEN;
    
    srand(time(NULL));
    newGenerate();
    
#ifdef TEST
    printFild();
#endif
}

void Fild::printFild()
{
    for(int i = 0; i < 30; i++)
    {
        for(int j = 0; j < 30; j++)
        {
            std::cout << this->fild[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

