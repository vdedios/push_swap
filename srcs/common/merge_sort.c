#include "../instructions/instructions.h"
#include "../common/common.h"

static t_element    *merge(t_element *stack_a, t_element *stack_b)
{
    int a_len;

    a_len = lst_len(stack_a);
    if (two_els(&stack_a, &stack_b))
        return (stack_a);
    while (stack_b && a_len > 0)
    {
        if (stack_a->value < stack_b->value)
            remove_a(&stack_a, &stack_b, &a_len);
        else
            remove_b(&stack_a, &stack_b, 0);
    }
    while (a_len > 0)
        remove_a(&stack_a, &stack_b, &a_len);
    while (stack_b)
        remove_b(&stack_a, &stack_b, 0);
    return (stack_a);
}

t_element           *merge_sort(t_element *stack_a) 
{
    t_element       *stack_b;
    int             len;

    len = lst_len(stack_a);
    if (len <= 1)
        return (stack_a);
    stack_b = split_stack(&stack_a, len / 2);
    stack_a = merge_sort(stack_a);
    stack_b = merge_sort(stack_b);
    return (merge(stack_a, stack_b));
}