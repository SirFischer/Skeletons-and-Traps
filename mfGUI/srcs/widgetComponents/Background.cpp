#include "Background.hpp"

namespace mf
{
	namespace component
	{
		Background::Background(sf::Vector2f *tPos,sf::Vector2f *tSize)
		:mPos(tPos)
		,mSize(tSize)
		{

		}
		
		Background::~Background()
		{
		}

		void            Background::SetBackground(sf::RectangleShape *tBackground)
		{
			if (!tBackground)
				return ;
			mBackground = *tBackground;
		}

		void            Background::SetBackground(sf::Color tColor)
		{
			mBackground.setFillColor(tColor);
			mBackground.setPosition(*mPos);
		}

		void			Background::SetBackground(sf::Texture tTexture)
		{
			mTexture = tTexture;
			SetBackground(sf::Color::White);
			mBackground.setTexture(&mTexture);
		}

		void            Background::SetBackground(std::string tPath)
		{
			mTexture.loadFromFile(tPath);
			SetBackground(sf::Color::White);
			mBackground.setTexture(&mTexture);
		}

		void			Background::SetOutlineColor(sf::Color tColor)
		{
			mBackground.setOutlineColor(tColor);
		}

		void			Background::SetOutlineThickness(float tThickness)
		{
			mBackground.setOutlineThickness(tThickness);
		}


		void            Background::Draw(sf::RenderWindow *tWindow)
		{
			if (mBackground.getPosition() != *mPos)
				mBackground.setPosition(*mPos);
			if (mBackground.getSize() != *mSize)
				mBackground.setSize(*mSize);
			tWindow->draw(mBackground);
		}
	} // namespace component 
} // namespace mf
