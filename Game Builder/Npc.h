#pragma once
#include "SFML/Graphics.hpp"
#include "GameBuilder.h"

class Npc
{

public:

	Npc(GameDataRef data);

	void MoveNPCType1(sf::Event event);

	void SwapTexture(std::string texture);

	void DragNpc(float mouseX, float mouseY);

	void DrawNpc();

	const sf::Sprite& GetSprite() const;

private:

	GameDataRef _data;

	sf::Sprite npc;
};

