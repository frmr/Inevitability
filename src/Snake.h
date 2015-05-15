#ifndef SNAKE_H
#define SNAKE_H

#include <utility>      // std::pair, std::make_pair
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using std::vector;
using std::pair;

class Snake
{
public:
    enum Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONE
    } dir;

private:
    vector< pair<int, int> >    snake;
    int                         field[8][13];
    double                      updateInterval;
    double                      updateTimer;

    int             headX;
    int             headY;

    sf::Image       segmentImage;
    sf::Image       foodImage;

    sf::Sprite      segmentSprite;
    sf::Sprite      foodSprite;

private:
    bool    PointInSnake( const int x, const int y ) const;

public:
    bool    Update( vector<Direction>* newDir, const double elapsedTime );
    void    Draw( sf::RenderWindow* app );


public:
    Snake();
};

#endif // SNAKE_H
