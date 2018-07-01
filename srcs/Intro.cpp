//
// EPITECH PROJECT, 2018
// bomber
// File description:
// intro
//

#include "Intro.hpp"

void	player1(irr::scene::ISceneManager *smgr)
{
	irr::scene::IAnimatedMeshSceneNode	*player;

	player = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./assets/Hip Hop Dancing.b3d"));
	player->setLoopMode(1);
	player->setFrameLoop(0, 500);
	player->setAnimationSpeed(30);
	player->setPosition(irr::core::vector3df(0, -50, -15));
	player->setRotation(irr::core::vector3df(-90, 0, -180));
	player->setScale(irr::core::vector3df(1.0f, 1.0f, 1.0f));
	player->addShadowVolumeSceneNode();
}

void	player2(irr::scene::ISceneManager *smgr)
{
	irr::scene::IAnimatedMeshSceneNode	*player;

	player = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./assets/Hip Hop Dancing (3).b3d"));
	player->setLoopMode(1);
	player->setFrameLoop(0, 500);
	player->setAnimationSpeed(40);
	player->setPosition(irr::core::vector3df(-150, 150, -15));
	player->setRotation(irr::core::vector3df(-90, 0, -180));
	player->setScale(irr::core::vector3df(1.0f, 1.0f, 1.0f));
	player->addShadowVolumeSceneNode();
}

void	player3(irr::scene::ISceneManager *smgr)
{
	irr::scene::IAnimatedMeshSceneNode	*player;

	player = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./assets/Samba Dancing.b3d"));
	player->setLoopMode(1);
	player->setFrameLoop(0, 500);
	player->setAnimationSpeed(30);
	player->setPosition(irr::core::vector3df(150, 150, -15));
	player->setRotation(irr::core::vector3df(-90, 0, -180));
	player->setScale(irr::core::vector3df(1.0f, 1.0f, 1.0f));
	player->addShadowVolumeSceneNode();
}

void	player4(irr::scene::ISceneManager *smgr)
{
	irr::scene::IAnimatedMeshSceneNode	*player;

	player = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./assets/Bellydancing.b3d"));
	player->setLoopMode(1);
	player->setFrameLoop(0, 500);
	player->setAnimationSpeed(30);
	player->setPosition(irr::core::vector3df(300, -50, -15));
	player->setRotation(irr::core::vector3df(-90, 0, -180));
	player->setScale(irr::core::vector3df(1.0f, 1.0f, 1.0f));
	player->addShadowVolumeSceneNode();
}

void	player5(irr::scene::ISceneManager *smgr)
{
	irr::scene::IAnimatedMeshSceneNode	*player;

	player = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./assets/Tut Hip Hop Dance.b3d"));
	player->setLoopMode(1);
	player->setFrameLoop(0, 500);
	player->setAnimationSpeed(40);
	player->setPosition(irr::core::vector3df(450, 150, -15));
	player->setRotation(irr::core::vector3df(-90, 0, -180));
	player->setScale(irr::core::vector3df(1.0f, 1.0f, 1.0f));
	player->addShadowVolumeSceneNode();
}

void	player6(irr::scene::ISceneManager *smgr)
{
	irr::scene::IAnimatedMeshSceneNode	*player;

	player = smgr->addAnimatedMeshSceneNode(smgr->getMesh("./assets/Dancing.b3d"));
	player->setLoopMode(1);
	player->setFrameLoop(0, 500);
	player->setAnimationSpeed(30);
	player->setPosition(irr::core::vector3df(150, -150, -15));
	player->setRotation(irr::core::vector3df(-90, 0, -180));
	player->setScale(irr::core::vector3df(1.0f, 1.0f, 1.0f));
	player->addShadowVolumeSceneNode();
}

Intro::Intro(irr::scene::ISceneManager *smgr, irr::video::IVideoDriver *drv)
	: _smgr(smgr)
{	
	_smgr->addCameraSceneNode(
		0,
		irr::core::vector3df(240, -600, -300),
		irr::core::vector3df(240, 2500, 500), -1, true);
	for (int y = -6; y < 30; y++) {
		for (int x = -30; x < 35; x++) {
			_cube = _smgr->addCubeSceneNode(30.0f, 0, -1, irr::core::vector3df(x * 30, y * 30, 0));
			_cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
			_cube->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING, true);
			_cube->setMaterialTexture(0, drv->getTexture("./assets/grass.bmp"));
			_cube->setMaterialTexture(1, drv->getTexture("./assets/grass_normal.png"));
			_cube->addShadowVolumeSceneNode();
			_smgr->setShadowColor(irr::video::SColor(150,0,0,0));
		}
	}
	player1(_smgr);
	player2(_smgr);
	player3(_smgr);
	player4(_smgr);
	player5(_smgr);
	player6(_smgr);
}

Intro::~Intro()
{
//	delete _cube;
}
