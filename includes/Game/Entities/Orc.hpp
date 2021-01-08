#pragma once
#include "Entity.hpp"

class Orc : public Entity
{
private:

public:
	Orc(/* args */);
	~Orc();

	void	Update();
	void	Render(Window	*tWindow);
};
