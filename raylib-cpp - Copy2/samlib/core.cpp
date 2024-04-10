#include "core.h"

Core::Core()
{

}
Core::~Core()
{

}

void Core::runScene(Scene* scene)
{
	deltaTime = GetFrameTime();
	scene->updateScene(deltaTime);
}

float Core::calculateDeltaTime()
{
	deltaTime = GetFrameTime();
	return deltaTime;
}