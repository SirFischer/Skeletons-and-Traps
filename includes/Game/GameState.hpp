#pragma once

#include "State.hpp"
#include "InputManager.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "Camera.hpp"

class GameState : public State
{
private:

	Map			mMap;
	Player		mPlayer;
	
public:
	GameState(Window *tWindow);
	~GameState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

