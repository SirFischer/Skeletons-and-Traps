#pragma once

#include "Window.hpp"
#include "StateAction.hpp"
#include "StateInformations.hpp"

class State
{

protected:
	sf::Time		mDeltaTime = sf::seconds(1.f / 64.f);
	StateAction		mStateReturnAction = StateAction::POP;

	bool			mIsActive = true;
	Window			*mWindow = NULL;

public:

	virtual				~State() {}

	virtual void		Init(StateInformations &tStateInformations) = 0;
	virtual StateAction	Run();
	virtual void		HandleEvents() = 0;
	virtual void		Update() = 0;
	virtual void		Render() = 0;

};


