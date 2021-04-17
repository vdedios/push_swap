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

void swap_a(t_element **stack_a, t_element **stack_b, int prnt)
{
    (void)stack_b;
    swap(stack_a);
    if (prnt)
        ft_putstr_fd("sa\n", 1);
}

void swap_b(t_element **stack_a, t_element **stack_b, int prnt)
{
    (void)stack_a;
    swap(stack_b);
    if (prnt)
        ft_putstr_fd("sb\n", 1);
}

void swap_ab(t_element **stack_a, t_element **stack_b, int prnt)
{
    swap(stack_a);
    swap(stack_b);
    if (prnt)
        ft_putstr_fd("ss\n", 1);
}