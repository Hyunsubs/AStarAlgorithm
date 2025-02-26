#pragma once

#include "Actor/DrawableActor.h"

class Timer;
class Path : public DrawableActor
{
	RTTI_DECLARATIONS(Path, DrawableActor)

public:
	Path(int x, int y, int idx);
	~Path();

	virtual void Update(float deltaTime) override;
	virtual void Draw() override;

	
private:
	float accTime = 0.f;
	Timer* renderStart;
};

