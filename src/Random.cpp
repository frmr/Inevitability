#include "Random.h"

#include <cstdlib> //sran()
#include <time>	//time()

void Random::Init()
{
	srand ( (unsigned int) time(NULL) );
}

int Random::Rand( int lowerBound, int upperBound )
{
    if ( upperBound - lowerBound == 0 )
    {
        return 0;
    }
    else
    {
        return rand() % ( upperBound - lowerBound + 1 ) + lowerBound;
    }
}

float Random::Rand(float lowerBound, float upperBound)
{
	if ( upperBound - lowerBound == 0.0f )
    {
        return 0.0f;
    }
    else
    {
        return lowerBound + (float) rand() / ( (float) RAND_MAX / ( upperBound - lowerBound ) );
    }
}
