#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define UP 1
# define DOWN 2

#include "../common/instructions/instructions.h"
#include "../common/lst_operations/lst_operations.h"
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

t_element       *merge_sort(t_element *stack_a);

/*
** Merge sort util functions
*/

t_element       *split_stack(t_element **stack, int len);
void            remove_a(t_element **stack_a, t_element **stack_b, int *a_len);
void            remove_b(t_element **stack_a, t_element **stack_b);
short           two_els(t_element **stack_a, t_element **stack_b);

/*
** Push swap sorting functions
*/

void            sort_three(t_element **a, t_element **b);
t_element       *sort_part_stack(t_element *start, int len);

/*
** Split back movement functions
*/

void            rot_and_split_to_b(t_element **a, t_element **b, int len);
void            rotate_stack_back(t_element **a, t_element **b, int rot);
void            rotate_maxs(t_element **a, t_element **b);
void            conquer_back(t_element **a, t_element **b, int len);

/*
** Split stack functions
*/

void            split_to_a(t_element **a, t_element **b, int len);
void            split_to_b(t_element **a, t_element **b, int len);
void            back_split(t_element **a, t_element **b, int len);
void            split_to_b_small(t_element **a, t_element **b, int len);

/*
** Utils
*/

void            find_and_replace(t_element *source, t_element *dest, int value);
short           is_sorted(t_element *start, int len, short order);
short           is_max_or_min(t_element *stack);
short           is_left_values(t_element *b, t_element *pivot);

#endif