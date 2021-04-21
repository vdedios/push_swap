#include "instructions.h"

t_element   *lst_goto(t_element *stack, short pos)
{
    if (!stack)
    {
        return (0);
    }
    while (pos > 0)
    {
        stack = stack->next;
        pos--;
    }
    return(stack);
}
