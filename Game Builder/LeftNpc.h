#pragma once
#include "SFML/Graphics.hpp"
#include "GameBuilder.h"

class LeftNpc
{
public:

	// constructor
	LeftNpc(GameDataRef data);

	// Moving 
	void Move(sf::Event event);

	// Replacing texture
	void SwapTexture(std::string texture);

	// Draging sprite with mouse position
	void DragNpc(float mouseX, float mouseY);

	// Drawing
	void DrawNpc();

	// Returng sprute
	const sf::Sprite& GetSprite() const;

private:

	// Access to game data
	GameDataRef _data;

	// Setting as sprite
	sf::Sprite npc;
};
