#pragma once

#include "Actor/DrawableActor.h"
#include <string>
#include <vector>
#include "Algorithm/Node.h"

class Map : public DrawableActor
{
	RTTI_DECLARATIONS(Map, DrawableActor)
public:
	Map(const std::string& path);
	~Map();

	virtual void Update(float deltaTime) override;
	virtual void Draw() override;

	inline std::vector<char> MapData() { return mapData; }
	std::vector<std::vector<int>> Grid() { return grid; }

private:
	std::vector<char> mapData;
	std::vector<std::vector<int>> grid;

	int width = 0;
	int height = 0;
};

