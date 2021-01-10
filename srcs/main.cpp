#include "Core.hpp"

void	Init()
{
	InputManager::LoadDefaultKeyBindings();
	SoundPlayer::Init();
}

int main( void )
{
	Window		window;

	StateManager	stateManager(&window);

	Init();

	stateManager.Run();

	return (0);
}