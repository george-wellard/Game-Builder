#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "State.h"
#include "GameBuilder.h"
#include "Player.h"
#include "Npc.h"
#include "Wall.h"
#include "Collision.h"
#include "GoalPoint.h"
#include "WallBank.h"
#include "EnemyBlock.h"
#include "Bullet.h"
#include "AiMap.h"
#include "RightNPC.h"
#include "LeftNpc.h"

class GameState : public State
{
public:

	GameState(GameDataRef data);

	// Iniating state
	void Init();

	// Managing input
	void HandleInput();

	//Updating state
	void Update(float dt);

	// Drawing assets
	void Draw(float dt);

private:

	GameDataRef _data;

	// Button sprites
	sf::Sprite _menu;
	sf::Sprite _playerSpriteButton;
	sf::Sprite _npcButton;
	sf::Sprite _wallButton;
	sf::Sprite _goalButton;
	sf::Sprite _playButton; 
	sf::Sprite _buildButton;
	sf::Sprite _playerMoveType1Button; 
	sf::Sprite _playerMoveType2Button;
	sf::Sprite _gravityButton;
	sf::Sprite _enemyBlockButton;
	sf::Sprite _enemyMoveType1;
	sf::Sprite _enemyMoveType2;
	sf::Sprite _playerBulletsButton;
	sf::Sprite _npcBulletsButton;
	sf::Sprite _RightNpcButton;
	sf::Sprite _LeftNpcButton; 

	// Texture buttons
	sf::Sprite _FrogTexButton;
	sf::Sprite _TruckTexButton;
	sf::Sprite _ShipTexButton;
	sf::Sprite _InvaderTexButton;

	// Background buttons
	sf::Sprite _FrogBackgroundButton;
	sf::Sprite _SpaceBackgroundButton;

	sf::Sprite _background;

	// Text
	sf::Text infoText;
	sf::Text buttonInfo;

	// Sprites
	Player* player; 
	Npc* npc;
	RightNpc* rightNpc; 
	LeftNpc* leftNpc; 
	Wall* wall;
	std::vector<LeftNpc> lNpcVec;
	std::vector<RightNpc> rNpcVec;
	std::vector<Bullet> bulletVec;
	std::vector<Bullet> enemyBulletVec;
	std::vector<Wall> wallVec;
	std::vector<EnemyBlock> eBlockVec;
	GoalPoint* goalPoint;
	Collision collision; 

	sf::Clock _clock;
	sf::Event event;

	int gameState; 

	//States for button/events
	bool playerCreated = false;
	bool npcCreated = false;
	bool wallCreated = false;
	bool goalCreated = false;
	bool eBlockCreated = false;
	bool moveType1 = false;
	bool moveType2 = false;
	bool rightNpcCreated = false;
	bool leftNpcCreated = false; 
	bool gravityOn = false;
	bool bulletsEnabled = false;
	bool enemyBulletsEnabled = false;
	bool isFiring = false;

	bool mouseClicked = false;
	bool mouseInsideRect = false;
	bool playerDragging = false;
	bool npcDragging = false;
	bool wallDragging = false; 
	bool goalDragging = false;
	bool eBlockDragging = false; 
	bool rNpcDragging = false;
	bool lNpcDragging = false; 

	//Variables
	int mouseX = 0;
	int mouseY = 0;

	sf::Vector2f mouseRectOffset;

};