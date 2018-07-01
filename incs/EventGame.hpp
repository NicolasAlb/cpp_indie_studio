//
//EPITECH PROJECT, 2018
//
//File description:
//Makefile
//

#ifndef __EVENT_HPP__
# define __EVENT_HPP__

#include <irrlicht.h>
#include <vector>
#include "Obj.hpp"
#include "Bomb.hpp"
#include "PowerUp.hpp"

class Event : public irr::IEventReceiver
{
public :
	Event(irr::scene::IAnimatedMeshSceneNode *, irr::scene::IAnimatedMeshSceneNode *, std::vector<std::vector<size_t> > *map, std::vector<std::vector<Obj *> > *map3d, std::pair<irr::scene::ISceneManager *, irr::video::IVideoDriver *>, bool);
	virtual bool 	OnEvent(const irr::SEvent &Event);
	void 		majPosMesh(irr::EKEY_CODE);
	void 		majPosMeshP2(irr::EKEY_CODE);
	void		putBomb(std::size_t, std::size_t);
	bool		isMovingP1();
	bool		isMovingP2();
	bool		isBomb();
	void		removeBomb();
	int		check_wall(int, int);
	int		check_wall1(int, int);
	int		check_wall2(int, int);
	void 		check_bomb1(size_t, size_t);
	void 		check_bomb2(size_t, size_t);
	int		check_fire(int, int);
	void		moveP1();
	void		moveP2();

	bool		_isBomb;
	std::vector<Bomb *>					_b;
	std::vector<PowerUp *>					_pow;

private :
	irr::scene::ISceneManager		*_smgr;
	irr::video::IVideoDriver		*_drv;
	irr::scene::IAnimatedMeshSceneNode* 	_player1;
	irr::scene::IAnimatedMeshSceneNode* 	_player2;
	std::vector<std::vector<size_t> >	_map;
	std::vector<std::vector<Obj *> >	*_map3d;
	size_t					_h;
	size_t					_l;
	size_t					_p2x;
	size_t					_p2y;
	size_t					_k;
	bool					m_isMoving;
	bool					_isMovingP2;
	int					_x;
	int					_y;
	int					_x2;
	int					_y2;
	int					_posBx;
	int					_posBy;
	bool					_isPlayer2;
	void	createFireNorth(double n, int, int);
	void	createFireSouth(double n, int, int);
	void	createFireWest(double n, int, int);
	void	createFireEast(double n, int, int);
	void	createFire(int pow, int, int);
};

#endif /* __EVENT_HPP__ */
