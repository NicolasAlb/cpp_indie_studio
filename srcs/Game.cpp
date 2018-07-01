//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
//
//

#include "Game.hpp"
#include <fstream>

Game::Game(int density, bool shader, bool isPlayer2)
{
	_device = irr::createDevice(
		irr::video::EDT_OPENGL,
		irr::core::dimension2d<irr::u32>(1280,800),
		32, false, true, false, 0);
	_shader = shader;
	_driver = _device->getVideoDriver();
	_sceneManager = _device->getSceneManager();
	_map = new Map(density);
	_ia1 = NULL;
	_ia2 = NULL;
	_ia3 = NULL;
	_isPlayer2 = isPlayer2;
	init_scene();
	create_map();
	add_player();
	launch();
}

Game::~Game()
{
}

void	Game::init_scene()
{
	irr::scene::ISceneNodeAnimator		*anim = 0;
	irr::scene::ISceneNode			*node;

	_device->getCursorControl()->setVisible(false);
	_sceneManager->addCameraSceneNode(
		0,
		irr::core::vector3df(240, -30, -400),
		irr::core::vector3df(240, 1800, 3000), -1, true);
	if (_shader == 1) {
		node = _sceneManager->addLightSceneNode(
			0, irr::core::vector3df(240,1500,-2000),
			irr::video::SColorf(1.0f, 0.6f, 0.7f, 1.0f),
			3000.0f);
		anim = _sceneManager->createFlyCircleAnimator(
			irr::core::vector3df(240,240,-3000),
			3000.0f, 0.00005f,
			irr::core::vector3df(-240, -240, 3000));
		node->addAnimator(anim);
		anim->drop();
	}
}

void	Game::create_map()
{
	_map->print_map();
	_map->displayMap(_driver, _sceneManager);
}

void	Game::add_player()
{
	_sydney = new Character(_driver, _sceneManager, _device, _map->getMap(), _map->get_map3d(), std::make_pair("./assets/Models/Claire/Claire.b3d", "./assets/Models/Claire/Girl01_diffuse.jpg"), _isPlayer2);

	_ia1 = new IA(_driver, _sceneManager, _sydney->_e);
	irr::core::vector3df 	v = _ia1->_sydney->getPosition();
	v.X = 15 * 30.0f;
	v.Y = 15 * 30.0f;
	_ia1->_sydney->setPosition(v);

	_ia2 = new IA(_driver, _sceneManager, _sydney->_e);
	v = _ia2->_sydney->getPosition();
	v.X = 1 * 30.0f;
	v.Y = 15 * 30.0f;
	_ia2->_sydney->setPosition(v);

	if (!_isPlayer2) {
		_ia3 = new IA(_driver, _sceneManager, _sydney->_e);
		v = _ia3->_sydney->getPosition();
		v.X = 15 * 30.0f;
		v.Y = 1 * 30.0f;
		_ia3->_sydney->setPosition(v);
	}
}

void	Game::save_game()
{
	std::ofstream	file("save.sav", std::ofstream::out);
	std::vector<std::vector<std::size_t> >	map = *(_map->getMap());

	file << "<map>\n";
	for (size_t x = 0; x < map.size(); x++)
		for (size_t y = 0; y < map[x].size(); y++)
			file << "\t<block>\n\t\t<x>\n\t\t\t" << x << "\n\t\t</x>\n\t\t<y>\n\t\t\t" << y << "\n\t\t</y>\n\t\t<type>\n\t\t\t" << map[y][x] << "\n\t\t</type>\n\t</block>\n";
	file << "</map>\n";
	file << "<players>\n\t<position>\n\t\t<x>\n\t\t\t" << _sydney->_position.X << "\n\t\t</x>\n\t\t<y>\n\t\t\t" << _sydney->_position.Y << "\n\t</position>\n\t<speed>\n\t\t" << _sydney->_speed << "\n\t</speed>\n\t<power>\n\t\t" << _sydney->_power << "\n\t</power>\n\t<bombs>\n\t\t" << _sydney->_nbBomb << "\n\t<wallPass>\n\t\t" << _sydney->_wallPass << "\n\t</wallPass>\n</players>\n";

}

void 	Game::moveIA(IA *_ia)
{
	if (_ia->_sydney->getPosition().Z != 30) {
		_ia->iaMove(_map->getMap());
		if (_ia->_sydney->getFrameNr() == 260) {
			_ia->_sydney->setFrameLoop(0, 240);
			_ia->move();
		}
	}
}

bool 	Game::checkWin()
{
	if (_ia1->_sydney->getPosition().Z == 30 && _ia2->_sydney->getPosition().Z == 30 && _isPlayer2) {
		_device->drop();
		return (true);
	}
	else if (_ia1->_sydney->getPosition().Z == 30 && _ia2->_sydney->getPosition().Z == 30 && _ia3->_sydney->getPosition().Z == 30 && !_isPlayer2) {
		_device->drop();
		return (true);
	}
	return (false);
}

void    Game::launch()
{
	std::chrono::time_point<std::chrono::system_clock>      start, end;

	while (_device->run()/* && !checkWin()*/) {
		_driver->beginScene(
			true, true,
			irr::video::SColor(255, 50, 50, 50));
			/*_sydney->_e->check_bomb1(_sydney->_sydney->getPosition().Y, _sydney->_sydney->getPosition().X);
			_sydney->_e->check_bomb1(_sydney->_sydney->getPosition().Y + 1, _sydney->_sydney->getPosition().X);
			_sydney->_e->check_bomb1(_sydney->_sydney->getPosition().Y, _sydney->_sydney->getPosition().X + 1);
			_sydney->_e->check_bomb1(_sydney->_sydney->getPosition().Y, _sydney->_sydney->getPosition().X - 1);
			_sydney->_e->check_bomb1(_sydney->_sydney->getPosition().Y - 1, _sydney->_sydney->getPosition().X);*/
		_sydney->checkMove();
		moveIA(_ia1);
		moveIA(_ia2);
		if (!_isPlayer2)
			moveIA(_ia3);
		if (_sydney->_sydney->getFrameNr() == 260 && _sydney->_sydney->getPosition().Z != 30) {
			_sydney->_sydney->setFrameLoop(0, 240);
			_sydney->_e->moveP1();
		}
		if (_isPlayer2) {
			if (_sydney->_player2->getFrameNr() == 260 && _sydney->_player2->getPosition().Z != 30) {
				_sydney->_player2->setFrameLoop(0, 240);
				_sydney->_e->moveP2();
			}
		}
		_sydney->_e->removeBomb();
		_sceneManager->drawAll();
		_driver->endScene();
	}
	_device->drop();
}
