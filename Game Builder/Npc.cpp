#include "Npc.h"

Npc::Npc(GameDataRef data) : _data(data)
{
	npc.setTexture(_data->assets.GetTexture("First NPC Texture"));

	npc.setPosition(300, 800);
}

void Npc::MoveNPCType1(sf::Event event)
{
	npc.move(5.0, 0);

	if (npc.getPosition().x > 980)
	{
		npc.setPosition(0, npc.getPosition().y);
	}
}

void Npc::SwapTexture(std::string texture)
{
	npc.setTexture(_data->assets.GetTexture(texture));
}

void Npc::DragNpc(float mouseX, float mouseY)
{
	npc.setPosition(mouseX, mouseY);
}

void Npc::DrawNpc()
{
	_data->window.draw(npc);
}

const sf::Sprite& Npc::GetSprite() const
{
	return npc;
}
