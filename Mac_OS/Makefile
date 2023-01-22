SRCS	=	main.c frac_util.c

OBJ		=	$(SRCS:.c=.o)

CFLAGS 	= 	-Wall -Wextra -Werror -Ofast -lm -L./minilibx_opengl -lmlx\
			-framework OpenGL -framework AppKit -g

INC		= 	/usr/include

RM		=	rm -rf

NAME	=	mini.x

CC		=	cc

%.o: %.c
			$(CC) -I $(INC) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME): 	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
