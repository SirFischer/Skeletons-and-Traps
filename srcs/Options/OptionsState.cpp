#include "OptionsState.hpp"

OptionsState::OptionsState(Window *tWindow)
{
	mWindow = tWindow;
}

OptionsState::~OptionsState()
{
}

void		OptionsState::Init(StateInformations &tStateInformations)
{
	(void)tStateInformations;
	mf::GUI::ClearWidgets();
	mIsActive = true;
	mStateReturnAction = StateAction::POP;
	mWindow->ShowCursor();

	/**
	 * INIT STATE AND GUI
	 **/
	StateAction	*actionReturn = &mStateReturnAction;
	bool		*active = &mIsActive;

	/**
	 * Button coloring/text/state return/ volume slider
	 **/
	mQuitButton = mf::Button::Create(sf::Color::Red, sf::Color::Cyan);
	mQuitButton->SetSize(150, 50);
	mQuitButton->SetPositionPercentage(true)->SetPosition(45, 60);
	mQuitButton->SetTextFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
	mQuitButton->SetTextColor(sf::Color::Black);
	mQuitButton->SetTextPosition(sf::Vector2f(43, 5));
	mQuitButton->SetText("Back");
	mQuitButton->SetClickEvent([actionReturn, active] {
		*actionReturn = StateAction::POP;
		*active = false;
	});
	mf::GUI::AddWidget(mQuitButton);

	// mAttackKey = mf::Button::Create(sf::Color(15, 15, 15, 255), sf::Color(155, 155, 155, 255));
	// mAttackKey->SetPositionPercentage(true)->SetPosition(10, 30);
	// mAttackKey->SetTextFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
	// mAttackKey->SetText(std::to_string(InputManager::GetKeyBinding(InputAction::ATTACK)));
	//mf::GUI::AddWidget(mAttackKey);
}

void		OptionsState::HandleEvents()
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

void		OptionsState::Update()
{
	
}

void		OptionsState::Render()
{
	mWindow->Clear(sf::Color::Black);
	
	mf::GUI::Render();
	mWindow->Render();
}