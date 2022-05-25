#include "Wall.h"

Wall::Wall(GameDataRef data) : _data(data)
{
	// Setting texture by grabbing assoicated string
	wall.setTexture(_data->assets.GetTexture("First Wall Texture"));

	// Setting first position to corner of window for further user placement
	wall.setPosition(0, 0);

	// Setting origin for sprite to center 
	wall.setOrigin(wall.getGlobalBounds().width / 2, wall.getGlobalBounds().height / 2);
}

void Wall::DrawWall()
{
	// Drawing sprite
	_data->window.draw(wall);
}

void Wall::DragWall(float mouseX, float mouseY)
{
	// Setting new position according to mouse position 
	wall.setPosition(mouseX, mouseY);
}


const sf::Sprite& Wall::GetSprite() const
{
	return wall; 
}
