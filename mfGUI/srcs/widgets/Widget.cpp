#include "Widget.hpp"

namespace mf
{

Widget::Widget()
{

}

Widget::~Widget()
{

}

Widget      *Widget::Create()
{
    return (new Widget());
}

void        Widget::HandleEvent(sf::Event &tEvent)
{
    //handle event for current widget
    for (auto i : mWidgets)
        i->HandleEvent(tEvent);
}

void		Widget::Render(sf::RenderWindow *tWindow)
{
    for (auto &i : mWidgets)
        i->Render(tWindow);
}

void		Widget::Init()
{
	this->SetPosition(mRelativePos);
	this->SetSize(mRelativeSize);
}


Widget			*Widget::AddWidget(Widget *tWidget)
{
    tWidget->mParent = this;
    tWidget->SetPosition(tWidget->mRelativePos);
    mWidgets.push_back(tWidget);
	tWidget->Init();
    return (this);
}

void			Widget::RemoveWidget(Widget *tWidget)
{
	std::vector<mf::Widget *>::iterator it;
    if ((it = std::find(mWidgets.begin(), mWidgets.end(), tWidget)) != mWidgets.end())
	{
		(*it)->ClearWidgets();
		mWidgets.erase(it);
	}
}

void        Widget::ClearWidgets()
{
    while (mWidgets.size())
    {
        mWidgets.back()->ClearWidgets();
        delete mWidgets.back();
        mWidgets.pop_back();
		
    }
}

Widget			*Widget::SetPosition(sf::Vector2f tPos)
{
	if (mPositionPercentage && mParent)
		mPos = sf::Vector2f(mParent->mSize.x * (tPos.x / 100.f), mParent->mSize.y * (tPos.y / 100.f));
	else
		mPos = tPos;
	if (mParent)
    	mPos += mParent->mPos;
    mRelativePos = tPos;
    return (this);
}

Widget			*Widget::SetPosition(float tX, float tY)
{
    this->SetPosition(sf::Vector2f(tX, tY));
    return (this);
}

Widget			*Widget::SetPositionPercentage(bool tPercentage)
{
	mPositionPercentage = tPercentage;
	this->SetPosition(mPos);
	return (this);
}


Widget			*Widget::SetSize(float tX, float tY)
{
    this->SetSize(sf::Vector2f(tX, tY));
    return (this);
}

Widget			*Widget::SetSize(sf::Vector2f tSize)
{
	if (mSizePercentage && mParent)
		mSize = sf::Vector2f(mParent->mSize.x * (tSize.x / 100.f), mParent->mSize.y * (tSize.y / 100.f));
	else
    	mSize = tSize;
	mRelativeSize = tSize;
    return (this);
}

Widget			*Widget::SetSizePercentage(bool tPercentage)
{
	mSizePercentage = tPercentage;
	this->SetSize(mRelativeSize);
	return (this);
}
    
} // namespace mf
