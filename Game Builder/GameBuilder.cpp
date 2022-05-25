#include "GameBuilder.h"
#include "SplashState.h"

GameBuilder::GameBuilder(int width, int height, std::string title)
{
	srand(time(NULL));

	// Creating window and title 
	_data->window.create(sf::VideoMode(width, height), title,
		sf::Style::Close | sf::Style::Titlebar);
	// Loading first state for when app starts 
	_data->machine.AddState(StateRef(new SplashState(this->_data)));

	this->Run();
}

void GameBuilder::Run()
{
	// Timers 
	float newTime, frameTime, interpolation;

	// tracking the current time 
	float currentTime = this->clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (this->_data->window.isOpen())
	{
		// Changing state 
		this->_data->machine.ProcessStateChange();

		newTime = this->clock.getElapsedTime().asSeconds();

		frameTime = newTime - currentTime;

		// Setting time for each frame
		if (frameTime > 0.25f)
		{
			frameTime = 0.25f;
		}

		currentTime = newTime;
		accumulator += frameTime;

		// Checking for whether accumlated time has surpassed delta (fps)
		while (accumulator >= dt)
		{
			// Updating inputs and state updaes for each frame
			this->_data->machine.GetActiveState()->HandleInput();
			this->_data->machine.GetActiveState()->Update(dt);

			accumulator -= dt;
		}

		// Updating current state's draw 
		interpolation = accumulator / dt;
		this->_data->machine.GetActiveState()->Draw(interpolation);
	}
}
