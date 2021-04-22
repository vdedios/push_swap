#include "checker.h"

int	main(int argc, char **argv)
{
	t_element	*instructions;
	t_element	*a;
	t_element	*b;
	t_op		options;

	if (argc < 2)
		exit(0);
	a = crt_stack(&argv[1 + read_options(&argv[1], &options, argc)]);
	b = NULL;
	normalize(&a);
	if (options.visualize)
		options.visualize = lst_len(a);
	instructions = read_instructions();
	sort(instructions, &a, &b, options);
	op_count(instructions, options);
	checker(a, b);
	return (0);
}
