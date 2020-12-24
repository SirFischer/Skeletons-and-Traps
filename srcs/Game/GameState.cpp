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

	mCameraPosition = mMap.GetGoalPosition();


	/**
	 * INIT STATE AND GUI
	 **/

	mHPText = mf::Text::Create("assets/fonts/PressStart2P-Regular.ttf", "HP: 100");
	mHPText->SetPositionPercentage(true)
	->SetPosition(90, 95)
	->SetTextColor(sf::Color::White)
	->SetBackgroundColor(sf::Color::Transparent)
	->SetTextFontSize(20);
	mf::GUI::AddWidget(mHPText);
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
	mMap.HandleCollisions(mPlayer.GetEntity(), &mParticleEffects);
	UpdateCameraPosition();
	mHPText->SetText("HP: " + std::to_string((int)mPlayer.GetEntity()->GetHealth()));
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
	for (auto &projectile : mProjectiles)
	{
		projectile.Update();
		mMap.HandleProjectileCollision(&projectile);
		if (!projectile.IsActive())
		{
			mProjectiles.remove(projectile);
			break;
		}
			
	}

	for (auto &entity : mEntities)
	{
		mMap.HandleCollisions(entity, &mParticleEffects);
		entity->HandleCollisions(mEntities);
		if (entity->GetHealth() > 0)
			AI::ProcessEntity(&mPlayer, entity, &mParticleEffects, &mProjectiles);
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
	if (mParticleEffects.size() > 20)
		mParticleEffects.pop_front();
	if (mMap.GetGoalStatus(mPlayer.GetEntity()))
	{
		mIsActive = false;
		mStateReturnAction = StateAction::POP;
	}
	if (mPlayer.GetEntity()->GetHealth() > 0)
	{
		mTimer.restart();
	}
	
	if(mPlayer.GetEntity()->IsAlive() == false || mPlayer.GetEntity()->GetHealth() <= 0)
	{
		if (mTimer.getElapsedTime().asSeconds() > 6.0)
		{
			mIsActive = false;
			mStateReturnAction = StateAction::GameOverState;
		}
			
	}
}

void		GameState::Render()
{
	mWindow->Clear(sf::Color(135,206,235));

	mWindow->View();
	mMap.Draw(mWindow);
	mPlayer.Render(mWindow);
	for (auto &projectile : mProjectiles)
		projectile.Render(mWindow);
	for (auto &entity : mEntities)
		entity->Render(mWindow);
	for (auto &particleEffect : mParticleEffects)
		particleEffect.Render(mWindow);
	mWindow->SetDefaultView();
	mf::GUI::Render();
	mWindow->Render();
}


void		GameState::UpdateCameraPosition()
{
	float cameraSpeed = 1.0f;
	
	if (mPlayer.GetEntity()->GetPosition().x > mCameraPosition.x + 100.f)
		mCameraPosition.x = mPlayer.GetEntity()->GetPosition().x - 100.f;
	if (mPlayer.GetEntity()->GetPosition().x < mCameraPosition.x - 100.f)
		mCameraPosition.x = mPlayer.GetEntity()->GetPosition().x + 100.f;
	if (mPlayer.GetEntity()->GetPosition().y > mCameraPosition.y + 100.f)
		mCameraVelocity.y += cameraSpeed;
	if (mPlayer.GetEntity()->GetPosition().y < mCameraPosition.y - 100.f)
		mCameraVelocity.y -= cameraSpeed;
	mCameraPosition += mCameraVelocity;
	mCameraVelocity.y *= 0.90;
	mCameraVelocity.x *= 0.90;
	mWindow->mView.setCenter(mCameraPosition);
}
