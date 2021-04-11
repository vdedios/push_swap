#include "push_swap.h"

static short is_sorted(t_element *start, t_element *end, short order)
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

static t_element *mid_el(t_element *start, t_element *end)
{
    int len;
    int it;
    t_element *stack;

    it = 0;
    stack = extract_stack(start, end);
    stack = merge_sort(stack);
    //lst_print("[STACK] ", stack);
    //printf("is_sorted: %d\n", is_sorted(stack, NULL, UP));
    len = lst_len(stack) + 1;
    while (it < len / 2)
    {
        stack = stack->next;
        it++;
    }
    return (stack);
}

static void split_a(t_element **stack_a, t_element **stack_b)
{
    int len;

    if (*stack_a)
    {
        len = lst_len(*stack_a) + 1;
        while (len)
        {
            if ((*stack_a)->value < pivot->value)
                push_b(stack_a, stack_b);
            else
                rot_a(stack_a, stack_b);
            len--;
        }
    }
}

static void push_swap(t_chunk *chunk_a, t_chunk *chunk_b)
{
    t_element   *pivot;
    t_chunk     *chunk_a;
    t_chunk     *chunk_b;

    pivot = mid_el(chunk_a->start, chunk_a->end);
    //split_a(stack_a, stack_b, start, end);
    //split_b(stack_a, stack_b, start, end);
    //push_swap(stack_a, stack_b, start, pivot);
    //push_swap(stack_a, stack_b, pivot, end);
}

static t_chunk     *init_chunk(t_element *stack, t_element *start,
                                t_element *end, char id)
{
    t_chunk *chunk;

    if (!(chunk = malloc(sizeof(chunk))))
        return (NULL);
    chunk->stack = stack;
    chunk->start = start;
    chunk->end = end;
    chunk->id = id;
    return (chunk);
}

int main(int argc, char **argv)
{
    t_chunk *chunk_a;
    t_chunk *chunk_b;
    t_element *stack;

    if (argc < 2)
        exit(0);
    stack = crt_stack(&argv[1]);
    chunk_a = init_chunk(stack, stack, NULL, 'a');
    chunk_b = init_chunk(NULL, NULL, NULL, 'b');
    push_swap(chunk_a, chunk_b);
    //lst_print("[A] ", stack_a);
    //lst_print("[B] ", stack_b);
    //lst_print("STACK B:\n", stack_b);
    return (0);
}