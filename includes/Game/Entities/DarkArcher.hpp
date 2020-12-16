#pragma once
#include "Entity.hpp"

class DarkArcher : public Entity
{
private:

public:
	DarkArcher(/* args */);
	~DarkArcher();

	void	Attack(Entity *tEntity, std::list<ParticleEffect> *tParticleEffects);

	void	Update();
	void	Render(Window	*tWindow);
};
