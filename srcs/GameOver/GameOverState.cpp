#include "GameOverState.hpp"

GameOverState::GameOverState(Window *tWindow)
{
	mWindow = tWindow;
}

GameOverState::~GameOverState()
{
}

void		GameOverState::Init(StateInformations &tStateInformations)
{
	(void)tStateInformations;
    mWindow->SetDefaultView();
	mf::GUI::ClearWidgets();
	mIsActive = true;
	mStateReturnAction = StateAction::POP;
	mWindow->ShowCursor();

    //Text 
    mScoreText.setFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
    mScoreText.setOrigin(-714, -50);
    mScoreText.setFillColor(sf::Color::Red);
    mScoreText.setString("GAME OVER");

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
void		GameOverState::HandleEvents()
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
void		GameOverState::Update()
{

}
void		GameOverState::Render()
{
	mWindow->Clear(sf::Color::Black);
	mf::GUI::Render();
    mWindow->Draw(mScoreText);
    mWindow->Render();
}