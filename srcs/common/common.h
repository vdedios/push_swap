#ifndef COMMON_H
# define COMMON_H

# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include "libft.h"
# include "get_next_line.h"
# include "lst_operations.h"
# include "instructions.h"

/*
** Err
*/

void		error(void);

/*
** Stack operations
*/

t_element	*crt_stack(char **els);
t_element	*extract_stack(t_element *start, int len);
t_element	*sort_part_stack(t_element *start, int len);

/*
** Sorting
*/

void		normalize(t_element **el);

/*
** Util functions
*/

int			simple_atoi(char *nptr);
void		clean_matrix(char **str);

/*
** Merge sort algorithm
*/

t_element	*merge_sort(t_element *stack_a);

/*
** Merge sort util functions
*/

t_element	*split_stack(t_element **stack, int len);
void		remove_a(t_element **stack_a, t_element **stack_b, int *a_len);
void		remove_b(t_element **stack_a, t_element **stack_b, int ptr);
short		two_els(t_element **stack_a, t_element **stack_b);

#endif
