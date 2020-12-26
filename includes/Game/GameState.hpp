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
#include "PowerUp.hpp"
#include "MusicPlayer.hpp"
#include "SoundPlayer.hpp"


class GameState : public State
{
private:

	sf::Clock								mTimer;

	Map										mMap;
	Player									mPlayer;
	std::list<Entity *>						mEntities;

	sf::Vector2f							mCameraVelocity = sf::Vector2f(0, 0);
	sf::Vector2f							mCameraPosition = sf::Vector2f(0, 0);
	MusicPlayer								mMusic;
	SoundPlayer								mSound;

	mf::Text								*mHPText;
	
	std::list<ParticleEffect>				mParticleEffects;
	std::list<Projectile>					mProjectiles;
	std::list<PowerUp>						mPowerUps;
	
	sf::Sprite								mBackground;

	void		UpdateCameraPosition();

public:
	GameState(Window *tWindow);
	~GameState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

