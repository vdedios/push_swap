#include "../instructions/instructions.h"
#include "../common/common.h"

int main(int argc, char **argv)
{
    t_element       *instructions;
    t_element       *stack_a;
    t_element       *stack_b;

    if (argc < 2)
        exit(0);
    instructions = read_instructions();
    stack_a = crt_stack(&argv[1]);
    stack_b = NULL;
    //sort(instructions, &stack_a, &stack_b);
    lst_print("INSTRUCTIONS:\n", instructions);
    lst_print("STACK A:\n", stack_a);
    lst_print("STACK B:\n", stack_b);
    //chequear orden
    return (0);
}