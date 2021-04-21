#ifndef LST_OPERATIONS_H
# define LST_OPERATIONS_H

typedef struct	s_element {
    int         value;
    int         n_val;
    short       chunk_limit;
    void        *next;
}				t_element;


/*
** Stack utils
*/

void            lst_print(char *msg, t_element *stack);
void            lst_print_norm(char *msg, t_element *stack);
void            lst_add(t_element **stack, int value);
int             lst_len(t_element *stack);
int             lst_len_end(t_element *stack, t_element *end);
t_element       *lst_goto(t_element *stack, short pos);
t_element       *lst_last(t_element *stack);

#endif