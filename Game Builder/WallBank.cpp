#include "WallBank.h"

WallBank::WallBank(GameDataRef data) : _data(data)
{
}

void WallBank::AddWall()
{
	Wall* wc = new Wall(_data);
	wallConstructor.push_back(wc);
}
