#include "checker.h"

static void	ko(void)
{
	ft_putstr_fd("KO\n", 1);
	exit(0);
}

static void	inspect_order(t_element *stack_a, t_element *stack_b)
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

int	main(int argc, char **argv)
{
	t_element	*instructions;
	t_element	*a;
	t_element	*b;
	t_op		options;

	if (argc < 2)
		exit(0);
	a = crt_stack(&argv[1 + read_options(&argv[1], &options)]);
	b = NULL;
	normalize(&a);
	if (options.visualize)
		options.visualize = lst_len(a);
	instructions = read_instructions();
	sort(instructions, &a, &b, options);
	op_count(instructions, options);
	inspect_order(a, b);
	return (0);
}
