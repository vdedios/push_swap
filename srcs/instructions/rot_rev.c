#include "instructions.h"

void rot_rev(t_element **stack)
{
    t_element *last;
    t_element *penultimate;

    if (*stack)
    {
        last = lst_last(*stack);
        penultimate = lst_goto(*stack, lst_len(*stack) - 1);
        last->next = *stack;
        *stack = last;
        penultimate->next = NULL;
    }
}

void rot_rev_a(t_element **stack_a, t_element **stack_b)
{
    (void)stack_b;
    rot_rev(stack_a);
}

void rot_rev_b(t_element **stack_a, t_element **stack_b)
{
    (void)stack_a;
    rot_rev(stack_b);
}

void rot_rev_ab(t_element **stack_a, t_element **stack_b)
{
    rot_rev(stack_a);
    rot_rev(stack_b);
}