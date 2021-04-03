# ENVS
NAME=run
SHELL=/bin/bash
CFLAGS=-g -Wall -Wextra -Werror

OBJ_DIR=objs/

TESTS_FILES= t_swap.c			
TESTS_OBJS=$(addprefix $(OBJ_DIR), $(TESTS_FILES:.c=.o))


# TARGETS AND RULES
.PHONY:			all
all: 			$(OBJ_DIR) $(NAME)

$(OBJ_DIR):		
				@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:	%.c
				$(CC) $(LFLAGS) $(CFLAGS) -c $< -o $@

$(NAME): 		$(TESTS_OBJS)
				$(CC) $(LFLAGS) $(CFLAGS) $(TESTS_OBJS) -o $(NAME)

.PHONY:			clean
clean:
				@rm -rf $(OBJ_DIR)

.PHONY:			fclean
fclean: 		clean
				@rm -rf $(NAME)

.PHONY:			re
re: 			fclean all