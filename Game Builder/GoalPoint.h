#pragma once
#include "SFML/Graphics.hpp"
#include "GameBuilder.h"

class GoalPoint
{
public:

	// constructor
	GoalPoint(GameDataRef data);

	// Drawing
	void DrawGoal();

	// Dragging with mouse
	void DragGoal(float mouseX, float mouseY);

	// Returning sprite
	const sf::Sprite& GetSprite() const;

private:

	GameDataRef _data;

	sf::Sprite goal;
};

