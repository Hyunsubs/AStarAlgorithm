#pragma once

#include "Level/Level.h"
#include <vector>
#include "Algorithm/Node.h"

class Map;
class AStar;
class Start;
class Player;
class Path;

class DemoLevel : public Level
{
	// RTTI Á¤ÀÇ.
	RTTI_DECLARATIONS(DemoLevel, Level)

public:
	DemoLevel();
	~DemoLevel();

	virtual void Update(float deltaTime) override;
	virtual void Draw() override;

	inline void SetChanged() { positionChanged = true; }

private:
	Map* mainMap = nullptr;
	Start* start = nullptr;
	Player* player = nullptr;
	AStar* pathFinder = nullptr;
	bool positionChanged = false;
	Node* startNode = nullptr;
	Node* playerNode = nullptr;
	std::vector<Node*> pathList = {};
	std::vector<Path*> printPathList = {};
};