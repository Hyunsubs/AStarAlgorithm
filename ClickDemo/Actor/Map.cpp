#include "Map.h"
#include "Engine/Engine.h"

Map::Map(const std::string& path)
{
	FILE* pFile = nullptr;
	fopen_s(&pFile, path.c_str(), "rt");
	if (pFile)
	{
		char buffer[4096] = {};
		// TODO : 맵 데이터 읽기
		fread(buffer, 4096, 1, pFile);

		while (buffer[width] != '\n')
		{
			width++;
		}
		width++;

		height = strlen(buffer) / width;

		grid.resize(height);

		for (int i = 0; i < sizeof(buffer); i++)
		{
			mapData.emplace_back(buffer[i]);
		}

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (j == width - 1)
					continue;
				grid[i].emplace_back(buffer[width * i + j] - '0');
			}
		}


		fclose(pFile);
	}
	else
	{
		__debugbreak();
	}
}

Map::~Map()
{
}

void Map::Update(float deltaTime)
{


}

void Map::Draw()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			Engine::Get().Draw(Vector2(j, i), mapData[i * width + j], Color::White);
		}
	}
}
