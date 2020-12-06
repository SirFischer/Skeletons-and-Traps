#include "GameState.hpp"

GameState::GameState(Window *tWindow)
:mMap("assets/Map/map.txt")
{
	mWindow = tWindow;
	mWindow->HideCursor();
	mMap.SpawnEntities(&mEntities);
}

GameState::~GameState()
{
	mWindow->ShowCursor();
}

void		GameState::Init()
{
	mf::GUI::ClearWidgets();
	mIsActive = true;
	mStateReturnAction = StateAction::POP;
	/**
	 * INIT STATE AND GUI
	 **/
}

void		GameState::HandleEvents()
{
	sf::Event event;
	while (mWindow->HandleEvent(event))
	{
		mf::GUI::HandleEvent(event);
		InputManager::HandleInput(event);
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
		{
			mIsActive = false;
		}
	}
}

void		GameState::Update()
{
	mMap.HandleCollisions(mPlayer.GetEntity());
	mWindow->mView.setCenter(mPlayer.GetEntity()->GetPosition());
	mPlayer.Update(mEntities);
	for (auto &entity : mEntities)
	{
		mMap.HandleCollisions(entity);
		if (entity->GetHealth() > 0)
			AI::ProcessEntity(&mPlayer, entity);
		entity->Update();
	}
	for (auto &entity : mEntities)
	{
		if (entity->IsAlive() == false)
		{
			delete entity;
			mEntities.remove(entity);
			break;
		}
	}
}

void		GameState::Render()
{
	mWindow->Clear();
	mWindow->View();
	mMap.Draw(mWindow);
	mPlayer.Render(mWindow);
	for (auto &entity : mEntities)
		entity->Render(mWindow);
	mf::GUI::Render();
	mWindow->Render();
}