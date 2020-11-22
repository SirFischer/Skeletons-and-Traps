#pragma once

#include "widgets/Widget.hpp"
#include "widgets/Image.hpp"
#include "widgets/Button.hpp"
#include "widgets/Text.hpp"

namespace mf
{
	class GUI
	{
	private:
		GUI(/* args */);
		~GUI();
		static sf::RenderWindow		*mWindow;
		static Widget				*mBaseWidget;

	public:
		static void				Init(sf::RenderWindow *tWindow);
		static void				HandleEvent(sf::Event	&tEvent);
		static void				Render();

		static void				AddWidget(Widget *tWidget);
		static void				RemoveWidget(Widget *tWidget);
		static void				ClearWidgets();

	};
} // namespace mf
