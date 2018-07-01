//
// EPITECH PROJECT, 2018
// handle_menu
// File description:
// 
//

#include "Bomberman.hpp"
#include "EventMenu.hpp"

void			display_help(t_env &my_env)
{
	std::vector<int>	*color;
	std::vector<int>	*position;

	if (my_env.text != NULL)
	{
		my_env.text->remove();
		my_env.text = NULL;
	}
	position = set_position(my_env.deskres.Width / 2 + 500,
				my_env.deskres.Height / 2 - 100,
				my_env.deskres.Width / 2 + 650,
				my_env.deskres.Height / 2 - 60),
	color = fill_color(255, 255, 255);
	display_text(my_env, L"Goal : The objective is to kill the ennemy. To achieve your mission, you can put bombs", color, position);
	color = fill_color(255, 255, 255);
	display_text(my_env, L"on the map. If the ennemy is close to the bombs, he will explode and the walls who are breakable will be destroyed.", color, position);
	my_env.play->setVisible(false);
	my_env.play2->setVisible(false);
	my_env.option->setVisible(false);
	my_env.help->setVisible(false);
	my_env.back->setVisible(true);
	my_env.densityBar->setVisible(false);
	my_env.shadersBar->setVisible(false);
	my_env.quit->setVisible(false);
}

void		display_option(t_env &my_env)
{
	std::vector<int>	*color;
	std::vector<int>	*position;

	if (my_env.text != NULL)
	{
		my_env.text->remove();
		my_env.text = NULL;
	}
	position = set_position(my_env.deskres.Width / 2 + 500,
				my_env.deskres.Height / 2 - 100,
				my_env.deskres.Width / 2 + 650,
				my_env.deskres.Height / 2 - 60),
	color = fill_color(255, 255, 255);
	display_text(my_env, L"Set the density of the game :", color, position);
	//display_text(my_env, L"Set the shadow (false/true)", color, position);
	my_env.play->setVisible(false);
	my_env.play2->setVisible(false);
	my_env.option->setVisible(false);
	my_env.help->setVisible(false);
	my_env.back->setVisible(true);
	my_env.densityBar->setVisible(true);
	my_env.shadersBar->setVisible(true);
	my_env.quit->setVisible(false);
}

void				display_menu(t_env &my_env)
{
	if (my_env.text != NULL)
	{
		my_env.text->remove();
		my_env.text = NULL;
	}
	my_env.play->setVisible(true);
	my_env.play2->setVisible(true);
	my_env.option->setVisible(true);
	my_env.help->setVisible(true);
	my_env.back->setVisible(false);
	my_env.densityBar->setVisible(false);
	my_env.shadersBar->setVisible(false);
	my_env.quit->setVisible(true);
}

void		display_game(t_env &my_env, bool isPlayer2)
{
	my_env.has_menu_sound = false;
	Game		game(my_env.density, my_env.shaders, isPlayer2);

	stopSound(my_env, 0);
}
