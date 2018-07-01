//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Ground
//

#ifndef __GROUND_HPP__
# define __GROUND_HPP__

#include "Obj.hpp"

class	Ground : public Obj
{
public:
	Ground(std::tuple<int, int, int>, std::pair<irr::io::path, irr::io::path>);
	~Ground();
//	int	get_x();
//	int	get_y();
//	int	get_z();
	PowerUp	*removeBreakableWall(irr::scene::ISceneManager *, irr::video::IVideoDriver*) { return (NULL); }
	std::pair<irr::io::path, irr::io::path>	getTextures();
	void	draw(irr::scene::ISceneManager *, irr::video::IVideoDriver*);
};

#endif /* __GROUND_HPP__ */
