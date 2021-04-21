# ENVS
CFLAGS=-Wall -Wextra -Werror
CFLAGS+=-Isrcs/checker -Isrcs/common -Isrcs/common/instructions -Isrcs/common/lst_operations -Isrcs/common/get_next_line -I$(LIB_DIR)
LFLAGS=-L$(LIB_DIR) -lft

SRC_DIR=srcs/
OBJ_DIR=objs/
LIB_DIR=dependencies/libft
COMMON_DIR=common/
PUSH_SWAP_DIR=push_swap/
CHECKER_DIR=checker/

CHECKER_FILES= args.c \
			   checker.c \
			   options.c \
			   read_instructions.c \
			   sort.c \
			   visualizer.c			

COMMON_FILES= error.c \
			  stack.c \
			  utils.c \
			  merge_sort.c \
			  merge_sort_utils.c \
			  instructions/push.c \
			  instructions/rot.c \
			  instructions/rot_rev.c \
			  instructions/swap.c \
			  lst_operations/lst_add.c \
			  lst_operations/lst_goto.c \
			  lst_operations/lst_last.c \
			  lst_operations/lst_len.c \
			  lst_operations/lst_print.c \
			  get_next_line/get_next_line.c

PUSH_SWAP_FILES= chunk.c \
				 push_swap.c \
				 sort.c \
				 split_back.c \
				 split_stack.c \
				 utils.c			

CHECKER_OBJS=$(addprefix $(OBJ_DIR)$(CHECKER_DIR), $(CHECKER_FILES:.c=.o))
COMMON_OBJS=$(addprefix $(OBJ_DIR)$(COMMON_DIR), $(COMMON_FILES:.c=.o))
PUSH_SWAP_OBJS=$(addprefix $(OBJ_DIR)$(PUSH_SWAP_DIR), $(PUSH_SWAP_FILES:.c=.o))

# TARGETS
.PHONY:			all
all: 			checker push_swap

$(OBJ_DIR):		
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(OBJ_DIR)/checker
				@mkdir -p $(OBJ_DIR)/common
				@mkdir -p $(OBJ_DIR)/common/instructions
				@mkdir -p $(OBJ_DIR)/common/get_next_line
				@mkdir -p $(OBJ_DIR)/common/lst_operations
				@mkdir -p $(OBJ_DIR)/push_swap


$(OBJ_DIR)$(COMMON_DIR)%.o:	$(SRC_DIR)$(COMMON_DIR)%.c
				@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)$(CHECKER_DIR)%.o:	$(SRC_DIR)$(CHECKER_DIR)%.c
				@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)$(PUSH_SWAP_DIR)%.o:	$(SRC_DIR)$(PUSH_SWAP_DIR)%.c
				@$(CC) $(CFLAGS) -c $< -o $@

# RULES

.PHONY:			push_swap
push_swap: 		$(OBJ_DIR) $(PUSH_SWAP_OBJS) $(COMMON_OBJS)
				@make -C $(LIB_DIR)
				$(CC) $(CFLAGS) $(LFLAGS) $(PUSH_SWAP_OBJS) $(COMMON_OBJS) -o push_swap

.PHONY:			checker
checker: 		$(OBJ_DIR) $(CHECKER_OBJS) $(COMMON_OBJS)
				@make -C $(LIB_DIR)
				$(CC) $(CFLAGS) $(LFLAGS) $(CHECKER_OBJS) $(COMMON_OBJS) -o checker

.PHONY:			clean
clean:
				@rm -rf $(OBJ_DIR)

.PHONY:			fclean
fclean: 		clean
				@make fclean -C $(LIB_DIR) 

.PHONY:			re
re: 			fclean all