#pragma once
#include "Entity.hpp"

class Hero : public Entity
{
private:

public:
	Hero(/* args */);
	~Hero();

	void	Update();
	void	Render(Window	*tWindow);
};

