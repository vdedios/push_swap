#include "instructions.h"

void rot_rev(t_element **stack)
{
    t_element *last;
    t_element *penultimate;

    if (*stack)
    {
        last = lst_last(*stack);
        penultimate = lst_goto(*stack, lst_len(*stack) - 2);
        last->next = *stack;
        *stack = last;
        penultimate->next = NULL;
    }
}

void rot_rev_a(t_element **stack_a, t_element **stack_b, int prnt)
{
    (void)stack_b;
    rot_rev(stack_a);
    if (prnt)
        ft_putstr_fd("rra\n", 1);
}

void rot_rev_b(t_element **stack_a, t_element **stack_b, int prnt)
{
    (void)stack_a;
    rot_rev(stack_b);
    if (prnt)
        ft_putstr_fd("rrb\n", 1);
}

void rot_rev_ab(t_element **stack_a, t_element **stack_b, int prnt)
{
    rot_rev(stack_a);
    rot_rev(stack_b);
    if (prnt)
        ft_putstr_fd("rrr\n", 1);
}