#pragma once
#include "GameBuilder.h"
#include "Definitions.h"

class EnemyBlock
{
public:

// constructor
	EnemyBlock(GameDataRef data);

	// Drawing
	void Draw(); 

	// Dragging with mouse
	void DragBlock(float mouseX, float mouseY);

	// Returning sprite
	const sf::Sprite& GetSprite() const;

private:

	// Access to game data
	GameDataRef _data;

	// Setting as sprite
	sf::Sprite enemyBlock;
};

