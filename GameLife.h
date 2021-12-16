#pragma once

#include <SFML/Graphics.hpp>

class GameLife{
private:
    const int WIDTH = 1980;
    const int HEIGHT = 1280;

    const int RANDOM_RANGE = 5;

    const int SQUARE_RADIUS = 20;

    int **field;
    int **oldField;

    int quanHorElements;
    int quanWertElements;

    bool action = true;
    bool board = true;
    int age = 0;
    int colony = 0;
    int speed = 10;

    void initField();
    void deleteField();
    void mouseClickEvent(const sf::Vector2<int> mousePos);
    void swapField();
    void printField(sf::RenderWindow &window);
    void setCount(sf::RenderWindow &window);
    void newAge();
    void clearField();
    void newGenerate();

public:
    GameLife();
    ~GameLife();

    void run();
};

