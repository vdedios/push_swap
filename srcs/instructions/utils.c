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