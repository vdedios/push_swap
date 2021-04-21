#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define UP 1
# define DOWN 2

#include "../instructions/instructions.h"
#include "../common/common.h"

typedef struct	s_chunk {
    t_element   *stack;
    t_element   *start;
    t_element   *end;
    char        id;
}				t_chunk;


/*
** Merge sort algorithm
*/

t_element    *merge_sort(t_element *stack_a);

/*
** Merge sort util functions
*/

t_element    *split_stack(t_element **stack, int len);
void         remove_a(t_element **stack_a, t_element **stack_b, int *a_len);
void         remove_b(t_element **stack_a, t_element **stack_b);
short        two_els(t_element **stack_a, t_element **stack_b);

#endif