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
    mWinText.setFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
    mWinText.setPosition(714, 100);
	mWinText.setCharacterSize(40);
    mWinText.setFillColor(sf::Color::Yellow);
    mWinText.setString("You Won!");

	mScoreText.setFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
    mScoreText.setPosition(714, 300);
	mScoreText.setCharacterSize(30);
    mScoreText.setFillColor(sf::Color::White);
    mScoreText.setString("Score: " + std::to_string(tStateInformations.mScore));

	/**
	 * INIT STATE AND GUI
	 **/

    StateAction	*actionReturn = &mStateReturnAction;
	bool		*active = &mIsActive;

    mQuitBtn = mf::Button::Create("assets/Textures/exit.png", "assets/Textures/exit.png");
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
    mWindow->Draw(mWinText);
    mWindow->Draw(mScoreText);
    mWindow->Render();
}