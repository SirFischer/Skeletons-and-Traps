#pragma once
#include "Window.hpp"
#include "Entities.hpp"
#include "InputManager.hpp"

#include <memory>

class Player
{
private:
	std::unique_ptr<Entity>	mCharacter;

public:
	Player(/* args */);
	~Player();

	void	Update();
	void	Render(Window	*tWindow);
};

