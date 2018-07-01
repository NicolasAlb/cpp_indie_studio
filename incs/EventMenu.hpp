//
// EPITECH PROJECT, 2018
// event
// File description:
// 
//

#ifndef EVENT_HPP_
# define EVENT_HPP_

#include <irrKlang.h>
#include <iostream>
#include <irrlicht.h>
#include <unistd.h>
#include "driverChoice.h"
#include "Game.hpp"

typedef struct s_env
{
	size_t					pMenu;
	int					density;
	bool					shaders;
	irr::core::dimension2d<irr::u32>	deskres;
	irr::IrrlichtDevice			*device;
	irr::gui::IGUIEnvironment		*gui;
	irr::gui::IGUIButton			*play;
	irr::gui::IGUIButton			*play2;
	irr::gui::IGUIButton			*option;
	irr::gui::IGUIButton			*help;
	irr::gui::IGUIButton			*back;
	irr::gui::IGUIButton			*quit;
	irr::gui::IGUIScrollBar			*densityBar;
	irr::gui::IGUIScrollBar			*shadersBar;
	irr::scene::ISceneManager		*smgr;
	irr::video::IVideoDriver		*driver;
	irr::video::ITexture			*image;
	irr::gui::IGUIStaticText		*text;
	irr::s32				pos;
	irrklang::ISoundEngine			*click_sound;
	irrklang::ISoundEngine			*game_sound;
	irrklang::ISoundEngine			*menu_sound;
	bool					has_menu_sound;
}		t_env;

class MyEventReceiver : public irr::IEventReceiver
{
public:
	MyEventReceiver(t_env	&_my_env, irr::s32 &_pos);

	virtual bool		OnEvent(const irr::SEvent &event);
	virtual bool		isKeyDown(irr::EKEY_CODE keyCode);
	virtual bool		isKeyPressed(irr::EKEY_CODE keyCode);

private:
	bool		_KeyIsDown[irr::KEY_KEY_CODES_COUNT];
	bool		_KeyIsPressed[irr::KEY_KEY_CODES_COUNT];
	t_env		&_my_env;
	irr::s32	&_pos;
};

void				setDensityBar(const irr::SEvent &, t_env &);
void				display_text(t_env &my_env, const wchar_t *msg,
				     std::vector<int> *color, std::vector<int> *position);
int				playSound(t_env &env, int position);
void				stopSound(t_env &env, int position);
std::vector<int>		*set_position(int width_start, int height_start,
					      int width_end, int height_end);
std::vector<int>		*fill_color(int r, int g, int b);
void				init_buttons(t_env &my_env);
void				init_struct(t_env &my_env, MyEventReceiver &receiver);
void				setShadersBar(const irr::SEvent &event, t_env &my_env);
void				display_help(t_env &my_env);
void				display_option(t_env &my_env);
void				display_menu(t_env &my_env);
void				display_game(t_env &my_env, bool isPlayer2);

#endif /* !EVENT_HPP_ */
