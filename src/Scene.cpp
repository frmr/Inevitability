#include "Scene.h"

#include <iostream>

using std::cout;
using std::endl;

Scene::Scene()
{
    dead = false;
    finished = false;

    wallImage.LoadFromFile( "media/wall.png" );
    wallImage.SetSmooth( false );
    wallSprite.SetImage( wallImage );

    frameImage.LoadFromFile( "media/frame.png" );
    frameImage.SetSmooth( false );
    frameSprite.SetImage( frameImage );


    dogImage0.LoadFromFile( "media/dog0.png" );
    dogImage1.LoadFromFile( "media/dog1.png" );
    dogImage2.LoadFromFile( "media/dog2.png" );
    dogImage3.LoadFromFile( "media/dog3.png" );
    dogImage4.LoadFromFile( "media/dog4.png" );
    dogImage5.LoadFromFile( "media/dog5.png" );
    dogImage6.LoadFromFile( "media/dog6.png" );

    dogImage0.SetSmooth( false );
    dogImage1.SetSmooth( false );
    dogImage2.SetSmooth( false );
    dogImage3.SetSmooth( false );
    dogImage4.SetSmooth( false );
    dogImage5.SetSmooth( false );
    dogImage6.SetSmooth( false );

    dogFrame0 = 2000.0;
    dogFrame1 = 400.0;

    dogTimer = dogFrame0;
    dogFrameNum = 0;
    dogSprite.SetImage( dogImage0 );



    deadImage.LoadFromFile( "media/dead.png" );
    deadImage.SetSmooth( false );



    lampImage0.LoadFromFile( "media/lamp0.png" );
    lampImage1.LoadFromFile( "media/lamp1.png" );
    lampImage2.LoadFromFile( "media/lamp2.png" );
    lampImage3.LoadFromFile( "media/lamp3.png" );
    lampImage4.LoadFromFile( "media/lamp4.png" );
    lampImage5.LoadFromFile( "media/lamp5.png" );
    lampImage6.LoadFromFile( "media/lamp6.png" );

    lampImage0.SetSmooth( false );
    lampImage1.SetSmooth( false );
    lampImage2.SetSmooth( false );
    lampImage3.SetSmooth( false );
    lampImage4.SetSmooth( false );
    lampImage5.SetSmooth( false );
    lampImage6.SetSmooth( false );

    lampFrame0 = 500.0;

    lampTimer = lampFrame0;
    lampFrameNum = 0;
    lampSprite.SetImage( lampImage0 );



    boyImage0.LoadFromFile( "media/boy0.png" );
    boyImage1.LoadFromFile( "media/boy1.png" );
    boyImage2.LoadFromFile( "media/boy2.png" );
    boyImage3.LoadFromFile( "media/boy3.png" );
    boyImage4.LoadFromFile( "media/boy4.png" );
    boyImage5.LoadFromFile( "media/boy5.png" );
    boyImage6.LoadFromFile( "media/boy6.png" );
    boyImage7.LoadFromFile( "media/boy7.png" );
    boyImage8.LoadFromFile( "media/boy8.png" );
    boyImage9.LoadFromFile( "media/boy9.png" );
    boyImage10.LoadFromFile( "media/boy10.png" );

    boyImage0.SetSmooth( false );
    boyImage1.SetSmooth( false );
    boyImage2.SetSmooth( false );
    boyImage3.SetSmooth( false );
    boyImage4.SetSmooth( false );
    boyImage5.SetSmooth( false );
    boyImage6.SetSmooth( false );
    boyImage7.SetSmooth( false );
    boyImage8.SetSmooth( false );
    boyImage9.SetSmooth( false );
    boyImage10.SetSmooth( false );

    boyFrame0 = 4000.0; //awake
    boyFrame1 = 500.0;  //sagging
    boyFrame2 = 500.0;  //sagging a bit more
    boyFrame3 = 1000.0; //sagging even more
    boyFrame4 = 50.0;  //sagging a bit more
    boyFrame5 = 50.0;  //sagging

    boy2Frame0 = 5000.0; //asleep
    boy2Frame1 = 700.0; //sagging even more
    boy2Frame2 = 700.0; //sagging a bit more
    boy2Frame3 = 700.0; //sagging
    boy2Frame4 = 2000.0; //awake
    boy2Frame5 = 3000.0; //looking at dog
    boy2Frame6 = 500.0; //tear

    boyTimer = boyFrame0;
    boyFrameNum = 0;
    boySprite.SetImage( boyImage0 );



    overlayImage.LoadFromFile( "media/overlay.png" );
    overlayImage.SetSmooth( false );
    overlaySprite.SetImage( overlayImage );
}

