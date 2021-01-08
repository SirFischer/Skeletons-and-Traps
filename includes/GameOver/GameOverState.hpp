#pragma once

#include "State.hpp"
#include "ResourceManager.hpp"

class GameOverState : public State
{
private:
    sf::Text            mScoreText;
	mf::Button		    *mQuitBtn;
    mf::Button          *mDeadBtn;
public:
    GameOverState(Window *tWindow);
    ~GameOverState();

    void		Init(StateInformations &tStateInformations);
	void		HandleEvents();
	void		Update();
	void		Render();
};