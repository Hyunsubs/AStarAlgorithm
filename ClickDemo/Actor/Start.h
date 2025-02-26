#pragma once

#include "Actor/DrawableActor.h"
#include "Algorithm/AStar.h"

class Start : public DrawableActor
{
public:
	Start();
	~Start();

	virtual void Update(float deltaTime) override;

private:
	AStar* pathFinder = nullptr;
};