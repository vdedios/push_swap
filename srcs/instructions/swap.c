#include "instructions.h"

void swap(t_element **stack)
{
    t_element *second;

    second = lst_goto(*stack, 2); 
    (*stack)->next = second->next;
    second->next = *stack;
    *stack = second;
}