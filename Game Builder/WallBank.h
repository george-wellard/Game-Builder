#pragma once
#include<vector>
#include "Wall.h"
#include "GameBuilder.h"

class WallBank
{
public:

	WallBank(GameDataRef data);

	void AddWall();

	std::vector<Wall*> wallConstructor; 

private:

	GameDataRef _data;

};

