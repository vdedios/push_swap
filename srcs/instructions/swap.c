#include "instructions.h"

static void swap(t_element **stack)
{
    t_element *second;
    if (*stack)
    {
        second = (*stack)->next; 
        (*stack)->next = second->next;
        second->next = *stack;
        *stack = second;
    }
}

void swap_a(t_element **stack_a, t_element **stack_b)
{
    (void)stack_b;
    swap(stack_a);
}

void swap_b(t_element **stack_a, t_element **stack_b)
{
    (void)stack_a;
    swap(stack_b);
}

void swap_ab(t_element **stack_a, t_element **stack_b)
{
    swap(stack_a);
    swap(stack_b);
}