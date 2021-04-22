#include "common.h"

static void	check_el_duplicate(t_element *stack, int value)
{
	if (stack)
	{
		while (stack->next)
		{
			if (value == stack->value)
				error();
			stack = stack->next;
		}
		if (value == stack->value)
			error();
	}
}

void	lst_add(t_element **stack, int value)
{
	t_element	*new;
	t_element	*last;

	if (stack)
	{
		new = malloc(sizeof(t_element));
		if (new)
		{
			check_el_duplicate(*stack, value);
			new->value = value;
			new->chunk_limit = 0;
			new->next = NULL;
			if (!*stack)
				*stack = new;
			else
			{
				last = lst_last(*stack);
				last->next = new;
			}
		}
	}
}
