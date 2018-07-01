//
//EPITECH PROJECT, 2018
//
//File description:
//Makefile
//

#include "EventGame.hpp"
#include "Bomb.hpp"
#include <iostream>

Event::Event(irr::scene::IAnimatedMeshSceneNode *player1, irr::scene::IAnimatedMeshSceneNode *player2, std::vector<std::vector<size_t> > *map,
	     std::vector<std::vector<Obj *> > *map3d, std::pair<irr::scene::ISceneManager *, irr::video::IVideoDriver *> irr_info, bool isPlayer2)
{
	_player1 = player1;
	if (isPlayer2)
		_player2 = player2;
	m_isMoving = false;
	_isMovingP2 = false;
	_map = *map;
	_map3d = map3d;
	_smgr = irr_info.first;
	_drv = irr_info.second;
	_isPlayer2 = isPlayer2;
	_h = 1;
	_l = 1;
	_p2x = 15;
	_p2y = 1;
	_k = 0;
	_isBomb = false;
	_x = 0;
	_y = 0;
	_x2 = 0;
	_y2 = 0;
}

bool Event::OnEvent(const irr::SEvent &event)
{
	if (_isPlayer2 && event.EventType == irr::EET_KEY_INPUT_EVENT && (event.KeyInput.Key == irr::KEY_KEY_O ||
									  event.KeyInput.Key == irr::KEY_KEY_K ||
									  event.KeyInput.Key == irr::KEY_KEY_L ||
									  event.KeyInput.Key == irr::KEY_KEY_M ||
									  event.KeyInput.Key == irr::KEY_KEY_N)) {
		if (event.KeyInput.PressedDown == true && event.KeyInput.Key != irr::KEY_KEY_N)
			_isMovingP2 = true;
		else {
			if (event.KeyInput.Key != irr::KEY_KEY_N)
				_isMovingP2 = false;
		}
//		std::cout << "MOVING PLAYER 2" << std::endl;
		majPosMeshP2(event.KeyInput.Key);
		return true;
	}
	else if (event.EventType == irr::EET_KEY_INPUT_EVENT && (event.KeyInput.Key == irr::KEY_KEY_Z ||
								 event.KeyInput.Key == irr::KEY_KEY_Q ||
								 event.KeyInput.Key == irr::KEY_KEY_D ||
								 event.KeyInput.Key == irr::KEY_KEY_S ||
								 event.KeyInput.Key == irr::KEY_KEY_B))
	{
		if (event.KeyInput.PressedDown == true && event.KeyInput.Key != irr::KEY_KEY_B)
			m_isMoving = true;
		else
		{
			if (event.KeyInput.Key != irr::KEY_KEY_B)
				m_isMoving = false;
		}
//		std::cout << "MOVING PLAYER 1" << std::endl;
		majPosMesh(event.KeyInput.Key);
		return true;
	}
	return false;
}

void	Event::moveP1()
{
	irr::core::vector3df	v = _player1->getPosition();

	v.Y += (_y * 30);
	v.X += (_x * 30);
	_player1->setPosition(v);
	_y = 0;
	_x = 0;
}

void	Event::moveP2()
{
	irr::core::vector3df	v = _player2->getPosition();

	v.Y += (_y2 * 30);
	v.X += (_x2 * 30);
	_player2->setPosition(v);
	_y2 = 0;
	_x2 = 0;
}

