#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <list>
#include <map>
#include <memory>
#include <iostream>

typedef	std::map<std::string, std::shared_ptr<sf::Font>> FontList;
typedef	std::map<std::string, std::shared_ptr<sf::Texture>> TextureList;

class ResourceManager
{
private:
	ResourceManager(/* args */);
	~ResourceManager();

	static FontList	mFontResources;
	static TextureList	mTextureResources;

public:

	static sf::Font		*LoadFont(std::string tPath);
	static sf::Texture	*LoadTexture(std::string tPath);

};
