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
** Common sorting algorithms
*/

t_element    *merge_sort(t_element *stack_a);

#endif