void	Event::majPosMeshP2(irr::EKEY_CODE key)
{
	/*check_bomb2(_l, _h);
	check_bomb2(_l + 1, _h);
	check_bomb2(_l, _h + 1);
	check_bomb2(_l, _h - 1);
	check_bomb2(_l - 1, _h);*/
	if (key == irr::KEY_KEY_N && _player2->getStartFrame() < 240)
		putBomb(_p2x, _p2y);
	if (_player2 != 0 && _isMovingP2 == true && _player2->getStartFrame() < 240) {
		irr::core::vector3df v = _player2->getPosition();
		if (key == irr::KEY_KEY_O && check_wall2(_p2y + 1, _p2x) == 0) {
			_player2->setFrameLoop(241, 260);
			_player2->setRotation(irr::core::vector3df(-90, 0, 0));
			v.Y += 30.0f;
			_y2 = 1;
			_p2y += 1;
		}
		else if (key == irr::KEY_KEY_K && check_wall2(_p2y, _p2x - 1) == 0) {
			_player2->setFrameLoop(241, 260);
			v.X -= 30.0f;
			_x2 = -1;
			_p2x -= 1;
			_player2->setRotation(irr::core::vector3df(-90, 0, 90));
		}
		else if (key == irr::KEY_KEY_M && check_wall2(_p2y, _p2x + 1) == 0) {
			_player2->setFrameLoop(241, 260);
			v.X += 30.0f;
			_x2 = 1;
			_p2x += 1;
			_player2->setRotation(irr::core::vector3df(-90, 0, -90));
		}
		else if (key == irr::KEY_KEY_L && check_wall2(_p2y - 1, _p2x) == 0) {
			_player2->setFrameLoop(241, 260);
			v.Y -= 30.0f;
			_y2 = -1;
			_p2y -= 1;
			_player2->setRotation(irr::core::vector3df(-90, 0, -180));
		}
	}
}
void Event::majPosMesh(irr::EKEY_CODE key)
{
//	std::cout << "MAJPOSMESH" << std::endl;
	/*check_bomb1(_l, _h);
	check_bomb1(_l + 1, _h);
	check_bomb1(_l, _h + 1);
	check_bomb1(_l, _h - 1);
	check_bomb1(_l - 1, _h);*/

	if (key == irr::KEY_KEY_B && _player1->getStartFrame() < 240)
		putBomb(_l, _h);
	if(_player1 != 0 && m_isMoving == true && _player1->getStartFrame() < 240) {
		irr::core::vector3df v = _player1->getPosition();
		if (key == irr::KEY_KEY_Z  && check_wall1(_h + 1, _l) == 0) {
			_player1->setFrameLoop(241, 260);
			_player1->setRotation(irr::core::vector3df(-90, 0, /*90*/0));
			v.Y += 30.0f;
			_y = 1;
			_h += 1;
		}
		else if (key == irr::KEY_KEY_Q  && check_wall1(_h, _l - 1) == 0) {
			_player1->setFrameLoop(241, 260);
			v.X -= 30.0f;
			_x = -1;
			_l -= 1;
			_player1->setRotation(irr::core::vector3df(-90, 0, /*180*/90));
		}
		else if (key == irr::KEY_KEY_D  && check_wall1(_h, _l + 1) == 0) {
			_player1->setFrameLoop(241, 260);
			v.X += 30.0f;
			_x = 1;
			_l += 1;
			_player1->setRotation(irr::core::vector3df(-90, 0, -90));
		}
		else if (key == irr::KEY_KEY_S  && check_wall1(_h - 1, _l) == 0) {
			_player1->setFrameLoop(241, 260);
			v.Y -= 30.0f;
			_y = -1;
			_h -= 1;
			_player1->setRotation(irr::core::vector3df(-90, 0, -180));
		}
		//_player1->setPosition(v);
	}
}

void	Event::createFireNorth(double n, int x, int y)
{
	int	minx = x;
	int	miny = y;
	int	minz = -30;
	int	maxx = minx;
	int	maxy = miny;
	int	maxz = 0;

//	std::cout << "North\n";
//	std::cout << "north pos : x = " << x << ", y = " << y << "\n";
	irr::scene::IParticleSystemSceneNode* ps = _smgr->addParticleSystemSceneNode(false);
	irr::scene::IParticleEmitter* em = ps->createBoxEmitter(irr::core::aabbox3d<irr::f32>(minx, miny, minz, maxx, maxy, maxz),
								irr::core::vector3df(0.0f, n, 0.0f), 200, 500, irr::video::SColor(0, 255, 0,0),
								irr::video::SColor(0, 255, 255, 255),650, 650, 0, irr::core::dimension2df(20.f, 20.f), irr::core::dimension2df(20.0f, 20.0f));
	ps->setEmitter(em);
	em->drop();
//	std::cout << "dropped\n";
	ps->setScale(irr::core::vector3df(1, 1, 1));
	ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	ps->setMaterialTexture(0, _drv->getTexture("./assets/fire.bmp"));
	ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
}

