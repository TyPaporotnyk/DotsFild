//
//  Fild.cpp
//  SimleGame
//
//  Created by Даниил on 30.08.2021.
//  Copyright © 2021 Даниил. All rights reserved.
//

#include "Fild.h"

void Fild::printDots(sf::RenderWindow &window)
{
    sf::CircleShape circle(this->lenFild / 2);
    
    int subLen = lenFild / 2;
    
    for(int i = 0; i < FILD_LEN; i++)
    {
        for(int j = 0; j < FILD_LEN; j++)
        {
            if(this->fild[i][j] >= 1 && this->fild[i][j] <= 5)
            {
                circle.setFillColor(sf::Color::Black);
                circle.setPosition((lenFild * ((j + 1)) - lenFild),
                                   (lenFild * ((i + 1)) - lenFild));
                
                window.draw(circle);
            }
            else if(this->fild[i][j] == 9)
            {
                circle.setFillColor(sf::Color::Red);
                circle.setPosition((lenFild * ((j + 1)) - lenFild),
                                   (lenFild * ((i + 1)) - lenFild));
                
                window.draw(circle);
            }
        }
    }
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

