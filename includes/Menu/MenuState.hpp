#pragma once

#include "State.hpp"
#include "ResourceManager.hpp"
#include <Map.hpp>
#include <Player.hpp>
#include <Entities.hpp>
#include <AI.hpp>
#include <Audio/MusicPlayer.hpp>
#include <Audio/SoundPlayer.hpp>

class MenuState : public State
{
private:
	mf::Button		*mPlayBtn;
	mf::Button		*mOptionBtn;
	mf::Button		*mQuitBtn;
	Map				 mMap;
	Player			 mPlayer;

	MusicPlayer		mMusic;
	SoundPlayer		mSound;
	sf::Sound		mButton;
	sf::Sprite		mBackground;

	std::list<Entity *>						mEntities;
	
	std::list<ParticleEffect>				mParticleEffects;

	bool									mButtonPressed = false;
	
public:
	MenuState(Window *tWindow);
	~MenuState();

	void		Init(StateInformations &tStateInformations);
	void		HandleEvents();
	void		Update();
	void		Render();
};