void	Event::createFireSouth(double n, int x, int y)
{
	int	minx = x;
	int	miny = y;
	int	minz = -30;
	int	maxx = minx;
	int	maxy = miny;
	int	maxz = 70;

	irr::scene::IParticleSystemSceneNode* ps = _smgr->addParticleSystemSceneNode(false);
	irr::scene::IParticleEmitter* em = ps->createBoxEmitter(irr::core::aabbox3d<irr::f32>(minx, miny, minz, maxx, maxy, maxz),
								irr::core::vector3df(0.0f, -n, 0.0f), 200, 500, irr::video::SColor(0, 255, 0,0),
								irr::video::SColor(0, 255, 255, 255),650, 650, 0, irr::core::dimension2df(20.f, 20.f), irr::core::dimension2df(20.0f, 20.0f));
	ps->setEmitter(em);
	em->drop();
	ps->setScale(irr::core::vector3df(1, 1, 1));
	ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	ps->setMaterialTexture(0, _drv->getTexture("./assets/fire.bmp"));
	ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
}

void	Event::createFireWest(double n, int x, int y)
{
	int	minx = x;
	int	miny = y;
	int	minz = -30;
	int	maxx = minx;
	int	maxy = miny;
	int	maxz = 70;

	irr::scene::IParticleSystemSceneNode* ps = _smgr->addParticleSystemSceneNode(false);
	irr::scene::IParticleEmitter* em = ps->createBoxEmitter(irr::core::aabbox3d<irr::f32>(minx, miny, minz, maxx, maxy, maxz),
								irr::core::vector3df(-n, 0.0f, 0.0f), 200, 500, irr::video::SColor(0, 255, 0,0),
								irr::video::SColor(0, 255, 255, 255),650, 650, 0, irr::core::dimension2df(20.f, 20.f), irr::core::dimension2df(20.0f, 20.0f));
	ps->setEmitter(em);
	em->drop();
	ps->setScale(irr::core::vector3df(1, 1, 1));
	ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	ps->setMaterialTexture(0, _drv->getTexture("./assets/fire.bmp"));
	ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
}

void	Event::createFireEast(double n, int x, int y)
{
	int	minx = x;
	int	miny = y;
	int	minz = -30;
	int	maxx = minx;
	int	maxy = miny;
	int	maxz = 70;

	irr::scene::IParticleSystemSceneNode* ps = _smgr->addParticleSystemSceneNode(false);
	irr::scene::IParticleEmitter* em = ps->createBoxEmitter(irr::core::aabbox3d<irr::f32>(minx, miny, minz, maxx, maxy, maxz),
								irr::core::vector3df(n, 0.0f, 0.0f), 200, 500, irr::video::SColor(0, 255, 0,0),
								irr::video::SColor(0, 255, 255, 255),650, 650, 0, irr::core::dimension2df(20.f, 20.f), irr::core::dimension2df(20.0f, 20.0f));
	ps->setEmitter(em);
	em->drop();
	ps->setScale(irr::core::vector3df(1, 1, 1));
	ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
	ps->setMaterialTexture(0, _drv->getTexture("./assets/fire.bmp"));
	ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
}

void	Event::createFire(int pow, int x, int y)
{
	double	dnorth = 0;
	double	dsouth = 0;
	double	dwest = 0;
	double	deast = 0;
	int	i = 1;

//	std::cout << "createFire\n";
//	std::cout << "pow : " << pow << "\n";
//	std::cout
 //<< "x : " << x << "\n";
//	std::cout << "y : " << y << "\n";
	while (i <= pow)
	{
//		std::cout << "first checkwall\n";
		if (check_fire(x / 30, y / 30 + i) == 0)
			dnorth += 1;
//		std::cout << "second checkwall\n";
		if (check_fire(x / 30, y / 30 - i) == 0)
			dsouth += 1;
//		std::cout << "third checkwall\n";
		if (check_fire(x / 30 + i, y / 30) == 0)
			dwest += 1;
//		std::cout << "fourth checkwall\n";
		if (check_fire(x / 30 - i, y / 30) == 0)
			deast += 1;
		i = i + 1;
	}
//	std::cout << "wall checked\n";
	dnorth *= 0.045;
	dsouth *= 0.045;
	dwest *= 0.045;
	deast *= 0.045;
//	std::cout << "fire size\n";
//	std::cout << "x : " << x << " y : " << y << "\n";
	createFireNorth(dnorth, x, y);
	createFireSouth(dsouth, x, y);
	createFireWest(dwest, x, y);
	createFireEast(deast, x, y);
//	std::cout << "fire created\n";
}

