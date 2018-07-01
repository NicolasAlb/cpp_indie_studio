//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IA.cpp
//

#include <thread>
#include <chrono>
#include <iostream>
#include "IA.hpp"

//Constructor + Destructor

IA::IA(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *sceneManager, Event *e)
{
	_smgr = sceneManager;
	_e = e;
	_sydney = sceneManager->addAnimatedMeshSceneNode(sceneManager->getMesh("./assets/Models/BigVegas/BigVegas.b3d"));
	_position = irr::core::vector3df(-5000, -5000, -5000);
	_speed = 10;
	_power = 1;
	_nbBomb = 1;
	_wallPass = false;
	_sydney->setLoopMode(0);
	_sydney->setFrameLoop(0, 240);
	_sydney->setAnimationSpeed(40);
	_sydney->setMD2Animation(irr::scene::EMAT_STAND);
	_sydney->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	_sydney->setMaterialTexture(0, driver->getTexture("./assets/Models/BigVegas/FatElvis_diffuse.jpg"));
	_sydney->setPosition(irr::core::vector3df(30, 30, -15));
	_sydney->setRotation(irr::core::vector3df(-90, 0, 0));
	_sydney->setScale(irr::core::vector3df(0.2f, 0.2f, 0.2f));
	_sydney->addShadowVolumeSceneNode();
	_x = 0;
	_y = 0;
	_dir = "none";
}

IA::~IA()
{
	delete _sydney;
}

// Initialisation

void	IA::initSyd(irr::scene::ISceneManager *sceneManager)
{
	_sydney = sceneManager->addAnimatedMeshSceneNode(sceneManager->getMesh("./assets/sydney.md2"));
}

// Fonctions de mouvements

void 				IA::check_bomb(size_t x, size_t y)
{
	size_t 			it = 0;

	for (; it < _e->_b.size(); it++) {
		if (_e->_b[it]->getPosition().X == x && _e->_b[it]->getPosition().Y == y) {
			if (_e->_b[it]->check_time()) {
				_sydney->setPosition(irr::core::vector3df(0, 0, 30));
			}
		}
	}
}

int 				IA::is_wall(std::vector<std::vector<size_t>> _map,
						size_t x, size_t y)
{
	check_bomb(x, y);
	if (x <= 15 && y <= 15 && x > 0 && y > 0 && (_map[y][x] == 0 || _map[y][x] == 4 || _map[y][x] == 5 || _map[y][x] == 6 || _map[y][x] == 7)) {
		return (1);
	}
	else if (x <= 15 && y <= 15 && x > 0 && y > 0 && (_map[y][x] == 1 || _map[y][x] == 2)) {
		if (_map[y][x] == 2) {
			_e->putBomb(_sydney->getPosition().X / 30, _sydney->getPosition().Y / 30);
		}
		return (0);
	}
	return (0);
}

bool 				IA::is_in_vec(std::string dir, std::vector<std::string> possibilities)
{
	size_t 			it = 0;

	for (; it < possibilities.size(); it++) {
		if (possibilities[it] == dir) {
			return true;
		}
	}
	return false;
}

std::vector<std::string> 	IA::check_possibilities(std::vector<std::vector<size_t>> *_map, irr::core::vector3df *v)
{
	std::vector<std::string> 	possibilities;

	if (_sydney->getPosition().Z != 30)
		check_bomb(v->X, v->Y);
	if (is_wall(*_map, v->X / 30, v->Y / 30 - 1) == 1) {
		possibilities.push_back("DOWN");
	}
	if (is_wall(*_map, v->X / 30 + 1, v->Y / 30) == 1) {
		possibilities.push_back("RIGHT");
	}
	if (is_wall(*_map, v->X / 30 - 1, v->Y / 30) == 1) {
		possibilities.push_back("LEFT");
	}
	if (is_wall(*_map, v->X / 30, v->Y / 30 + 1) == 1) {
		possibilities.push_back("UP");
	}
	if (_dir != "none" && is_in_vec(_dir, possibilities)) {
		possibilities.push_back(_dir);
		possibilities.push_back(_dir);
	}
	return (possibilities);
}

int 				IA::get_rand(std::vector<std::string> possibilities)
{
	int a = rand() % possibilities.size();
	return (a);
}

void    IA::putBomb()
{
	_b = new Bomb(_smgr, _sydney->getPosition());

	_isBomb = true;
}

void	IA::move()
{
	irr::core::vector3df	v = _sydney->getPosition();

	v.Y += (_y * 30);
	v.X += (_x * 30);
	_sydney->setPosition(v);
	_y = 0;
	_x = 0;
}

void 					IA::move_down(std::string direction, irr::core::vector3df *v)
{
	if (direction == "DOWN") {
		_y = -1;
		v->Y -= 30.0f;
		_sydney->setFrameLoop(241, 260);
		_sydney->setRotation(irr::core::vector3df(-90, 0, -180));
		set_dir("DOWN");
	}
}

void 					IA::move_right(std::string direction, irr::core::vector3df *v)
{
	if (direction == "RIGHT") {
		_x = 1;
		v->X += 30.0f;
		_sydney->setFrameLoop(241, 260);
		_sydney->setRotation(irr::core::vector3df(-90, 0, -90));
		set_dir("RIGHT");
	}
}

void 					IA::move_left(std::string direction, irr::core::vector3df *v)
{
	if (direction == "LEFT") {
		_x = -1;
		v->X -= 30.0f;
		_sydney->setFrameLoop(241, 260);
		_sydney->setRotation(irr::core::vector3df(-90, 0, 90));
		set_dir("LEFT");
	}
}

void 					IA::move_up(std::string direction, irr::core::vector3df *v)
{
	if (direction == "UP") {
		_y = 1;
		v->Y += 30.0f;
		_sydney->setFrameLoop(241, 260);
		_sydney->setRotation(irr::core::vector3df(-90, 0, 0));
		set_dir("UP");
	}
}

void 					IA::iaMove(std::vector<std::vector<size_t>> *_map)
{
	irr::core::vector3df 		v = _sydney->getPosition();
	std::vector<std::string>	possibilities = check_possibilities(_map, &v);
	int 				a;

	if (possibilities.size() != 0)
		a = get_rand(possibilities);
	else
		a = -1;
	if (a != -1) {
		if (_sydney->getStartFrame() < 241) {
			move_down(possibilities[a], &v);
			move_right(possibilities[a], &v);
			move_left(possibilities[a], &v);
			move_up(possibilities[a], &v);
		}
	}

}

// Getters

std::string 			IA::get_dir(void)
{
	return _dir;
}

int 					IA::get_speed(void)
{
	return _speed;
}

int 					IA::get_power(void)
{
	return _power;
}

int 					IA::get_nbBomb(void)
{
	return _nbBomb;
}

bool 					IA::get_wallPass(void)
{
	return _wallPass;
}

// Setters

void 					IA::set_dir(std::string _new_dir)
{
	_dir = _new_dir;
}

void 					IA::set_speed(int new_speed)
{
	_speed = new_speed;
}

void 					IA::set_power(int new_power)
{
	_power = new_power;
}

void 					IA::set_nbBomb(int new_nb)
{
	_nbBomb = new_nb;
}

void 					IA::set_wallPass(bool new_state)
{
	_wallPass = new_state;
}
