#pragma once

#include "InputAction.hpp"

#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>

class InputManager
{
private:
	InputManager(/* args */);

	static std::map<InputAction, bool>	mActionMap;
	static std::map<int, InputAction>	mInputKeyMap;
	static std::map<int, InputAction>	mInputButtonMap;

	static void		HandleKeyPress(sf::Event	&tEvent);
	static void		HandleKeyRelease(sf::Event	&tEvent);

public:
	~InputManager();

	static void		LoadDefaultKeyBindings();

	static void		ResetActionStates();

	static void		HandleInput(sf::Event	&tEvent);

	static bool		IsActive(InputAction	tAction);

};
