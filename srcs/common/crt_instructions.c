#include "common.h"

static short            get_code(char *instruction)
{
    int i;
	static char	*set[] = {
        "sa", "sb", "ss",
        "ra", "rb", "rr",
        "rra", "rrb", "rrr",
        "pa", "pb"
	};

    i = 0;
    while (set[i])
    {
        if (!ft_strncmp(set[i], instruction, ft_strlen(instruction)))
            return (i);
        i++;
    }
    return (i);
}

static int              ft_matrix_len(char **instructions)
{
    int len;

    len = 0;
    while (instructions[len])
        len++;
    return (len);
}

static t_instruction    instruction_codes(char **s_instructions)
{
    size_t          i;
    short           *codes;
    t_instruction   instructions;

    i = 0;
    instructions.len = ft_matrix_len(s_instructions);
    if ((codes = malloc(instructions.len * sizeof(short))))
    {
        while (*s_instructions)
        {
            if ((codes[i] = get_code(*s_instructions)) > 10)
                error();
            s_instructions++;
            i++;
        }
        instructions.codes = codes;
        return (instructions);
    }
    return (instructions);
}

t_instruction           crt_instructions(char *input)
{
    char    **instructions;
    
    instructions = ft_split(input, ' ');
    return (instruction_codes(instructions));
}