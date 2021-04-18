#include "push_swap.h"

static short is_sorted(t_element *start, int len, short order)
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

static t_element *sort_part_stack(t_element *start, int len)
{
    t_element *stack;

    stack = extract_stack(start, len);
    stack = merge_sort(stack);
    return (stack);
}

static void split_to_b(t_element **a, t_element **b, int len)
{
    t_element *sorted;
    t_element *pivot;

    sorted = sort_part_stack(*a, len);
    pivot = lst_goto(sorted, len / 2);
    while (lst_len(*b) <= len / 2)
    {
        if ((*a)->value <= pivot->value)
            push_b(a, b, 1);
        else
            rot_a(a, b, 1);
    }
}

static void split_to_a(t_element **a, t_element **b, int len)
{
    t_element *sorted;
    t_element *pivot;
    int pushed;

    if (!(*b)->next)
    {
        push_a(a, b, 1);
        return;
    }
    sorted = sort_part_stack(*b, len);
    pivot = lst_goto(sorted, len / 2);
    pushed = 0;
    while (pushed < len / 2)
    {
        if ((*b)->value >= pivot->value)
        {
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

static void conquer_back(t_element **a, t_element **b, int len)
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
            rot_b(a, b, 1);
        //smart rotate?
    }
}

static void rotate_maxs(t_element **a, t_element **b)
{
    while((*a)->next && (*a)->n_val == lst_last(*a)->n_val + 1)
        rot_a(a, b, 1);

}

static void back_split(t_element **a, t_element **b, int len)
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

static void push_swap(t_element **a, t_element **b, int len)
{
    split_to_b(a, b, len);
    back_split(a, b, lst_len(*b));
    //push_swap(a, b, len);
}

static void find_and_replace(t_element *source, t_element *dest, int value)
{
    while (dest && source->value != dest->value)
        dest = dest->next;
    if (dest)
        dest->n_val = value;
}

static void normalize(t_element **el)
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

int main(int argc, char **argv)
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