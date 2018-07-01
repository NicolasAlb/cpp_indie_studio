//
//EPITECH PROJECT, 2018
//
//File description:
//Makefile
//

#ifndef __OBJ_HPP__
# define __OBJ_HPP__

# include <irrlicht.h>
# include "Bomberman.hpp"
# include "PowerUp.hpp"

class	Obj
{
public:
	Obj(std::tuple<int, int, int>, ObjType type, std::pair<irr::io::path, irr::io::path>);
	virtual ~Obj() = 0;
	std::pair<irr::io::path, irr::io::path>	get_textures() const;
	int					get_x() const;
	int					get_y() const;
	int					get_z() const;
	void					set_type(bool);
	virtual	void				draw(irr::scene::ISceneManager*, irr::video::IVideoDriver*) = 0;
	virtual PowerUp				*removeBreakableWall(irr::scene::ISceneManager *, irr::video::IVideoDriver *) = 0;

	std::vector<std::vector<size_t> > *_map;
protected:
	irr::scene::IMeshSceneNode		*_cube;
	int					_posx;
	int					_posy;
	int					_posz;	
	ObjType					_type;
	std::pair<irr::io::path, irr::io::path>	_textures;
	void					destroy();

private:

};

#endif /* __OBJ_HPP__ */
