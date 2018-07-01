//
//EPITECH PROJECT, 2018
//
//File description:
//Makefile
//

#include "irrlicht.h"
#include "PowerUp.hpp"
#include "Obj.hpp"

PowerUp::PowerUp(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr, irr::core::vector3df coord, Powers powerUp) 
	//: Obj(coor, POWERUP, path)
{
	_pos = coord;
	std::cout << "PowerUp construct : x : " << _pos.X << ", y = " << _pos.Y << "\n";
	_powerUp = powerUp;
	_cube = smgr->addCubeSceneNode(10.0f, 0, -1, irr::core::vector3df(coord.X, coord.Y, -30));
	_cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_cube->setScale(irr::core::vector3df(2.5f, 2.5f, 2.5f));
	assignPowerUp(driver);
}

PowerUp::~PowerUp()
{
	
}

irr::scene::IMeshSceneNode      *PowerUp::getCube()
{
	return(_cube);
}

void	PowerUp::destroy()
{
	_cube->remove();
}

void	PowerUp::assignPowerUp(irr::video::IVideoDriver *driver)
{
	if (_powerUp == SPEED_UP)
		_cube->setMaterialTexture(0, driver->getTexture("./assets/speedup.png"));
	else if (_powerUp == FIRE_UP)
		_cube->setMaterialTexture(0, driver->getTexture("./assets/fireup.jpg"));
	else if (_powerUp == WALL_UP)
		_cube->setMaterialTexture(0, driver->getTexture("./assets/wallup.jpg"));
	else
		_cube->setMaterialTexture(0, driver->getTexture("./assets/BOMBUP.psd"));
}

Powers	PowerUp::getPower()
{
	return (_powerUp);
}
