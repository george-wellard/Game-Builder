#include "InputManager.h"

bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
{
	// Checking if mouse button is pressed 
	if (sf::Mouse::isButtonPressed(button))
	{
		// Setting template for sprite object
		sf::IntRect tempRect(object.getPosition().x, object.getPosition().y,
			object.getGlobalBounds().width, object.getGlobalBounds().height);

		// Checking if sprite object is within the current position of the mouse 
		if (tempRect.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}

	}

	return false;

}

// For when mouse is in position without clicking 
bool InputManager::MouseHoverOver(sf::Sprite object, sf::RenderWindow& window)
{
	// creating a template for sprite
	sf::IntRect tempRect(object.getPosition().x, object.getPosition().y,
		object.getGlobalBounds().width, object.getGlobalBounds().height);

	// Checking if template is within mouse position 
	if (tempRect.contains(sf::Mouse::getPosition(window)))
	{
		return true;
	}

	return false;
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)
{
	return sf::Mouse::getPosition(window);
}