#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

namespace mf
{
	namespace component
	{
		class Background
		{
		protected:
			sf::RectangleShape     					mBackground;
			sf::Texture                             mTexture;

			sf::Vector2f                            *mPos = NULL;
			sf::Vector2f                            *mSize = NULL;
			
		public:
			Background(sf::Vector2f *tPos,sf::Vector2f *tSize);
			~Background();

			void            SetBackground(sf::RectangleShape *tBackground);
			void			SetBackground(sf::Texture tTexture);
			void            SetBackground(sf::Color tColor);
			void            SetBackground(std::string tPath);

			void			SetOutlineColor(sf::Color tColor);
			void			SetOutlineThickness(float tThickness);

			void            Draw(sf::RenderWindow *tWindow);
		};
	}
} // namespace mf
