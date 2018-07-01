//
// EPITECH PROJECT, 2018
// bomberman
// File description:
//
//

#ifndef _BOMBERMAN_HPP_
# define _BOMBERMAN_HPP_

# include <tuple>
# include <iostream>
# include <vector>
# include <utility>
# include <irrlicht.h>
# include "Error.hpp"
# include "Player.hpp"

enum ObjType {
	CHARACTER,
	WALL,
	GROUND,
	BOMB,
	POWERUP,
	EMPTY,
	FIRE
};

enum ActionInMenu {
	MENU,
	PLAY,
	PLAY2,
	OPTION,
	HELP,
	DENSITY_SCROLLBAR,
	DENSITY_SHADERSBAR,
	QUIT
};

// enum {
// 	DENSITY
// };

// std::vector<std::vector<std::size_t> >	create_map(std::size_t);
// void					print_map(std::vector<std::vector<std::size_t> >);

#endif /* _BOMBERMAN_HPP_ */
