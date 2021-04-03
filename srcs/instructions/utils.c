#include "instructions.h"

t_element   *lst_goto(t_element *stack, short pos)
{
    if (!stack)
    {
        return (0);
    }
    while (pos)
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
    return(len);
}

void        lst_print(t_element *stack)
{
    char *char_value;

    while (stack->next)
    {
        char_value = ft_itoa(stack->value);
        write(1, char_value, ft_strlen(char_value));
        write(1, "\n", 1);
        free(char_value);
        stack = stack->next;
    }
}

void        lst_add(t_element **stack, int value)
{
	t_element	*new;
	t_element	*last;

	if (stack)
	{
        if (!(new = malloc(sizeof(t_element))))
        {
            new->value = value;
            new->next = NULL;
            if (!*stack)
            {
	            *stack = new;
            }
            else
            {
                last = lst_last(*stack);
	            last->next = new;
            }
        }
	}
}
