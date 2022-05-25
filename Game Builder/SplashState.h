#pragma once
#include "State.h"
#include "GameBuilder.h"

class SplashState : public State
{
public:

	// Constructor
	SplashState(GameDataRef data);

	// Iniating state
	void Init();

	// Input for state
	void HandleInput();

	// Updating state
	void Update(float dt);

	// Drawing state assests
	void Draw(float dt);

private:

	// Access to game data
	GameDataRef _data;

	// Clock for timer
	sf::Clock _clock;

	// Background sprite
	sf::Sprite _background;
};

