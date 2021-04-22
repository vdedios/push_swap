#include "instructions.h"
#include "common.h"

t_element	*split_stack(t_element **stack, int len)
{
	t_element	*aux;

	aux = NULL;
	while (len)
	{
		push_b(stack, &aux, 0);
		len--;
	}
	return (aux);
}

void	remove_a(t_element **stack_a, t_element **stack_b, int *a_len)
{
	rot_a(stack_a, stack_b, 0);
	*a_len -= 1;
}

void	remove_b(t_element **stack_a, t_element **stack_b, int ptr)
{
	push_a(stack_a, stack_b, ptr);
	rot_a(stack_a, stack_b, ptr);
}

short	two_els(t_element **stack_a, t_element **stack_b)
{
	if (!(*stack_a)->next && !(*stack_b)->next)
	{
		if ((*stack_a)->value < (*stack_b)->value)
			remove_b(stack_a, stack_b, 0);
		else
			push_a(stack_a, stack_b, 0);
		return (1);
	}
	return (0);
}
