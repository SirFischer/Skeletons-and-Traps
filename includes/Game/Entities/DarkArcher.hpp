#pragma once
#include "Entity.hpp"

class DarkArcher : public Entity
{
private:

public:
	DarkArcher(/* args */);
	~DarkArcher();

	void	Update();
	void	Render(Window	*tWindow);
};
