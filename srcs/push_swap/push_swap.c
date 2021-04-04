#include "../instructions/instructions.h"
#include "../common/common.h"

int         main(int argc, char **argv)
{
    t_element       *stack_a;
    t_element       *stack_b;

    if (argc < 2)
        exit(0);
    stack_a = crt_stack(&argv[1]);
    stack_b = NULL;
    //lst_print("STACK A:\n", stack_a);
    //lst_print("STACK B:\n", stack_b);
    return (0);
}