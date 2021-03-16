# ENVS
CC=gcc
RM = rm -rf
CFLAGS=-g -Wall -Wextra -Werror
LFLAGS=-I includes/

CHECKER=checker
PUSH_SWAP=push_swap
TESTS=test

SRC_DIR=srcs/
OBJ_DIR=objs/
TESTS_DIR=tests/

SRC_FILES = instructions/swap.c

TEST_FILES = tests.c \
			 t_swap.c			

OBJ_FILES=$(SRC_FILES:.c=.o)
OBJS=$(addprefix $(OBJ_DIR), $(OBJ_FILES))

TESTS_OBJ_FILES=$(TESTS_FILES:.c=.o)
TESTS_OBJS=$(addprefix $(OBJ_DIR)/tests, $(TESTS_OBJ_FILES))


# DEPENDENCIES

$(OBJ_DIR):		
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(OBJ_DIR)/instructions
				@mkdir -p $(OBJ_DIR)/tests

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@$(CC) $(LFLAGS) $(CFLAGS) -c $< -o $@

$(TESTS): 		$(TESTS_OBJS)
				@$(CC) $(LFLAGS) $(CFLAGS) $(TESTS_OBJS) $(OBJS) -o tests/$(TESTS)

# RULES

all: 			$(OBJ_DIR) $(TESTS)

test: 			$(OBJ_DIR) $(TESTS)

clean:	
				@$(RM) $(OBJ_DIR)

fclean: 		clean
				@$(RM) $(CHECKER)
				@$(RM) $(PUSH_SWAP).dSYM

re: 			fclean all


.PHONY: all test clean fclean re