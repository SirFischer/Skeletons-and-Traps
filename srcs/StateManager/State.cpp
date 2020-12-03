#include "State.hpp"

StateAction			State::Run()
{
	sf::Time		mElapsedTime = sf::seconds(0);
	sf::Clock		mClock;

	int i = 0;
	sf::Clock		mFpsClock;

	while (mIsActive)
	{
		while (mElapsedTime.asSeconds() > mDeltaTime.asSeconds())
		{
			HandleEvents();
			Update();
			mElapsedTime -= mDeltaTime;
		}
		Render();
		mElapsedTime += mClock.restart();
		i++;
		if (mFpsClock.getElapsedTime().asSeconds() > 1)
		{
			std::cout << "FPS: " << i << std::endl;
			mFpsClock.restart();
			i = 0;
		}
	}
	return (mStateReturnAction);
}