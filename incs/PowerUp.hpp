//
//EPITECH PROJECT, 2018
//
//File description:
//Makefile
//

#ifndef __POWERUP_HPP__
# define __POWERUP_HPP__

#include "irrlicht.h"
#include <tuple>

class	Obj;

enum Powers {
	FIRE_UP, //4
	BOMB_UP,
	SPEED_UP,
	WALL_UP
};

class	PowerUp
{
public:
	PowerUp(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, irr::core::vector3df coord, Powers powerUp);
	~PowerUp();
	void	destroy();
	Powers	getPower();
	irr::scene::IMeshSceneNode      *getCube();
	irr::core::vector3df	_pos;
	
protected:
	Powers				_powerUp;
	irr::scene::IMeshSceneNode	*_cube;

private:
	void	assignPowerUp(irr::video::IVideoDriver *driver);
};

#endif /* __POWERUP_HPP__ */
