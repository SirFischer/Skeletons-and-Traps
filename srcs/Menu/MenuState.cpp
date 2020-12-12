#include "MenuState.hpp"

MenuState::MenuState(Window *tWindow)
:mMap("assets/Map/menu.txt")
{
	mWindow = tWindow;
}

MenuState::~MenuState()
{
}

void		MenuState::Init()
{
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
		mMap.HandleCollisions(entity, &mParticleEffects);
		if (entity->GetHealth() > 0)
		AI::ProcessEntity(&mPlayer, entity, &mParticleEffects);
		entity->Update();
	}
	mWindow->mView.setCenter(mPlayer.GetEntity()->GetPosition());
}

void		MenuState::Render()
{
	mWindow->Clear(sf::Color(135,206,235));
	mPlayer.Render(mWindow);
	for (auto &entity : mEntities)
		entity->Render(mWindow);
	for (auto &particleEffect : mParticleEffects)
		particleEffect.Render(mWindow);
	mMap.Draw(mWindow);
	mf::GUI::Render();
	mWindow->Render();
}