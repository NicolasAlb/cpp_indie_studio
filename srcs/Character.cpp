//
//EPITECH PROJECT, 2018
//
//File description:
//Makefile
//

#include <iostream>
#include "Character.hpp"

void	Character::init_player2()
{
	_player2 = _smgr->addAnimatedMeshSceneNode(_smgr->getMesh("./assets/Models/Kaya/Kaya.b3d"));
	_player2->setLoopMode(0);
	_player2->setFrameLoop(0, 240);
	_player2->setAnimationSpeed(40);
	_player2->setMD2Animation(irr::scene::EMAT_STAND);
	_player2->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_player2->setMaterialTexture(0, _dvr->getTexture("./assets/Models/Kaya/OccupyGuy_diffuse.jpg"));
	_player2->setPosition(irr::core::vector3df(450, 30, -15));
	_player2->setRotation(irr::core::vector3df(-90, 0, 0));
	_player2->setScale(irr::core::vector3df(0.2f, 0.2f, 0.2f));
	_player2->addShadowVolumeSceneNode();
}

Character::Character(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *sceneManager, irr::IrrlichtDevice *device, std::vector<std::vector<size_t> > *map, std::vector<std::vector<Obj *> > *map3d, std::pair<irr::io::path, irr::io::path> texture, bool isPlayer2)
{
	_isPlayer2 = isPlayer2;
	_smgr = sceneManager;
	_dvr = driver;
	_sydney = sceneManager->addAnimatedMeshSceneNode(sceneManager->getMesh(texture.first));
	if (_isPlayer2)
		init_player2();
	//_sydney = sceneManager->addAnimatedMeshSceneNode(sceneManager->getMesh("./assets/Zombie/MESH/Zombie.mesh"));
	_position = irr::core::vector3df(-5000, -5000, -5000);
	_speed = 10;
	_map = map;
	_map3d = map3d;
	_power = 1;
	_nbBomb = 1;
	_wallPass = false;
	_sydney->setLoopMode(0);
	_sydney->setFrameLoop(0, 240);
	_sydney->setAnimationSpeed(40);
	_sydney->setMD2Animation(irr::scene::EMAT_STAND);
	_sydney->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_sydney->setMaterialTexture(0, driver->getTexture(texture.second));
	//_sydney->setMaterialTexture(0, driver->getTexture("./assets/Zombie/OBJ/mremireh_body__diffuse.png"));
	_sydney->setPosition(irr::core::vector3df(30, 30, -15));
	_sydney->setRotation(irr::core::vector3df(-90, 0, 0));
	_sydney->setScale(irr::core::vector3df(0.2f, 0.2f, 0.2f));
	_sydney->addShadowVolumeSceneNode();
	_e = new Event(_sydney, _player2, map, map3d, std::make_pair(sceneManager, driver), _isPlayer2);
	device->setEventReceiver(_e);
}

Character::~Character()
{
	delete _sydney;
	delete _e;
}

void	Character::checkMove()
{
	/*_e->check_bomb1(_sydney->getPosition().X, _sydney->getPosition().Y);
	_e->check_bomb1(_sydney->getPosition().X + 1, _sydney->getPosition().Y);
	_e->check_bomb1(_sydney->getPosition().X, _sydney->getPosition().Y + 1);
	_e->check_bomb1(_sydney->getPosition().X, _sydney->getPosition().Y - 1);
	_e->check_bomb1(_sydney->getPosition().X - 1, _sydney->getPosition().Y);*/
	if (_e->isMovingP1() == true)
		_sydney->setMD2Animation(irr::scene::EMAT_ATTACK);
	else {
		_sydney->setMD2Animation(irr::scene::EMAT_STAND);
		takePowerUp(_sydney->getPosition());
	}
	if (_isPlayer2) {
		/*_e->check_bomb2(_player2->getPosition().X, _player2->getPosition().Y);
		_e->check_bomb2(_player2->getPosition().X + 1, _player2->getPosition().Y);
		_e->check_bomb2(_player2->getPosition().X, _player2->getPosition().Y + 1);
		_e->check_bomb2(_player2->getPosition().X, _player2->getPosition().Y - 1);
		_e->check_bomb2(_player2->getPosition().X - 1, _player2->getPosition().Y);*/
		if (_e->isMovingP2() == true)
			_player2->setMD2Animation(irr::scene::EMAT_ATTACK);
		else {
			_player2->setMD2Animation(irr::scene::EMAT_STAND);
			takePowerUp(_player2->getPosition());
		}
	}
}

bool	Character::checkBomb()
{
	return (_e->isBomb());
}

void	Character::removeBomb()
{
	_e->removeBomb();
}

void	Character::increaseSpeed()
{
	_speed += 5;
}

void	Character::increasePower()
{
	_power += 1;
}

void	Character::increaseNbBomb()
{
	_nbBomb += 1;
}

void	Character::activeWallPass()
{
	_wallPass = true;
}

void    Character::takePowerUp(irr::core::vector3df coor)
{
	size_t  y = coor.Y / 30;
	size_t  x = coor.X / 30;

//	std::cout <<"{ value map : " << (*_map)[y][x]
//		  << " }" << std::endl;
	if ((*_map)[y][x] > 3) {
		if ((*_map)[y][x] == 4)
			increasePower();
		if ((*_map)[y][x] == 5)
			increaseNbBomb();
		if ((*_map)[y][x] == 6)
			increaseSpeed();
		if ((*_map)[y][x] == 7)
			activeWallPass();
		destroyPowerUp(y, x);
	}
}

void    Character::destroyPowerUp(size_t y, size_t x)
{

//	(*_map)[y][x] = 0;
//	std::cout << "{ New value : " << (*_map)[y][x] << " }" <<std::endl;
	(*_map3d)[y][x]->removeBreakableWall(_smgr, _dvr);
//	std::cout << "pow size : " << _e->_pow.size() << "\n";
//	for (std::size_t i = 0; i < _e->_pow.size(); i++) {
		//std::cout << "pow[i] : x = " << _e->_pow[i]->_pos.X << ", y = " << _e->_pow[i]->_pos.Y << "\n";
//		if (_e->_pow[i] && _e->_pow[i]->_pos.X == x && _e->_pow[i]->_pos.Y == y) {
//			std::cout << "test\n";
//			_e->_pow.erase(_e->_pow.begin(), _e->_pow.begin() + i);
}
