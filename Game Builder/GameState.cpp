#include<iostream>
#include "GameState.h"
#include "Definitions.h"

GameState::GameState(GameDataRef data) : _data(data)
{
}

void GameState::Init()
{

	// Loading in textures 
	_data->assets.LoadTexture("Menu Bar", MENU_FILEPATH);
	_data->assets.LoadTexture("Create Player Button", CREATE_PLAYER_BUTTON_FILEPATH);
	_data->assets.LoadTexture("Move Type 1 Button", PLAYER_MOVETYPE_1_FILEPATH);
	_data->assets.LoadTexture("Move Type 2 Button", PLAYER_MOVETYPE_2_FILEPATH);
	_data->assets.LoadTexture("Create Wall Button", CREATE_WALL_BUTTON_FILEPATH);
	_data->assets.LoadTexture("Enemy Block Button", ENEMY_BLOCK_BUTTON_FILEPATH);
	_data->assets.LoadTexture("Play Button", PLAYBUTTON_FILEPATH);
	_data->assets.LoadTexture("Build Button", BUILD_BUTTON_FILEPATH);
	_data->assets.LoadTexture("Gravity Button", GRAVITY_BUTTON_FILEPATH);
	_data->assets.LoadTexture("NPC Move Type 1", NPC_MOVETYPE_1_FILEPATH);
	_data->assets.LoadTexture("NPC Move Type 2", NPC_MOVETYPE_2_FILEPATH);
	_data->assets.LoadTexture("Player Bullets", BULLETS_BUTTON_FILEPATH);
	_data->assets.LoadTexture("NPC Bullets", NPC_BULLETS_BUTTON_FILEPATH);
	_data->assets.LoadFont("Info Text", INFO_TEXT);

	_data->assets.LoadTexture("First Player Texture", PLAYER_FIRST_TEXTURE);
	_data->assets.LoadTexture("Frog Player Texture", PLAYER_FROG_TEXTURE);
	_data->assets.LoadTexture("Ship Player Texture", PLAYER_SHIP_TEXTURE);
	_data->assets.LoadTexture("Invader Texture", INVADER_TEXTURE);
	_data->assets.LoadTexture("First NPC Texture", NPC_FIRST_TEXTURE);
	_data->assets.LoadTexture("Truck NPC Texture", NPC_TRUCK_TEXTURE);
	_data->assets.LoadTexture("First Wall Texture", WALL_FIRST_TEXTURE);
	_data->assets.LoadTexture("Goal Texture", GOAL_TEXTURE);
	_data->assets.LoadTexture("Enemy Block Texture", ENEMY_BLOCK_TEXTURE);
	_data->assets.LoadTexture("Bullets Texture", PLAYER_BULLETS_FILEPATH);

	_data->assets.LoadTexture("Frogger Background", FROG_BACKGROUND);
	_data->assets.LoadTexture("Space Background", SPACE_BACKGROUND);

	_background.setPosition(0, 0);

	// Setting texures and positions for buttons 
	_menu.setTexture(this->_data->assets.GetTexture("Menu Bar"));
	_menu.setPosition(980, 1);

	_playerSpriteButton.setTexture(this->_data->assets.GetTexture("Create Player Button"));
	_playerSpriteButton.setPosition(990, 180);

	_playerMoveType1Button.setTexture(this->_data->assets.GetTexture("Move Type 1 Button"));
	_playerMoveType1Button.setPosition(1050, 180);

	_playerMoveType2Button.setTexture(this->_data->assets.GetTexture("Move Type 2 Button"));
	_playerMoveType2Button.setPosition(1110, 180);

	_wallButton.setTexture(this->_data->assets.GetTexture("Create Wall Button"));
	_wallButton.setPosition(1000, 660);

	_goalButton.setTexture(this->_data->assets.GetTexture("Goal Texture"));
	_goalButton.setPosition(1050, 660);

	_gravityButton.setTexture(this->_data->assets.GetTexture("Gravity Button"));
	_gravityButton.setPosition(1200, 660);

	_enemyBlockButton.setTexture(this->_data->assets.GetTexture("Enemy Block Button"));
	_enemyBlockButton.setPosition(1000, 430);

	_playerBulletsButton.setTexture(this->_data->assets.GetTexture("Player Bullets"));
	_playerBulletsButton.setPosition(1160, 180);

	_npcBulletsButton.setTexture(this->_data->assets.GetTexture("NPC Bullets"));
	_npcBulletsButton.setPosition(1220, 430);

	_RightNpcButton.setTexture(this->_data->assets.GetTexture("NPC Move Type 1"));
	_RightNpcButton.setPosition(1050, 430);

	_LeftNpcButton.setTexture(this->_data->assets.GetTexture("NPC Move Type 2"));
	_LeftNpcButton.setPosition(1110, 430);

	_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
	_playButton.setPosition(980, 800);

	_buildButton.setTexture(this->_data->assets.GetTexture("Build Button"));
	_buildButton.setPosition(1300, 810);

	_FrogTexButton.setTexture(this->_data->assets.GetTexture("Frog Player Texture"));
	_FrogTexButton.setPosition(990, 230);

	_ShipTexButton.setTexture(this->_data->assets.GetTexture("Ship Player Texture"));
	_ShipTexButton.setPosition(1070, 210);

	_TruckTexButton.setTexture(this->_data->assets.GetTexture("Truck NPC Texture"));
	_TruckTexButton.setPosition(1000, 500);

	_InvaderTexButton.setTexture(this->_data->assets.GetTexture("Invader Texture"));
	_InvaderTexButton.setPosition(1200, 500);

	_FrogBackgroundButton.setTexture(this->_data->assets.GetTexture("Frogger Background"));
	_FrogBackgroundButton.setPosition(1000, 720);
	_FrogBackgroundButton.setScale(0.1, 0.1);

	_SpaceBackgroundButton.setTexture(this->_data->assets.GetTexture("Space Background"));
	_SpaceBackgroundButton.setPosition(1100, 720);
	_SpaceBackgroundButton.setScale(0.05, 0.05);

	// Setting screen text 
	infoText.setFont(this->_data->assets.GetFont("Info Text"));
	infoText.setPosition(400, 400);
	infoText.setCharacterSize(128);
	infoText.setFillColor(sf::Color::White);

	buttonInfo.setFont(this->_data->assets.GetFont("Info Text"));
	buttonInfo.setPosition(990, 10);
	buttonInfo.setCharacterSize(58);
	buttonInfo.setFillColor(sf::Color::Black);

	// Calling in sprite objects
	player = new Player(_data);
	npc = new Npc(_data);
	goalPoint = new GoalPoint(_data);

	// Creating game state and setting it to build mode when first intitiated
	gameState == GameStates::Building;
}

