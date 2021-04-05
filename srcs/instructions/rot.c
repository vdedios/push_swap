#include "instructions.h"

static void rot(t_element **stack)
{
    t_element *last;
    t_element *second;

    if (*stack && (*stack)->next)
    {
        second = (*stack)->next;
        last = lst_last(*stack);
        last->next = *stack;
        (*stack)->next = NULL;
        *stack = second;
    }
}

void rot_a(t_element **stack_a, t_element **stack_b)
{
    (void)stack_b;
    rot(stack_a);
}

void rot_b(t_element **stack_a, t_element **stack_b)
{
    (void)stack_a;
    rot(stack_b);
}

void rot_ab(t_element **stack_a, t_element **stack_b)
{
    rot(stack_a);
    rot(stack_b);
}