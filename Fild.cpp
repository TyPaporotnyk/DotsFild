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

#define TEST

void Fild::printDots(sf::RenderWindow &window)
{
    int subLen = lenFild / 2;
    sf::RectangleShape shape(sf::Vector2f(lenFild, lenFild));
    
    for(int i = 0; i < FILD_LEN; i++)
    {
        for(int j = 0; j < FILD_LEN; j++)
        {
            shape.setPosition((lenFild * ((j + 1)) - lenFild),
                               (lenFild * ((i + 1)) - lenFild));
            
            if(oldFild[i][j] == 1)
            {
                shape.setFillColor(sf::Color::Black);
               
            }
            else {
                shape.setFillColor(sf::Color::White);
            }
            
            window.draw(shape);
        }
    }
}

void Fild::newGenerate()
{
    for(int i = 0; i < FILD_LEN; i++)
    {
        for(int j = 0; j < FILD_LEN; j++)
        {
            fild[i][j] = rand() % 2;
        }
    }
}

void Fild::newLife()
{
    for(int i = 0; i < FILD_LEN; i++)
    {
        for(int j = 0; j < FILD_LEN; j++)
        {
            oldFild[i][j] = fild[i][j];
        }
    }
    
    for(int i = 0; i < FILD_LEN; i++)
    {
        for(int j = 0; j < FILD_LEN; j++)
        {
            int points = 0;
            
            for(int di = -1; di <= 1; di++)
            {
                for(int dj = -1; dj <= 1; dj++)
                {
                    if(di == 0 && dj == 0) continue;
                    if(oldFild[i + di][j + dj] == 1) points++;
                }
            }
            
            if(oldFild[i][j] == 0 && points == 3)
            {
                fild[i][j] = 1;
            }
            
            else if(oldFild[i][j] == 1 && (points >= 2 && points <= 3))
            {
                continue;
            }
            else
            {
                fild[i][j] = 0;
            }
        }
    }
}

void Fild::setDot(int mouseX, int mouseY)
{
    int dotX = mouseX / lenFild;
    int dotY = mouseY / lenFild;
    
#ifdef TEST
    std::cout << "X -> " << mouseX << "; Y -> " << mouseY << std::endl;
    std::cout << "dX -> " << dotX << "; dY -> " << dotY << std::endl;
    std::cout << oldFild[dotX][dotY] << std::endl;
#endif
    
    if(fild[dotY][dotX] == 0)
    {
        fild[dotY][dotX] = 1;
    }
    else
    {
        fild[dotY][dotX] = 0;
    }
    
#ifdef TEST
//  std::cout << fild[dotX][dotY] << std::endl;
#endif
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
            std::cout << fild[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
