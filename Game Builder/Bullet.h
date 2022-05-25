#pragma once
#include "GameBuilder.h"
#include "Definitions.h"

class Bullet
{
public:

	// constructor
	Bullet(GameDataRef data);

	// Giving position
	void setPos(float x, float y);

	// Firing
	void Fire(int speed);

	// Drawing
	void Draw();

	// Returning sprite
	const sf::Sprite& getSprite() const;

private:

	// Game data
	GameDataRef _data;

	// Setting as sprite
	sf::Sprite bullet;
};