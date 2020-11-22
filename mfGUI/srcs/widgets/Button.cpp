#include "Button.hpp"

namespace mf
{

Button::Button()
:mBackground(&mPos, &mSize)
,mEventManager(&mPos, &mSize)
,mText(&mPos, &mSize)
{

}

Button::~Button()
{

}

void		Button::HandleEvent(sf::Event &tEvent)
{
	mEventManager.Update(tEvent);
	Widget::HandleEvent(tEvent);
}

void		Button::Render(sf::RenderWindow *tWindow)
{
	mBackground.Draw(tWindow);
	mText.Draw(tWindow);
	Widget::Render(tWindow);
}

Button      *Button::Create(std::string tPathIdle, std::string tPathHover)
{
    Button *btn = new Button();
    btn->mBackground.SetBackground(tPathIdle);
    btn->SetSize(sf::Vector2f(100, 50));
    btn->mEventManager.AddEventListener(eEvent::EXITED, [btn, tPathIdle] {
        btn->mBackground.SetBackground(tPathIdle);
    });
    btn->mEventManager.AddEventListener(eEvent::ENTERED, [btn, tPathHover] {
        btn->mBackground.SetBackground(tPathHover);
    });
    return (btn);
}

Button      *Button::Create(sf::Color tIdle, sf::Color tHover)
{
    Button *btn = new Button();
    btn->mBackground.SetBackground(tIdle);
    btn->SetSize(sf::Vector2f(100, 50));
	(void)tHover;
    btn->mEventManager.AddEventListener(eEvent::EXITED, [btn, tIdle] {
        btn->mBackground.SetBackground(tIdle);
    });
    btn->mEventManager.AddEventListener(eEvent::ENTERED, [btn, tHover] {
        btn->mBackground.SetBackground(tHover);
    });
    return (btn);
}

Button		*Button::SetClickEvent(std::function<void()> tListener)
{
	mEventManager.AddEventListener(eEvent::LEFT_CLICK, tListener);
	return (this);
}

Button		*Button::SetText(std::string tText)
{
	mText.SetString(tText);
	return (this);
}

Button		*Button::SetTextFont(std::string tPath)
{
	mText.LoadFont(tPath);
	return (this);
}

Button		*Button::SetTextFont(sf::Font tFont)
{
	mText.LoadFont(tFont);
	return (this);
}

Button		*Button::SetTextPosition(sf::Vector2f tPos)
{
	mText.SetPos(tPos);
	return (this);
}

Button		*Button::SetTextColor(sf::Color tColor)
{
	mText.SetColor(tColor);
	return (this);
}

Button		*Button::SetOutlineThickness(float tThickness)
{
	mBackground.SetOutlineThickness(tThickness);
	return (this);
}

Button		*Button::SetOutlineColor(sf::Color tColor)
{
	mBackground.SetOutlineColor(tColor);
	return (this);
}


} // namespace mf
