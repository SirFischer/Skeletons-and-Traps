#include "Text.hpp"

namespace mf
{
	namespace component
	{
		Text::Text(sf::Vector2f *tPos,sf::Vector2f *tSize)
		:mPos(tPos)
		,mSize(tSize)
		{

		}
		
		Text::~Text()
		{
		}

		void			Text::LoadFont(std::string tPath)
		{
			mFont.loadFromFile(tPath);
			mText.setFont(mFont);
		}

		void			Text::LoadFont(sf::Font tFont)
		{
			mFont = tFont;
			mText.setFont(mFont);
		}

		void			Text::SetSize(unsigned int tSize)
		{
			mText.setCharacterSize(tSize);
		}

		void			Text::SetPos(sf::Vector2f tPos)
		{
			mRelPos = tPos;
		}

		void			Text::SetColor(sf::Color tColor)
		{
			mText.setFillColor(tColor);
		}

		void			Text::Draw(sf::RenderWindow *tWindow)
		{
			if (*mSize != mLastSize)
			{
				mLastSize = *mSize;
				ReformatString();
			}
			mText.setPosition(*mPos + mRelPos);
			tWindow->draw(mText);
		}

		void			Text::ReformatString()
		{
			mText.setString(FormatText(mString));
		}

		std::string			Text::FormatText(std::string tString)
		{
			std::string		res = tString;
			unsigned int	start = 0;
			unsigned int	maxCharPerLine = (mSize->x / ((float)mText.getCharacterSize())) * 2.f;

			while (start < res.size())
			{
				std::size_t stopPos = res.find_first_of('\n', start) - start;
				if (stopPos == std::string::npos)
					stopPos = 0;
				if (stopPos && stopPos < maxCharPerLine)
				{
					start += stopPos + 1;
					continue;
				}
				if (start + maxCharPerLine < res.size())
				{
					stopPos = res.rfind(' ', start + maxCharPerLine);
					if (stopPos != std::string::npos && stopPos > 0 && stopPos > start)
					{
						res.insert(stopPos + 1, "\n");
						start += 1;
					}
					else
					{
						res.insert(start + maxCharPerLine, "-\n");
						start += 2;
					}
				}	
				start += maxCharPerLine;
			}
			return (res);
		}
		
		void			Text::SetString(std::string tString)
		{
			mString = tString;
			mText.setString(FormatText(tString));
		}

		void			Text::AddString(std::string tString)
		{
			mString += tString;
			std::string	lineStart = mText.getString().toAnsiString();
			size_t	lineStartPos = lineStart.rfind('\n');
			if (lineStartPos == std::string::npos)
				lineStartPos = 0;
			std::string newString = lineStart.substr(lineStartPos) + tString;
			newString = FormatText(newString);
			lineStart.replace(lineStartPos, lineStart.size() - lineStartPos, newString);
			mText.setString(lineStart);
		}

		void			Text::DeleteString(size_t tNum)
		{
			if (tNum <= mString.size())
			{
				mString.erase(mString.size() - tNum, tNum);
				ReformatString();
			}
			else
			{
				mString = "";
				mText.setString("");
			}
				
			
		}

		void			Text::ResetString()
		{
			mString = "";
			mText.setString("");
		}

	} // namespace component 
} // namespace mf
