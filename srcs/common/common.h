#ifndef COMMON_H
# define COMMON_H

#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "./instructions/instructions.h"
#include "./../../dependencies/libft/libft.h"
#include "./../../dependencies/get_next_line/get_next_line.h"

typedef struct	s_element {
    int         value;
    int         n_val;
    short       chunk_limit;
    void        *next;
}				t_element;

/*
** Err
*/

void            error();

/*
** Stack operations
*/

t_element       *crt_stack(char **els);
t_element       *extract_stack(t_element *start, int len);

/*
** Sorting
*/

void            normalize(t_element **el);

/*
** Util functions
*/

int		        simple_atoi(const char *nptr);

#endif