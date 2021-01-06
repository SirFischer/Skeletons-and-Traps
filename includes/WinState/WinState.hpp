#pragma once

#include "State.hpp"
#include "ResourceManager.hpp"

class WinState : public State
{
private:
    sf::Text            mWinText;
    sf::Text            mScoreText;
	mf::Button		    *mQuitBtn;
public:
    WinState(Window *tWindow);
    ~WinState();

    void		Init(StateInformations &tStateInformations);
	void		HandleEvents();
	void		Update();
	void		Render();
};