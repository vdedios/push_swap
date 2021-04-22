NAME	=	 libft.a

CC	=	 gcc

CFLAGS	=	 -Werror -Wall -Wextra

AR	=	 ar -rcs

SRC	=	 ft_isdigit.c 		\
			 ft_itoa.c 		\
			 ft_putstr_fd.c 	\
			 ft_strlen.c 		\
			 ft_strncmp.c 		\

OBJS	 =	$(SRC:%.c=%.o)

all	:	$(NAME)

$(NAME)	: 	$(OBJS) libft.h
	$(AR) $(NAME) $(OBJS)

%.o	:	%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I.


clean	:
	rm -rf $(OBJS) $(OBJ_BONUS)

fclean	: 	clean
	rm -rf $(NAME)

re	:	fclean all

.PHONY: clean fclean all re bonus
