//
//EPITECH PROJECT, 2018
//
//File description:
//Makefile
//

#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

#include "EventGame.hpp"

class	Character
{
public:
	Event					*_e;
	irr::scene::IAnimatedMeshSceneNode	*_sydney;
	irr::scene::IAnimatedMeshSceneNode	*_player2;
	irr::core::vector3df 			_position;
	int					_speed;
	int					_power;
	int					_nbBomb;
	bool					_wallPass;
	std::vector<std::vector<size_t> >	*_map;
	std::vector<std::vector<Obj *>  >	*_map3d;
	irr::video::IVideoDriver		*_dvr;
	irr::scene::ISceneManager      		*_smgr;
	bool					_isPlayer2;

	Character(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *sceneManager, irr::IrrlichtDevice *device, std::vector<std::vector<size_t> > *map, std::vector<std::vector<Obj *> > *, std::pair<irr::io::path, irr::io::path>, bool);
	~Character();
	void	init_player2();
	void	checkMove();
	bool	checkBomb();
	void	removeBomb();
	void	increaseSpeed();
	void	increasePower();
	void	increaseNbBomb();
	void	activeWallPass();
	void    takePowerUp(irr::core::vector3df);
	void    destroyPowerUp(size_t, size_t);
private:
};

#endif /* __CHARACTER_HPP__ */
