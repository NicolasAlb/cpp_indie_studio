//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Ground
//

#include "Ground.hpp"

Ground::Ground(std::tuple<int, int, int> coor, std::pair<irr::io::path, irr::io::path> textures) : Obj(coor, GROUND , textures)
{
	_posx *= 30;
	_posy *= 30;
	_posz = 0;
}

Ground::~Ground()
{
}

/*int	Ground::get_x()
{
	return _posx;
}

int	Ground::get_y()
{
	return _posy;
}

int	Ground::get_z()
{
	return _posz;
	}*/

/*PowerUp	*removeBreakableWall(irr::scene::ISceneManager *, irr::video::IVideoDriver*) {
	return NULL;
}*/

std::pair<irr::io::path, irr::io::path>	Ground::getTextures()
{
	return _textures;
}

void	Ground::draw(irr::scene::ISceneManager* smgr, irr::video::IVideoDriver* drv)
{
	irr::scene::IMeshSceneNode      *cube;

	cube = smgr->addCubeSceneNode(
		30.0f, 0, -1,
		irr::core::vector3df(
			_posx,
			_posy,
			_posz));
	cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	cube->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING, true);
	cube->setMaterialTexture(0, drv->getTexture(_textures.first));
	cube->setMaterialTexture(1, drv->getTexture(_textures.second));
	cube->addShadowVolumeSceneNode();
	smgr->setShadowColor(irr::video::SColor(150,0,0,0));
}
