#include "./push_swap.h"

void         sort_three(t_element **a, t_element **b)
{
    t_element *next;

    next = (*a)->next;
    if ((*a)->n_val == 1 && !next->n_val)
        swap_a(a, b, 1);
    else if ((*a)->n_val == 2 && next->n_val)
    {
        swap_a(a, b, 1);
        rot_rev_a(a, b, 1);
    }
    else if ((*a)->n_val == 2 && !next->n_val)
        rot_a(a, b, 1);
    else if (!(*a)->n_val && next->n_val == 2)
    {
        swap_a(a, b, 1);
        rot_a(a, b, 1);
    }
    else
        rot_rev_a(a, b, 1);
}

t_element    *sort_part_stack(t_element *start, int len)
{
    t_element *stack;

    stack = extract_stack(start, len);
    stack = merge_sort(stack);
    return (stack);
}
