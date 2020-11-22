#pragma once

#include <SFML/Graphics.hpp>
#include "utils/Events.hpp"

#include "widgetComponents/Background.hpp"
#include "widgetComponents/EventManager.hpp"
#include "widgetComponents/Text.hpp"

namespace mf
{
	class Widget
	{
	protected:
		Widget(/* args */);
		virtual ~Widget();

		//Absolute position
		sf::Vector2f	mPos = sf::Vector2f(0, 0);
		//Position relative to parent
		sf::Vector2f	mRelativePos = sf::Vector2f(0, 0);

		//Absolue size
		sf::Vector2f	mSize = sf::Vector2f(100, 100);
		//Size Relative to parent
		sf::Vector2f	mRelativeSize = sf::Vector2f(0, 0);

		bool			mSizePercentage = false;
		bool			mPositionPercentage = false;

		Widget					*mParent = NULL;
		std::vector<Widget *>	mWidgets = std::vector<Widget *>();

		int				mIndex;

		virtual void	Render(sf::RenderWindow *tWindow);
		virtual void	HandleEvent(sf::Event &tEvent);

		virtual void	Init();

	public:
		friend class	GUI;

		static Widget 	*Create();
		Widget			*AddWidget(Widget *tWidget);
		void			RemoveWidget(Widget *tWidget);
		void			ClearWidgets();

		/**
		 * Setters
		 **/
		Widget			*SetPosition(sf::Vector2f tPos);
		Widget			*SetPosition(float tX, float tY);
		Widget			*SetPositionPercentage(bool tPercentage);
		Widget			*SetSize(float tX, float tY);
		Widget			*SetSize(sf::Vector2f tSize);
		Widget			*SetSizePercentage(bool tPercentage);

		/**
		 * Getters
		 **/

	};
	
} // namespace mf
