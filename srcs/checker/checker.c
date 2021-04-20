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
    printf("usage: ./checker [-v] [-s] [-c]\n\n");
    printf("Check push_swap output:\n");
    printf("-v: visualize operations\n");
    printf("-p: print stacks after exexuting instructions\n");
    printf("-c: print number of push_swap instruction\n\n");
    exit(1);
}

static short read_options(char **argv, t_op *options)
{
    size_t i;

    i = 0;
    if ((*argv)[i] != '-' && !ft_isalpha((*argv)[i + 1]))
        return (0);
    i++;
    while ((*argv)[i])
    {
        if ((*argv)[i] == 'h')
            usage();
        else if ((*argv)[i] == 'v')
            options->visualize = 1;
        else if ((*argv)[i] == 'p')
            options->print = 1;
        else if ((*argv)[i] == 'c')
            options->count = 1;
        else
            error();
        i++;
    }
    return (1);
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
        printf("[INSTRUCTIONS]: %d\n", len);
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
    if (read_options(&argv[1], &options))
        a = crt_stack(&argv[2]);
    else
        a = crt_stack(&argv[1]);
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