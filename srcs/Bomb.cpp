//
//EPITECH PROJECT, 2018
//
//File description:
//Makefile
//

#include "Bomberman.hpp"
#include "Bomb.hpp"


Bomb::Bomb(irr::scene::ISceneManager *smgr, irr::core::vector3df pos)
{
	_pos = pos;
	_pos.X /= 30;
	_pos.Y /= 30;
	_pos.Z /= 30;
	_smgr = &smgr;
	_bomb = (*_smgr)->addAnimatedMeshSceneNode(smgr->getMesh("./assets/Key_bomb.3DS"));
	_bomb->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_bomb->setPosition(irr::core::vector3df(pos.X, pos.Y, -30));
	_bomb->setRotation(irr::core::vector3df(-90, 45, -90));
	_bomb->setScale(irr::core::vector3df(0.15f, 0.15f, 0.15f));
	_bomb->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING, true);
	(*_smgr)->setShadowColor(irr::video::SColor(150,0,0,0));
	_start = std::chrono::system_clock::now();
}

Bomb::~Bomb()
{

}

bool	Bomb::check_time()
{
	std::chrono::time_point<std::chrono::system_clock>	end;
	int							time;
	
	end = std::chrono::system_clock::now();
	time = std::chrono::duration_cast<std::chrono::seconds>(end - _start).count();
	if (time >= 3) {
		undraw();
		return true;
	}
	return false;
}

irr::core::vector3df	Bomb::getPosition()
{
	return _pos;
}

void	Bomb::undraw()
{
	_bomb->setPosition(irr::core::vector3df(_pos.X, _pos.Y, 60));
}
