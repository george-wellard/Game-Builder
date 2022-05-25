#include "AssestManager.h"

// Loading in texture
void AssetManager::LoadTexture(std::string name, std::string filename)
{
	sf::Texture tex;

	// Loading in a file
	if (tex.loadFromFile(filename))
	{
		// Setting file name as texture
		this->_textures[name] = tex;
	}
}

// Calling in texture
sf::Texture& AssetManager::GetTexture(std::string name)
{
	// Getting texture element with string name
	return this->_textures.at(name);
}

// Repeating process for fonts
void AssetManager::LoadFont(std::string name, std::string filename)
{
	sf::Font fon;

	if (fon.loadFromFile(filename))
	{
		this->_fonts[name] = fon;
	}
}

sf::Font& AssetManager::GetFont(std::string name)
{
	return this->_fonts.at(name);
}