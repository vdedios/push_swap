#include "common.h"

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