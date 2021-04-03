#include "instructions.h"

static short        is_valid_input(char **str)
{
    size_t i;

    if (!*str)
        return (0);
    while (*str)
    {
        i = 0;
        while ((*str)[i])
        {
            if (!ft_isdigit((*str)[i]))
                return (0);
            i++;
        }
        str++;
    }
    return (1);
}

static void        clean_matrix(char **str)
{
    while (*str)
    {
        free(*str);
        str++;
    }
}

t_element           *crt_stack(char *str)
{
    t_element   *stack;
    char        **els;

    stack = NULL;
    els = ft_split(str, ' ');
    if (!is_valid_input(els))
    {
        clean_matrix(els);
        return (NULL);
    }
    while (*els)
    {
        lst_add(&stack, ft_atoi(*els));
        els++;
    }
    clean_matrix(els);
    return (stack);
}