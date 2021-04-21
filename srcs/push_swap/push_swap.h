#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define UP 1
# define DOWN 2

#include "common.h"

typedef struct	s_chunk {
    t_element   *stack;
    t_element   *start;
    t_element   *end;
    char        id;
}				t_chunk;

/*
** Push swap sorting functions
*/

void            sort_three(t_element **a, t_element **b);

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
** Chunk functions
*/

void            new_chunk_limit(t_element *stack, t_element *limit);
void            set_chunk_limit(t_element **b, int *is_limit_set);
int             chunk_len(t_element *a);

/*
** Utils
*/

short           is_sorted(t_element *start, int len, short order);
short           is_max_or_min(t_element *stack);
short           is_left_values(t_element *b, t_element *pivot);

#endif