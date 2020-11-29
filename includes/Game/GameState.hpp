#pragma once

#include "State.hpp"
#include "InputManager.hpp"
#include "Player.hpp"

class GameState : public State
{
private:
	Player		mPlayer;
	
public:
	GameState(Window *tWindow);
	~GameState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

