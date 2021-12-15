#include <iostream>
#include "GameLife.h"

int main()
{
    std::cout << "To stop the game pres \"SPACE\"" << std::endl;
    std::cout << "To clear the field pres \"C\"" << std::endl;
    std::cout << "To generate new field pres \"N\"" << std::endl;
    std::cout << "To create a new point press \"LB\" on the selected area" << std::endl;

    GameLife g;
    g.run();

    return 0;
}

