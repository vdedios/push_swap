#include "checker.h"

static int      get_code(char *instruction)
{
    int         i;
	static char	*set[] = {
        "sa", "sb", "ss",
        "ra", "rb", "rr",
        "rra", "rrb", "rrr",
        "pa", "pb"
	};

    i = 0;
    while (set[i])
    {
        if (!ft_strncmp(set[i], instruction, ft_strlen(instruction))
            && !set[i][ft_strlen(instruction)])
            return (i);
        i++;
    }
    return (i);
}

static void     add_instruction(t_element **instructions, char *el)
{
    int         code;
    t_element   *last;
    t_element   *new_instruction;

    if ((new_instruction = malloc(sizeof(t_element))))
    {
        if ((code = get_code(el)) > 10)
            error();
        new_instruction->value = code;
        new_instruction->next = NULL;
        if (!*instructions)
            *instructions = new_instruction;
        else
        {
            last = lst_last(*instructions);
            last->next = new_instruction;
        }
    }
}

t_element       *read_instructions()
{
    t_element       *instructions;
    char            *line;
    int             read;

    instructions = NULL;
    read = get_next_line(&line);
    while (read)
    {
        if (*line && *line !='\n')
            add_instruction(&instructions, line);
        free(line);
        read = get_next_line(&line);
    }
    free(line);
    return (instructions);
}