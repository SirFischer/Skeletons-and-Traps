#include "GameState.hpp"

GameState::GameState(Window *tWindow)
:mMap("assets/Map/map.txt")
{
	mWindow = tWindow;
	mWindow->HideCursor();
	mMap.SpawnEntities(&mEntities);
	mMap.SpawnPlayer(&mPlayer);
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

	InputManager::ResetActionStates();

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
	mPlayer.Update(mEntities, &mParticleEffects);
	for (auto &particleEffect : mParticleEffects)
	{
		particleEffect.Update();
		mMap.HandleParticleCollisions(&particleEffect);
		if (!particleEffect.IsActive())
		{
			mParticleEffects.remove(particleEffect);
			break;
		}
			
	}
	for (auto &entity : mEntities)
	{
		mMap.HandleCollisions(entity);
		if (entity->GetHealth() > 0)
			AI::ProcessEntity(&mPlayer, entity, &mParticleEffects);
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

	if (mMap.GetGoalStatus() == true)
	{
		mIsActive = false;
		mStateReturnAction = StateAction::POP;
	}
}

void		GameState::Render()
{
	mWindow->Clear(sf::Color(135,206,235));
	mWindow->View();
	mMap.Draw(mWindow);
	mPlayer.Render(mWindow);
	for (auto &entity : mEntities)
		entity->Render(mWindow);
	for (auto &particleEffect : mParticleEffects)
		particleEffect.Render(mWindow);
	mf::GUI::Render();
	mWindow->Render();
}