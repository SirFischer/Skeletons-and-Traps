#pragma once

#include "State.hpp"
#include "Window.hpp"
#include "InputManager.hpp"
#include "Player.hpp"
#include "Map.hpp"

class GameState : public State
{
private:

	Map						mMap;
	Player					mPlayer;
	std::list<Entity *>		mEntities;
	sf::View				mView;
	
public:
	GameState(Window *tWindow);
	~GameState();

	void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};

