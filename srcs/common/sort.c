#include "common.h"

void sort(t_element *instructions, t_element **stack_a, t_element **stack_b)
{
	static void (*f_instructions[])(t_element **stack_a, t_element **stack_b) = {
        &swap_a, &swap_b, &swap_ab,
        &rot_a, &rot_b, &rot_ab,
        &rot_rev_a, &rot_rev_b, &rot_rev_ab,
        &push_a, &push_b
    };

    if (instructions)
    {
        while (instructions->next)
        {
            f_instructions[instructions->value](stack_a, stack_b);
            instructions = instructions->next;
        }
        f_instructions[instructions->value](stack_a, stack_b);
    }
}