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

void            input(char *message, char **line);
void            error();

/*
** Stack creation
*/

t_element       *crt_stack(char *str);

/*
** Instruction set creation
*/

t_instruction   crt_instructions(char *input);

/*
** Stack utils
*/

void            lst_print(t_element *stack);
void            lst_add(t_element **stack, int value);

#endif