#include "WinState.hpp"

WinState::WinState(Window *tWindow)
{
	mWindow = tWindow;
}

WinState::~WinState()
{
}

void		WinState::Init(StateInformations &tStateInformations)
{
	(void)tStateInformations;
    mWindow->SetDefaultView();
	mf::GUI::ClearWidgets();
	mIsActive = true;
	mStateReturnAction = StateAction::POP;
	mWindow->ShowCursor();

    //Text 
    mScoreText.setFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
    mScoreText.setPosition(714, 100);
	mScoreText.setCharacterSize(40);
    mScoreText.setFillColor(sf::Color::Yellow);
    mScoreText.setString("You Won!");

	/**
	 * INIT STATE AND GUI
	 **/

    StateAction	*actionReturn = &mStateReturnAction;
	bool		*active = &mIsActive;

    mQuitBtn = mf::Button::Create(sf::Color::Red, sf::Color::Yellow);
	mQuitBtn->SetSize(150, 50);
	mQuitBtn->SetPositionPercentage(true)->SetPosition(45, 55);
	mQuitBtn->SetClickEvent([actionReturn, active] {
		*actionReturn = StateAction::POP;
		*active = false;
	});

    mQuitBtn->SetTextFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
	mQuitBtn->SetTextColor(sf::Color::Black);
	mQuitBtn->SetTextPosition(sf::Vector2f(45, 5));
	mQuitBtn->SetText("Quit!");

	mf::GUI::AddWidget(mQuitBtn);

}
void		WinState::HandleEvents()
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
void		WinState::Update()
{

}
void		WinState::Render()
{
	mWindow->Clear(sf::Color::Black);
	mf::GUI::Render();
    mWindow->Draw(mScoreText);
    mWindow->Render();
}