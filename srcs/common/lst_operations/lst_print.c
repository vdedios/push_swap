#include "common.h"

static void print_element(int value)
{
    char *char_value;

    char_value = ft_itoa(value);
    printf("%s ", char_value);
    free(char_value);
}

void        lst_print(char *msg, t_element *stack)
{
    printf("%s", msg);
    if (stack)
    {
        while (stack->next)
        {
            print_element(stack->value);
            stack = stack->next;
        }
        print_element(stack->value);
        printf("\n");
    }
    else
    {
        ft_putstr_fd("(empty)\n", 1);
    }
}

void        lst_print_norm(char *msg, t_element *stack)
{
    ft_putstr_fd(msg, 1);
    if (stack)
    {
        while (stack->next)
        {
            print_element(stack->n_val);
            stack = stack->next;
        }
        print_element(stack->n_val);
        write(1, "\n", 1);
    }
    else
    {
        ft_putstr_fd("(empty)\n", 1);
    }
}