void Scene::Update( const double elapsed )
{
    if ( !dead )
    {
        dogTimer -= elapsed;

        if ( dogTimer <= 0 )
        {
            if ( dogFrameNum == 0 )
            {
                dogTimer = dogFrame1;
                dogFrameNum = 1;
                dogSprite.SetImage( dogImage1 );
            }
            else if ( dogFrameNum == 1 )
            {
                dogTimer = dogFrame1;
                dogFrameNum = 2;
                dogSprite.SetImage( dogImage2 );
            }
            else if ( dogFrameNum == 2 )
            {
                dogTimer = dogFrame1;
                dogFrameNum = 3;
                dogSprite.SetImage( dogImage3 );
            }
            else if ( dogFrameNum == 3 )
            {
                dogTimer = dogFrame1;
                dogFrameNum = 4;
                dogSprite.SetImage( dogImage4 );
            }
            else if ( dogFrameNum == 4 )
            {
                dogTimer = dogFrame1;
                dogFrameNum = 5;
                dogSprite.SetImage( dogImage5 );
            }
            else if ( dogFrameNum == 5 )
            {
                dogTimer = dogFrame0;
                dogFrameNum = 6;
                dogSprite.SetImage( dogImage6 );
            }
            else if ( dogFrameNum == 6 )
            {
                dogTimer = dogFrame1;
                dogFrameNum = 7;
                dogSprite.SetImage( dogImage5 );
            }
            else if ( dogFrameNum == 7 )
            {
                dogTimer = dogFrame1;
                dogFrameNum = 8;
                dogSprite.SetImage( dogImage4 );
            }
            else if ( dogFrameNum == 8 )
            {
                dogTimer = dogFrame1;
                dogFrameNum = 9;
                dogSprite.SetImage( dogImage3 );
            }
            else if ( dogFrameNum == 9 )
            {
                dogTimer = dogFrame1;
                dogFrameNum = 10;
                dogSprite.SetImage( dogImage2 );
            }
            else if ( dogFrameNum == 10 )
            {
                dogTimer = dogFrame1;
                dogFrameNum = 11;
                dogSprite.SetImage( dogImage1 );
            }
            else if ( dogFrameNum == 11 )
            {
                dogTimer = dogFrame0;
                dogFrameNum = 0;
                dogSprite.SetImage( dogImage0 );
            }
        }
    }


    lampTimer -= elapsed;

    if ( lampTimer <= 0 )
    {
        lampTimer = lampFrame0;

        if ( lampFrameNum == 0 )
        {
            lampFrameNum = 1;
            lampSprite.SetImage( lampImage1 );
        }
        else if ( lampFrameNum == 1 )
        {
            lampFrameNum = 2;
            lampSprite.SetImage( lampImage2 );
        }
        else if ( lampFrameNum == 2 )
        {
            lampFrameNum = 3;
            lampSprite.SetImage( lampImage3 );
        }
        else if ( lampFrameNum == 3 )
        {
            lampFrameNum = 4;
            lampSprite.SetImage( lampImage4 );
        }
        else if ( lampFrameNum == 4 )
        {
            lampFrameNum = 5;
            lampSprite.SetImage( lampImage5 );
        }
        else if ( lampFrameNum == 5 )
        {
            lampFrameNum = 6;
            lampSprite.SetImage( lampImage6 );
        }
        else if ( lampFrameNum == 6 )
        {
            lampFrameNum = 7;
            lampSprite.SetImage( lampImage5 );
        }
        else if ( lampFrameNum == 7 )
        {
            lampFrameNum = 8;
            lampSprite.SetImage( lampImage4 );
        }
        else if ( lampFrameNum == 8 )
        {
            lampFrameNum = 9;
            lampSprite.SetImage( lampImage3 );
        }
        else if ( lampFrameNum == 9 )
        {
            lampFrameNum = 10;
            lampSprite.SetImage( lampImage2 );
        }
        else if ( lampFrameNum == 10 )
        {
            lampFrameNum = 11;
            lampSprite.SetImage( lampImage1 );
        }
        else if ( lampFrameNum == 11 )
        {
            lampFrameNum = 0;
            lampSprite.SetImage( lampImage0 );
        }
    }

    boyTimer -= elapsed;

    if ( boyTimer <= 0 )
    {
        if ( !dead )
        {
            if ( boyFrameNum == 0 )
            {
                boyTimer = boyFrame1;
                boyFrameNum = 1;
                boySprite.SetImage( boyImage1 );
            }
            else if ( boyFrameNum == 1)
            {
                boyTimer = boyFrame2;
                boyFrameNum = 2;
                boySprite.SetImage( boyImage2 );
            }
            else if ( boyFrameNum == 2 )
            {
                boyTimer = boyFrame3;
                boyFrameNum = 3;
                boySprite.SetImage( boyImage3 );
            }
            else if ( boyFrameNum == 3 )
            {
                boyTimer = boyFrame4;
                boyFrameNum = 4;
                boySprite.SetImage( boyImage2 );
            }
            else if ( boyFrameNum == 4 )
            {
                boyTimer = boyFrame5;
                boyFrameNum = 5;
                boySprite.SetImage( boyImage1 );
            }
            else if ( boyFrameNum == 5 )
            {
                boyTimer = boyFrame0;
                boyFrameNum = 0;
                boySprite.SetImage( boyImage0 );
            }
        }
        else //if dead
        {
            if ( boyFrameNum == 0 ) //asleep
            {
                boyTimer = boy2Frame1;
                boyFrameNum = 1;
                boySprite.SetImage( boyImage3 );
            }
            else if ( boyFrameNum == 1 ) //sagging even more
            {
                boyTimer = boy2Frame2;
                boyFrameNum = 2;
                boySprite.SetImage( boyImage2 );
            }
            else if ( boyFrameNum == 2 ) //sagging a bit more
            {
                boyTimer = boy2Frame3;
                boyFrameNum = 3;
                boySprite.SetImage( boyImage1 );
            }
            else if ( boyFrameNum == 3 ) //sagging
            {
                boyTimer = boy2Frame4;
                boyFrameNum = 4;
                boySprite.SetImage( boyImage0 );
            }
            else if ( boyFrameNum == 4 ) //awake
            {
                boyTimer = boy2Frame5;
                boyFrameNum = 5;
                boySprite.SetImage( boyImage1 );
            }
            else if ( boyFrameNum == 5 ) //looking
            {
                boyTimer = boy2Frame6;
                boyFrameNum = 6;
                boySprite.SetImage( boyImage6 );
            }
            else if ( boyFrameNum == 6 ) //tear1
            {
                boyTimer = boy2Frame6;
                boyFrameNum = 7;
                boySprite.SetImage( boyImage7 );
            }
            else if ( boyFrameNum == 7 ) //tear2
            {
                boyTimer = boy2Frame6;
                boyFrameNum = 8;
                boySprite.SetImage( boyImage8 );
            }
            else if ( boyFrameNum == 8 ) //tear3
            {
                boyTimer = boy2Frame6;
                boyFrameNum = 9;
                boySprite.SetImage( boyImage9 );
            }
            else if ( boyFrameNum == 9)
            {
                boyTimer = boy2Frame6;
                boyFrameNum = 10;
                boySprite.SetImage( boyImage10 );
                finished = true;
            }
            else if ( boyFrameNum == 10 );
            {

            }
        }
    }
}

void Scene::DrawWall( sf::RenderWindow* window ) const
{
    window->Draw( wallSprite );
}

void Scene::DrawEverythingElse( sf::RenderWindow* window ) const
{
    window->Draw( frameSprite );
    window->Draw( lampSprite );
    window->Draw( boySprite );
    window->Draw( dogSprite );
    window->Draw( overlaySprite );
}

void Scene::SetDead()
{
    dead = true;
    dogSprite.SetImage( deadImage );
    boySprite.SetImage( boyImage4 );
    boyFrameNum = 0;
    boyTimer = boy2Frame0;
}
