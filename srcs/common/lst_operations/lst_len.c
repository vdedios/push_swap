#include "instructions.h"

size_t      lst_len(t_element *stack)
{
    size_t len;

   len = 0;
    if (!stack)
    {
        return (0);
    }
    while (stack->next)
    {
        stack = stack->next;
        len++;
    }
    len++;
    return(len);
}

size_t      lst_len_end(t_element *stack, t_element *end)
{
    size_t len;

    len = 0;
    if (!stack)
    {
        return (0);
    }
    while (stack && stack != end)
    {
        stack = stack->next;
        len++;
    }
    if (end)
        len++;
    return(len);
}