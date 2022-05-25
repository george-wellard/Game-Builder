#include "SplashState.h"
#include "Definitions.h"
#include "GameState.h"
#include<iostream>
#include<sstream>

SplashState::SplashState(GameDataRef data) : _data(data)
{

}

void SplashState::Init()
{
	// Loading state background texture
	_data->assets.LoadTexture("Splash State Background", SPLASH_SCREEN_BACKGROUND_FILEPATH);

	// Setting texture as background
	_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));

	// Postioning background to center of window
	_background.setPosition((SCREEN_WIDTH / 2) - (_background.getGlobalBounds().width / 2),
		((SCREEN_HEIGHT / 2) - (_background.getGlobalBounds().height / 2)));
}

void SplashState::HandleInput()
{
	sf::Event event;

	while (_data->window.pollEvent(event))
	{
		// Allowing window to be closed
		if (sf::Event::Closed == event.type)
		{
			_data->window.close();
		}
	}
}

void SplashState::Update(float dt)
{
	// Changing to game state when elasped time is over 
	if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	{
		_data->machine.AddState(StateRef(new GameState(_data)), true);
	}
}

void SplashState::Draw(float dt)
{
	_data->window.clear();

	// drawing background
	_data->window.draw(_background);

	_data->window.display();
}