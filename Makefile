NAME = libftprintf.a

SRCS	= ft_printf.c\
		  ft_putstr.c\
		  ft_putnbr_base.c\
		  ft_putchar.c\
		  ft_putnbr.c

OBJS	= $(SRCS:.c=.o)

HEADER	= ft_printf.h

CC		= cc

FLGS	= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

.c.o:
			$(CC) $(FLGS) -I $(HEADER) -c $<

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re

