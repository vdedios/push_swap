#include "checker.h"

void                sort(t_element *instructions, t_element **a, t_element **b, t_op options)
{
    static void (*f_instructions[])(t_element **a, t_element **b, int prnt) = {
        &swap_a, &swap_b, &swap_ab,
        &rot_a, &rot_b, &rot_ab,
        &rot_rev_a, &rot_rev_b, &rot_rev_ab,
        &push_a, &push_b};

    if (instructions)
    {
        while (instructions->next)
        {
            f_instructions[instructions->value](a, b, 0);
            op_print(*a, *b, options);
            op_visualize(*a, *b, options);
            instructions = instructions->next;
        }
        f_instructions[instructions->value](a, b, 0);
        op_print(*a, *b, options);
        op_visualize(*a, *b, options);
    }
}