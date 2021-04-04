#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

#include <stdlib.h>
#include "./../../dependencies/libft/libft.h"
#include "./../../dependencies/get_next_line/get_next_line.h"

typedef struct	s_element {
    int         value;
    void        *next;
}				t_element;

typedef struct	s_instruction {
    short       *codes;
    size_t      len;
}				t_instruction;


/*
** Instructions util functions
*/

t_element       *lst_goto(t_element *stack, short pos);
t_element       *lst_last(t_element *stack);
size_t          lst_len(t_element *stack);

/*
** Instructions
*/

void            swap_a(t_element **stack_a, t_element **stack_b);
void            swap_b(t_element **stack_a, t_element **stack_b);
void            swap_ab(t_element **stack_a, t_element **stack_b);
void            rot_a(t_element **stack_a, t_element **stack_b);
void            rot_b(t_element **stack_a, t_element **stack_b);
void            rot_ab(t_element **stack_a, t_element **stack_b);
void            rot_rev_a(t_element **stack_a, t_element **stack_b);
void            rot_rev_b(t_element **stack_a, t_element **stack_b);
void            rot_rev_ab(t_element **stack_a, t_element **stack_b);

#endif