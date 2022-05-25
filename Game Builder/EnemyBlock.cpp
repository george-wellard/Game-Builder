#include "EnemyBlock.h"

EnemyBlock::EnemyBlock(GameDataRef data) : _data(data)
{
	// Setting the texture by grabbing associated string
	enemyBlock.setTexture(_data->assets.GetTexture("Enemy Block Texture"));

	// Setting position to edge of the screen for the user to drag into desired place
	enemyBlock.setPosition(0, 0);

	// Setting origin of sprite to center instead of top left edge
	enemyBlock.setOrigin(enemyBlock.getGlobalBounds().width / 2, enemyBlock.getGlobalBounds().height / 2);
}

void EnemyBlock::Draw()
{
	// Drwaing enemy block 
	_data->window.draw(enemyBlock);
}

void EnemyBlock::DragBlock(float mouseX, float mouseY)
{
	// Setting new positon for block according to mouse position 
	enemyBlock.setPosition(mouseX, mouseY);
}

const sf::Sprite& EnemyBlock::GetSprite() const
{
	return enemyBlock;
}
