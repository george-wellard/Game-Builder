#include "LeftNpc.h"

LeftNpc::LeftNpc(GameDataRef data) : _data(data)
{
	// setting texture by grabbing assoiciated string
	npc.setTexture(_data->assets.GetTexture("First NPC Texture"));

	// setting to position of npc on edge of screen to be dragged in a more appropiate place by player
	npc.setPosition(0, 0);
}

void LeftNpc::Move(sf::Event event)
{
	// Moving npc left
	npc.move(-3.0, 0);

	// moving npc to the opposite x position when it goes past the level area 
	if (npc.getPosition().x < -50)
	{
		npc.setPosition(980, npc.getPosition().y);
	}
}

void LeftNpc::SwapTexture(std::string texture)
{
	// Getting new texture by grabbing assoicaited string 
	npc.setTexture(_data->assets.GetTexture(texture));
}

void LeftNpc::DragNpc(float mouseX, float mouseY)
{
	// setting npc to new position of mouse 
	npc.setPosition(mouseX, mouseY);
}

void LeftNpc::DrawNpc()
{
	// Drawing npc
	_data->window.draw(npc);
}

const sf::Sprite& LeftNpc::GetSprite() const
{
	return npc;
}