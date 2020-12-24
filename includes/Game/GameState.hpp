#pragma once

#include "State.hpp"
#include "Window.hpp"
#include "InputManager.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "AI.hpp"
#include "ParticleEffect.hpp"
#include "Projectile.hpp"


class GameState : public State
{
private:

	sf::Clock								mTimer;

	Map										mMap;
	Player									mPlayer;
	std::list<Entity *>						mEntities;

	sf::Vector2f							mCameraVelocity = sf::Vector2f(0, 0);
	sf::Vector2f							mCameraPosition = sf::Vector2f(0, 0);

	mf::Text								*mHPText;
	
	std::list<ParticleEffect>				mParticleEffects;
	std::list<Projectile>					mProjectiles;

	void		UpdateCameraPosition();
	
public:
	GameState(Window *tWindow);
	~GameState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

