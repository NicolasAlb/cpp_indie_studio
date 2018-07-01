//
//EPITECH PROJECT, 2018
//
//File description:
//Makefile
//

#ifndef __BOMB_HPP__
# define __BOMB_HPP__

#include "Obj.hpp"
#include <tuple>
#include <chrono>
#include <ctime>

class	Bomb
{
public:
       	Bomb(irr::scene::ISceneManager *, irr::core::vector3df);
       	~Bomb();

	bool	check_time();
	irr::core::vector3df	getPosition();
	void			undraw();
	irr::scene::IAnimatedMeshSceneNode	*_bomb;
	
protected:
	irr::scene::ISceneManager		**_smgr;
	std::chrono::time_point<std::chrono::system_clock>	_start;
	irr::core::vector3df					_pos;
	
//	int					_timer;
//	int					_power;
//	irr::io::path				_texture;

private:
};

#endif /* __BOMB_HPP__ */
