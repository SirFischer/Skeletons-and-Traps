#include "PowerUp.hpp"

PowerUp::PowerUp(sf::Vector2f tPosition)
{
	mPosition = tPosition;
}

PowerUp::~PowerUp()
{
}

void		PowerUp::Update()
{
	mSprite.setPosition(sf::Vector2f(mPosition.x, mPosition.y + ((sin(mClock.getElapsedTime().asSeconds() * 2.f) + 2.f) * 10.f)));
}

void		PowerUp::Render(Window *tWindow)
{
	tWindow->Draw(mSprite);
}

void		PowerUp::HandlePickUp(Entity *tEntity)
{
	if (!mActive)
		return ;
	if (mSprite.getGlobalBounds().intersects(tEntity->GetSprite().getGlobalBounds()))
	{
		mEffect(tEntity);
		mActive = false;
	}
}

void		PowerUp::SetEffect(std::function<void(Entity *)> tEffect)
{
	mEffect = tEffect;
}

void		PowerUp::SetTexture(std::string tPath)
{
	mSprite.setTexture(*ResourceManager::LoadTexture(tPath));
}