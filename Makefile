# ENVS
CC=gcc
CFLAGS=-g -Wall -Wextra -Werror
RM = rm -rf

TESTS=run

OBJ_DIR=objs/
TESTS_OBJ_DIR=objs/tests/
TESTS_DIR=tests/

TESTS_FILES= t_swap.c			
TESTS_OBJS=$(addprefix $(TESTS_OBJ_DIR), $(TESTS_FILES:.c=.o))


# TARGETS
.PHONY:			all
all: 			$(OBJ_DIR) $(TESTS)

$(OBJ_DIR):		
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(OBJ_DIR)/tests

$(TESTS_OBJ_DIR)%.o:	$(TESTS_DIR)%.c
				@$(CC) $(LFLAGS) $(CFLAGS) -c $< -o $@

$(TESTS): 		$(TESTS_OBJS)
				$(CC) $(LFLAGS) $(CFLAGS) $(TESTS_OBJS) -o tests/$@

# RULES

.PHONY:			tests
tests: 			$(OBJ_DIR) $(TESTS)

.PHONY:			clean
clean:	
				@$(RM) $(OBJ_DIR)

.PHONY:			fclean
fclean: 		clean
				@$(RM) $(TESTS_DIR)$(TESTS)

.PHONY:			re
re: 			fclean all