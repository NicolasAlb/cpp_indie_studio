//
// EPITECH PROJECT, 2018
// main
// File description:
// 
//

#include "Bomberman.hpp"
#include "EventMenu.hpp"
#include "Intro.hpp"



static void		handle_menu(t_env &my_env)
{
	switch (my_env.pMenu)
	{
	case MENU:
		if (my_env.has_menu_sound == false)
		{
			playSound(my_env, 2);
			my_env.has_menu_sound = true;
		}
		display_menu(my_env);
		break;
	case PLAY:
		playSound(my_env, 0);
		stopSound(my_env, 2);
		display_game(my_env, false);
		my_env.pMenu = MENU;
		break;
	case PLAY2:
		playSound(my_env, 0);
		stopSound(my_env, 2);
		display_game(my_env, true);
		my_env.pMenu = MENU;
		break;
	case OPTION:
		display_option(my_env);
		break;
	case HELP:
		display_help(my_env);
		break;
	case QUIT:
		my_env.device->drop();
	default:
		break;
	}
}

void				setDensityBar(const irr::SEvent &event, t_env &my_env)
{
	irr::s32		new_pos;

	new_pos = ((irr::gui::IGUIScrollBar *)event.GUIEvent.Caller)->getPos();
	my_env.density = (int)new_pos / 10;
}

void				setShadersBar(const irr::SEvent &event, t_env &my_env)
{
	irr::s32		new_pos;

	if (my_env.shaders == true)
	{
		new_pos = ((irr::gui::IGUIScrollBar *)event.GUIEvent.Caller)->getPos();
		my_env.shaders = (int)new_pos / 10;
		my_env.shaders = false;
	}
	else
	{
		new_pos = ((irr::gui::IGUIScrollBar *)event.GUIEvent.Caller)->getPos();
		my_env.shaders = (int)new_pos / 10;
		my_env.shaders = true;
	}
}

int					main()
{
	irr::s32			density = 10;
	t_env				my_env;
	MyEventReceiver			receiver(my_env, density);

	init_struct(my_env, receiver);
	Intro				intro(my_env.smgr, my_env.driver);
	init_buttons(my_env);
	while (my_env.device->run())
	{
		my_env.driver->beginScene(true, true, irr::video::SColor(255,113,113,133));
		my_env.driver->draw2DImage(my_env.image,irr::core::position2d<irr::s32>(250,50),
				    irr::core::rect<irr::s32>(0,0,1400,400), 0,
				    irr::video::SColor (255,255,255,255),
				    true);
		handle_menu(my_env);
		my_env.smgr->drawAll();
		my_env.gui->drawAll();
		my_env.driver->endScene();
	}
	my_env.device->drop();
	return 0;
}
