//
// EPITECH PROJECT, 2018
// error
// File description:
// 
//

#include "Error.hpp"

static const char	*g_tab[] =
{
	"ERREUR 1",
	"ERREUR 2",
	NULL
};

int		error(int err)
{
	int	i = 0;

	err *= -1;
	err -= 1;
	while (g_tab[i])
	{
		if (i == err)
		{
			std::cerr << RED << g_tab[i] << DEFAULT << std::endl;
			std::cerr << RED << "PROGRAM STOPPED" << DEFAULT << std::endl;
		}
		i += 1;
	};
	return (err = err * -1 + 1);
}
