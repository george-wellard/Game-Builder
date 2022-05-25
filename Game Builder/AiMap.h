#pragma once
#include "SFML/Graphics.hpp"
#include "Node.h"
#include "GameBuilder.h"
#include <list>
#include <vector>
#include <iostream>

class AiMap
{
public:

	AiMap(GameDataRef data);

	void Draw();

	static const short unsigned rows = 33;
	static const short unsigned columns = 41;

	Node* mapArray[rows][columns];

private:

	GameDataRef _data;
};

