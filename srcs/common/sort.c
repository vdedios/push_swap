#include "common.h"

void sort(t_instruction instructions, t_element **stack)
{
    size_t      i;
	static void (*f_instructions[])(t_element **stack) = {
        &swap, &rot, &rot_rev 
    };

    i = 0;
    while (i < instructions.len)
    {
        f_instructions[instructions.codes[i]](stack);
        i++;
    }
}