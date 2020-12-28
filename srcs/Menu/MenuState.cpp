#include "MenuState.hpp"

MenuState::MenuState(Window *tWindow)
:mMap("assets/Map/menu.txt")
{
	mWindow = tWindow;
}

MenuState::~MenuState()
{
}

void		MenuState::Init(StateInformations &tStateInformations)
{
	(void)tStateInformations;
	mWindow->SetDefaultView();
	mf::GUI::ClearWidgets();
	InputManager::ResetActionStates();
	mIsActive = true;
	mStateReturnAction = StateAction::POP;
	mWindow->ShowCursor();
	mEntities.clear();
	mPlayer.GetEntity()->Reset();
	mMap.SpawnEntities(&mEntities);
	mMap.SpawnPlayer(&mPlayer);

	mBackground.setTexture(*ResourceManager::LoadTexture("assets/Textures/Nature Background Raw.png"));
	mBackground.setScale(1.3, 1.3);

	
	/**
	 * INIT STATE AND GUI
	 **/

	StateAction	*actionReturn = &mStateReturnAction;
	bool		*active = &mIsActive;
	/**
	 * Button coloring/text/state return
	 **/

	mPlayBtn = mf::Button::Create(sf::Color::Green, sf::Color::Cyan);
	mPlayBtn->SetSize(150, 50);
	mPlayBtn->SetPositionPercentage(true)->SetPosition(45, 35);
	mPlayBtn->SetClickEvent([actionReturn, active] {
		*actionReturn = StateAction::GAME;
		*active = false;
	});

	mOptionBtn = mf::Button::Create(sf::Color::Blue, sf::Color::Cyan);
	mOptionBtn->SetSize(150, 50);
	mOptionBtn->SetPositionPercentage(true)->SetPosition(45, 45);
	mOptionBtn->SetClickEvent([actionReturn, active] {
		*actionReturn = StateAction::OPTIONS;
		*active = false;
	});

	mQuitBtn = mf::Button::Create(sf::Color::Red, sf::Color::Yellow);
	mQuitBtn->SetSize(150, 50);
	mQuitBtn->SetPositionPercentage(true)->SetPosition(45, 55);
	mQuitBtn->SetClickEvent([actionReturn, active] {
		*actionReturn = StateAction::POP;
		*active = false;
	});
	mPlayBtn->SetTextFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
	mPlayBtn->SetTextColor(sf::Color::Black);
	mPlayBtn->SetTextPosition(sf::Vector2f(45, 5));
	mPlayBtn->SetText("Play!");

	mOptionBtn->SetTextFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
	mOptionBtn->SetTextColor(sf::Color::Black);
	mOptionBtn->SetTextPosition(sf::Vector2f(20, 5));
	mOptionBtn->SetText("Options");
	
	mQuitBtn->SetTextFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
	mQuitBtn->SetTextColor(sf::Color::Black);
	mQuitBtn->SetTextPosition(sf::Vector2f(45, 5));
	mQuitBtn->SetText("Quit!");


	mf::GUI::AddWidget(mPlayBtn);
	mf::GUI::AddWidget(mOptionBtn);
	mf::GUI::AddWidget(mQuitBtn);


	if (mIsActive == true)
	{
		mMusic.Play(Music::MenuTheme);
	}
}

void		MenuState::HandleEvents()
{
	sf::Event event;
	while (mWindow->HandleEvent(event))
	{
		mf::GUI::HandleEvent(event);
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
		{
			mIsActive = false;
		}
	}
}

void		MenuState::Update()
{
	mMap.HandleCollisions(mPlayer.GetEntity(), &mParticleEffects);
	mWindow->mView.setCenter(sf::Vector2f(500, 500));
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
		mMap.HandleCollisions(entity, &mParticleEffects);
		if (entity->GetHealth() > 0)
		AI::ProcessEntity(&mPlayer, entity, &mParticleEffects, NULL);
		entity->Update();
	}
	//mWindow->mView.setCenter(mPlayer.GetEntity()->GetPosition());


	if (mIsActive == false)
	{
		mMusic.Stop();
		mSound.StopSound();
	}


	
}

void		MenuState::Render()
{
	mWindow->Clear(sf::Color(135,206,235));
	mWindow->SetDefaultView();
	mWindow->Draw(mBackground);
	mPlayer.Render(mWindow);
	for (auto &entity : mEntities)
		entity->Render(mWindow);
	for (auto &particleEffect : mParticleEffects)
		particleEffect.Render(mWindow);
	mMap.Draw(mWindow);
	mf::GUI::Render();
	mWindow->Render();
}