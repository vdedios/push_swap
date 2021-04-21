#include "./checker.h"

void        op_print(t_element *a, t_element *b, t_op options)
{
    if (options.print)
    {
        printf("\033[H\033[J");
        lst_print("\n[STACK A]:\n", a);
        lst_print("\n[STACK B]:\n", b);
        usleep(options.frame_delay * 1000);
    }
}

void        op_visualize(t_element *a, t_element *b, t_op options)
{
    if (options.visualize)
    {
        visualize_frame(a, b, options.visualize);
        usleep(options.frame_delay * 1000);
    }
}

void        op_count(t_element *instructions, t_op options)
{
    int len;

    if (options.count)
    {
        len = 0;
        while (instructions)
        {
            instructions = instructions->next;
            len++;
        }
        printf("[N_INSTRUCTIONS]: %d\n", len);
    }
}