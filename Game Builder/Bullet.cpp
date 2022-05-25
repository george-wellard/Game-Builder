#include "Bullet.h"

Bullet::Bullet(GameDataRef data) : _data(data)
{
	// Grabbing texture
	bullet.setTexture(_data->assets.GetTexture("Bullets Texture"));
}

void Bullet::setPos(float x, float y)
{
	// Setting position according float positions set in the game state
	bullet.setPosition(x, y);
}

void Bullet::Fire(int speed)
{
	// Moving the bullet by a set speed in the y position 
	bullet.move(0, -speed);
}

void Bullet::Draw()
{
	// Drawing bullet
	_data->window.draw(bullet);
}

const sf::Sprite& Bullet::getSprite() const
{
	// Returning bullet 
	return bullet;
}