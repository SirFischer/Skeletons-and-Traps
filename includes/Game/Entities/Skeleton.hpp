#pragma once
#include "Entity.hpp"

class Skeleton : public Entity
{
private:

public:
	Skeleton(/* args */);
	~Skeleton();

	void	Update();
	void	Render(Window	*tWindow);
};
