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
	StateInformations		informtations;
	
	while (mStates.size())
	{
		mStates.top()->Init(informtations);
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

		case StateAction::OPTIONS:
			mStates.push(new OptionsState(mWindow));
			break;

		case StateAction::GameOverState:
			delete mStates.top();
			mStates.pop();
			mStates.push(new GameOverState(mWindow));
			break;

		case StateAction::WIN:
			delete mStates.top();
			mStates.pop();
			mStates.push(new WinState(mWindow));
			break;

		default:
			delete mStates.top();
			mStates.pop();
			break;
		}
		
	}
}