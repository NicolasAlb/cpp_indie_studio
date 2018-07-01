//
// EPITECH PROJECT, 2018
// init
// File description:
// 
//

#include "Bomberman.hpp"
#include "EventMenu.hpp"

void		init_buttons(t_env &my_env)
{
	my_env.play = my_env.gui->addButton(irr::core::rect<irr::s32>(1400, 400, 1600, 450),
					    0, PLAY, L"Play : 1 player", L"Launch the game for one player");
	my_env.play2 = my_env.gui->addButton(irr::core::rect<irr::s32>(1600, 400, 1800, 450),
					    0, PLAY2, L"Play : 2 players", L"Launch the game for two players");
	my_env.option = my_env.gui->addButton(irr::core::rect<irr::s32>(1500, 450, 1700, 500),
					    0, OPTION, L"Options", L"Set the gameplay");
	my_env.help = my_env.gui->addButton(irr::core::rect<irr::s32>(1500, 500, 1700, 550),
					    0, HELP, L"Help", L"If you need help ;)");
	my_env.quit = my_env.gui->addButton(irr::core::rect<irr::s32>(1500, 550, 1700, 600),
					    0, QUIT, L"Quit", L"Exit the proram");
	my_env.back = my_env.gui->addButton(irr::core::rect<irr::s32>(1500, 600, 1700, 650),
					    0, MENU, L"Back to the menu", L"Go back to the menu");
}

void				init_struct(t_env &my_env, MyEventReceiver &receiver)
{
	irr::IrrlichtDevice		*getResolution = irr::createDevice(irr::video::EDT_NULL);
	irr::core::dimension2d<irr::u32> deskres =
		getResolution->getVideoModeList()->getDesktopResolution();
	irr::gui::IGUISkin		*skin;
	irr::gui::IGUIFont		*font;

	getResolution->drop();
	my_env.pMenu = MENU;
	my_env.deskres = deskres;
	my_env.device = irr::createDevice(irr::video::EDT_SOFTWARE, deskres);
	my_env.driver = my_env.device->getVideoDriver();
	my_env.smgr = my_env.device->getSceneManager();
	my_env.gui = my_env.device->getGUIEnvironment();
	my_env.densityBar = my_env.gui->addScrollBar(true, irr::core::rect<irr::s32>
						     (my_env.deskres.Width / 2 + 500,
						      my_env.deskres.Height / 2 - 80,
						      my_env.deskres.Width / 2 + 850,
						      my_env.deskres.Height / 2 - 40), 0,
						     DENSITY_SCROLLBAR);
	my_env.densityBar->setMax(140);
	my_env.densityBar->setPos(40);
	my_env.density = 5;
	my_env.shadersBar = my_env.gui->addScrollBar(true, irr::core::rect<irr::s32>
						     (my_env.deskres.Width / 2 + 500,
						      my_env.deskres.Height / 2,
						      my_env.deskres.Width / 2 + 650,
						      my_env.deskres.Height / 2 + 40), 0,
						     DENSITY_SHADERSBAR);
	my_env.shadersBar->setMax(10);
	my_env.shadersBar->setPos(0);
	my_env.back = NULL;
	my_env.play = NULL;
	my_env.option = NULL;
	my_env.help = NULL;
	my_env.quit = NULL;
	my_env.game_sound = NULL;
	my_env.menu_sound = NULL;
	my_env.click_sound = irrklang::createIrrKlangDevice();
	my_env.device->setResizable(false);
	my_env.device->setEventReceiver(&receiver);
	my_env.text = NULL;
	my_env.pos = 5;
	my_env.has_menu_sound = false;
	my_env.shaders = false;
	skin = my_env.gui->getSkin();
	font = my_env.gui->getFont("assets/fonthaettenschweiler.bmp");
	if (font != NULL)
		skin->setFont(font);
	my_env.image = my_env.driver->getTexture("assets/Bomberman.png");
}
