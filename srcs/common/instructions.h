#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

#include <stdlib.h>
#include "./common.h"
#include "./../../dependencies/libft/libft.h"
#include "./../../dependencies/get_next_line/get_next_line.h"

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