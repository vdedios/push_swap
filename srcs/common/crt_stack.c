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
    while (*els)
    {
        lst_add(&stack, simple_atoi(*els));
        els++;
    }
    clean_matrix(els);
    return (stack);
}