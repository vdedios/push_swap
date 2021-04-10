#include "push_swap.h"

static short        is_sorted(t_element *start, t_element *end, short order)
{
    t_element *next;

    while (start->next != end)
    {
        next = start->next;
        if (order == UP && start->value > next->value)
        {
            return (0);
        }
        if (order == DES && start->value < next->value)
        {
            return (0);
        }
        start = next;
    }
    return (1);
}

static int          mid_el(t_element *start, t_element *end)
{
    int         len;
    int         it;
    t_element   *stack;

    it = 0;
    stack = extract_stack(start, end);
    stack = merge_sort(stack);
    lst_print("[STACK] ", stack);
    printf("is_sorted: %d\n", is_sorted(stack, NULL, UP));
    len = lst_len(stack) + 1;
    while(it < len / 2)
    {
        stack = stack->next;
        it++;
    }
    return (stack->value);
}

static void         sort_stacks(t_element **stack_a, t_element **stack_b)
{
    int mid;

    mid = mid_el(*stack_a, NULL);
    printf("MID_EL: %d\n", mid);
}

int                 main(int argc, char **argv)
{
    t_element       *stack_a;
    t_element       *stack_b;
    if (argc < 2)
        exit(0);
    stack_b = NULL;
    stack_a = crt_stack(&argv[1]);
    sort_stacks(&stack_a, &stack_b);
    //lst_print("[A] ", stack_a);
    //lst_print("[B] ", stack_b);
    //lst_print("STACK B:\n", stack_b);
    return (0);
}
