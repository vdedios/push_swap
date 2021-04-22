#include "./push_swap.h"

static void	rot_towards_max(t_element **a, t_element **b,
									t_element *max, int len)
{
	int			d;
	t_element	*aux;

	d = 0;
	aux = *b;
	while (aux && aux->value != max->value)
	{
		aux = aux->next;
		d++;
	}
	if (d < len / 2)
		rot_b(a, b, 1);
	else
		rot_rev_b(a, b, 1);
}

void	rot_and_split_to_b(t_element **a, t_element **b, int len)
{
	while (len)
	{
		if ((*a)->n_val == 0 || (*a)->n_val == lst_last(*a)->n_val + 1)
			rot_a(a, b, 1);
		else
			push_b(a, b, 1);
		len--;
	}
}

void	rotate_stack_back(t_element **a, t_element **b, int rot)
{
	while (rot)
	{
		if (is_max_or_min(*b))
			rot_rev_a(a, b, 1);
		else
			rot_rev_ab(a, b, 1);
		rot--;
	}
}

void	rotate_maxs(t_element **a, t_element **b)
{
	while ((*a)->next && (*a)->n_val == lst_last(*a)->n_val + 1)
		rot_a(a, b, 1);
}

void	conquer_back(t_element **a, t_element **b, int len)
{
	t_element	*sorted;
	t_element	*max;

	sorted = sort_part_stack(*b, len);
	while (len)
	{
		max = lst_last(sorted);
		if ((*b)->n_val == 0 || (*b)->n_val == lst_last(*a)->n_val + 1)
		{
			push_a(a, b, 1);
			rot_a(a, b, 1);
			len--;
		}
		else if ((*b)->value == max->value)
		{
			push_a(a, b, 1);
			lst_goto(sorted, lst_len(sorted) - 2)->next = NULL;
			len--;
		}
		else
			rot_towards_max(a, b, max, len);
	}
}
