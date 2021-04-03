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

static void print_element(int value)
{
    char *char_value;

    char_value = ft_itoa(value);
    write(1, char_value, ft_strlen(char_value));
    write(1, "\n", 1);
    free(char_value);
}

void        lst_print(t_element *stack)
{
    while (stack->next)
    {
        print_element(stack->value);
        stack = stack->next;
    }
    print_element(stack->value);
}

void        lst_add(t_element **stack, int value)
{
	t_element	*new;
	t_element	*last;

	if (stack)
	{
        if ((new = malloc(sizeof(t_element))))
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
