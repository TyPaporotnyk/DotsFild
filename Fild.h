//
//  Fild.hpp
//  SimleGame
//
//  Created by Даниил on 30.08.2021.
//  Copyright © 2021 Даниил. All rights reserved.
//

#ifndef Fild_H
#define Fild_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>

#define FILD_LEN 50

class Fild{
private:
    int fild[FILD_LEN][FILD_LEN];
    int lenFild;
    
public:
    Fild(int len)
    {
        lenFild = len / FILD_LEN;
        
        srand(time(NULL));
        for(int i = 0; i < FILD_LEN; i++)
        {
            for(int j = 0; j < FILD_LEN; j++)
            {
                fild[i][j] = rand() % 10;
            }
        }
    }
    
    void printDots(sf::RenderWindow &window);
    
    [[deprecated]] void printFild();
    
};

#endif /* Fild_hpp */
