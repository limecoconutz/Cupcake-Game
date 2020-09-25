#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <memory>

class TextureHolder
{
public:
	TextureHolder();
	static sf::Texture& GetTexture(std::string const& filename);

private:
	//A map that holds related pairs of String and Texture
	std::map<std::string, sf::Texture> m_Textures;

	//A pointer of the same type as the class itself 
	//the one and only instance
	static TextureHolder* m_s_Instance;

};

