//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// 
//

#include "Block.hpp"

Block::Block(std::tuple<std::size_t, std::size_t, int> coor, irr::io::path file, irr::io::path normal) : _filename(file), _normal(normal)
{
	std::tie(_x, _y, _z) = coor;
	_x *= 30;
	_y *= 30;
	_z *= 30;
}

Block::~Block()
{
}

void			Block::set_type(std::size_t type)
{
	_type = type;
}

std::size_t		Block::get_x() const
{
	return _x;
}

std::size_t		Block::get_y() const
{
	return _y;
}

int			Block::get_z() const
{
	return _z;
}

irr::io::path	Block::get_filename() const
{
	return _filename;
}

irr::io::path	Block::get_normal() const
{
	return _normal;
}
