//
//EPITECH PROJECT, 2018
//
//File description:
//Makefile
//

#include "Wall.hpp"
#include "PowerUp.hpp"

Wall::Wall(std::tuple<int, int, int> coor, std::pair<irr::io::path, irr::io::path> path, bool isBreakable, bool isPowerUp)
	: Obj(coor, WALL, path)
{
	_isBreakable = isBreakable;
	_isPowerUp = isPowerUp;
	_posx *= 30;
	_posy *= 30;
	_posz *= 30;
	_map = NULL;
}

Wall::~Wall()
{
}

void					Wall::set_type(bool breakable)
{
	_isBreakable = breakable;
}

std::pair<irr::io::path, irr::io::path>	Wall::get_textures() const
{
	return _textures;
}

PowerUp		*Wall::removeBreakableWall(irr::scene::ISceneManager *smgr, irr::video::IVideoDriver *drv)
{
	int	i = rand() % 3;
	int	j = rand() % 20 + 1;
	size_t	s = 0;
	Powers	p;

	srand(time(NULL));
	_cube->remove();
	if (i == 1 && (*_map)[_posy / 30][_posx / 30] == 2)
	{
		PowerUp *tmp;
		show_the_fucking_map();
		p = assignPow(j);
		tmp = new PowerUp(drv, smgr, irr::core::vector3df(_posx, _posy, _posz), p);
		_cube = tmp->getCube();
		show_the_fucking_map();
		return tmp;
	}
	else
		(*_map)[_posy / 30][_posx / 30] = s;
	return NULL;
}

Powers	Wall::assignPow(int i)
{
	Powers	p;
	size_t	s;

	if (i <= 2)
	{
		p = WALL_UP;
		s = 7;
	}
	else if (i > 2 && i <= 6)
	{
		p = SPEED_UP;
		s = 6;
	}
	else
	{
		if (i > 6 && i <= 12)
		{
			p = FIRE_UP;
			s = 4;
		}
		else
		{
			p = BOMB_UP;
			s = 5;
		}
	}
	(*_map)[_posy / 30][_posx / 30] = s;
	return (p);
}

void	Wall::show_the_fucking_map()
{
	int	i = 0;
	int	j;

	while (i < 17)
	{
		j = 0;
		while (j < 17)
		{
			j = j + 1;
		}
		i = i + 1;
	}
}

void	Wall::draw(irr::scene::ISceneManager *smgr, irr::video::IVideoDriver *drv)
{
	_cube = smgr->addCubeSceneNode(
		30.0f, 0, -1,
		irr::core::vector3df(
			_posx,
			_posy,
			_posz));
	_cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_cube->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING, true);
	_cube->setMaterialTexture(0, drv->getTexture(_textures.first));
	_cube->setMaterialTexture(1, drv->getTexture(_textures.second));
	_cube->addShadowVolumeSceneNode();
	smgr->setShadowColor(irr::video::SColor(150,0,0,0));
}
