#pragma once

#include "State.hpp"
#include "Window.hpp"
#include "InputManager.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "AI.hpp"
#include "ParticleEffect.hpp"


class GameState : public State
{
private:

	sf::Clock								mTimer;

	Map										mMap;
	Player									mPlayer;
	std::list<Entity *>						mEntities;
	
	std::list<ParticleEffect>				mParticleEffects;
	
public:
	GameState(Window *tWindow);
	~GameState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

