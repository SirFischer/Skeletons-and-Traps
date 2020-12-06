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

	
	void	Update(std::list<Entity *> tEntities);
	void	Render(Window	*tWindow);
	
	Entity	*GetEntity(){return mCharacter.get();}
};

