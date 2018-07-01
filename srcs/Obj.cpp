//
//EPITECH PROJECT, 2018
//
//File description:
//Makefile
//

#include "Obj.hpp"

Obj::Obj(std::tuple<int, int, int> coor, ObjType type, std::pair<irr::io::path, irr::io::path> path)
	: _type(type), _textures(path)
{
	std::tie(_posx, _posy, _posz) = coor;
}

Obj::~Obj()
{
}

int					Obj::get_x() const
{
	return _posx;
}

int					Obj::get_y() const
{
	return _posy;
}

int					Obj::get_z() const
{
	return _posz;
}

std::pair<irr::io::path, irr::io::path>	Obj::get_textures() const
{
	return _textures;
}

void	Obj::draw(irr::scene::ISceneManager *smgr, irr::video::IVideoDriver *drv)
{
	(void)smgr;
	(void)drv;
}
