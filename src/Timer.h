//ORIGINALLY FROM http://cplus.about.com/od/howtodothingsi2/a/timing.htm, modified to comply with conventions

#ifndef TIMER_H
#define TIMER_H

#include "windows.h"

typedef struct
{
    LARGE_INTEGER start;
    LARGE_INTEGER stop;
} stopWatch;

class Timer
{
private:
	stopWatch		timer;
	LARGE_INTEGER	frequency;
	double			elapsed;

private:
	double	ConvertLargeIntToMS( LARGE_INTEGER &in ) const;

public:
	void	StartTimer();
	void	StopTimer();
	double	GetElapsedTime() const;

public:
	Timer();
	~Timer();
};

#endif // TIMER_H
