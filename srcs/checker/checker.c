#include "checker.h"

static void	ko(void)
{
	ft_putstr_fd("KO\n", 1);
	exit(0);
}

void	checker(t_element *stack_a, t_element *stack_b)
{
	int	aux;

	if (stack_b)
		ko();
	aux = stack_a->value;
	while (stack_a->next)
	{
		stack_a = stack_a->next;
		if (aux >= stack_a->value)
			ko();
	}
	ft_putstr_fd("OK\n", 1);
}
