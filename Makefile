# ENVS

LIBFT=libft
CHECKER=checker
PUSH_SWAP=push_swap

CFLAGS=-Wall -Wextra -Werror
CFLAGS+=-Isrcs/checker -Isrcs/common -Isrcs/common/instructions -Isrcs/common/lst_operations -Isrcs/common/get_next_line -I$(LIB_DIR)
LFLAGS=-L$(LIB_DIR) -lft

SRC_DIR=srcs/
OBJ_DIR=objs/
LIB_DIR=dependencies/mini_libft
COMMON_DIR=common/
PUSH_SWAP_DIR=push_swap/
CHECKER_DIR=checker/

CHECKER_FILES= main.c \
			   args.c \
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

PUSH_SWAP_FILES= main.c \
				 chunk.c \
				 push_swap.c \
				 sort_three.c \
				 split_back.c \
				 split_stack.c \
				 utils.c			

CHECKER_OBJS=$(addprefix $(OBJ_DIR)$(CHECKER_DIR), $(CHECKER_FILES:.c=.o))
COMMON_OBJS=$(addprefix $(OBJ_DIR)$(COMMON_DIR), $(COMMON_FILES:.c=.o))
PUSH_SWAP_OBJS=$(addprefix $(OBJ_DIR)$(PUSH_SWAP_DIR), $(PUSH_SWAP_FILES:.c=.o))

# TARGETS
.PHONY:			all
all: 			$(OBJ_DIR)  $(COMMON_OBJS) $(LIBFT) $(CHECKER) $(PUSH_SWAP)

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


$(PUSH_SWAP): 	$(PUSH_SWAP_OBJS)
				@printf "Building push_swap..."
				@$(CC) $(CFLAGS) $(LFLAGS) $(PUSH_SWAP_OBJS) $(COMMON_OBJS) -o $@
				@printf " ✔︎\n"

$(CHECKER): 	$(CHECKER_OBJS)
				@printf "Building checker..."
				@$(CC) $(CFLAGS) $(LFLAGS) $(CHECKER_OBJS) $(COMMON_OBJS) -o $@
				@printf " ✔︎\n"
				
$(LIBFT):	
				@make -C $(LIB_DIR)

# RULES

.PHONY:			clean
clean:
				@printf "Removing objs..."
				@rm -rf $(OBJ_DIR)
				@rm -rf checker
				@rm -rf push_swap
				@printf " ✔︎\n"

.PHONY:			fclean
fclean: 		clean
				@printf "Removing libft..."
				@make fclean -C $(LIB_DIR) 
				@printf " ✔︎\n"

.PHONY:			re
re: 			fclean all