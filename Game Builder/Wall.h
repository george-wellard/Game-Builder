#pragma once
#include "SFML/Graphics.hpp"
#include "GameBuilder.h"
#include "Definitions.h"
#include <vector>

class Wall
{
public:

	// Constructor
	Wall(GameDataRef data); 

	// Drawing
	void DrawWall();

	// Dragging sprite with mouse
	void DragWall(float mouseX, float mouseY);

	// Returning sprite
	const sf::Sprite& GetSprite() const; 

private:

	// Access to game data
	GameDataRef _data; 

	// Settin as sprite
	sf::Sprite wall; 
};