void GameState::HandleInput()
{
	while (_data->window.pollEvent(event))
	{
		// Closing window
		if (sf::Event::Closed == event.type)
		{
			_data->window.close();
		}

		// Input for Build mode
		if (GameStates::Building == gameState)
		{
			//LMB released
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				// All dragging are set to false so nothing is moved by the mouse when the button is not pressed on a sprite
				playerDragging = false;
				wallDragging = false;
				goalDragging = false;
				eBlockDragging = false;
				rNpcDragging = false;			
				lNpcDragging = false;
			}

			//Tracking mouse movement in window
			if (event.type == sf::Event::MouseMoved)
			{
				mouseX = event.mouseMove.x;
				mouseY = event.mouseMove.y;
			}

			// Checking if Player button is pressed
			if (_data->input.IsSpriteClicked(_playerSpriteButton, sf::Mouse::Left, _data->window))
			{
				playerCreated = true;
				std::cout << "Player Created" << std::endl;
			}

			// Checking if mouse is just moving over button to print out button info text. Does so for every button
			if (_data->input.MouseHoverOver(_playerSpriteButton, _data->window))
			{
				buttonInfo.setString("Player Sprite");
			}

			// Checking if Player movement type button is pressed
			if (_data->input.IsSpriteClicked(_playerMoveType1Button, sf::Mouse::Left, _data->window))
			{
				moveType1 = true;
				std::cout << "Move Type 1 selected" << std::endl;
			}

			if (_data->input.MouseHoverOver(_playerMoveType1Button, _data->window))
			{
				buttonInfo.setString("Move Type 1");
			}

			// Checking if Player movement type 2 button is pressed
			if (_data->input.IsSpriteClicked(_playerMoveType2Button, sf::Mouse::Left, _data->window))
			{
				moveType2 = true;
				std::cout << "Move Type 2 selected" << std::endl;
			}

			if (_data->input.MouseHoverOver(_playerMoveType2Button, _data->window))
			{
				buttonInfo.setString("Move Type 2");
			}

			// Checking if Enemy block button is pressed
			if (_data->input.IsSpriteClicked(_enemyBlockButton, sf::Mouse::Left, _data->window))
			{
				eBlockCreated = true;
			}

			if (_data->input.MouseHoverOver(_enemyBlockButton, _data->window))
			{
				buttonInfo.setString("Enemy Block");
			}

			// Checking if wall block button is pressed
			if (_data->input.IsSpriteClicked(_wallButton, sf::Mouse::Left, _data->window))
			{
				wallCreated = true;
				std::cout << "Wall Created" << std::endl;
			}

			if (_data->input.MouseHoverOver(_wallButton, _data->window))
			{
				buttonInfo.setString("Wall Block");
			}

			// Checking if goal button is pressed
			if (_data->input.IsSpriteClicked(_goalButton, sf::Mouse::Left, _data->window))
			{
				goalCreated = true;
			}

			if (_data->input.MouseHoverOver(_goalButton, _data->window))
			{
				buttonInfo.setString("Level Goal");
			}

			// Checking if Frog texture button is pressed
			if (_data->input.IsSpriteClicked(_FrogTexButton, sf::Mouse::Left, _data->window))
			{
				player->SwapTexture("Frog Player Texture");
			}

			if (_data->input.MouseHoverOver(_FrogTexButton, _data->window))
			{
				buttonInfo.setString("Set as Player Tex");
			}

			// Checking if Truck texture button is pressed
			if (_data->input.IsSpriteClicked(_TruckTexButton, sf::Mouse::Left, _data->window))
			{
				// Swapping texture for every element in right moving npc vector
				for (int i = 0; i < rNpcVec.size(); i++)
				{
					rNpcVec[i].SwapTexture("Truck NPC Texture");
				}

				// Swapping texture for every element in left moving npc vector
				for (int i = 0; i < lNpcVec.size(); i++)
				{
					lNpcVec[i].SwapTexture("Truck NPC Texture");
				}
			}

			if (_data->input.MouseHoverOver(_TruckTexButton, _data->window))
			{
				buttonInfo.setString("Set as NPC Tex");
			}


			if (_data->input.IsSpriteClicked(_InvaderTexButton, sf::Mouse::Left, _data->window))
			{
				// Swapping texture for every element in right moving npc vector
				for (int i = 0; i < rNpcVec.size(); i++)
				{
					rNpcVec[i].SwapTexture("Invader Texture");
				}

				// Swapping texture for every element in left moving npc vector
				for (int i = 0; i < lNpcVec.size(); i++)
				{
					lNpcVec[i].SwapTexture("Invader Texture");
				}
			}

			if (_data->input.MouseHoverOver(_InvaderTexButton, _data->window))
			{
				buttonInfo.setString("Set as NPC Tex");
			}

			// Checking if Ship texture button is pressed
			if (_data->input.IsSpriteClicked(_ShipTexButton, sf::Mouse::Left, _data->window))
			{
				player->SwapTexture("Ship Player Texture");
			}

			if (_data->input.MouseHoverOver(_FrogTexButton, _data->window))
			{
				buttonInfo.setString("Set as Player Tex");
			}

			// Checking if right moving npc button is pressed
			if (_data->input.IsSpriteClicked(_RightNpcButton, sf::Mouse::Left, _data->window))
			{
				rightNpcCreated = true;
			}

			if (_data->input.MouseHoverOver(_RightNpcButton, _data->window))
			{
				buttonInfo.setString("R-Moving NPC");
			}

			// Checking if left moving npc button is pressed
			if (_data->input.IsSpriteClicked(_LeftNpcButton, sf::Mouse::Left, _data->window))
			{
				leftNpcCreated = true; 
			}

			if (_data->input.MouseHoverOver(_LeftNpcButton, _data->window))
			{
				buttonInfo.setString("L-Moving NPC");
			}

			// Checking if player bullet enabling button is pressed
			if (_data->input.IsSpriteClicked(_playerBulletsButton, sf::Mouse::Left, _data->window))
			{
				bulletsEnabled = true;
			}

			if (_data->input.MouseHoverOver(_playerBulletsButton, _data->window))
			{
				buttonInfo.setString("Player Bullets");
			}

			// Checking if npc bullet enabling button is pressed
			if (_data->input.IsSpriteClicked(_npcBulletsButton, sf::Mouse::Left, _data->window))
			{
				enemyBulletsEnabled = true; 
			}

			if (_data->input.MouseHoverOver(_npcBulletsButton, _data->window))
			{
				buttonInfo.setString("NPC Bullets");
			}

			// Checking if Road background button is pressed
			if (_data->input.IsSpriteClicked(_FrogBackgroundButton, sf::Mouse::Left, _data->window))
			{
				_background.setTexture(this->_data->assets.GetTexture("Frogger Background"));
				_background.setScale(2, 2);
			}

			if (_data->input.MouseHoverOver(_FrogBackgroundButton, _data->window))
			{
				buttonInfo.setString("Road Background");
			}

			// Checking if Space background button is pressed
			if (_data->input.IsSpriteClicked(_SpaceBackgroundButton, sf::Mouse::Left, _data->window))
			{
				_background.setTexture(this->_data->assets.GetTexture("Space Background"));
			}

			if (_data->input.MouseHoverOver(_SpaceBackgroundButton, _data->window))
			{
				buttonInfo.setString("Space Background");
			}

			// Checking if Play button is pressed
			if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window))
			{
				gameState = GameStates::Playing;
			}

			if (_data->input.MouseHoverOver(_playButton, _data->window))
			{
				buttonInfo.setString("Play Game");
			}

			// Checking if sprite is clicked 
			if (_data->input.IsSpriteClicked(player->GetSprite(), sf::Mouse::Left, _data->window))
			{
				// Checking if button is still being pressed
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				{
					// Sprite dragging true to call respective drag function
					playerDragging = true;

					// Setting x and y offsets for mouse movement
					mouseRectOffset.x = event.mouseButton.x - player->GetSprite().getGlobalBounds().left - player->GetSprite().getOrigin().x;
					mouseRectOffset.y = event.mouseButton.y - player->GetSprite().getGlobalBounds().top - player->GetSprite().getOrigin().y;
				}
			}

			// Repeat process for other draggable sprites
			if (_data->input.IsSpriteClicked(goalPoint->GetSprite(), sf::Mouse::Left, _data->window))
			{
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				{
					goalDragging = true; 
					mouseRectOffset.x = event.mouseButton.x - goalPoint->GetSprite().getGlobalBounds().left - goalPoint->GetSprite().getOrigin().x;
					mouseRectOffset.y = event.mouseButton.y - goalPoint->GetSprite().getGlobalBounds().top - goalPoint->GetSprite().getOrigin().y;
				}
			}

			for (int i = 0; i < wallVec.size(); i++)
			{
				if (_data->input.IsSpriteClicked(wallVec[i].GetSprite(), sf::Mouse::Left, _data->window))
				{
					if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
					{
						wallDragging = true;
						mouseRectOffset.x = event.mouseButton.x - wallVec[i].GetSprite().getGlobalBounds().left - wallVec[i].GetSprite().getOrigin().x;
						mouseRectOffset.y = event.mouseButton.y - wallVec[i].GetSprite().getGlobalBounds().top - wallVec[i].GetSprite().getOrigin().y;

					}
				}
			}

			for (int i = 0; i < eBlockVec.size(); i++)
			{
				if (_data->input.IsSpriteClicked(eBlockVec[i].GetSprite(), sf::Mouse::Left, _data->window))
				{
					if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
					{
						eBlockDragging = true; 
						mouseRectOffset.x = event.mouseButton.x - eBlockVec[i].GetSprite().getGlobalBounds().left - eBlockVec[i].GetSprite().getOrigin().x;
						mouseRectOffset.y = event.mouseButton.y - eBlockVec[i].GetSprite().getGlobalBounds().top - eBlockVec[i].GetSprite().getOrigin().y;
					}
				}
			}

			for (int i = 0; i < rNpcVec.size(); i++)
			{
				if (_data->input.IsSpriteClicked(rNpcVec[i].GetSprite(), sf::Mouse::Left, _data->window))
				{
					if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
					{
						rNpcDragging = true;
						mouseRectOffset.x = event.mouseButton.x - rNpcVec[i].GetSprite().getGlobalBounds().left - rNpcVec[i].GetSprite().getOrigin().x;
						mouseRectOffset.y = event.mouseButton.y - rNpcVec[i].GetSprite().getGlobalBounds().top - rNpcVec[i].GetSprite().getOrigin().y;
					}
				}
			}

			for (int i = 0; i < lNpcVec.size(); i++)
			{
				if (_data->input.IsSpriteClicked(lNpcVec[i].GetSprite(), sf::Mouse::Left, _data->window))
				{
					if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
					{
						lNpcDragging = true;
						mouseRectOffset.x = event.mouseButton.x - lNpcVec[i].GetSprite().getGlobalBounds().left - lNpcVec[i].GetSprite().getOrigin().x;
						mouseRectOffset.y = event.mouseButton.y - lNpcVec[i].GetSprite().getGlobalBounds().top - lNpcVec[i].GetSprite().getOrigin().y;
					}
				}
			}
		}

		// Input for when the app is in playing state. 
		if (GameStates::Playing == gameState)
		{
			buttonInfo.setString("Playing Game");

			// Going back into build mode 
			if (_data->input.IsSpriteClicked(_buildButton, sf::Mouse::Left, _data->window))
			{
				gameState = GameStates::Building;
			}

			if (_data->input.MouseHoverOver(_buildButton, _data->window))
			{
				buttonInfo.setString("Build Game");
			}

			// Allowing the player to move in all directions
			if (moveType1)
			{
				if (sf::Event::KeyPressed)
				{
					player->PlayerMoveType1(event);
				}
			}

			// Allowing the player to move side to side
			if (moveType2)
			{
				if (sf::Event::KeyPressed)
				{
					player->PlayerMoveType2(event);
				}
			}
			
			// Firing player bullets with space bar
			if (bulletsEnabled)
			{
				if (sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
				{
					isFiring = true;
				}
			}
		}
	}
}

