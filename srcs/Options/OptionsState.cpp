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
	mFullscreenButton = mf::Button::Create(sf::Color::Yellow, sf::Color::Red);
	Window	*window = mWindow;
	mFullscreenButton->SetClickEvent([window] {
		window->ToggleFullscreen();
	});

	mf::GUI::AddWidget(mFullscreenButton);
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