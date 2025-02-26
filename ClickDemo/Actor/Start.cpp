#include "Start.h"
#include "Engine/Engine.h"
#include "Level/DemoLevel.h"

Start::Start()
	: DrawableActor("s")
{
	color = Color::Red;
	pathFinder = new AStar();
}

Start::~Start()
{
	SafeDelete(pathFinder);
}

void Start::Update(float deltaTime)
{
	Super::Update(deltaTime);

	if (Engine::Get().GetKeyDown(VK_LBUTTON))
	{
		position = Engine::Get().MousePosition();
		DemoLevel* demo = dynamic_cast<DemoLevel*>(Engine::Get().GetLevel());
		if (demo)
		{
			demo->SetChanged();
		}
	}
}