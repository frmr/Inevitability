#include "TimeManager.h"

void TimeManager::UpdateDeltaTime()
{
	deltaTime = (float) ( elapsedTime / timeBase );
}

void TimeManager::Update()
{
    elapsedTime = timer.GetElapsedTime();
	UpdateDeltaTime();
}

void TimeManager::StartTimer()
{
	timer.StartTimer();
}

void TimeManager::StopTimer()
{
	timer.StopTimer();
}

float TimeManager::GetDeltaTime() const
{
	return deltaTime;
}

double TimeManager::GetElapsedTime() const
{
	return elapsedTime;
}

TimeManager::TimeManager()
	: timeBase( 1.0 ),
	  deltaTime( 1.0f ),
	  elapsedTime( 1.0 )
{
}

TimeManager::~TimeManager()
{
}
