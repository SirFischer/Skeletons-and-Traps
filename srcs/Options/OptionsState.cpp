#include "OptionsState.hpp"

OptionsState::OptionsState(Window *tWindow)
{
	mWindow = tWindow;
}

OptionsState::~OptionsState()
{
}

void		OptionsState::Init()
{
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
	/* ERROR TOGGLEFULLSCREEN FUNCTION FAILS TO FIND VIDEO MODE AND RRMODE
	mFullscreenButton = mf::Button::Create(sf::Color::Yellow, sf::Color::Red);
	mFullscreenButton->SetSize(150, 50);
	mFullscreenButton->SetPositionPercentage(true)->SetPosition(45, 50);
	mFullscreenButton->SetTextFont(*ResourceManager::LoadFont("assets/fonts/Roboto-Regular.ttf"));
	mFullscreenButton->SetTextColor(sf::Color::Black);
	mFullscreenButton->SetTextPosition(sf::Vector2f(8, 5));
	mFullscreenButton->SetText("Fullscreen");
	Window	*window = mWindow;
	mFullscreenButton->SetClickEvent([window] {
		window->ToggleFullscreen();
	});
	*/

	/*
	Volume slider
	*/

	//mf::GUI::AddWidget(mFullscreenButton);
	mf::GUI::AddWidget(mQuitButton);
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