#ifndef COMMON_H
# define COMMON_H

#include <stdlib.h>
#include <limits.h>
#include "./../instructions/instructions.h"
#include "./../../dependencies/libft/libft.h"
#include "./../../dependencies/get_next_line/get_next_line.h"

/*
** User interface
*/

void    input(char *message, char **line);
void    error();

/*
** Stack creation
*/

t_element       *crt_stack(char *str);

#endif