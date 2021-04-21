#ifndef COMMON_H
# define COMMON_H

#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "./instructions.h"
#include "./../../dependencies/libft/libft.h"
#include "./../../dependencies/get_next_line/get_next_line.h"

typedef struct	s_element {
    int         value;
    int         n_val;
    short       chunk_limit;
    void        *next;
}				t_element;

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
size_t          lst_len(t_element *stack);
size_t          lst_len_end(t_element *stack, t_element *end);
t_element       *lst_goto(t_element *stack, short pos);
t_element       *lst_last(t_element *stack);


/*
** Sorting
*/

void            sort(t_element *instructions, t_element **stack_a,
                        t_element **stack_b, t_op options);
void            normalize(t_element **el);

/*
** Util functions
*/

int		    simple_atoi(const char *nptr);

#endif