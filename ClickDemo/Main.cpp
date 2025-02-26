#include "Engine/Engine.h"
#include "Level/DemoLevel.h"


int main()
{
	CheckMemoryLeak();
	//_CrtSetBreakAlloc(459);
	Engine engine;
	engine.LoadLevel(new DemoLevel());
	engine.Run();
}