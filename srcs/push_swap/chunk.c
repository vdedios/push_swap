#include "./push_swap.h"

void	new_chunk_limit(t_element *stack, t_element *limit)
{
	while (limit && stack && stack->next != limit)
		stack = stack->next;
	if (stack && limit)
		stack->chunk_limit = 1;
}

void	set_chunk_limit(t_element **b, int *is_limit_set)
{
	if (*is_limit_set)
	{
		(*b)->chunk_limit = 0;
	}
	else
	{
		(*b)->chunk_limit = 1;
		*is_limit_set = 1;
	}
}

int	chunk_len(t_element *a)
{
	int	len;

	len = 0;
	while (a && !a->chunk_limit && a->n_val)
	{
		a = a->next;
		len++;
	}
	if (a->n_val)
		len++;
	return (len);
}
