#include "./push_swap.h"

short        is_sorted(t_element *start, int len, short order)
{
    t_element *next;

    while (len > 1)
    {
        next = start->next;
        if (order == UP && start->value > next->value)
        {
            return (0);
        }
        if (order == DOWN && start->value < next->value)
        {
            return (0);
        }
        start = next;
        len--;
    }
    return (1);
}

short        is_max_or_min(t_element *stack)
{
    t_element   *sorted;
    int         len;

    len = lst_len(stack);
    sorted = sort_part_stack(stack, len);
    return ((short)(lst_last(sorted)->value == lst_last(stack)->value)
           || (short)(lst_last(sorted)->value == stack->value)
           || (short)(sorted->value == stack->value));
}

short        is_left_values(t_element *b, t_element *pivot)
{
    while (b)
    {
        if (b->value > pivot->value)
            return (1);
        b = b->next;
    }
    return (0);
}
