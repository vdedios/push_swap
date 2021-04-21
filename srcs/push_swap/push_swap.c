#include "./push_swap.h"

static void         push_swap_small(t_element **a, t_element **b, int len)
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

static void         push_swap(t_element **a, t_element **b, int len)
{
    if (len > 20)
        split_to_b(a, b, len);
    else
        rot_and_split_to_b(a, b, len);
    back_split(a, b, lst_len(*b));
    if ((*a)->n_val)
        push_swap(a, b, chunk_len(*a));
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
    len = lst_len(a);
    if (is_sorted(a, len, UP))
        exit(0);
    if (len <= 5)
        push_swap_small(&a, &b, len);
    else
        push_swap(&a, &b, len);
    return (0);
}