#ifndef CHECKER_H
# define CHECKER_H

#include "./../common/common.h"
#include "./../common/instructions.h"

typedef struct	s_op {
    int         visualize;
    int         frame_delay;
    short       print;
    short       count;
}				t_op;

typedef struct	s_rgb {
    int         r;
    int         g;
    int         b;
}				t_rgb;

/*
** Sorting
*/

void        sort(t_element *instructions, t_element **a,
                    t_element **b, t_op options);

/*
** Instructions
*/

t_element   *read_instructions();

/*
** Argument options
*/

short       read_options(char **argv, t_op *options);

/*
** Options
*/

void        op_print(t_element *a, t_element *b, t_op options);
void        op_visualize(t_element *a, t_element *b, t_op options);
void        op_count(t_element *instructions, t_op options);

/*
** Visualizer
*/

void        visualize_frame(t_element *a, t_element *b, int max);

#endif