#include "Player.h"
#include "Engine/Engine.h"
#include "Level/DemoLevel.h"

Player::Player()
	: DrawableActor("e")
{
	color = Color::Green;
	position = Vector2(5, 5);
}

void Player::Update(float deltaTime)
{
	DrawableActor::Update(deltaTime);

	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}

	if (Engine::Get().GetKeyDown(VK_RBUTTON))
	{
		position = Engine::Get().MousePosition();
		DemoLevel* demo = dynamic_cast<DemoLevel*>(Engine::Get().GetLevel());
		if (demo)
		{
			demo->SetChanged();
		}
	}
}