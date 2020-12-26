#pragma once

#include "Window.hpp"
#include "Entities.hpp"

#include <functional>
#include <time.h>

class PowerUp
{
private:
	sf::Vector2f					mPosition;
	sf::Sprite						mSprite;
	sf::Clock						mClock;
	std::function<void(Entity *)>	mEffect;

	bool							mActive = true;
	
public:
	PowerUp(sf::Vector2f tPosition);
	~PowerUp();

	void		Update();
	void		Render(Window *tWindow);

	void		HandlePickUp(Entity *tEntity);
	void		SetEffect(std::function<void(Entity *)> tEffect);
	void		SetTexture(std::string tPath);

	bool		IsActive() {return (mActive);}

	bool operator == (const PowerUp& s) const { return mPosition == s.mPosition; }
};
