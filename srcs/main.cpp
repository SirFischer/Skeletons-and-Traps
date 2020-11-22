#include "Core.hpp"

int main( void )
{
	Window		window;

	StateManager	stateManager(&window);

	stateManager.Run();

	return (0);
}