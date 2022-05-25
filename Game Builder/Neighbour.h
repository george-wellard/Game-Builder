#pragma once
#include "Node.h"

class Neighbour
{
public:


	Neighbour(int row, int column, bool diagonal);
	bool canMove();
	int getRow();
	int getColumns();
	bool isDiagonal();

private:

	int row;
	int columns;
	bool diagonal;
	bool exists;

	Node* moveable;
};

