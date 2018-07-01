/*
** EPITECH PROJECT, 2018
** error
** File description:
** 
*/

#ifndef _ERROR_HPP_
# define _ERROR_HPP_

# include <iostream>

# define BLUE			"\033[34m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define DEFAULT		"\033[0m"

enum ERROR
{
	ERREUR1 = -1,
	ERREUR2 = -2
};

enum STATUS
{
	FAIL = -1,
	SUCCESS = 0
};

int				error(int);

#endif /* _ERROR_HPP_ */
