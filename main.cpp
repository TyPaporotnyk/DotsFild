#include <SFML/Graphics.hpp>
#include <iostream>

using std::cout;
using std::endl;

#define WIDTH 1980
#define HEIGHT 1280

#define RANDOM_RANGE 2

#define SQUARE_RADIUS 20

int **fild;
int **oldFild;

int quanHorElements;
int quanWertElements;

int age = 0;
int colony = 0;

void initFild()
{
    quanWertElements = WIDTH / SQUARE_RADIUS;
    quanHorElements = HEIGHT / SQUARE_RADIUS;

    fild = new int*[quanHorElements];
    oldFild = new int*[quanHorElements];

    for(int i = 0; i < quanHorElements; i++)
    {
        fild[i] = new int[quanWertElements];
        oldFild[i] = new int[quanWertElements];

        for(int j = 0; j < quanWertElements; j++)
        {
            fild[i][j] = (rand() % RANDOM_RANGE + 1) == 1 ? 1 : 0;
            oldFild[i][j] = 0;
        }
    }
}

void swapFild()
{
    for(int i = 0; i < quanHorElements; i++)
    {
        for(int j = 0; j < quanWertElements; j++)
        {
            oldFild[i][j] = fild[i][j];
            //fild[i][j] = 0;
        }
    }
}

void printFild(sf::RenderWindow &window)
{
    sf::RectangleShape square(sf::Vector2f(SQUARE_RADIUS, SQUARE_RADIUS));
    square.setFillColor(sf::Color::White);
    square.setOutlineColor(sf::Color::Black);
    square.setOutlineThickness(1);

    for(int i = 0; i < quanHorElements; i++)
    {
        for(int j = 0; j < quanWertElements; j++)
        {
            square.setPosition(SQUARE_RADIUS * j + (WIDTH % SQUARE_RADIUS) / 2,
                               SQUARE_RADIUS * i + (HEIGHT % SQUARE_RADIUS) / 2);

            if(oldFild[i][j] == 1) square.setFillColor(sf::Color::Black);
            else square.setFillColor(sf::Color::White);

            window.draw(square);
        }
    }
}

void newAge()
{
    swapFild();
    for(int i = 0; i < quanHorElements; i++)
    {
        for(int j = 0; j < quanWertElements; j++)
        {
            int points = 0;

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

                    if(oldFild[posI][posJ] == 1) points++;
                }
            }

            if(oldFild[i][j] == 0 && points == 3)
            {
                fild[i][j] = 1;
                colony++;
            }

            else if(oldFild[i][j] == 1 && (points >= 2 && points <= 3))
            {
                colony++;
                continue;
            }
            else
            {
                fild[i][j] = 0;
            }
        }
    }

    age++;
}

int main()
{
    bool run = true;

    initFild();

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Game life");

    window.setFramerateLimit(10);
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed) window.close();
            else if( event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Space) run = !run;
            }
        }

        window.clear(sf::Color::White);

        if(run) newAge();

        printFild(window);

        window.display();
    }

    return 0;
}
