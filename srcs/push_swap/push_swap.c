#include "../instructions/instructions.h"
#include "../common/common.h"

#define UP 1
#define DES 2

static short        is_sorted(t_element *start, t_element *end, short order)
{
    t_element *next;

    while (start->next != end->next)
    {
        next = start->next;
        if (order == UP && start->value > next->value)
        {
            return (0);
        }
        if (order == DES && start->value > next->value)
        {
            return (0);
        }
        start = next;
    }
    return (1);
}

static void         split_stack(t_element **stack, t_element **stack_aux)
{
    int len;

    len = lst_len(*stack) + 1;
    while (len > len / 2)
    {
        push_b(stack, stack_aux);
        len--;
    }
}

static t_element    *merge(t_element *stack_a, t_element *stack_b)
{
    t_element *merged;

    while (stack_a && stack_b)
    {
        if (stack_a->value > stack_b->value)

    }
}

static t_element    *merge_sort(t_element *stack)
{
    t_element *stack_aux;

    stack_aux = NULL;
    if (lst_len(stack))
    {
        split_stack(&stack, &stack_aux);
        stack = merge_sort(stack);
        stack_aux = merge_sort(stack_aux);
        return merge(stack, stack_aux);
    }
    return (stack);
}

static t_element    *gen_stack(t_element *start, t_element *end)
{

    t_element *next;
    t_element *stack;

    stack = NULL;
    while (start->next != end->next)
    {
        lst_add(&stack, simple_atoi(start->value));
        start = next;
    }
    return (stack);
}

static int          mid_el(t_element *start, t_element *end)
{
    int         len;
    t_element   *stack;

    stack = gen_stack(start, end);
    stack = merge_sort(stack);
    lst_print("[STACK] ", stack);
    len = lst_len(stack) + 1;
    while(len)
    {
        stack = stack->next;
        len--;
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