#include "common.h"

static void print_element(int value)
{
    char *char_value;

    char_value = ft_itoa(value);
    printf("%s ", char_value);
    //write(1, char_value, ft_strlen(char_value));
    //write(1, " ", 1);
    free(char_value);
}

void        lst_print(char *msg, t_element *stack)
{
    //ft_putstr_fd(msg, 1);
    printf("%s", msg);
    if (stack)
    {
        while (stack->next)
        {
            print_element(stack->value);
            stack = stack->next;
        }
        print_element(stack->value);
        //write(1, "\n", 1);
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

static void check_el_duplicate(t_element *stack, int value)
{
    if (stack)
    {
        while (stack->next)
        {
            if (value == stack->value)
                error();
            stack = stack->next;
        }
        if (value == stack->value)
            error();
    }
}

void        lst_add(t_element **stack, int value)
{
    t_element *new;
    t_element *last;

    if (stack)
        if ((new = malloc(sizeof(t_element))))
        {
            check_el_duplicate(*stack, value);
            new->value = value;
            new->next = NULL;
            if (!*stack)
                *stack = new;
            else
            {
                last = lst_last(*stack);
                last->next = new;
            }
        }
}