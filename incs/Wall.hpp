//
//EPITECH PROJECT, 2018
//
//File description:
//Makefile
//

#ifndef __WALL_HPP__
# define __WALL_HPP__

//#include "bomberman.hpp"
#include "PowerUp.hpp"
#include "Obj.hpp"
#include <iostream>

class	Wall : public Obj
{
public:
	Wall(std::tuple<int, int, int>, std::pair<irr::io::path, irr::io::path>, bool, bool);
	~Wall();
	void	draw(irr::scene::ISceneManager *, irr::video::IVideoDriver*);
	PowerUp			       *removeBreakableWall(irr::scene::ISceneManager *, irr::video::IVideoDriver *);	
	std::pair<irr::io::path, irr::io::path>	get_textures() const;
	void					set_type(bool);
	void					show_the_fucking_map();
protected:
	irr::scene::IMeshSceneNode      *_cube;
	bool	_isBreakable;
	bool	_isPowerUp;
private:
	Powers	assignPow(int i);
};

#endif /* __WALL_HPP__ */
