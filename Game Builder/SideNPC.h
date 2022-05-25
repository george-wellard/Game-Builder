#pragma once
#include "GameBuilder.h"

class SideNPC
{
public:

	SideNPC(GameDataRef data);

	void MoveSideNpc(sf::Event event);

	void DrawSideNpc();

	const sf::Sprite& GetSprite() const;

private:

	GameDataRef _data;

	sf::Sprite sideNpc;
};

