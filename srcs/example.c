#include "instructions/instructions.h"
#include "common/common.h"

int main()
{
    char            *i_stack;
    char            *i_instructions;
    char            **instructions;
    t_element       *stack;

    input("Enter stack: ", &i_stack);
    input("Enter instructions: ", &i_instructions);
    stack = crt_stack(i_stack);
    instructions = crt_instructions(i_instructions);
    //sort(instructions, stack);
    free(i_stack);
    free(i_instructions);
    lst_print(stack);
    return (0);
}