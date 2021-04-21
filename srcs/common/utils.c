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

int		            simple_atoi(const char *nptr)
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

void         clean_matrix(char **str)
{
    while (*str)
    {
        free(*str);
        str++;
    }
}
