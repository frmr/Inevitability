#include "Snake.h"

#include "Random.h"

using std::make_pair;

Snake::Snake()
    : updateInterval( 200.0 ),
      updateTimer( 200.0 ),
      headX( 4 ),
      headY( 7 )
{
    for ( int i = 0; i < 8; i++ )
    {
        for ( int j = 0; j < 13; j++ )
        {
            field[i][j] = 0;
        }
    }

    snake.push_back( make_pair( headX, headY ) );

    int newFoodX = headX;
    int newFoodY = headY;

    while ( PointInSnake( newFoodX, newFoodY ) )
    {
        newFoodX = Random::Rand( 0, 7 );
        newFoodY = Random::Rand( 0, 12 );
    }

    field[newFoodX][newFoodY] = 1;

    dir = NONE;


    segmentImage.LoadFromFile( "media/segment.png" );
    foodImage.LoadFromFile( "media/food.png" );

    segmentImage.SetSmooth( false );
    foodImage.SetSmooth( false );

    segmentSprite.SetImage( segmentImage );
    foodSprite.SetImage( foodImage );

}

bool Snake::PointInSnake( const int x, const int y ) const
{
    for ( int i = 0; i < snake.size(); i++ )
    {
        if ( snake[i].first == x && snake[i].second == y )
        {
            return true;
        }
    }
    return false;
}

bool Snake::Update( vector<Direction>* dirList, const double elapsedTime )
{
    updateTimer -= elapsedTime;

    if ( updateTimer <= 0.0 )
    {
        Direction newDir = dir;

        if ( dirList->size() > 0 )
        {
            //cout << dirList.size() << endl;
            newDir = *(dirList->begin());
            dirList->erase( dirList->begin() );
        }

        //change player direction
        if ( !( ( dir == Snake::UP && newDir == Snake::DOWN ) ||
                ( dir == Snake::DOWN && newDir == Snake::UP ) ||
                ( dir == Snake::LEFT && newDir == Snake::RIGHT ) ||
                ( dir == Snake::RIGHT && newDir == Snake::LEFT ) ) )
        {
            dir = newDir;
        }

        updateTimer = updateInterval;

        if ( dir == Snake::UP )
        {
            headY--;
        }
        else if ( dir == Snake::DOWN )
        {
            headY++;
        }
        else if ( dir == Snake::LEFT )
        {
            headX--;
        }
        else if ( dir == Snake::RIGHT )
        {
            headX++;
        }

        if ( headX < 0 || headX > 7 || headY < 0 || headY > 12 )
        {
            return false;
        }

        if ( dir != Snake::NONE )
        {
            //move snake forward
            snake.push_back( make_pair( headX, headY ) );

            //check for food
            if ( field[headX][headY] == 1 )
            {
                field[headX][headY] = 0;

                int newFoodX = headX;
                int newFoodY = headY;

                while ( PointInSnake( newFoodX, newFoodY ) )
                {
                    newFoodX = Random::Rand( 0, 7 );
                    newFoodY = Random::Rand( 0, 12 );
                }

                field[newFoodX][newFoodY] = 1;

            }
            else
            {
                snake.erase( snake.begin() );
            }

            //check lose conditions
            if ( snake.size() > 103 )
            {
                return false;
            }

            if ( snake.size() != 0 )
            {
                for ( int i = 0; i < snake.size() - 1; i++ )
                {
                    if ( snake[i].first == headX && snake[i].second == headY )
                    {
                        return false;
                    }
                }
            }
        }

    }

    return true;
}

void Snake::Draw( sf::RenderWindow* app )
{
    for ( int i = 0; i < 8; i++ )
    {
        for ( int j = 0; j < 13; j++ )
        {
            if ( field[i][j] == 1 )
            {
                foodSprite.SetPosition( i * 40.0f + 480, j * 40.0f + 64 );
                app->Draw( foodSprite );
            }
        }
    }

    for ( int coordIndex = 0; coordIndex < snake.size(); coordIndex++ )
    {
        segmentSprite.SetPosition( snake[coordIndex].first * 40.0f + 480, snake[coordIndex].second * 40.0f + 64 );
        app->Draw( segmentSprite );
    }
}
