#include "common.h"

void sort(t_instruction instructions, t_element **stack_a, t_element **stack_b)
{
    size_t      i;
	static void (*f_instructions[])(t_element **stack_a, t_element **stack_b) = {
        &swap_a, &swap_b, &swap_ab,
        &rot_a, &rot_b, &rot_ab,
        &rot_rev_a, &rot_rev_b, &rot_rev_ab,
        &push_a, &push_b
    };

    i = 0;
    while (i < instructions.len)
    {
        f_instructions[instructions.codes[i]](stack_a, stack_b);
        i++;
    }
}