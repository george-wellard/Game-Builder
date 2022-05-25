#pragma once
#include "SFML/Graphics.hpp"

class InputManager
{
public:

	// constructor/deconstructr
	InputManager() { }
	~InputManager() { }


	// Checking for button being pressed on sprite
	bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);

	// Checking if mouse moving on sprite
	bool MouseHoverOver(sf::Sprite object, sf::RenderWindow& window);

	// Returning mouse postion 
	sf::Vector2i GetMousePosition(sf::RenderWindow& window);
};

