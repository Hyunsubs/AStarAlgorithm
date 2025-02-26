#include "DemoLevel.h"
#include "Actor/Player.h"
#include "Actor/Start.h"
#include "Actor/Map.h"
#include "Actor/Path.h"
#include "Algorithm/AStar.h"
#include "Engine/Engine.h"

DemoLevel::DemoLevel()
{
	mainMap = new Map("..\\Assets\\map.txt");
	start = new Start();
	player = new Player();
	pathFinder = new AStar();


	AddActor(mainMap);
	AddActor(start);
	AddActor(player);

}

DemoLevel::~DemoLevel()
{
	SafeDelete(pathFinder);

}

void DemoLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	if (positionChanged)
	{
		positionChanged = false;

		startNode = new Node();
		playerNode = new Node();

		if (!printPathList.empty())
		{
			for (Path* path : printPathList)
			{
				path->Destroy();
			}
			printPathList.clear();
		}

		startNode->SetPosition(start->Position());
		playerNode->SetPosition(player->Position());

		pathList = pathFinder->FindPath(startNode, playerNode, mainMap->Grid());

		int idx = 0;
		for (Node* node : pathList)
		{
			if (node == pathList[0] || node == pathList[pathList.size() - 1])
			{
				continue;
			}

			Path* newPath = new Path(node->Position().x, node->Position().y, idx);
			printPathList.emplace_back(newPath);
			AddActor(newPath);
			idx++;
		}
		pathList.clear();
		pathFinder->Clear();
		SafeDelete(playerNode);
	}

}

void DemoLevel::Draw()
{
	Super::Draw();
}

