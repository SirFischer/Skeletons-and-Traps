#pragma once

#include "State.hpp"
#include "ResourceManager.hpp"
#include <Map.hpp>
#include <Player.hpp>
#include <Entities.hpp>
#include <AI.hpp>
#include <Audio/MusicPlayer.hpp>

class MenuState : public State
{
private:
	mf::Button		*mPlayBtn;
	mf::Button		*mOptionBtn;
	mf::Button		*mQuitBtn;
	Map				 mMap;
	Player			 mPlayer;

	MusicPlayer		mMusic;

	std::list<Entity *>						mEntities;
	
	std::list<ParticleEffect>				mParticleEffects;
	
public:
	MenuState(Window *tWindow);
	~MenuState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