void GameState::Update(float dt)
{

	if (GameStates::Building == gameState)
	{
		// Checking for dragging the different objects, setting the position of the objects to the mouse position
		if (playerDragging)
		{
			player->DragPlayer(mouseX - mouseRectOffset.x, mouseY - mouseRectOffset.y);
		}

		if (goalDragging)
		{
			goalPoint->DragGoal(mouseX - mouseRectOffset.x, mouseY - mouseRectOffset.y);
		}

		if (wallDragging)
		{
			wallVec.back().DragWall(mouseX - mouseRectOffset.x, mouseY - mouseRectOffset.y);
		}

		if (eBlockDragging)
		{
			eBlockVec.back().DragBlock(mouseX - mouseRectOffset.x, mouseY - mouseRectOffset.y);
		}

		if (lNpcDragging)
		{
			lNpcVec.back().DragNpc(mouseX - mouseRectOffset.x, mouseY - mouseRectOffset.y);
		}

		if (rNpcDragging)
		{
			rNpcVec.back().DragNpc(mouseX - mouseRectOffset.x, mouseY - mouseRectOffset.y);
		}
	}

	// Updating while in play mode
	if (GameStates::Playing == gameState)
	{
		// Moving all the left moving NPCs 
		for (int i = 0; i < lNpcVec.size(); i++)
		{
			lNpcVec[i].Move(event);
		}

		// Moving all the right moving NPCs
		for (int i = 0; i < rNpcVec.size(); i++)
		{
			rNpcVec[i].Move(event);
		}

		// Adding new bullets to a bullet vector
		if (isFiring)
		{
			Bullet newBullet(_data);
			newBullet.setPos(player->GetSprite().getPosition().x, player->GetSprite().getPosition().y);
			bulletVec.push_back(newBullet);
			isFiring = false;
		}

		// Firing each bullet and giving it a speed
		for (int i = 0; i < bulletVec.size(); i++)
		{
			bulletVec[i].Fire(4);
		}

		if (enemyBulletsEnabled)
		{
			// Adding a new bullet to the enemy bullet vector for the left moving npc
			for (int i = 0; i < lNpcVec.size(); i++)
			{
				if (_clock.getElapsedTime().asSeconds() > rand() % 1000)
				{
					Bullet newLeftBullet(_data);
					newLeftBullet.setPos(lNpcVec[i].GetSprite().getPosition().x, lNpcVec[i].GetSprite().getPosition().y);
					enemyBulletVec.push_back(newLeftBullet);
					_clock.restart();
				}
			}

			// Adding a new bullet to the enemy bullet vector for the right moving npc
			for (int i = 0; i < rNpcVec.size(); i++)
			{
				if (_clock.getElapsedTime().asSeconds() > rand() % 1000)
				{
					Bullet newRightBullet(_data);
					newRightBullet.setPos(rNpcVec[i].GetSprite().getPosition().x, rNpcVec[i].GetSprite().getPosition().y);
					enemyBulletVec.push_back(newRightBullet);
					_clock.restart();

				}
			}
		}

		// Firing the enemy bullets 
		for (int i = 0; i < enemyBulletVec.size(); i++)
		{
			enemyBulletVec[i].Fire(-4);
		}

		// Printing out winning text for when player collides with goal
		if (collision.CheckSpriteCollision(player->GetSprite(), goalPoint->GetSprite()))
		{
			infoText.setString("Level Finished!");
		}

		// Stopping the player moving when colliding with editor
		if (collision.CheckSpriteCollision(player->GetSprite(), _menu))
		{
			player->PlayerStop(event);
		}

		// Killing player when colliding with npc
		for (int i = 0; i < rNpcVec.size(); i++)
		{
			if (collision.CheckSpriteCollision(player->GetSprite(), rNpcVec[i].GetSprite()))
			{
				player->PlayerDeath(event);
			}
		}

		for (int i = 0; i < lNpcVec.size(); i++)
		{
			if (collision.CheckSpriteCollision(player->GetSprite(), lNpcVec[i].GetSprite()))
			{
				player->PlayerDeath(event);
			}
		}

		// Blocking player movement when colliding with wall
		for (int i = 0; i < wallVec.size(); i++)
		{
			if (collision.CheckSpriteCollision(player->GetSprite(), wallVec[i].GetSprite()))
			{
				player->PlayerStop(event);
			}
		}

		// Killing Player when colliding with wall block 
		for (int i = 0; i < eBlockVec.size(); i++)
		{
			if (collision.CheckSpriteCollision(player->GetSprite(), eBlockVec[i].GetSprite()))
			{
				player->PlayerDeath(event);
			}
		}

		// Removing NPCs when collided with player bullet 
		for (int i = 0; i < bulletVec.size(); i++)
		{
			for (int j = 0; j < lNpcVec.size(); j++)
			{
				if (collision.CheckSpriteCollision(bulletVec[i].getSprite(), lNpcVec[j].GetSprite()))
				{
					// Removing sprite element from vector
					lNpcVec.erase(lNpcVec.begin() + j);
				}
			}
		}

		for (int i = 0; i < bulletVec.size(); i++)
		{
			for (int j = 0; j < rNpcVec.size(); j++)
			{
				if (collision.CheckSpriteCollision(bulletVec[i].getSprite(), rNpcVec[j].GetSprite()))
				{
					// Removing sprite element from vector
					rNpcVec.erase(rNpcVec.begin() + j);
				}
			}
		}

		// Calling the player death function for when the player collides with an enemy bullet 
		for (int i = 0; i < enemyBulletVec.size(); i++)
		{
			if (collision.CheckSpriteCollision(player->GetSprite(), enemyBulletVec[i].getSprite()))
			{
				player->PlayerDeath(event);
			}
		}
	}
}

