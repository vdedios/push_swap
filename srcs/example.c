#include "instructions/instructions.h"
#include "common/common.h"

int main()
{
    char            *i_stack;
    char            *i_instructions;
    t_instruction   instructions;
    t_element       *stack_a;
    t_element       *stack_b;

    input("Enter stack: ", &i_stack);
    input("Enter instructions: ", &i_instructions);
    stack_a = crt_stack(i_stack);
    stack_b = NULL;
    instructions = crt_instructions(i_instructions);
    sort(instructions, &stack_a, &stack_b);
    free(i_stack);
    free(i_instructions);
    lst_print("STACK A:\n", stack_a);
    lst_print("STACK B:\n", stack_b);
    return (0);
}