#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

namespace mf
{
	namespace component
	{
		class Text
		{
		protected:
			sf::Vector2f		*mPos = NULL;
			sf::Vector2f		*mSize = NULL;

			sf::Vector2f		mLastSize = sf::Vector2f(0, 0);

			sf::Vector2f		mRelPos = sf::Vector2f(0.f, 0.f);

			sf::Font			mFont;
			sf::Text			mText;

			std::string			mString;

			
			
		public:
			Text(sf::Vector2f *tPos,sf::Vector2f *tSize);
			~Text();

			void			LoadFont(std::string tPath);
			void			LoadFont(sf::Font tFont);

			void			SetSize(unsigned int tSize);
			void			SetPos(sf::Vector2f tPos);
			void			SetColor(sf::Color tColor);

			void			ReformatString();
			std::string		FormatText(std::string tString);
			void			SetString(std::string tString);
			void			AddString(std::string tString);
			void			DeleteString(size_t tNum);
			void			ResetString();

			std::string		GetString() {return (mString);}

			void            Draw(sf::RenderWindow *tWindow);
		};
	}
} // namespace mf
