#ifndef COMMON_H
# define COMMON_H

#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "./../instructions/instructions.h"
#include "./../../dependencies/libft/libft.h"
#include "./../../dependencies/get_next_line/get_next_line.h"

typedef struct	s_op {
    short       visualize;
    short       print;
    short       count;
}				t_op;

typedef struct	s_rgb {
    int         r;
    int         g;
    int         b;
}				t_rgb;

/*
** User interface
*/

void            error();

/*
** Stack creation
*/

t_element       *crt_stack(char **els);
t_element       *extract_stack(t_element *start, int len);

/*
** Instruction set creation
*/

t_element       *read_instructions();

/*
** Stack utils
*/

void            lst_print(char *msg, t_element *stack);
void            lst_print_norm(char *msg, t_element *stack);
void            lst_add(t_element **stack, int value);

/*
** Sorting
*/

void            sort(t_element *instructions, t_element **stack_a,
                        t_element **stack_b, t_op options);

void            normalize(t_element **el);

#endif