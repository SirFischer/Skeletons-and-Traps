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

	mHighScore.setFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
    mHighScore.setPosition(714, 350);
	mHighScore.setCharacterSize(30);
    mHighScore.setFillColor(sf::Color::White);
    mHighScore.setString("Highscore: " + std::to_string(tStateInformations.mScore));

	/**
	 * INIT STATE AND GUI
	 **/

    StateAction	*actionReturn = &mStateReturnAction;
	bool		*active = &mIsActive;

	mVictoryBtn = mf::Button::Create("assets/Textures/victory.png", "assets/Textures/victory.png");
	mVictoryBtn->SetSize(64, 64);
	mVictoryBtn->SetPositionPercentage(true)->SetPosition(47.8, 47);

    mQuitBtn = mf::Button::Create("assets/Textures/exit.png", "assets/Textures/buttonHL.png");
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
	mf::GUI::AddWidget(mVictoryBtn);

	//HIGHSCORE
	std::fstream	stream;
	std::string		scoreString;
	stream.open("assets/Highscore.score", std::fstream::in);
	stream >> scoreString;
	mHighScore.setString("Highscore: " + scoreString);
	stream.close();
	if (tStateInformations.mScore > std::stoi(scoreString))
	{
		mHighScore.setString("Highscore: " + std::to_string(tStateInformations.mScore));
		stream.open("assets/Highscore.score", std::fstream::out);
		stream << std::to_string(tStateInformations.mScore) << std::endl;
		mWinText.setString("You Won!\n New highscore!");
		stream.close();
	}
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
    mWindow->Draw(mHighScore);
    mWindow->Draw(mScoreText);
    mWindow->Render();
}