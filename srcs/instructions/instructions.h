#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

#include <stdlib.h>
#include "./../../dependencies/libft/libft.h"
#include "./../../dependencies/get_next_line/get_next_line.h"

typedef struct	s_element {
    int         value;
    void        *next;
}				t_element;

/*
** Instructions util functions
*/

t_element       *lst_goto(t_element *stack, short pos);
t_element       *lst_last(t_element *stack);
size_t          lst_len(t_element *stack);

/*
** Instructions
*/

void            swap(t_element **stack);
void            rot_rev(t_element **stack);
void            rot(t_element *stack);

#endif