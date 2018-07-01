//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// IA.hpp
//

#ifndef 					__IA_HPP__
# define 					__IA_HPP__

#include 					"EventGame.hpp"

class						IA
{
public:
//Constructor + Destructor
	IA(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *sceneManager, Event *);
	~IA();

//Modele, Position + fonctions utiles
	irr::scene::IAnimatedMeshSceneNode	*_sydney;
	irr::core::vector3df 			_position;
	Event					*_e;

	int 					get_rand(std::vector<std::string>);
	std::vector<std::string> 		check_possibilities(std::vector<std::vector<size_t>> *, irr::core::vector3df *);
	int 					is_wall(std::vector<std::vector<size_t>>, size_t, size_t);
	void 					move();
	void 					move_down(std::string direction, irr::core::vector3df *v);
	void 					move_right(std::string direction, irr::core::vector3df *v);
	void 					move_left(std::string direction, irr::core::vector3df *v);
	void 					move_up(std::string direction, irr::core::vector3df *v);
	void 					iaMove(std::vector<std::vector<size_t>> *);
	void					initSyd(irr::scene::ISceneManager *);
	bool 					is_in_vec(std::string, std::vector<std::string>);
	void 					check_bomb(size_t, size_t);

//Getters
	std::string 				get_dir(void);
	int 					get_speed(void);
	int 					get_power(void);
	int 					get_nbBomb(void);
	bool 					get_wallPass(void);

private:
//Stats
	int 					_x;
	int 					_y;
	std::string 				_dir;
	int					_speed;
	int					_power;
	int					_nbBomb;
	bool					_wallPass;
	bool					_isBomb;
	irr::scene::ISceneManager		*_smgr;
	Bomb					*_b;

//Setters
	void 					set_dir(std::string);
	void 					set_speed(int);
	void 					set_power(int);
	void 					set_nbBomb(int);
	void 					set_wallPass(bool);
	void					putBomb();
};

#endif 						/* __IA_HPP__ */
