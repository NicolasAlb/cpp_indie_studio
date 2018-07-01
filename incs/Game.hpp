//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Game
//

#ifndef	__GAME_HPP__
# define __GAME_HPP__

# include <chrono>
# include <ctime>
# include "Bomberman.hpp"
# include "Map.hpp"
# include "IA.hpp"
# include "Character.hpp"
# include "irrlicht.h"

class Game {
	irr::IrrlichtDevice		*_device;
	irr::video::IVideoDriver	*_driver;
	irr::scene::ISceneManager	*_sceneManager;
	Map				*_map;
	Character			*_sydney;
	Character			*_player2;
	IA 				*_ia1;
	IA 				*_ia2;
	IA 				*_ia3;
	bool				_isPlayer2;
	bool 				_shader;
public:
	Game(int, bool, bool);
	~Game();

private:
	void	init_scene();
	void	create_map();
	void	add_player();
	void	save_game();
	void	launch();
	void 	moveIA(IA *);
	bool 	checkWin();
};

#endif /* __GAME_HPP__ */
