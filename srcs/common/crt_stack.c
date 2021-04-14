#include "common.h"

static void         iterate(const char *nptr, long *num)
{
	while (*nptr)
	{
        if (!ft_isdigit(*nptr))
            error();
		*num = (*num) * 10 + *nptr - '0';
		nptr++;
	}
}

static int		    simple_atoi(const char *nptr)
{
	long	num;
	short	sign;

	sign = 1;
	num = 0;
	if (*nptr == '-')
    {
		sign = -1;
        nptr++;
    }
	iterate(nptr, &num);
    if ((sign * num) > INT_MAX || (sign * num) < INT_MIN)
        error();
	return ((int)(sign * num));
}

static void         clean_matrix(char **str)
{
    while (*str)
    {
        free(*str);
        str++;
    }
}

t_element           *extract_stack(t_element *start, int len)
{
    t_element *stack;

    stack = NULL;
    while (len)
    {
        lst_add(&stack, start->value);
        start = start->next;
        len--;
    }
    return (stack);
}

t_element           *crt_stack(char **els)
{
    t_element   *stack;

    stack = NULL;
    while (*els)
    {
        lst_add(&stack, simple_atoi(*els));
        els++;
    }
    clean_matrix(els);
    return (stack);
}