# ENVS
CFLAGS=-g -Wall -Wextra -Werror
NAME=run

OBJ_DIR=objs/
TESTS_OBJ_DIR=objs/tests/
TESTS_DIR=tests/

TESTS_FILES= t_swap.c			
TESTS_OBJS=$(addprefix $(TESTS_OBJ_DIR), $(TESTS_FILES:.c=.o))


# TARGETS
.PHONY:			all
all: 			$(OBJ_DIR) $(NAME)

$(OBJ_DIR):		
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(OBJ_DIR)/tests

$(TESTS_OBJ_DIR)%.o:	$(TESTS_DIR)%.c
				@$(CC) $(LFLAGS) $(CFLAGS) -c $< -o $@

$(NAME): 		$(TESTS_OBJS)
				$(CC) $(LFLAGS) $(CFLAGS) $(TESTS_OBJS) -o $(TESTS_DIR)$(NAME)

# RULES

.PHONY:			tests
tests: 			$(OBJ_DIR) $(TESTS)

.PHONY:			clean
clean:
				@rm -rf $(OBJ_DIR)

.PHONY:			fclean
fclean: 		clean
				@rm -rf $(TESTS_DIR)$(NAME)

.PHONY:			re
re: 			fclean all