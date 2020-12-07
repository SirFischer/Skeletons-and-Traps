#pragma once

#include "State.hpp"
#include "ResourceManager.hpp"

class OptionsState : public State
{
private:
	mf::Button	*mFullscreenButton;
	mf::Button	*mQuitButton;
	
public:
	OptionsState(Window *tWindow);
	~OptionsState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

