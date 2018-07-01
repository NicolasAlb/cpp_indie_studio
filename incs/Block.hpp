//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// 
//

#ifndef BLOCK_HPP_
# define BLOCK_HPP_

# include <iostream>
# include <tuple>
# include "irrlicht.h"

class	Block
{
	std::size_t		_x;
	std::size_t		_y;
	int			_z;
	irr::io::path		_filename;
	irr::io::path		_normal;
	std::size_t		_type;

public:
	Block(std::tuple<size_t, size_t, int>, irr::io::path, irr::io::path);
	~Block();

public:
	void			set_type(std::size_t);
	std::size_t		get_x() const;
	std::size_t		get_y() const;
	int			get_z() const;
	irr::io::path		get_filename() const;
	irr::io::path		get_normal() const;
};

#endif /* BLOCK_HPP_ */
