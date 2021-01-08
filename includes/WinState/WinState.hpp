#pragma once

#include "State.hpp"
#include "ResourceManager.hpp"

#include <fstream>

class WinState : public State
{
private:
    sf::Text            mWinText;
    sf::Text            mScoreText;
	sf::Text			mHighScore;
	mf::Button		    *mQuitBtn;
    mf::Button          *mVictoryBtn;
public:
    WinState(Window *tWindow);
    ~WinState();

    void		Init(StateInformations &tStateInformations);
	void		HandleEvents();
	void		Update();
	void		Render();
};