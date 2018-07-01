//
// EPITECH PROJECT, 2018
// bomberman
// File description:
// intro
//

#ifndef _INTRO_HPP_
# define _INTRO_HPP_

# include <irrlicht.h>
# include <iostream>

class	Intro
{
	irr::scene::ISceneManager	*_smgr;
	irr::scene::IMeshSceneNode      *_cube;
public:
	Intro(irr::scene::ISceneManager *, irr::video::IVideoDriver *);
	~Intro();
};

#endif
