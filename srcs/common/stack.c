#include "common.h"

static void	find_and_replace(t_element *source, t_element *dest, int value)
{
	while (dest && source->value != dest->value)
		dest = dest->next;
	if (dest)
		dest->n_val = value;
}

t_element	*extract_stack(t_element *start, int len)
{
	t_element	*stack;

	stack = NULL;
	while (len)
	{
		lst_add(&stack, start->value);
		start = start->next;
		len--;
	}
	return (stack);
}

t_element	*crt_stack(char **els)
{
	t_element	*stack;

	stack = NULL;
	while (*els)
	{
		lst_add(&stack, simple_atoi(*els));
		els++;
	}
	clean_matrix(els);
	return (stack);
}

t_element	*sort_part_stack(t_element *start, int len)
{
	t_element	*stack;

	stack = extract_stack(start, len);
	stack = merge_sort(stack);
	return (stack);
}

void	normalize(t_element **el)
{
	int			len;
	int			i;
	t_element	*sorted;

	i = -1;
	len = lst_len(*el);
	sorted = sort_part_stack(*el, lst_len(*el));
	while (++i < len)
	{
		find_and_replace(sorted, *el, i);
		sorted = sorted->next;
	}
}
