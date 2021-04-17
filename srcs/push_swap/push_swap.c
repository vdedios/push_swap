#include "push_swap.h"

static short        is_sorted(t_element *start, int len, short order)
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

static t_element    *sort_part_stack(t_element *start, int len)
{
    t_element *stack;

    stack = extract_stack(start, len);
    stack = merge_sort(stack);
    return (stack);
}

static void         split_to_b(t_element **a, t_element **b, int len)
{
    t_element   *sorted;
    t_element   *pivot;

    sorted = sort_part_stack(*a, len);
    pivot = STACK_MIDDLE(sorted, lst_len(sorted));
    while (lst_len(*b) <= len / 2)
    {
        if ((*a)->value <= pivot->value)
            push_b(a, b, 1);
        else
            rot_a(a, b, 1);
    }
}

static void         push_swap(t_element **a, t_element **b, int len)
{
    split_to_b(a, b, len);
}

int                 main(int argc, char **argv)
{
    t_element   *a;
    t_element   *b;
    int         len;

    if (argc < 2)
        exit(0);
    a = crt_stack(&argv[1]);
    b = NULL;
    push_swap(&a, &b, lst_len(a));
    return (0);
}