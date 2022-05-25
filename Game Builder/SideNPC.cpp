#include "SideNpc.h"

SideNPC::SideNPC(GameDataRef data) : _data(data)
{

}

void SideNPC::MoveSideNpc(sf::Event event)
{
  
}

void SideNPC::DrawSideNpc()
{
}

const sf::Sprite& SideNPC::GetSprite() const
{
	return sideNpc;
}
