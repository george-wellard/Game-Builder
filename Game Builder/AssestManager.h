#pragma once
#include <map>
#include <SFML/Graphics.hpp>

class AssetManager
{
public:

	AssetManager() {}

	~AssetManager() {}

	// Loading in texture
	void LoadTexture(std::string name, std::string filename);
	sf::Texture& GetTexture(std::string name);

	// Loading in font
	void LoadFont(std::string name, std::string filename);
	sf::Font& GetFont(std::string name);

private:
	// storage for textures
	std::map<std::string, sf::Texture> _textures;

	// stprage for fonts
	std::map<std::string, sf::Font> _fonts;
};

