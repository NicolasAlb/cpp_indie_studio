//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Player.hpp
//

#ifndef			PLAYER_HPP_
# define		PLAYER_HPP_

# include		<iostream>
# include 		"irrlicht.h"
//# include 		"Map.hpp"

class Map;
class			Player
{
	const bool	_isplayer;
	std::size_t	_x;
	std::size_t	_y;
	irr::io::path	_texture;
	bool		_move_up;
	bool		_move_left;
	bool		_move_down;
	bool		_move_right;

public:
	// Constructor + Destructor
	Player(bool, std::size_t, std::size_t, irr::io::path);
	~Player();

	// Getters
	std::size_t	get_x(void) const;
	std::size_t	get_y(void) const;
	irr::io::path	get_texture(void) const;
	bool		get_move_up(void) const;
	bool		get_move_left(void) const;
	bool		get_move_down(void) const;
	bool		get_move_right(void) const;

	// Setters
	void		set_x(std::size_t);
	void		set_y(std::size_t);
	void		set_texture(irr::io::path);
	void		set_move_up(bool);
	void		set_move_left(bool);
	void		set_move_down(bool);
	void		set_move_right(bool);

	// Usual Functions
	void 		move(std::size_t, std::size_t);
	bool 		can_move_up(Map map);
	bool 		can_move_left(Map map);
	bool 		can_move_down(Map map);
	bool 		can_move_right(Map map);
	void 		move_up(Map map);
	void 		move_left(Map map);
	void 		move_down(Map map);
	void 		move_right(Map map);
	void 		check_possibility(void);
	//void 		drop_bomb(std::vector<Bomb>);
};

#endif			// PLAYER_HPP_
