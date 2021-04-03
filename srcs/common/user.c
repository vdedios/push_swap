#include "common.h"

void    input(char *message, char **line)
{
    ft_putstr_fd(message, 1);
    get_next_line(line);
}

void    error()
{
    ft_putstr_fd("Error\n", 2);
    exit(127);
}