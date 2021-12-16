#include "GameLife.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

GameLife::GameLife()
{
    quanWertElements = WIDTH / SQUARE_RADIUS;
    quanHorElements = HEIGHT / SQUARE_RADIUS;

    initField();
}

GameLife::~GameLife()
{
    deleteField();
}

void GameLife::run()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Game life");
    window.setFramerateLimit(speed);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            // button click event
            if(event.type == sf::Event::Closed) window.close();
            else if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Space) action = !action;
                else if(event.key.code == sf::Keyboard::N) newGenerate();
                else if(event.key.code == sf::Keyboard::C) clearField();
                else if(event.key.code == sf::Keyboard::B) board = !board;
                else if(event.key.code == sf::Keyboard::LBracket && speed > 2)
                {
                    speed--;
                    cout << "Speed: " << speed << endl;
                    window.setFramerateLimit(speed);
                }
                else if(event.key.code == sf::Keyboard::RBracket && speed < 60)
                {
                    speed++;
                    cout << "Speed: " << speed << "\\50" << endl;
                    window.setFramerateLimit(speed);
                }
            }

            // mouse click event
            else if( event.type == sf::Event::MouseButtonPressed)
            {
                mouseClickEvent(sf::Mouse::getPosition(window));
            }
        }

        window.clear(sf::Color::White);

        if(action){
            newAge();
            setCount(window);
        }

        printField(window);

        window.display();
    }

}

// creating two arrays and fill up them
void GameLife::initField()
{
    field = new int*[quanHorElements];
    oldField = new int*[quanHorElements];

    for(int i = 0; i < quanHorElements; i++)
    {
        field[i] = new int[quanWertElements];
        oldField[i] = new int[quanWertElements];

        for(int j = 0; j < quanWertElements; j++)
        {
            field[i][j] = (rand() % RANDOM_RANGE + 1) == 1 ? 1 : 0;
            oldField[i][j] = 0;
        }
    }
}

void GameLife::deleteField()
{
    for(int i = 0; i < quanHorElements; i++)
    {
        delete[] field[i];
        delete[] oldField[i];
    }

    delete[] field;
    delete[] oldField;
}

// get each element of array and depending on the value
// draw squares on the window
void GameLife::printField(sf::RenderWindow &window)
{
    sf::RectangleShape square(sf::Vector2f(SQUARE_RADIUS, SQUARE_RADIUS));
    if(board)
    {
        square.setOutlineColor(sf::Color::Black);
        square.setOutlineThickness(1);
    }
    square.setFillColor(sf::Color::White);

    for(int i = 0; i < quanHorElements; i++)
    {
        for(int j = 0; j < quanWertElements; j++)
        {
            square.setPosition(SQUARE_RADIUS * j + (WIDTH % SQUARE_RADIUS) / 2,
                               SQUARE_RADIUS * i + (HEIGHT % SQUARE_RADIUS) / 2);

            if(oldField[i][j] == 1 && action) square.setFillColor(sf::Color::Black);
            else if(field[i][j] == 1 && !action) square.setFillColor(sf::Color::Black);
            else square.setFillColor(sf::Color::White);

            window.draw(square);
        }
    }
}

// create new age and swap elements from field to oldField
void GameLife::newAge()
{
    colony = 0;
    swapField();

    for(int i = 0; i < quanHorElements; i++)
    {
        for(int j = 0; j < quanWertElements; j++)
        {
            int points = 0;

            // looking for neighbor and increases value if true
            for(int di = -1; di <= 1; di++)
            {
                for(int dj = -1; dj <= 1; dj++)
                {
                    int posI = 0;
                    int posJ = 0;

                    if(di == 0 && dj == 0) continue;

                    posI = i + di;
                    if(posI == quanHorElements) posI = 0;
                    else if(posI == -1) posI = quanHorElements - 1;

                    posJ = j + dj;
                    if(posJ == quanWertElements) posJ = 0;
                    else if(posJ == -1) posJ = quanWertElements - 1;

                    if(oldField[posI][posJ] == 1) points++;
                }
            }

            // rules
            if(oldField[i][j] == 0 && (points == 3))
            {
                field[i][j] = 1;
                colony++;
            }
            else if(oldField[i][j] == 1 && (points >= 2 && points <= 3))
            {
                colony++;
                continue;
            }
            else
            {
                field[i][j] = 0;
            }
        }
    }
    age++;
}

void GameLife::swapField()
{
    for(int i = 0; i < quanHorElements; i++)
    {
        for(int j = 0; j < quanWertElements; j++)
        {
            oldField[i][j] = field[i][j];
        }
    }
}

void GameLife::clearField()
{
    age = 0;
    colony = 0;

    for(int i = 0; i < quanHorElements; i++)
    {
        for(int j = 0; j < quanWertElements; j++)
        {
            field[i][j] = 0;
        }
    }
}

void GameLife::newGenerate()
{
    age = 0;
    colony = 0;

    for(int i = 0; i < quanHorElements; i++)
    {
        for(int j = 0; j < quanWertElements; j++)
        {
            field[i][j] = (rand() % RANDOM_RANGE + 1) == 1 ? 1 : 0;
        }

    }
}

void GameLife::mouseClickEvent(const sf::Vector2<int> mousePos)
{
    int mousePosI = mousePos.y / SQUARE_RADIUS;
    int mousePosJ = mousePos.x / SQUARE_RADIUS;

    if(field[mousePosI][mousePosJ] == 1) field[mousePosI][mousePosJ] = 0;
    else field[mousePosI][mousePosJ] = 1;

    cout << "X: " << mousePosJ + 1 << " Y: " << mousePosI + 1 << endl;
}

void GameLife::setCount(sf::RenderWindow &window)
{
    window.setTitle("Age: " + std::to_string(age) + ", Colony: " + std::to_string(colony));
}

