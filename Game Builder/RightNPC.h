#pragma once
#include "SFML/Graphics.hpp"
#include "GameBuilder.h"

class RightNpc
{
public:

	// Constructor
	RightNpc(GameDataRef data);

	// Moving
	void Move(sf::Event event);

	// Replacing texture
	void SwapTexture(std::string texture);

	// Dragging srpite with mouse
	void DragNpc(float mouseX, float mouseY);

	// Drawing
	void DrawNpc();

	// Returning sprute
	const sf::Sprite& GetSprite() const;

private:

	// Access to game data
	GameDataRef _data;

	// Setting as sprite
	sf::Sprite npc;
};

