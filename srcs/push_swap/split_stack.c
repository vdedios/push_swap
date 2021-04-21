#include "./push_swap.h"

static t_element    *get_pivot(t_element **stack, int len)
{
    t_element   *sorted;
    t_element   *pivot;

    sorted = sort_part_stack(*stack, len);
    pivot = lst_goto(sorted, len / 2);
    return (pivot);
}

void                split_to_b(t_element **a, t_element **b, int len)
{
    t_element   *pivot;
    t_element   *limit;
    int         stack_len;
    int         rot;

    rot = 0;
    stack_len = lst_len(*a);
    pivot = get_pivot(a, len);
    limit = NULL;
    while (lst_len(*b) <= len / 2)
    {
        if ((*a)->chunk_limit)
            limit = (*a)->next;
        if ((*a)->value <= pivot->value)
            push_b(a, b, 1);
        else
        {
            if (len < stack_len)
                rot++;
            rot_a(a, b, 1);
        }
    }
    rotate_stack_back(a, b, rot);
    new_chunk_limit(*a, limit);
}

void                split_to_a(t_element **a, t_element **b, int len)
{
    t_element   *pivot;
    int         is_limit_set; 
    int         half;

    if (!(*b)->next)
    {
        push_a(a, b, 1);
        return;
    }
    pivot = get_pivot(b, len);
    is_limit_set = 0;
    while ((*b) && is_left_values(*b, pivot))
        if ((*b)->value > pivot->value)
        {
            set_chunk_limit(b, &is_limit_set);
            push_a(a, b, 1);
        }
        else
        {
            if ((*b)->n_val == 0 || (*b)->n_val == lst_last(*a)->n_val + 1)
                remove_b(a, b);
            else
                rot_b(a, b, 1);
        }
}

void                back_split(t_element **a, t_element **b, int len)
{
    if (len > 20)
    {
        split_to_a(a, b, len);
        back_split(a, b, lst_len(*b));
    }
    else if (len)
    {
        conquer_back(a, b, len);
        rotate_maxs(a, b);
    }
}

void                split_to_b_small(t_element **a, t_element **b, int len)
{
    short limit;

    if (len == 4)
        limit = 1;
    else
        limit = 2;
    while (lst_len(*b) < limit)
    {
        if ((*a)->n_val > 2)
            push_b(a, b, 1);
        else
            rot_a(a, b, 1);
    }
    if ((*b)->next && (*b)->value > ((t_element *)(*b)->next)->value)
            rot_b(a, b, 1);
}
