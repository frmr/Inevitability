#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include "Timer.h"

class TimeManager
{
private:
	const double	timeBase;
	float 			deltaTime;
	double          elapsedTime;
	Timer           timer;

private:
	void 	UpdateDeltaTime();

public:
	void	Update();
	void	StartTimer();
	void	StopTimer();
	float	GetDeltaTime() const;
	double	GetElapsedTime() const;

public:
	TimeManager();
	~TimeManager();
};

#endif
