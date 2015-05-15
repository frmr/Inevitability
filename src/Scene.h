#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Scene
{
private:
    bool dead;

    sf::Image   wallImage;
    sf::Sprite  wallSprite;

    sf::Image   frameImage;
    sf::Sprite  frameSprite;



    sf::Image   dogImage0;
    sf::Image   dogImage1;
    sf::Image   dogImage2;
    sf::Image   dogImage3;
    sf::Image   dogImage4;
    sf::Image   dogImage5;
    sf::Image   dogImage6;

    double      dogFrame0;
    double      dogFrame1;

    double      dogTimer;
    int         dogFrameNum;
    sf::Sprite  dogSprite;



    sf::Image   deadImage;



    sf::Image   lampImage0;
    sf::Image   lampImage1;
    sf::Image   lampImage2;
    sf::Image   lampImage3;
    sf::Image   lampImage4;
    sf::Image   lampImage5;
    sf::Image   lampImage6;

    double      lampFrame0;

    double      lampTimer;
    int         lampFrameNum;
    sf::Sprite  lampSprite;



    sf::Image   boyImage0; //awake
    sf::Image   boyImage1; //sagging
    sf::Image   boyImage2; //sagging a bit more
    sf::Image   boyImage3; //sagging even more
    sf::Image   boyImage4; //asleep
    sf::Image   boyImage5; //looking at dog
    sf::Image   boyImage6; //tear1
    sf::Image   boyImage7; //tear2
    sf::Image   boyImage8; //tear3
    sf::Image   boyImage9; //tear4
    sf::Image   boyImage10;//tear5

    double      boyFrame0;
    double      boyFrame1;
    double      boyFrame2;
    double      boyFrame3;
    double      boyFrame4;
    double      boyFrame5;


    double      boy2Frame0;
    double      boy2Frame1;
    double      boy2Frame2;
    double      boy2Frame3;
    double      boy2Frame4;
    double      boy2Frame5;
    double      boy2Frame6;
    double      boy2Frame7;
    double      boy2Frame8;


    double      boyTimer;
    int         boyFrameNum;
    sf::Sprite  boySprite;




    sf::Image   overlayImage;
    sf::Sprite  overlaySprite;

public:
    bool finished;

    Scene();
    void Update( const double elapsed );
    void DrawWall( sf::RenderWindow* window ) const;
    void DrawEverythingElse( sf::RenderWindow* window ) const;
    void SetDead();
};
