#include "GoalPoint.h"

GoalPoint::GoalPoint(GameDataRef data) : _data(data)
{
	// Setting texture by gravving assoicated string 
	goal.setTexture(_data->assets.GetTexture("Goal Texture")); 

	// Setting position to edge of the screen for the user to drag into desired place
	goal.setPosition(0, 0);
}

void GoalPoint::DrawGoal()
{
	// Drawing sprite
	_data->window.draw(goal); 
}

void GoalPoint::DragGoal(float mouseX, float mouseY)
{
	// Setting new position for sprite based on mouse position
	goal.setPosition(mouseX, mouseY);
}

const sf::Sprite& GoalPoint::GetSprite() const
{
	return goal;
}
