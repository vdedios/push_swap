#include "instructions.h"

static void	push(t_element **origin, t_element **dest)
{
	t_element	*aux;

	if (*origin)
	{
		aux = (*origin)->next;
		(*origin)->next = *dest;
		*dest = *origin;
		*origin = aux;
	}
}

void	push_a(t_element **stack_a, t_element **stack_b, int prnt)
{
	push(stack_b, stack_a);
	if (prnt)
		ft_putstr_fd("pa\n", 1);
}

void	push_b(t_element **stack_a, t_element **stack_b, int prnt)
{
	push(stack_a, stack_b);
	if (prnt)
		ft_putstr_fd("pb\n", 1);
}
