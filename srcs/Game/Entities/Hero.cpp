#include "Hero.hpp"

Hero::Hero(/* args */)
{
	mTexture.loadFromFile("assets/textures/Hero.png");
	mSprite.setTexture(mTexture);
}

Hero::~Hero()
{
}

void	Hero::Update()
{

}


void	Hero::Render(Window	*tWindow)
{
	tWindow->Draw(mSprite);
}