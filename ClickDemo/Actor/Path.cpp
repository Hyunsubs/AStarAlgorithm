#include "Path.h"
#include "Engine/Timer.h"

Path::Path(int x, int y, int idx)
	: DrawableActor("p")
{
	color = Color::Blue;
	position.x = x;
	position.y = y;
	this->accTime = accTime;
	renderStart = new Timer(0.05f * idx);
}

Path::~Path()
{
	SafeDelete(renderStart);
}

void Path::Update(float deltaTime)
{
	Super::Update(deltaTime);
	renderStart->Update(deltaTime);
}

void Path::Draw()
{
	if (renderStart->IsTimeOut())
	{
		Super::Draw();
	}
}


