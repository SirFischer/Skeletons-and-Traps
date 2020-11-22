#pragma once

#include "Widget.hpp"

namespace mf
{
    class Button : public Widget
    {
    private:
        Button(/* args */);
        ~Button();

        /**
		 * Components
		 **/
		component::Background  	mBackground;
		component::EventManager	mEventManager;
		component::Text			mText;

    public:
		void				HandleEvent(sf::Event &tEvent);
		void				Render(sf::RenderWindow *tWindow);

        /**
		 * Create
		 **/
        static Button      *Create(std::string tPathIdle, std::string tPathHover);
        static Button      *Create(sf::Color tIdle, sf::Color tHover);

		/**
		 * Setters
		 **/
		Button				*SetClickEvent(std::function<void()> tListener);

		//Text
		Button				*SetText(std::string tText);
		Button				*SetTextFont(std::string tPath);
		Button				*SetTextFont(sf::Font tFont);
		Button				*SetTextPosition(sf::Vector2f tPos);
		Button				*SetTextColor(sf::Color tColor);

		//Background
		Button				*SetOutlineThickness(float tThickness);
		Button				*SetOutlineColor(sf::Color tColor);

		/**
		 * Overides
		 **/
		Button				*SetPosition(sf::Vector2f tPos){Widget::SetPosition(tPos); return (this);}
		Button				*SetPosition(float tX, float tY){Widget::SetPosition(tX, tY); return (this);}
		Button				*SetSize(sf::Vector2f tSize){Widget::SetSize(tSize); return (this);}
		Button				*SetSize(float tX, float tY){Widget::SetSize(tX, tY); return (this);}
		Button				*SetSizePercentage(bool tPercentage) { Widget::SetSizePercentage(tPercentage); return (this);}
		Button				*SetPositionPercentage(bool tPercentage) { Widget::SetPositionPercentage(tPercentage); return (this);}
        
    };
} // namespace mf
