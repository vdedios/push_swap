#include "../instructions/instructions.h"
#include "../common/common.h"

static void ko()
{
    ft_putstr_fd("KO\n", 1);
    exit(0);
}

static void inspect_order(t_element *stack_a, t_element *stack_b)
{
    int aux;

    if (stack_b)
        ko();
    aux = stack_a->value;
    while (stack_a->next)
    {
        stack_a = stack_a->next;
        if (aux >= stack_a->value)
            ko();
    }
    ft_putstr_fd("OK\n", 1);
}

static void usage()
{
    printf("usage: ./checker [-v:<frame_delay>] [-p:<frame_delay>] [-c]\n\n");
    printf("Check push_swap output:\n");
    printf("-v: visualize operations.\n");
    printf("-p: print stacks after exexuting instructions\n");
    printf("-c: print number of push_swap instruction\n\n");
    printf("NOTE: [-v] and [-p] cannot coexist\n\n");
    exit(1);
}

static short    string_is_num(char *str)
{
    if (*str != '-')
        str++;
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (0);
        str++;
    }
    return (1);
}

static void get_frame_delay(char *argv, t_op *options)
{
    while (*argv && *argv != ':')
        argv++;
    argv++;
    if (!string_is_num(argv))
        error();
    options->frame_delay = simple_atoi(argv);
}

static void extract_option(char *argv, t_op *options)
{
    if (ft_strncmp(argv, "-h", 3) == 0)
        usage();
    else if (ft_strncmp(argv, "-v:", 3) == 0)
    {
        if (options->visualize || options->frame_delay)
            error();
        get_frame_delay(argv, options);
        options->visualize = 1;
    }
    else if (ft_strncmp(argv, "-p:", 3) == 0)
    {
        if (options->print || options->frame_delay)
            error();
        get_frame_delay(argv, options);
        options->print = 1;
    }
    else if (ft_strncmp(argv, "-c", 3) == 0)
    {
        if (options->count)
            error();
        options->count = 1;
    }
    else
        error();
}

static short read_options(char **argv, t_op *options)
{
    short i;

    i = 0;
    while (argv[i] && !string_is_num(argv[i]))
    {
        extract_option(argv[i], options);
        i++;
    }
    return (i);
}

static  void    op_count(t_element *instructions, t_op options)
{
    int len;

    if (options.count)
    {
        len = 0;
        while (instructions)
        {
            instructions = instructions->next;
            len++;
        }
        printf("[N_INSTRUCTIONS]: %d\n", len);
    }
}

int         main(int argc, char **argv)
{
    t_element       *instructions;
    t_element       *a;
    t_element       *b;
    t_op            options;

    if (argc < 2)
        exit(0);
    a = crt_stack(&argv[1 + read_options(&argv[1], &options)]);
    b = NULL;
    normalize(&a);
    if (options.visualize)
        options.visualize = lst_len(a);
    instructions = read_instructions();
    sort(instructions, &a, &b, options);
    op_count(instructions, options);
    inspect_order(a, b);
    return (0);
}