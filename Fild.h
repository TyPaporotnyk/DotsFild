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

#define FILD_LEN 100

class Fild{
private:
    int fild[FILD_LEN][FILD_LEN] = {};
    int oldFild[FILD_LEN][FILD_LEN] = {};
    int lenFild;
    
public:
    explicit Fild(int len);
    
    void printDots(sf::RenderWindow &window);
    void newGenerate();
    void setDot(int x, int y);
    void newLife();
    [[deprecated]] void printFild();
    
};

#endif /* Fild_hpp */
