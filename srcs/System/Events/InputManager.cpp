#include "InputManager.hpp"

std::map<InputAction, bool>	InputManager::mActionMap = std::map<InputAction, bool>();
std::map<int, InputAction>	InputManager::mInputKeyMap = std::map<int, InputAction>();
std::map<int, InputAction>	InputManager::mInputButtonMap = std::map<int, InputAction>();
sf::Keyboard::Key			InputManager::mLastPressedKey = sf::Keyboard::Unknown;

InputManager::InputManager(/* args */)
{

}

InputManager::~InputManager()
{
}

void		InputManager::LoadDefaultKeyBindings()
{
	mInputKeyMap[sf::Keyboard::D] = InputAction::MOVE_RIGHT;
	mInputKeyMap[sf::Keyboard::A] = InputAction::MOVE_LEFT;
	mInputKeyMap[sf::Keyboard::Space] = InputAction::ATTACK;
	mInputKeyMap[sf::Keyboard::W] = InputAction::JUMP;
}

int			InputManager::GetKeyBinding(InputAction tAction)
{
	auto res = std::find_if(std::begin(mInputKeyMap), std::end(mInputKeyMap), [&](const std::pair<int, InputAction> &pair)
	{
		return pair.second == tAction;
	});
	if (std::end(mInputKeyMap) == res)
		return (-1);
	return (res->first);
}

void		InputManager::HandleInput(sf::Event	&tEvent)
{
	switch (tEvent.type)
	{
	case sf::Event::KeyPressed:
		HandleKeyPress(tEvent);
		break;
	case sf::Event::KeyReleased:
		HandleKeyRelease(tEvent);
		break;
	default:
		break;
	}
}

void		InputManager::ResetActionStates()
{
	for (auto &state : mActionMap)
		state.second = false;
}


void		InputManager::HandleKeyPress(sf::Event	&tEvent)
{
	sf::Keyboard::Key	key;
	InputAction			action;
	key = tEvent.key.code;
	if (mInputKeyMap.count(key))
	{
		action = mInputKeyMap[key];
		mActionMap[action] = true;
	}
	
}

void		InputManager::HandleKeyRelease(sf::Event	&tEvent)
{
	sf::Keyboard::Key	key;
	InputAction			action;
	key = tEvent.key.code;
	if (mInputKeyMap.count(key))
	{
		action = mInputKeyMap[key];
		mActionMap[action] = false;
	}
}

bool		InputManager::IsActive(InputAction	tAction)
{
	return ((mActionMap.count(tAction)) ? mActionMap[tAction] : false);
}
