#include "Collision.h"

Collision::Collision()
{
}

bool Collision::CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2)
{
	// Creating rects as templates for sprites called into the parmeters 
	sf::Rect<float> rect1 = sprite1.getGlobalBounds();
	sf::Rect<float> rect2 = sprite2.getGlobalBounds();

	// Checking for an intersection between the two rects
	if (rect1.intersects(rect2))
	{
		return true;
	}
	else
	{
		return false;
	}
}