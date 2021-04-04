#include "instructions.h"

void rot_rev(t_element **stack)
{
    t_element *last;
    t_element *penultimate;

    last = lst_last(*stack);
    penultimate = lst_goto(*stack, lst_len(*stack) - 1);
    last->next = *stack;
    *stack = last;
    penultimate->next = NULL;
}