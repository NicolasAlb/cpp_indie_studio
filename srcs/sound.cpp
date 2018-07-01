//
// EPITECH PROJECT, 2018
// sound
// File description:
// 
//

#include <irrKlang.h>
#include "EventMenu.hpp"

int						playSound(t_env &env, int position)
{
	if (position == 0)
	{
		if (env.game_sound == NULL)
			env.game_sound = irrklang::createIrrKlangDevice();
		env.game_sound->play2D("assets/sounds/bomberman_ig.ogg");
	}
	else if (position == 1)
		env.click_sound->play2D("assets/sounds/click.ogg");
	else if (position == 2)
	{
		if (env.menu_sound == NULL)
			env.menu_sound = irrklang::createIrrKlangDevice();
		env.menu_sound->play2D("assets/sounds/eminem.wav");
	}
	return SUCCESS;
}

void						stopSound(t_env &env, int position)
{
	if (position == 0)
	{
		env.game_sound->drop();
		env.game_sound = NULL;
	}
	else if (position == 2)
	{
		env.menu_sound->drop();
		env.menu_sound = NULL;
	}
}
