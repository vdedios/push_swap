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

int         main(int argc, char **argv)
{
    t_element       *instructions;
    t_element       *stack_a;
    t_element       *stack_b;

    if (argc < 2)
        exit(0);
    instructions = read_instructions();
    stack_a = crt_stack(&argv[1]);
    stack_b = NULL;
    sort(instructions, &stack_a, &stack_b);
    inspect_order(stack_a, stack_b);
    return (0);
}