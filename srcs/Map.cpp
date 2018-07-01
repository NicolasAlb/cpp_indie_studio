
//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
//
//

#include "Map.hpp"

Map::Map(int density)
{
	std::vector<std::vector<size_t> >	map(17, std::vector<size_t>(17));
	std::vector<std::vector<Obj*> >	map3d(17, std::vector<Obj*>(17));
	_map = map;
	_map3d = map3d;
	create_map(density);
}
						Map::~Map()
{
	for (std::size_t y = 0; y < _map3d.size(); y++)
		for (std::size_t x = 0; x < _map3d[y].size(); x++)
			if (_map3d[y][x])
				delete _map3d[y][x];
	for (std::size_t i = 0; i < _ground.size(); i++)
		delete _ground[i];
}

std::vector<std::vector<std::size_t> >		*Map::getMap()
{
	return &_map;
}

void						Map::create_ground()
{
	for (int y = -6; y < 40; y++)
		for (int x = -30; x < 45; x++)
			_ground.push_back(new Ground(std::make_tuple(x, y, -1), std::make_pair("./assets/grass.bmp", "./assets/grass_normal.png")));
		   
}

void						Map::create_top_wall(int z)
{
	for (std::size_t x = 0; x < _map[0].size(); x++) {
		_map[0][x] = 1;
		_map3d[0][x] = new Wall(std::make_tuple(x, 0, z), std::make_pair("./assets/rock_n.bmp", "./assets/rock_n_normal.png"), 0, 0);
//		_map3d[0][x]->set_type(1);
	}
}

void					Map::create_bottom_wall(int z)
{
	for (std::size_t x = 0; x < _map[0].size(); x++) {
		_map[_map.size() - 1][x] = 1;
		_map3d[_map.size() - 1][x] = (Obj *)new Wall(std::make_tuple(x, _map.size() - 1, z), std::make_pair("./assets/rock_n.bmp", "./assets/rock_n_normal.png"), 0, 0);
//		_map3d[_map.size() - 1][x]->set_type(1);
	}
}

void					Map::create_left_wall(int z)
{
	for (std::size_t y = 0; y < _map.size(); y++) {
		_map[y][0] = 1;
		_map3d[y][0] = (Obj *) new Wall(std::make_tuple(0, y, z), std::make_pair("./assets/rock_n.bmp", "./assets/rock_n_normal.png"), 0 ,0);
//		_map3d[y][0]->set_type(1);
	}
}

void					Map::create_right_wall(int z)
{
	for (std::size_t y = 0; y < _map.size(); y++) {
		_map[y][_map[0].size() - 1] = 1;
		_map3d[y][_map[0].size() - 1] = (Obj *) new Wall(std::make_tuple(_map[0].size() - 1, y, z), std::make_pair("./assets/rock_n.bmp", "./assets/rock_n_normal.png"), 0, 0);
//		_map3d[y][_map[0].size() - 1]->set_type(1);
	}
}

void					Map::print_map()
{
	for (std::size_t y = 0; y < 17; y++) {
		for (std::size_t x = 0; x < 17; x++) {
		}
	}
}

void					Map::init_map(int z)
{
	for (std::size_t y = 0; y < 17; y++) {
		for (std::size_t x = 0; x < 17; x++) {
			if (y % 2 == 0 && x % 2 == 0) {
				_map[y][x] = 1;
				_map3d[y][x] = (Obj *) new Wall(std::make_tuple(x, y, z), std::make_pair("./assets/rock_n.bmp", "./assets/rock_n_normal.png"), 0, 0);
//				_map3d[y][x]->set_type(1);
			}
			else {
				_map[y][x] = 0;
				_map3d[y][x] = NULL;
				if (z == 0) {
					/*_map3d[y][x] = new Ground(std::make_tuple(x, y, z), "./assets/grass.bmp", "./assets/grass_normal.png");
					  _map3d[y][x]->set_type(0);*/
				}
			}
		}
	}
}

void					Map::create_destructible_walls(
	std::size_t density)
{
	std::size_t	nb_walls;
	std::size_t	x = 0;
	std::size_t	y = 0;

	std::srand(time(NULL));
	nb_walls = density * ((std::rand() % 10) + 11);
	if (nb_walls > 164)
		nb_walls = 164;
	for (std::size_t i = 0; i < nb_walls; i++) {
		while (_map[y][x] == 1 || _map[y][x] == 2 ||
		       (y <= 2 && x <= 2) || (y <= 2 && x >= 14) ||
		       (y >= 14 && x <= 2) || (y >= 14 && x >= 14)) {
			x = (std::rand() % 15) + 1;
			y = (std::rand() % 15) + 1;
		}
		_map[y][x] = 2;
		_map3d[y][x] = (Obj *) new Wall(std::make_tuple(x, y, -1), std::make_pair("./assets/rock.bmp", "./assets/rock_normal.png"), 1, 0);
//		_map3d[y][x]->set_type(2);
		x = 0;
		y = 0;
	}
}

void		Map::create_map(
	std::size_t density)
{
	int z = -1;
	//for (int z = 0; z > -2; z--) {
		init_map(z);
		create_ground();
		create_top_wall(z);
		create_left_wall(z);
		create_right_wall(z);
		create_bottom_wall(z);
		//}
	create_destructible_walls(density);

	assign_map_in_block();

}

void	Map::assign_map_in_block()
{
	int	i = 0;
	int	j = 0;

	while (i < 17)
	{
		j = 0;
		while (j < 17)
		{
			if (_map[i][j] == 2)
				_map3d[i][j]->_map = &_map;
			j = j + 1;
		}
		i = i + 1;
	}
}