void    Event::putBomb(std::size_t x, std::size_t y)
{
//	std::cout << "We r puting a bomb" << std::endl;
//	std::cout << "x = " << x << " y = " << y << " z = " << _k << std::endl;

	_b.push_back(new Bomb(_smgr, irr::core::vector3df(x * 30, y * 30, -30)));
//	createFire(1, x * 30, y * 30);
	_posBx = x;
	_posBy = y;
	_isBomb = true;
}

bool	Event::isBomb()
{
	return (_isBomb);
}

void	Event::removeBomb()
{
	for (std::size_t i = 0; i < _b.size(); i++) {
		if (_b[i] != NULL && _b[i]->check_time() && _b[i]->getPosition().X != 0 && _b[i]->getPosition().Y != 0)
		{
			PowerUp	*tmp = NULL;
			irr::core::vector3df	pos = _b[i]->getPosition();
			if (check_wall(/*_posBy + 1, _posBx*/pos.Y + 1, pos.X) == 2) {
				tmp = ((*_map3d)[pos.Y + 1][pos.X]->removeBreakableWall(_smgr, _drv));
				_map[pos.Y + 1][pos.X] = 0;
			}
			if (check_wall(pos.Y, pos.X - 1) == 2) {
				tmp = ((*_map3d)[pos.Y][pos.X - 1]->removeBreakableWall(_smgr, _drv));
				_map[pos.Y][pos.X - 1] = 0;
			}
			if (check_wall(pos.Y, pos.X + 1) == 2) {
				tmp = ((*_map3d)[pos.Y][pos.X + 1]->removeBreakableWall(_smgr, _drv));
				_map[pos.Y][pos.X + 1] = 0;
			}
			if (check_wall(pos.Y - 1, pos.X) == 2) {
				tmp = ((*_map3d)[pos.Y - 1][pos.X]->removeBreakableWall(_smgr, _drv));
				_map[pos.Y - 1][pos.X] = 0;
			}
			if (tmp != NULL) {
				_pow.push_back(tmp);
			}
			//_b[i]->undraw();
			_b.erase(_b.begin(), _b.begin() + i);
//			delete _b[i];
//			_b[i] = NULL;
			if (_b.size() == 0)
				_isBomb = false;
		}
	}
}

int     Event::check_fire(int x, int y)
{
	if (x >= 17 || y >= 17 || x < 0 || y < 0)
		return (2);
	if (_map[x][y] != 0)
		return (1);
	return (0);
}


void 				Event::check_bomb1(size_t x, size_t y)
{
/*	if (_player1->getPosition().X == x && _player1->getPosition().Y == y) {
		delete _player1;
	}
		//_player1->setPosition(irr::core::vector3df(0, 0, 30));
*/
	size_t 			it = 0;

	for (; it < _b.size(); it++) {
		if (_b[it]->getPosition().X == x && _b[it]->getPosition().Y == y) {
			if (_b[it]->check_time()) {
				_player1->setPosition(irr::core::vector3df(0, 0, 30));
			}
		}
	}
}

void 				Event::check_bomb2(size_t x, size_t y)
{
/*	if (_player2->getPosition().X == x && _player2->getPosition().Y == y) {
}*/

	size_t 			it = 0;

	for (; it < _b.size(); it++) {
		if (_b[it]->getPosition().X == x && _b[it]->getPosition().Y == y) {
			if (_b[it]->check_time()) {
				_player2->setPosition(irr::core::vector3df(0, 0, 30));
			}
		}
	}
}


int	Event::check_wall(int y, int x)
{
	/*check_bomb1(x, y);
	check_bomb2(x, y);*/

	if (x >= 17 || y >= 17 || x < 0 || y < 0)
		return (2);
	if (_map[y][x] == 0)
		return (0);
	if (_map[y][x] == 2)
		return (2);
	return (1);
}

int	Event::check_wall1(int y, int x)
{
	//check_bomb1(x, y);
	if (x >= 17 || y >= 17 || x < 0 || y < 0)
		return (2);
	if (_map[y][x] == 0)
		return (0);
	if (_map[y][x] == 2)
		return (2);
	return (1);
}

int	Event::check_wall2(int y, int x)
{
	//check_bomb2(x, y);
	if (x >= 17 || y >= 17 || x < 0 || y < 0)
		return (2);
	if (_map[y][x] == 0)
		return (0);
	if (_map[y][x] == 2)
		return (2);
	return (1);
}

bool	Event::isMovingP1()
{
	return (m_isMoving);
}

bool	Event::isMovingP2()
{
	return (_isMovingP2);
}
