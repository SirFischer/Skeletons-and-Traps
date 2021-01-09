#pragma once
#include "Entity.hpp"

class Knight : public Entity
{
private:

public:
	Knight(/* args */);
	~Knight();

	void	Update();
	void	Render(Window	*tWindow);
};
