#pragma once

#include "State.hpp"
#include "ResourceManager.hpp"
#include "InputManager.hpp"

class OptionsState : public State
{
private:
	mf::Button	*mQuitButton;

	mf::Button	*mAttackKey;
	
public:
	OptionsState(Window *tWindow);
	~OptionsState();

	void		Init(StateInformations &tStateInformations);
	void		HandleEvents();
	void		Update();
	void		Render();
};

