#include "StateManager.hpp"


StateManager::StateManager(Window *tWindow)
{
	mWindow = tWindow;
	mStates.push(new MenuState(mWindow)); //Entry State
}

StateManager::~StateManager()
{

}

void		StateManager::Run()
{
	StateAction	action = StateAction::POP;

	while (mStates.size())
	{
		mStates.top()->Init();
		action = mStates.top()->Run();

		switch (action)
		{
		case StateAction::POP:
			delete mStates.top();
			mStates.pop();
			break;
		
		case StateAction::GAME:
			mStates.push(new GameState(mWindow));
			break;

		case StateAction::MENU:
			mStates.push(new MenuState(mWindow));
			break;

		default:
			delete mStates.top();
			mStates.pop();
			break;
		}
	}
}