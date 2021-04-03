#include "instructions/instructions.h"
#include "common/common.h"

int main()
{
    char            *i_stack;
    char            *i_instructions;
    t_instruction   instructions;
    t_element       *stack;

    input("Enter stack: ", &i_stack);
    input("Enter instructions: ", &i_instructions);
    stack = crt_stack(i_stack);
    instructions = crt_instructions(i_instructions);
    printf("LEN: %zu\n", instructions.len);
    while (instructions.len)
    {
        printf("%d\n", *instructions.codes);
        instructions.codes++;
        instructions.len--;
    }
    //sort(instructions, stack);
    free(i_stack);
    free(i_instructions);
    //lst_print(stack);
    return (0);
}