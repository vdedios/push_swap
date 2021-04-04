#include "instructions.h"

void rot(t_element **stack)
{
    t_element *last;
    t_element *second;

    second = (*stack)->next;
    last = lst_last(*stack);
    last->next = *stack;
    (*stack)->next = NULL;
    *stack = second;
}