#include "common.h"

static void create_bar(char *buf, int len)
{
    *buf = '\0';
    while (len)
    {
        strncat(buf, ".", 1);
        len--;
    }
}

static t_rgb pick_color(int region, int x)
{
    t_rgb rgb;

    if (region == 0)
    {
        rgb.r = 255;
        rgb.g = x;
        rgb.b = 0;
    }
    if (region == 1)
    {
        rgb.r = 255 - x;
        rgb.g = 255;
        rgb.b = 0;
    }
    if (region == 2 || region == 3)
    {
        rgb.r = 0;
        rgb.g = 255;
        rgb.b = x;
    }
    return (rgb);
}

static t_rgb get_rgb_color(int value)
{
    float ratio;
    int normalized;
    int x;

    ratio = (float)value / 50;
    normalized = (int)(ratio * 256 * 3);
    x = normalized % 256;
    return (pick_color((int)(normalized / 256), x));
}

static void visualize_frame(t_element *a, t_element *b)
{
    char a_v[1000];
    char b_v[1000];
    t_rgb rgb;

    printf("\033[H\033[J");
    printf("%-75s", "[STACK A]");
    printf("%s\n\n", "[STACK B]");
    while (a || b)
    {
        if (a)
        {
            create_bar(a_v, a->n_val + 1);
            printf("%5d: ", a->value);
            rgb = get_rgb_color(a->value);
            printf("\x1b[38;2;%d;%d;%dm", rgb.r, rgb.g, rgb.b);
            printf("%-70s"
                   "\x1b[0m",
                   a_v);
            a = a->next;
        }
        else
            printf("%-75c", ' ');
        if (b)
        {
            create_bar(b_v, b->n_val + 1);
            printf("%5d: ", b->value);
            rgb = get_rgb_color(b->value);
            printf("\x1b[38;2;%d;%d;%dm", rgb.r, rgb.g, rgb.b);
            printf("%s\n"
                   "\x1b[0m",
                   b_v);
            b = b->next;
        }
        else
            printf("\n");
    }
}

void sort(t_element *instructions, t_element **stack_a, t_element **stack_b, t_op options)
{
    static void (*f_instructions[])(t_element * *stack_a, t_element * *stack_b, int prnt) = {
        &swap_a, &swap_b, &swap_ab,
        &rot_a, &rot_b, &rot_ab,
        &rot_rev_a, &rot_rev_b, &rot_rev_ab,
        &push_a, &push_b};

    if (instructions)
    {
        while (instructions->next)
        {
            f_instructions[instructions->value](stack_a, stack_b, 0);
            if (options.visualize)
            {
                visualize_frame(*stack_a, *stack_b);
                usleep(50000);
            }
            instructions = instructions->next;
        }
        f_instructions[instructions->value](stack_a, stack_b, 0);
        if (options.visualize)
        {
            visualize_frame(*stack_a, *stack_b);
        }
    }
}