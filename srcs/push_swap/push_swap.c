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

static void         new_chunk_limit(t_element *stack, t_element *limit)
{
    while (limit && stack && stack->next != limit)
        stack = stack->next;
    if (stack && limit)
        stack->chunk_limit = 1;
}

static short        is_max_or_min(t_element *stack)
{
    t_element   *sorted;
    int         len;

    len = lst_len(stack);
    sorted = sort_part_stack(stack, len);
    return ((short)(lst_last(sorted)->value == lst_last(stack)->value)
           || (short)(lst_last(sorted)->value == stack->value)
           || (short)(sorted->value == stack->value));
}

static void         split_to_b(t_element **a, t_element **b, int len)
{
    t_element   *sorted;
    t_element   *pivot;
    t_element   *limit;
    int         rot;
    int         stack_len;

    rot = 0;
    stack_len = lst_len(*a);
    sorted = sort_part_stack(*a, len);
    pivot = lst_goto(sorted, len / 2);
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
    while (rot)
    {
        if (is_max_or_min(*b))
            rot_rev_a(a, b, 1);
        else
            rot_rev_ab(a, b, 1);
        rot--;
    }
    new_chunk_limit(*a, limit);
}

static void         split_to_a(t_element **a, t_element **b, int len)
{
    t_element   *sorted;
    t_element   *pivot;
    int         pushed;
    int         limit; 

    if (!(*b)->next)
    {
        push_a(a, b, 1);
        return;
    }
    sorted = sort_part_stack(*b, len);
    pivot = lst_goto(sorted, len / 2);
    pushed = 0;
    limit = 1;
    while ((*b) && pushed <= len / 2)
    {
        if ((*b)->value >= pivot->value)
        {
            if (limit)
            {
                (*b)->chunk_limit = 1;
                limit = 0;
            }
            else
                (*b)->chunk_limit = 0;
            push_a(a, b, 1);
            pushed++;
        }
        else
        {
            if ((*b)->n_val == 0 || (*b)->n_val == lst_last(*a)->n_val + 1)
            {
                push_a(a, b, 1);
                rot_a(a, b, 1);
            }
            else
                rot_b(a, b, 1);
        }
    }
}

static void         rot_towards_max(t_element **a, t_element **b,
                                    t_element *max, int len)
{
    int         d;
    t_element   *aux;

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

static void         conquer_back(t_element **a, t_element **b, int len)
{
    t_element *sorted;
    t_element *max;

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
           // rev_rot_b(a, b, 1);
            //rot_b(a, b, 1);
    }
}

static void         rotate_maxs(t_element **a, t_element **b)
{
    while((*a)->next && (*a)->n_val == lst_last(*a)->n_val + 1)
        rot_a(a, b, 1);

}

static void         back_split(t_element **a, t_element **b, int len)
{
    if (len > 16)
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

static int          chunk_len(t_element *a)
{
    int len;

    len = 0;
    while (a && !a->chunk_limit && a->n_val)
    {
        a = a->next;
        len++;
    }
    if (a->n_val)
        len++;
    return (len);
}

static void         push_swap(t_element **a, t_element **b, int len)
{
    split_to_b(a, b, len);
    back_split(a, b, lst_len(*b));
    if ((*a)->n_val)
        push_swap(a, b, chunk_len(*a));
}

static void         find_and_replace(t_element *source, t_element *dest, int value)
{
    while (dest && source->value != dest->value)
        dest = dest->next;
    if (dest)
        dest->n_val = value;
}

static void         normalize(t_element **el)
{
    int len;
    int i;
    t_element *sorted;

    i = -1;
    len = lst_len(*el);
    sorted = sort_part_stack(*el, lst_len(*el));
    while (++i < len)
    {
        find_and_replace(sorted, *el, i);
        sorted = sorted->next;
    }
}

int                 main(int argc, char **argv)
{
    t_element *a;
    t_element *b;
    int len;

    if (argc < 2)
        exit(0);
    a = crt_stack(&argv[1]);
    b = NULL;
    normalize(&a);
    push_swap(&a, &b, lst_len(a));
    return (0);
}