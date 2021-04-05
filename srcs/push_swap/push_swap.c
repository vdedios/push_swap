#include "../instructions/instructions.h"
#include "../common/common.h"

static t_element *split_stack(t_element **stack, int len)
{
    t_element *aux;

    aux = NULL;
    while (len)
    {
        push_b(stack, &aux);
        len--;
    }
    return (aux);
}

static t_element *merge(t_element *stack_a, t_element *stack_b)
{
    int             len;

    len = lst_len(stack_a) + 1;
    while (stack_b->next)
    {
        if (stack_a->value < stack_b->value)
            rot_a(&stack_a, &stack_b);
        else
        {
            push_a(&stack_a, &stack_b);
            rot_a(&stack_a, &stack_b);
        }
    }
    if(stack_a->value < stack_b->value)
    {
        rot_a(&stack_a, &stack_b);
        push_a(&stack_a, &stack_b);
    }
    else
    {
        push_a(&stack_a, &stack_b);
        rot_a(&stack_a, &stack_b);
    }
    rot_a(&stack_a, &stack_b);
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
    lst_print("> ", stack_a);
    //lst_print("STACK B:\n", stack_b);
    return (0);
}