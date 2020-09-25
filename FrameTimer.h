#pragma once
#include<chrono>

class FrameTimer
{
public:
	//constructor
	FrameTimer();

	//How much time has passed since the previous mark?
	float Mark();

private:
	std::chrono::steady_clock::time_point last;


};

