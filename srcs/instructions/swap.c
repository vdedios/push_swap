#include "instructions.h"

void swap(t_element **stack)
{
    t_element *second;

    //second = lst_goto(*stack, 2); 
    second = (*stack)->next; 
    (*stack)->next = second->next;
    second->next = *stack;
    *stack = second;
}