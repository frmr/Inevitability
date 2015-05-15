#include "Timer.h"

double Timer::ConvertLargeIntToMS( LARGE_INTEGER &in ) const
{
    return ((double) in.QuadPart / (double) frequency.QuadPart) * 1000.0 ;
}

void Timer::StartTimer()
{
    QueryPerformanceCounter( &timer.start );
}

void Timer::StopTimer()
{
    QueryPerformanceCounter( &timer.stop );

	LARGE_INTEGER time;
    time.QuadPart = timer.stop.QuadPart - timer.start.QuadPart;
    elapsed = ConvertLargeIntToMS( time );
}

double Timer::GetElapsedTime() const
{
    return elapsed;
}

Timer::Timer()
{
    timer.start.QuadPart = 0;
    timer.stop.QuadPart = 0;
    QueryPerformanceFrequency( &frequency );
}

Timer::~Timer()
{
}
