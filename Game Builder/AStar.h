#pragma once
#include "SFML/Graphics.hpp"
#include "Node.h"
#include "AiMap.h"
#include "Neighbour.h"
#include <list>
#include <vector>
#include <algorithm>

class AStar
{
public:

	AStar(AiMap* map);

	bool possiblePath(Node start, Node goal);

	std::list<Node>getPath();

private:

	std::vector<Node*> getNeighbourNodes(Node* node);

	void createPath(std::list<Node>& closed, Node* node);

	std::list<Node> path;

	AiMap* mapPoint;

	int rows;

	int columns;

};