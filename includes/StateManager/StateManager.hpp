#pragma once

#include "States.hpp"
#include "StateInformations.hpp"
#include <stack>

class StateManager
{
private:
	std::stack<State *>	mStates;

	Window				*mWindow = NULL;

public:
	StateManager(Window *tWindow);
	~StateManager();

	void		Run();
};
