//
// EPITECH PROJECT, 2018
// event
// File description:
// 
//

#include "Bomberman.hpp"
#include "EventMenu.hpp"

MyEventReceiver::MyEventReceiver(t_env	&my_env, irr::s32 &pos) :
	_my_env(my_env), _pos(pos)
{}

bool				MyEventReceiver::OnEvent(const irr::SEvent &event)
{
	irr::s32		id;

	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		_KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
	if (event.EventType == irr::EET_GUI_EVENT)
	{
		id = event.GUIEvent.Caller->getID();
		switch (event.GUIEvent.EventType)
		{
		case irr::gui::EGET_BUTTON_CLICKED:
			playSound(_my_env, 1);
			switch (id) {
			case PLAY:
				_my_env.pMenu = PLAY;
				return true;
			case PLAY2:
				_my_env.pMenu = PLAY2;
				return true;
			case OPTION:
				_my_env.pMenu = OPTION;
				return true;
			case HELP:
				_my_env.pMenu = HELP;
				return true;
			case MENU:
				_my_env.pMenu = MENU;
				return true;
			case QUIT:
				_my_env.device->closeDevice();
				return true;
			default:
				_my_env.pMenu = MENU;
				return false;
			}
		case irr::gui::EGET_SCROLL_BAR_CHANGED:
			if (id == DENSITY_SCROLLBAR)
				setDensityBar(event, _my_env);
			if (id == DENSITY_SHADERSBAR)
				setShadersBar(event, _my_env);
			break;
		default:
			return false;
		}
	}
	return false;
}

bool	MyEventReceiver::isKeyDown(irr::EKEY_CODE keyCode)
{
	return _KeyIsDown[keyCode];
}

bool	MyEventReceiver::isKeyPressed(irr::EKEY_CODE keyCode)
{
	return _KeyIsPressed[keyCode];
}