void	Map::put_background(irr::scene::ISceneManager *smgr, irr::video::IVideoDriver *driver)
{
	irr::scene::IAnimatedMeshSceneNode		*back;
	irr::scene::IAnimatedMesh			*mesh = smgr->getMesh("./assets/table.3ds");

	back = smgr->addAnimatedMeshSceneNode(mesh);
	back->setPosition(irr::core::vector3df(260, 800, 40));
	back->setRotation(irr::core::vector3df(-90, 0, 0));
	back->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	back->setMaterialTexture(0, driver->getTexture("./assets/table.3ds"));
//	back->addShadowVolumeSceneNode();
//	smgr->setShadowColor(irr::video::SColor(150, 0, 0, 0));
}

/*void	Map::draw_ground(irr::scene::ISceneManager *smgr, Ground *grd, irr::video::IVideoDriver *drv)
{
	irr::scene::IMeshSceneNode      *cube;

	cube = smgr->addCubeSceneNode(
		30.0f, 0, -1,
		irr::core::vector3df(
			grd->get_x(),
			grd->get_y(),
			grd->get_z()));
	cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	cube->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING, true);
	cube->setMaterialTexture(0, drv->getTexture(grd->getTextures().first));
//	cube->setMaterialTexture(1, drv->getTexture(grd->getTexture().second));
	cube->addShadowVolumeSceneNode();
	smgr->setShadowColor(irr::video::SColor(150,0,0,0));
}

void	Map::draw_block(irr::scene::ISceneManager *smgr, Obj *blk, irr::video::IVideoDriver *drv)
{
	irr::scene::IMeshSceneNode      *cube;

	cube = smgr->addCubeSceneNode(
		30.0f, 0, -1,
		irr::core::vector3df(
			blk->get_x(),
			blk->get_y(),
			blk->get_z()));
	cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	cube->setMaterialFlag(irr::video::EMF_GOURAUD_SHADING, true);
	cube->setMaterialTexture(0, drv->getTexture(blk->get_textures().first));
	cube->setMaterialTexture(1, drv->getTexture(blk->get_textures().second));
	cube->addShadowVolumeSceneNode();
	smgr->setShadowColor(irr::video::SColor(150,0,0,0));
	}*/

void	Map::add_torch(irr::scene::ISceneManager *smgr, std::tuple<int, int, int> coor)
{
	int	x, y, z;
	irr::scene::IAnimatedMeshSceneNode     	*back;
	irr::scene::IAnimatedMesh	       	*mesh = smgr->getMesh("./assets/lamp3.3DS");

	std::tie(x, y, z) = coor;
//	node = smgr->addLightSceneNode(0, irr::core::vector3df(x - 20, y - 20, z - 60),
//					  irr::video::SColorf(1.0f, 1.0f, 0.0f, 0.0f), 60.0f);
	smgr->addLightSceneNode (0, irr::core::vector3df(x, y - 15, z - 110), irr::video::SColorf(0.5f,0.2f,0.0f,0.0f), 200.0f);
	smgr->addLightSceneNode (0, irr::core::vector3df(x, y + 15, z - 110),
				 irr::video::SColorf(0.5f,0.2f,0.0f,0.0f), 200.0f);
	smgr->addLightSceneNode (0, irr::core::vector3df(x - 15, y, z - 110),
				 irr::video::SColorf(0.5f,0.2f,0.0f,0.0f), 200.0f);
	smgr->addLightSceneNode (0, irr::core::vector3df(x - 15, y, z - 110), irr::video::SColorf(0.5f,0.2f,0.0f,0.0f), 200.0f);
	//smgr->createFlyCircleAnimator(irr::core);
	back = smgr->addAnimatedMeshSceneNode(mesh);
	back->setPosition(irr::core::vector3df(x - 263, y + 193, z));
	back->setRotation(irr::core::vector3df(-90, 0, 0));
	back->setMaterialFlag(irr::video::EMF_LIGHTING, true);
	back->setScale(irr::core::vector3df(0.9, 0.9, 0.9));
	//back->getMaterial(0).EmissiveColor = irr::video::SColor(255,0,255,255);
	back->addShadowVolumeSceneNode();
}

void	Map::displayMap(irr::video::IVideoDriver *drv, irr::scene::ISceneManager *smgr)
{
	//put_background(smgr, drv);
	for (std::size_t y = 0; y < _map3d.size(); y++)
		for (std::size_t x = 0; x < _map3d[y].size(); x++) {
			if (_map3d[y][x] != NULL)
				_map3d[y][x]->draw(smgr, drv);
				//draw_block(smgr, _map3d[y][x], drv);
		}
	for (std::size_t i = 0; i < _ground.size(); i++)
		_ground[i]->draw(smgr, drv);
		//draw_ground(smgr, _ground[i], drv);
}

bool	Map::is_block(std::size_t x, std::size_t y)
{
	if (_map3d[y][x]) {
		return true;
	}
	/*for (std::size_t y = 0; y < _map3d.size(); y++)
		for (std::size_t x = 0; x < _map3d[y].size(); x++) {
			if (_map3d[y][x]->get_z() < 0 && _map3d[y][x]->get_x() == x && _map3d[y][x]->get_y() == y ) {
				return true;
			}
			}*/
	return false;
}

std::vector<std::vector<Obj *> >	*Map::get_map3d()
{
	return &_map3d;
}
