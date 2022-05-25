#pragma once

// Storage for values and file paths for easier calling

#define SCREEN_HEIGHT 1024
#define SCREEN_WIDTH 1444

#define SPLASH_STATE_SHOW_TIME 3.0
#define SPLASH_SCREEN_BACKGROUND_FILEPATH "res/Logo.png"

#define PLAYBUTTON_FILEPATH "res/PlayButton.png"
#define MENU_FILEPATH "res/MenuBar.png"
#define BUILD_BUTTON_FILEPATH "res/BuildButton.png"

#define CREATE_PLAYER_BUTTON_FILEPATH "res/PlayerSpriteButton.png"
#define CREATE_NPC_BUTTON_FILEPATH "res/NpcSpriteButton.png"
#define CREATE_WALL_BUTTON_FILEPATH "res/WallButton.png"
#define PLAYER_MOVETYPE_1_FILEPATH "res/MoveType1.png"
#define PLAYER_MOVETYPE_2_FILEPATH "res/MoveType2.png"
#define ENEMY_BLOCK_BUTTON_FILEPATH "res/EnemyBlockButton.png"
#define GRAVITY_BUTTON_FILEPATH "res/GravityButton.png"
#define BULLETS_BUTTON_FILEPATH "res/PlayerBulletsButton.png"
#define PLAYER_BULLETS_FILEPATH "res/PlayerBullet.png"
#define NPC_BULLETS_FILEPATH "res/NpcBullet.png"
#define NPC_BULLETS_BUTTON_FILEPATH "res/NpcBulletsButton.png"
#define NPC_MOVETYPE_1_FILEPATH "res/NpcMoveType1.png"
#define NPC_MOVETYPE_2_FILEPATH "res/NpcMoveType2.png"

#define PLAYER_FIRST_TEXTURE "res/PlayerStartTex.png"
#define PLAYER_FROG_TEXTURE "res/Frog.png"
#define PLAYER_SHIP_TEXTURE "res/Ship.png"
#define NPC_FIRST_TEXTURE "res/NpcStartTex.png"
#define NPC_TRUCK_TEXTURE "res/Truck.png"
#define WALL_FIRST_TEXTURE "res/WallStartTex.png"
#define GOAL_TEXTURE "res/FinishTex.png"
#define ENEMY_BLOCK_TEXTURE "res/EnemyBlock.png"
#define INVADER_TEXTURE "res/Invader.png"

#define FROG_BACKGROUND "res/FrogBackground.png"
#define SPACE_BACKGROUND "res/Space.png"

#define GRAVITY 350.0f
#define JUMPING_SPEED 350.0f
#define JUMPING_DURATION 0.5f;

#define INFO_TEXT "res/arial.ttf"

enum GameStates
{
	Building,
	Playing
};