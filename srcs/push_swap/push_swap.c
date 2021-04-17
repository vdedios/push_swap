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
    while (it < len / 2)
    {
        stack = stack->next;
        it++;
    }
    return (stack);
}

static void push_swap(t_element **stack_a, t_element **stack_b,
                        int len, char stack_id)
{
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
    return (0);
}