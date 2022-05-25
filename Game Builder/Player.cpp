#include "Player.h"

Player::Player(GameDataRef data) : _data(data)
{
	// setting player texture by grabbing assoiciated string
	player.setTexture(_data->assets.GetTexture("First Player Texture"));

	// Setting position to edge of screen for further position by the user 
	player.setPosition(0, 0);

	// Setting the origin of the player sprite to the center 
	player.setOrigin(player.getGlobalBounds().width / 2, player.getGlobalBounds().height / 2);

}

void Player::DrawPlayer()
{
	// Drawing sprite
	_data->window.draw(player);
}

void Player::DragPlayer(float mouseX, float mouseY)
{
	// Dragging sprite to new position according to mouse position
	player.setPosition(mouseX, mouseY);
}

// Moving in all directions
void Player::PlayerMoveType1(sf::Event event)
{
	// Moving sprite right if right arrow pressed
	if (sf::Keyboard::Key::Right == event.key.code)
	{
		player.move(30, 0);
	}

	// Moving sprite left is left arrow pressed
	if (sf::Keyboard::Key::Left == event.key.code)
	{
		player.move(-30, 0); 
	}

	// Moving sprite up if up arrow pressed
	if (sf::Keyboard::Key::Up == event.key.code)
	{
		player.move(0, -30);
	}

	// Moving sprite down if down arrow pressed
	if (sf::Keyboard::Key::Down == event.key.code)
	{
		player.move(0, 30);
	}
}

// Moving only side to side
void Player::PlayerMoveType2(sf::Event event)
{
	// Moving sprite right if right arrow pressed
	if (sf::Keyboard::Key::Right == event.key.code)
	{
		player.move(30, 0);
	}

	// Moving sprite left is left arrow pressed
	if (sf::Keyboard::Key::Left == event.key.code)
	{
		player.move(-30, 0);
	}
}

void Player::PlayerStop(sf::Event event)
{
	// Moving player by opposite speed of movement in order to stop them moving in a certain direction 
	if (sf::Keyboard::Key::Right == event.key.code)
	{
		player.move(-30, 0);
	}

	if (sf::Keyboard::Key::Left == event.key.code)
	{
		player.move(30, 0);
	}

	if (sf::Keyboard::Key::Up == event.key.code)
	{
		player.move(0, 30);
	}

	if (sf::Keyboard::Key::Down == event.key.code)
	{
		player.move(0, -30);
	}
}

void Player::SwapTexture(std::string texture)
{
	// Swapping with new texture by grabbing assoiciated string 
	player.setTexture(_data->assets.GetTexture(texture));
}


void Player::PlayerDeath(sf::Event event)
{
	// Moving the player out from the window if they are killed
	player.setPosition(1500, 0);
}

const sf::Sprite& Player::GetSprite() const
{
	return player; 
}