void GameState::Draw(float dt)
{
	_data->window.clear();

	_data->window.draw(_background);

	// Drawing assets once they have been added via the editor buttons 
	if (playerCreated == true)
	{
		player->DrawPlayer();
	}

	if (goalCreated)
	{
		goalPoint->DrawGoal();
	}

	// Adding a new wall to wall vector 
	if (wallCreated)
	{		
		Wall newWall(_data);
		wallVec.push_back(newWall);
		wallCreated = false;
	}

	// Drawing walls 
	for (int i = 0; i < wallVec.size(); i++)
	{
		wallVec[i].DrawWall();
	}

	// Repeat process for other sprite vectors 
	if (rightNpcCreated)
	{
		RightNpc newNPC(_data);
		rNpcVec.push_back(newNPC);
		rightNpcCreated = false;
	}

	for (int i = 0; i < rNpcVec.size(); i++)
	{
		rNpcVec[i].DrawNpc();
	}

	if (leftNpcCreated)
	{
		LeftNpc newNPC(_data); 
		lNpcVec.push_back(newNPC);
		leftNpcCreated = false;
	}

	for (int i = 0; i < lNpcVec.size(); i++)
	{
		lNpcVec[i].DrawNpc();
	}

	if (eBlockCreated)
	{
		EnemyBlock newBlock(_data);
		eBlockVec.push_back(newBlock);
		eBlockCreated = false; 
	}

	for (int i = 0; i < eBlockVec.size(); i++)
	{
		eBlockVec[i].Draw();
	}

	for (int i = 0; i < bulletVec.size(); i++)
	{
		bulletVec[i].Draw();
	}

	for (int i = 0; i < enemyBulletVec.size(); i++)
	{
		enemyBulletVec[i].Draw();
	}

	// Drawing editor and subsequent buttons
	_data->window.draw(_menu);
	_data->window.draw(_playerSpriteButton);
	_data->window.draw(_playerMoveType1Button);
	_data->window.draw(_playerMoveType2Button);
	_data->window.draw(_wallButton);
	_data->window.draw(_goalButton);
	_data->window.draw(_playButton);
	_data->window.draw(_buildButton);
	_data->window.draw(_enemyBlockButton);
	_data->window.draw(_FrogTexButton);
	_data->window.draw(_TruckTexButton);
	_data->window.draw(_ShipTexButton);
	_data->window.draw(_playerBulletsButton);
	_data->window.draw(_npcBulletsButton);
	_data->window.draw(_RightNpcButton);
	_data->window.draw(_LeftNpcButton);
	_data->window.draw(_FrogBackgroundButton);
	_data->window.draw(_SpaceBackgroundButton);
	_data->window.draw(_InvaderTexButton);

	_data->window.draw(infoText);
	_data->window.draw(buttonInfo);

	_data->window.display();
}