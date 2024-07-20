CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	push_swap

SRCS	=		src/checkargs.c\
				src/ft_split.c\
				src/list_creation.c\
				src/use_list.c\
				main.c\
				stack_order.c\
				instruction.c\
				instruction2.c

# SRC_BONUS	=

OBJS	=	$(SRCS:.c=.o)

# OBJ_BONUS	=

all	:	$(NAME)

%.o: %.c
	$(CC) -g $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
		$(MAKE) -C ft_printf
		$(CC) -g $(CFLAGS) $(OBJS) ft_printf/libftprintf.a -o $(NAME)

# bonus : $(OBJ_BONUS)
# 		$(CC) $(CFLAGS) $(OBJ_BONUS)

clean	:
		$(MAKE) -C ft_printf clean
		rm -rf $(OBJS)
# $(OBJ_BONUS)

fclean	:	clean
		$(MAKE) -C ft_printf fclean
		rm -f $(NAME)
# $(NAME_BONUS)

re	:	fclean all

.PHONY	:	all bonus clean fclean re
