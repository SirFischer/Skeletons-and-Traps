#pragma once

#include "Widget.hpp"

namespace mf
{
	class Image : public Widget
	{
	private:
		Image(/* args */);
		~Image();

		/**
		 * Components
		 **/
		component::Background mBackground;

	public:
		void	Render(sf::RenderWindow	*tWindow);

		/**
		 * Create
		 **/
		static Image *Create(std::string tPath);

		/**
		 * Setters
		 **/
		void	SetImage(std::string tPath);
		void	SetImage(sf::Texture &tTexture);

		Image	*SetOutlineThickness(float tThickness);
		Image	*SetOutlineColor(sf::Color tColor);

		/**
		 * Overides
		 **/
		Image			*SetPosition(sf::Vector2f tPos){Widget::SetPosition(tPos); return (this);}
		Image			*SetPosition(float tX, float tY){Widget::SetPosition(tX, tY); return (this);}
		Image			*SetSize(sf::Vector2f tSize){Widget::SetSize(tSize); return (this);}
		Image			*SetSize(float tX, float tY){Widget::SetSize(tX, tY); return (this);}
		Image			*SetSizePercentage(bool tPercentage) { Widget::SetSizePercentage(tPercentage); return (this);}
		Image			*SetPositionPercentage(bool tPercentage) { Widget::SetPositionPercentage(tPercentage); return (this);}
	};
} // namespace mf
