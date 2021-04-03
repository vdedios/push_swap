#include "instructions.h"

int main()
{
    char        *line;
    t_element   *stack;

    ft_putstr_fd("Enter stack: ", 1);
    get_next_line(&line);
    stack = crt_stack(line);
    if (!stack)
    {
        ft_putstr_fd("Not a valid stack :(", 1);
        return (0);
    }
    lst_print(stack);
    free(line);
    return (0);
}