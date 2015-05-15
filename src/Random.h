#ifndef RANDOM_H
#define RANDOM_H

class Random
{
public:
	static void		Init();
	static int      Rand( int lowerBound, int upperBound );
	static float	Rand(float lowerBound, float upperBound);
};

#endif
