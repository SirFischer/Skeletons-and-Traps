#pragma once

#include "State.hpp"
#include "ResourceManager.hpp"

class GameOverState : public State
{
private:
    sf::Text            mScoreText;
	mf::Button		    *mQuitBtn;
public:
    GameOverState(Window *tWindow);
    ~GameOverState();

    void		Init();
	void		HandleEvents();
	void		Update();
	void		Render();
};