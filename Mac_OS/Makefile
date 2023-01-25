SRCS	=	main.c help.c init_frac.c fractol_mandelbrot.c fractol_julia.c\
			fractol_burning_ship.c error.c events.c
PREFD	=	$(addprefix ./obj/, $(SRCS))
OBJF	=	$(PREFD:.c=.o)
SRCPATH	=	./src/
OBJPATH	=	./obj/
OB		=	./obj
INCPATH	=	./include/
NAME	=	fractol	
CC		= 	cc
RM		=	rm -f
CFLAGS 	= 	-Wall -Wextra -Werror -Ofast 
AR 		=	ar -rcs
RM		=	rm -rf

$(OBJPATH)%.o: $(SRCPATH)%.c 
			$(CC) $(CFLAGS) -I$(INCPATH) -Imlx -c $< -o $@

all:		$(NAME)

$(NAME): 	$(OB) $(OBJF)
			make -C ../ft_printf
			$(CC) $(CFLAGS) $(OBJF) -L../ft_printf/ -lftprintf  -L./minilibx_opengl/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OB):		
			mkdir obj

clean:
			make clean -C ../ft_printf
			$(RM) $(OBJF)
			rm -rf obj

fclean:		clean
			make fclean -C ../ft_printf
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
