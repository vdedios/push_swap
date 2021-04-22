#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_element	*a;
	t_element	*b;
	int			len;

	if (argc < 2)
		exit(0);
	a = crt_stack(&argv[1]);
	b = NULL;
	normalize(&a);
	len = lst_len(a);
	if (is_sorted(a, len, UP))
		exit(0);
	if (len <= 5)
		push_swap_small(&a, &b, len);
	else
		push_swap(&a, &b, len);
	return (0);
}
