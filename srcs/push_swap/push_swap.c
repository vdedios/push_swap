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

static t_element *mid_el(t_element *start, int len)
{
    int it;
    t_element *stack;

    it = 0;
    stack = extract_stack(start, len);
    stack = merge_sort(stack);
    //lst_print("[STACK] ", stack);
    //printf("is_sorted: %d\n", is_sorted(stack, NULL, UP));
    while (it < len / 2)
    {
        stack = stack->next;
        it++;
    }
    return (stack);
}

static int split_a(t_element **stack_a, t_element **stack_b,
                    int len, t_element *pivot)
{
    int rot_rev;
    int split_len;
    int half_len;

    half_len = len / 2;
    rot_rev = 0;
    split_len = 0;
    if (*stack_a)
    {
        while (len)
        {
            if (split_len >= half_len)
                break;
            if ((*stack_a)->value < pivot->value)
            {
                push_b(stack_a, stack_b);
                ft_putstr_fd("pb\n", 1);
                split_len++;
            }
            else
            {
                rot_rev++;
                rot_a(stack_a, stack_b);
                ft_putstr_fd("ra\n", 1);
            }
            len--;
        }
    }
    while (rot_rev)
    {
        rot_rev_a(stack_a, stack_b);
        ft_putstr_fd("rra\n", 1);
        rot_rev--;
    }
    return (split_len);
}

static int split_b(t_element **stack_a, t_element **stack_b,
                    int len, t_element *pivot)
{
    int rot_rev;
    int split_len;
    int half_len;

    half_len = len / 2;
    rot_rev = 0;
    rot_rev = 0;
    split_len = 0;
    if (*stack_b)
    {
        while (len)
        {
            if (split_len >= half_len)
                break;
            if ((*stack_b)->value >= pivot->value)
            {
                push_a(stack_a, stack_b);
                ft_putstr_fd("pa\n", 1);
                split_len++;
            }
            else
            {
                rot_rev++;
                rot_b(stack_a, stack_b);
                ft_putstr_fd("rb\n", 1);
            }
            len--;
        }
    }
    while (rot_rev)
    {
        rot_rev_b(stack_a, stack_b);
        ft_putstr_fd("rrb\n", 1);
        rot_rev--;
    }
    return (split_len);
}

static void undo_split_a(t_element **stack_a, t_element **stack_b,
                         int len)
{
    while (len)
    {
        push_b(stack_a, stack_b);
        ft_putstr_fd("pb\n", 1);
        len--;
    }
}

static void undo_split_b(t_element **stack_a, t_element **stack_b,
                         int len)
{
    while (len)
    {
        push_a(stack_a, stack_b);
        ft_putstr_fd("pa\n", 1);
        len--;
    }
}

static void push_swap(t_element **stack_a, t_element **stack_b,
                        int len, char stack_id)
{
    t_element   *pivot;
    int         split_len;

    //lst_print("[A] ", *stack_a);
    //lst_print("[B] ", *stack_b);
    if (stack_id == 'a' && len == 2)
    {
        if ((*stack_a)->value > ((t_element *)(*stack_a)->next)->value)
        {
            swap_a(stack_a, stack_b);
            ft_putstr_fd("sa\n", 1);
        }
    }
    else if (stack_id == 'a' && len > 2)
    {
        if (!is_sorted(*stack_a, len, UP))
        {
            pivot = mid_el(*stack_a, len);
            split_len = split_a(stack_a, stack_b, len, pivot);
            push_swap(stack_a, stack_b, split_len, 'b');
            push_swap(stack_a, stack_b, len - split_len, 'a');
            undo_split_b(stack_a, stack_b, split_len);
        }
    }
    else if (stack_id == 'b' && len == 2)
    {
        if ((*stack_b)->value < ((t_element *)(*stack_b)->next)->value)
        {
            swap_b(stack_a, stack_b);
            ft_putstr_fd("sb\n", 1);
        }
    }
    else if (stack_id == 'b' && len > 2)
    {
        if (!is_sorted(*stack_b, len, DOWN))
        {
            pivot = mid_el(*stack_b, len);
            split_len = split_b(stack_a, stack_b, len, pivot);
            push_swap(stack_a, stack_b, split_len, 'a');
            push_swap(stack_a, stack_b, len - split_len, 'b');
            undo_split_a(stack_a, stack_b, split_len);
        }
    }
}

int main(int argc, char **argv)
{
    t_element   *stack_a;
    t_element   *stack_b;
    int         len;

    if (argc < 2)
        exit(0);
    stack_a = crt_stack(&argv[1]);
    stack_b = NULL;
    push_swap(&stack_a, &stack_b, lst_len(stack_a) + 1, 'a');
    //printf("%d\n", is_sorted(stack_a, lst_len(stack_a), UP));
//    printf("\nRESULT\n");
//    lst_print("[A] ", stack_a);
//    lst_print("[B] ", stack_b);
    return (0);
}