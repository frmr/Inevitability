#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>

#include "Random.h"
#include "Snake.h"
#include "TimeManager.h"
#include "Scene.h"

using std::cout;
using std::endl;
using std::vector;

int main()
{
    Random::Init();
    TimeManager timeMngr;

    sf::RenderWindow app(sf::VideoMode(1280, 720, 32), "Inevitability");

    bool running = true;
    //Snake::Direction dir = Snake::NONE;
    Snake snakeGame;
    Scene scene;

    sf::Image textImage0;
    sf::Image textImage1;
    sf::Image textImage2;
    sf::Image textImage3;
    sf::Image textImage4;
    sf::Image textImageNone;

    textImage0.LoadFromFile( "media/text0.png" );
    textImage1.LoadFromFile( "media/text1.png" );
    textImage2.LoadFromFile( "media/text2.png" );
    textImage3.LoadFromFile( "media/text3.png" );
    textImage4.LoadFromFile( "media/text4.png" );
    textImageNone.LoadFromFile( "media/textnone.png" );

    textImage0.SetSmooth( false );
    textImage1.SetSmooth( false );
    textImage2.SetSmooth( false );
    textImage3.SetSmooth( false );
    textImage4.SetSmooth( false );
    textImageNone.SetSmooth( false );

    sf::Sprite textSprite;
    sf::Sprite textNoneSprite;
    textSprite.SetImage( textImage0 );
    textNoneSprite.SetImage( textImageNone );

    sf::Image endImage;
    endImage.LoadFromFile( "media/end.png" );
    endImage.SetSmooth( false );
    sf::Sprite endSprite;
    endSprite.SetImage( endImage );

    sf::Image creditImage;
    creditImage.LoadFromFile( "media/credit.png" );
    creditImage.SetSmooth( false );
    sf::Sprite creditSprite;
    creditSprite.SetImage( creditImage );

    sf::Music music;
    music.OpenFromFile( "media/plaint.ogg" );
    music.GetStatus();
    music.SetVolume( 100 );
    music.SetLoop( true );
    music.Play();

    int stage = 0; //0 = text, 1 = snake, 2 = fade to black, 3 = fading back in, 4 = new scene (dead dog, boy animation), 5 = fade to white, 6 = white with text

    int textStage = 0;
    int black = 0;
    float volume = 100.0;
    const double fadeInterval = 10.0;
    double fadeTimer = fadeInterval;
    double endTimer = 6000.0;

    int textFade = 0;
    double textFadeInterval = 10.0;
    double textFadeTimer = textFadeInterval;

    bool fadingIn = true;
    bool fadingOut = false;

    vector<Snake::Direction> dirList;

    while ( running )
    {
        bool upPressed = false;
        bool downPressed = false;
        bool leftPressed = false;
        bool rightPressed = false;

        sf::Event event;
        while ( app.GetEvent( event ) )
        {
            // Window closed
            if ( event.Type == sf::Event::Closed )
            {
                running = false;
            }

            // Escape key pressed
            if ( event.Type == sf::Event::KeyPressed )
            {
                if ( event.Key.Code == sf::Key::Escape )
                {
                    running = false;
                }
                else if ( event.Key.Code == sf::Key::Up )
                {
                    upPressed = true;
                }
                else if ( event.Key.Code == sf::Key::Down )
                {
                    downPressed = true;
                }
                else if ( event.Key.Code == sf::Key::Left )
                {
                    leftPressed = true;
                }
                else if ( event.Key.Code == sf::Key::Right )
                {
                    rightPressed = true;
                }
            }
        }

        if ( stage == 0 )
        {
            timeMngr.StartTimer();

            if ( textStage == 5 )
            {
                //stage++;
                fadingOut = false;
                fadingIn = false;
                //textFade = 255;
                sf::Color newColor( 255, 255, 255, textFade );
                textNoneSprite.SetColor( newColor );

                textFadeTimer -= timeMngr.GetElapsedTime();
                if ( textFadeTimer <= 0.0 )
                {
                    textFade--;
                    textFadeTimer = textFadeInterval;
                }
                if ( textFade <= 0 )
                {
                    stage++;
                }
            }
            else
            {
                if ( fadingIn )
                {
                    textFadeTimer -= timeMngr.GetElapsedTime();

                    if ( textFadeTimer <= 0.0 )
                    {
                        textFade++;
                        if ( textFade >= 255 )
                        {
                            fadingIn = false;
                            fadingOut = true;
                        }
                        textFadeTimer = textFadeInterval;
                    }
                }

                if ( fadingOut )
                {
                    textFadeTimer -= timeMngr.GetElapsedTime();

                    if ( textFadeTimer <= 0.0 )
                    {
                        textFade--;
                        if ( textFade <= 0 )
                        {
                            fadingOut = false;
                            fadingIn = true;
                            textStage++;
                            if ( textStage == 5 )
                            {
                                textFade = 255;
                            }
                        }
                        textFadeTimer = textFadeInterval;
                    }
                }


                if ( textStage == 1 )
                {
                    textSprite.SetImage( textImage1 );
                }
                else if ( textStage == 2 )
                {
                    textSprite.SetImage( textImage2 );
                }
                else if ( textStage == 3 )
                {
                    textSprite.SetImage( textImage3 );
                }
                else if ( textStage == 4 )
                {
                    textSprite.SetImage( textImage4 );
                }
            }

            scene.Update( timeMngr.GetElapsedTime() );
            app.Clear();
            scene.DrawWall( &app );
            scene.DrawEverythingElse( &app );
            app.Draw( textNoneSprite );

            sf::Color newColor( 255, 255, 255, textFade );
            textSprite.SetColor( newColor );

            if ( textStage != 5 )
            {
                app.Draw( textSprite );
            }

            app.Display();

            timeMngr.StopTimer();
            timeMngr.Update();
        }
        else if ( stage == 1 )
        {
            timeMngr.StartTimer();

            if ( upPressed )
            {
                dirList.push_back( Snake::UP );
            }
            else if ( downPressed )
            {
                dirList.push_back( Snake::DOWN );
            }
            else if ( leftPressed )
            {
                dirList.push_back( Snake::LEFT );
            }
            else if ( rightPressed )
            {
                dirList.push_back( Snake::RIGHT );
            }

            Snake::Direction latestDir = Snake::NONE;

            if ( !snakeGame.Update( &dirList, timeMngr.GetElapsedTime() ) )
            {
                stage++;
            }

            scene.Update( timeMngr.GetElapsedTime() );

            app.Clear();

            scene.DrawWall( &app );
            snakeGame.Draw( &app );
            scene.DrawEverythingElse( &app );

            app.Display();

            timeMngr.StopTimer();
            timeMngr.Update();
        }
        else if ( stage == 2 )
        {
            timeMngr.StartTimer();

            scene.Update( timeMngr.GetElapsedTime() );
            app.Clear();
            scene.DrawWall( &app );
            snakeGame.Draw( &app );
            scene.DrawEverythingElse( &app );

            int newBlack = ( black > 255 ) ? 255 : black;

            sf::Color color( 0, 0, 0, newBlack );
            sf::Shape blackOverlay = sf::Shape::Rectangle( 0, 0, 1280, 720, color );
            app.Draw( blackOverlay );
            app.Display();

            timeMngr.StopTimer();
            timeMngr.Update();

            fadeTimer -= timeMngr.GetElapsedTime();
            if ( fadeTimer <= 0.0 )
            {
                black += 1;
                volume -= 0.5f;
                volume = ( volume < 0.0f ) ? 0.0f : volume;
                music.SetVolume( volume );
                fadeTimer = fadeInterval;
            }


            if ( black >= 350 )
            {
                scene.SetDead();
                music.Stop();
                stage++;
            }
        }
        else if ( stage == 3 )
        {
            timeMngr.StartTimer();

            scene.Update( timeMngr.GetElapsedTime() );
            app.Clear();
            scene.DrawWall( &app );
            scene.DrawEverythingElse( &app );

            int newBlack = ( black > 255 ) ? 255 : black;

            sf::Color color( 0, 0, 0, newBlack );
            sf::Shape blackOverlay = sf::Shape::Rectangle( 0, 0, 1280, 720, color );
            app.Draw( blackOverlay );
            app.Display();

            timeMngr.StopTimer();
            timeMngr.Update();

            fadeTimer -= timeMngr.GetElapsedTime();

            if ( fadeTimer <= 0.0 )
            {
                black -= 1;
                fadeTimer = fadeInterval;
            }

            if ( black <= 0 )
            {
                stage++;
            }
        }
        else if ( stage == 4 )
        {
            timeMngr.StartTimer();
            scene.Update( timeMngr.GetElapsedTime() );

            if ( scene.finished )
            {
                stage++;
            }

            app.Clear();
            scene.DrawWall( &app );
            scene.DrawEverythingElse( &app );

            app.Display();

            timeMngr.StopTimer();
        }
        else if ( stage == 5 )
        {
            timeMngr.StartTimer();

            app.Clear();
            scene.DrawWall( &app );
            scene.DrawEverythingElse( &app );

            int newBlack = ( black > 255 ) ? 255 : black;

            sf::Color color( 255, 255, 255, newBlack );
            sf::Shape blackOverlay = sf::Shape::Rectangle( 0, 0, 1280, 720, color );
            app.Draw( blackOverlay );
            app.Display();

            timeMngr.StopTimer();
            timeMngr.Update();

            fadeTimer -= timeMngr.GetElapsedTime();

            if ( fadeTimer <= 0.0 )
            {
                black += 1;
                fadeTimer = fadeInterval;
            }

            if ( black >= 400 )
            {
                stage++;
            }
        }
        else if ( stage == 6 )
        {
            timeMngr.StartTimer();
            app.Clear();
            app.Draw( endSprite );
            app.Display();

            timeMngr.StopTimer();
            timeMngr.Update();

            endTimer -= timeMngr.GetElapsedTime();
            if ( endTimer <= 0.0 )
            {
                stage++;
            }
        }
        else if ( stage == 7 )
        {
            app.Clear();
            app.Draw( creditSprite );
            app.Display();
        }
    }

    app.Close();

    return EXIT_SUCCESS;
}
