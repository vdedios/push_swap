#include "./push_swap.h"

void	push_swap_small(t_element **a, t_element **b, int len)
{
	if (len <= 3)
		sort_three(a, b);
	else
	{
		split_to_b_small(a, b, len);
		sort_three(a, b);
		back_split(a, b, lst_len(*b));
	}
}

void	push_swap(t_element **a, t_element **b, int len)
{
	if (len > 20)
		split_to_b(a, b, len);
	else
		rot_and_split_to_b(a, b, len);
	back_split(a, b, lst_len(*b));
	if ((*a)->n_val)
		push_swap(a, b, chunk_len(*a));
}
