CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	push_swap

NAME_BONUS = checker

SRCS	=		checkargs.c\
				ft_split.c\
				list_creation.c\
				use_list.c\
				main.c\
				instruction_push.c\
				instruction_swap.c\
				instruction_rotation.c\
				instruction_reverse_rotate.c\
				stack_order.c\
				rotation.c\
				stack_attribute.c\
				calcul.c\
				calcul2.c\

SRCS_BONUS	=	bonus/checker_arg_bonus.c\
				bonus/checker_bonus.c\
				bonus/list_creation_bonus.c\
				bonus/ft_split_bonus.c

OBJS	=	$(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all	:	$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus	:	$(OBJS_BONUS)
		$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)

clean	:
		rm -rf $(OBJS)
		rm -rf $(OBJS_BONUS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all bonus clean fclean re
