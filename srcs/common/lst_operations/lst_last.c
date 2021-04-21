#include "instructions.h"

t_element   *lst_last(t_element *stack)
{
    if (!stack)
    {
        return (0);
    }
    while (stack->next)
    {
        stack = stack->next;
    }
    return(stack);
}
