#include "../instructions/instructions.h"
#include "../common/common.h"

static t_element *split_stack(t_element **stack, int len)
{
    t_element *aux;

    aux = NULL;
    while (len)
    {
        push_b(stack, &aux);
        ft_putstr_fd("pb\n", 1);
        len--;
    }
    return (aux);
}

static void     remove_a(t_element **stack_a, t_element **stack_b, int *a_len)
{

    rot_a(stack_a, stack_b);
    ft_putstr_fd("ra\n", 1);
    *a_len -= 1;
}

static void     remove_b(t_element **stack_a, t_element **stack_b)
{

    push_a(stack_a, stack_b);
    ft_putstr_fd("pa\n", 1);
    rot_a(stack_a, stack_b);
    ft_putstr_fd("ra\n", 1);
}

static short    two_els(t_element **stack_a, t_element **stack_b)
{
    if (!(*stack_a)->next && !(*stack_b)->next)
    {
        if ((*stack_a)->value < (*stack_b)->value)
            remove_b(stack_a, stack_b);
        else
        {
            push_a(stack_a, stack_b);
            ft_putstr_fd("pa\n", 1);
        }
        return (1);
    }
    return (0);
}

static t_element *merge(t_element *stack_a, t_element *stack_b)
{
    int a_len;

    a_len = lst_len(stack_a) + 1;
    if (two_els(&stack_a, &stack_b))
        return (stack_a);
    while (stack_b && a_len > 0)
    {
        if (stack_a->value < stack_b->value)
            remove_a(&stack_a, &stack_b, &a_len);
        else
            remove_b(&stack_a, &stack_b);
    }
    while (a_len > 0)
        remove_a(&stack_a, &stack_b, &a_len);
    while (stack_b)
        remove_b(&stack_a, &stack_b);
    return (stack_a);
}

static t_element *merge_sort(t_element *stack_a) 
{
    t_element       *stack_b;
    int             len;

    len = lst_len(stack_a) + 1;
    if (len <= 1)
        return (stack_a);
    stack_b = split_stack(&stack_a, len / 2);
    stack_a = merge_sort(stack_a);
    stack_b = merge_sort(stack_b);
    return (merge(stack_a, stack_b));
}

int         main(int argc, char **argv)
{
    t_element       *stack_a;
    if (argc < 2)
        exit(0);
    stack_a = crt_stack(&argv[1]);
    stack_a = merge_sort(stack_a);
//    lst_print("> ", stack_a);
    //lst_print("STACK B:\n", stack_b);
    return (0);
}