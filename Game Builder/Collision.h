#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Wall.h"

class Collision
{
public:

	Collision();

	// Checking collision between two sprites
	bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2);

};

