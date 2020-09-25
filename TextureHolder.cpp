#include "TextureHolder.h"
#include <assert.h>

using namespace sf;

TextureHolder* TextureHolder::m_s_Instance = NULL;

TextureHolder::TextureHolder()
{
	assert(m_s_Instance == NULL);
	m_s_Instance = this;
}


Texture& TextureHolder::GetTexture(std::string const& filename)
{
	//Get a reference to m_Textures using m_s_Instance
	auto& m = m_s_Instance->m_Textures;
	//auto is the equivalent of map<string, Texture>

	//Create an iterator to hold a key-value-pair (kvp) and search for the required kvp using the file name
	auto keyValuePair = m.find(filename);
	//auto is the equivalent of map<string, Texture>::iterator


	//Did we find a match?
	if (keyValuePair != m.end())
	{
		//Yes
		//Return the texture
		return keyValuePair->second;
	}
	else
	{
		//File name not found
		//create a new kvp using the filename
		auto& texture = m[filename];

		//Load the texture from file the usual way
		texture.loadFromFile(filename);

		//Return the texture to the calling code
		return texture;
	}
}