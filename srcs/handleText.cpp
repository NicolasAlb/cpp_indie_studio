//
// EPITECH PROJECT, 2018
// displayText
// File description:
// 
//

#include "Bomberman.hpp"
#include "EventMenu.hpp"

void		display_text(t_env &my_env, const wchar_t *msg,
				     std::vector<int> *color, std::vector<int> *position)
{
	if (my_env.text != NULL)
		my_env.text->remove();
	my_env.text = my_env.gui->addStaticText(L"",
						irr::core::rect<irr::s32>
						(position->at(0),
						position->at(1),
						position->at(2),
						 position->at(3)),
						false);
	my_env.text->setText(msg);
	my_env.text->setOverrideColor(irr::video::SColor
				      (255,
				       color->at(0),
				       color->at(1),
				       color->at(2)));
	delete(color);
}

std::vector<int>		*set_position(int width_start, int height_start,
					      int width_end, int height_end)
{
	std::vector<int>	*position = new std::vector<int>;

	position->push_back(width_start);
	position->push_back(height_start);
	position->push_back(width_end);
	position->push_back(height_end);
	return (position);
}

std::vector<int>		*fill_color(int r, int g, int b)
{
	std::vector<int>	*color = new std::vector<int>;

	color->push_back(r);
	color->push_back(g);
	color->push_back(b);
	return (color);
}
