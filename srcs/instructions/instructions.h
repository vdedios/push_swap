#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

#include <stdlib.h>
#include "./../../dependencies/libft/libft.h"
#include "./../../dependencies/get_next_line/get_next_line.h"

typedef struct	s_element {
    int         value;
    int         n_val;
    short       chunk_limit;
    void        *next;
}				t_element;

/*
** Instructions util functions
*/

t_element       *lst_goto(t_element *stack, short pos);
t_element       *lst_last(t_element *stack);
size_t          lst_len(t_element *stack);
size_t          lst_len_end(t_element *stack, t_element *end);

/*
** Instructions
*/

void            swap_a(t_element **stack_a, t_element **stack_b, int prnt);
void            swap_b(t_element **stack_a, t_element **stack_b, int prnt);
void            swap_ab(t_element **stack_a, t_element **stack_b, int prnt);
void            rot_a(t_element **stack_a, t_element **stack_b, int prnt);
void            rot_b(t_element **stack_a, t_element **stack_b, int prnt);
void            rot_ab(t_element **stack_a, t_element **stack_b, int prnt);
void            rot_rev_a(t_element **stack_a, t_element **stack_b, int prnt);
void            rot_rev_b(t_element **stack_a, t_element **stack_b, int prnt);
void            rot_rev_ab(t_element **stack_a, t_element **stack_b, int prnt);
void            push_a(t_element **stack_a, t_element **stack_b, int prnt);
void            push_b(t_element **stack_a, t_element **stack_b, int prnt);

#endif