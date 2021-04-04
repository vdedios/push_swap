#include "instructions.h"

void rot(t_element **stack)
{
    t_element *last;

    last = lst_last(*stack);
    last->next = *stack;
    (*stack)->next = NULL;
}