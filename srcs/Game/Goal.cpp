#include "Goal.hpp"

Goal::Goal()
{

	if (!mTexture.loadFromFile("assets/Textures/flag.png"))
	{
		/* code */
	}
	
	mSprite.setTexture(mTexture);
	mSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mGoalPosition = sf::Vector2f(5750, 800);
	mSprite.setPosition(mGoalPosition);

}

Goal::~Goal()
{
}

void	Goal::GoalTrigger()
{
	/*sf::Vector2f mPlayerPosition = mPlayer.GetEntity()->GetPosition();
	sf::Vector2f mGoalPosition = mSprite.getPosition();
*/
	/**/
}

void	Goal::Draw(Window *tWindow)
{
	tWindow->Draw(mSprite);
}

