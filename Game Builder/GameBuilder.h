#pragma once
#include<string>
#include<SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssestManager.h"
#include "InputManager.h"

// Game Data storage
struct GameData
{
	StateMachine machine;
	sf::RenderWindow window;
	AssetManager assets;
	InputManager input;
};

// Pointer for accessing data storage
typedef std::shared_ptr<GameData> GameDataRef;

class GameBuilder
{
public:

	// Constuctor
	GameBuilder(int width, int height, std::string title);

	// Running app
	void Run();

private:

	// SFML window
	sf::RenderWindow* window;

	// Setting delta to for 60 fps
	const float dt = 1.0f / 60.0f;

	// Clock for various timers 
	sf::Clock clock;

	GameDataRef _data = std::make_shared<GameData>();



};