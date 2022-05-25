#include "RightNPC.h"

RightNpc::RightNpc(GameDataRef data) : _data(data)
{
	// setting texture by grabbing assoiciated string
	npc.setTexture(_data->assets.GetTexture("First NPC Texture"));

	// setting to position of npc on edge of screen to be dragged in a more appropiate place by player
	npc.setPosition(0, 0);
}

void RightNpc::Move(sf::Event event)
{
	// Moving npc to the right
	npc.move(3.0, 0);

	// moving npc to the opposite x position when it goes past the level area 
	if (npc.getPosition().x > 980)
	{
		npc.setPosition(0, npc.getPosition().y);
	}
}

void RightNpc::SwapTexture(std::string texture)
{
	// Getting new texture by grabbing assoicaited string 
	npc.setTexture(_data->assets.GetTexture(texture));
}

void RightNpc::DragNpc(float mouseX, float mouseY)
{
	// setting npc to new position of mouse 
	npc.setPosition(mouseX, mouseY);
}

void RightNpc::DrawNpc()
{
	// drawing npc
	_data->window.draw(npc);
}

const sf::Sprite& RightNpc::GetSprite() const
{
	return npc;
}
