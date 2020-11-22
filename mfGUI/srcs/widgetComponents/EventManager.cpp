#include "EventManager.hpp"

namespace mf
{
	namespace component
	{
		EventManager::EventManager(sf::Vector2f *tPos, sf::Vector2f *tSize)
		: mPos(tPos), mSize(tSize)
		{
		}

		EventManager::~EventManager()
		{
		}

		void EventManager::Update(sf::Event &tEvent)
		{
			sf::Vector2i pos = sf::Vector2i(tEvent.mouseMove.x, tEvent.mouseMove.y);
			bool inside = (pos.x > mPos->x && pos.y > mPos->y && pos.x < mPos->x + mSize->x && pos.y < mPos->y + mSize->y);
			switch (tEvent.type)
			{
			case sf::Event::MouseMoved:
				if (inside && mEvent == eEvent::OUTSIDE)
					mEvent = eEvent::ENTERED;
				else if (inside || mEvent == eEvent::ENTERED)
					mEvent = eEvent::INSIDE;
				else if (!inside && mEvent == eEvent::INSIDE)
					mEvent = eEvent::EXITED;
				else if (!inside || mEvent == eEvent::EXITED)
					mEvent = eEvent::OUTSIDE;
				break;

			case sf::Event::MouseButtonPressed:
				if (mEvent != eEvent::OUTSIDE && mEvent != eEvent::EXITED)
				{
					if (tEvent.mouseButton.button == sf::Mouse::Left)
						mEvent = eEvent::LEFT_CLICK;
					if (tEvent.mouseButton.button == sf::Mouse::Right)
						mEvent = eEvent::RIGHT_CLICK;
					mFocus = true;
					if (mKeyListeners[(uint32_t)eEvent::FOCUS])
						mKeyListeners[(uint32_t)eEvent::FOCUS]();
				}
				else
				{
					mFocus = false;
					if (mKeyListeners[(uint32_t)eEvent::LOST_FOCUS])
						mKeyListeners[(uint32_t)eEvent::LOST_FOCUS]();
				}
					
			break;

			case sf::Event::MouseButtonReleased:
				if (mEvent != eEvent::OUTSIDE && mEvent != eEvent::EXITED)
				{
					if (tEvent.mouseButton.button == sf::Mouse::Left)
						mEvent = eEvent::LEFT_CLICK_RELEASE;
					if (tEvent.mouseButton.button == sf::Mouse::Right)
						mEvent = eEvent::RIGHT_CLICK_RELEASE;
				}
			break;

			default:
				mEvent = (inside) ? eEvent::INSIDE : eEvent::OUTSIDE;
				break;
			}

			if (mPreviousEvent != mEvent && mKeyListeners[(uint32_t)mEvent])
			{
				mKeyListeners[(uint32_t)mEvent]();
				mPreviousEvent = mEvent;
			}

			if (tEvent.type == sf::Event::TextEntered)
				mCharInput = tEvent.text.unicode;
			else
				mCharInput = 0;
		}

		void EventManager::AddEventListener(eEvent tEvent ,std::function<void()> tListener)
		{
			mKeyListeners[(uint32_t)tEvent] = tListener;
		}

		void    EventManager::TriggerEvent(eEvent tEvent)
		{
			if (mKeyListeners[(uint32_t)tEvent])
				mKeyListeners[(uint32_t)tEvent]();
		}
	} // namespace component
	
	

} // namespace mf
