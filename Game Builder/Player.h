#pragma once
#include "SFML/Graphics.hpp"
#include "Definitions.h"
#include "GameBuilder.h"

class Player
{
public:

	// constructor
	Player(GameDataRef data); 

	// Drawing
	void DrawPlayer();

	// Dragging with mouse
	void DragPlayer(float mouseX, float mouseY);

	// Moving in all directions
	void PlayerMoveType1(sf::Event event);

	// Moving side to side
	void PlayerMoveType2(sf::Event event); 

	// Stop moving
	void PlayerStop(sf::Event event);

	// Replacing texture
	void SwapTexture(std::string texture);

	// Removing player 
	void PlayerDeath(sf::Event event);

	// Returning sprute
	const sf::Sprite& GetSprite() const;

private:

	// Access to game data
	GameDataRef _data;

	// Setting as sprite
	sf::Sprite player;
	
};

