//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
//
//

#ifndef	MAP_HPP_
# define MAP_HPP_

# include <iostream>
# include <vector>
# include <tuple>
# include "Wall.hpp"
# include "irrlicht.h"
# include "Block.hpp"
# include "Ground.hpp"

class Obj;

class	Map {
	std::vector<std::vector<size_t> >	_map;
	std::vector<std::vector<Obj *> >	_map3d;
	std::vector<Ground *>			_ground;

public:
	Map(int density);
	~Map();
	std::vector<std::vector<size_t> >	*getMap();
	void					print_map();
	void					displayMap(irr::video::IVideoDriver*, irr::scene::ISceneManager*);
	bool					is_block(std::size_t, std::size_t);	
	std::vector<std::vector<Obj *> >	*get_map3d();

private:
	void				       	create_map(std::size_t);
	void					create_destructible_walls(std::size_t);
	void					init_map(int);
	void					create_ground();
	void					create_right_wall(int);
	void					create_left_wall(int);
	void					create_bottom_wall(int);
	void					create_top_wall(int);
	void					add_torch(irr::scene::ISceneManager*, std::tuple<int, int, int>);
	void					draw_block(irr::scene::ISceneManager*, Obj *, irr::video::IVideoDriver *);
	void					put_background(irr::scene::ISceneManager*, irr::video::IVideoDriver*);
	void					draw_ground(irr::scene::ISceneManager *, Ground *, irr::video::IVideoDriver *);
	void					assign_map_in_block();
};

#endif /* MAP_HPP_ */
