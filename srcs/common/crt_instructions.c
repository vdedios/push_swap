#include "common.h"

static short contains(char *instruction)
{
    int i;
	static char	*set[] = {
        "sa", "sb", "ss"
        "ra", "rb", "rr"
        "rra", "rrb", "rrr"
        "pa", "pb"
	};

    i = 0;
    while (set[i])
    {
        if (!ft_strncmp(set[i], instruction, ft_strlen(instruction)))
            return (1);
        i++;
    }
    return (0);
}

static void check_instructions_format(char **instructions)
{
    while (*instructions)
    {
        if (!contains(*instructions))
            error();
        instructions++;
    }
}

char        **crt_instructions(char *input)
{
    char **instructions;
    
    instructions = ft_split(input, ' ');
    check_instructions_format(instructions);
    return (instructions);
}