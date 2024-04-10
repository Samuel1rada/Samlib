/*
* Copyright 2024 Rowan Pijnaker
*/

#ifndef CORE_H
#define CORE_H


#include "scene.h"

#include "raylib.h"

class Core
{
public:
	Core();
	virtual ~Core();

	void runScene(Scene* scene);

private:
	float calculateDeltaTime();
	float deltaTime;

};

#endif /* CORE_H */