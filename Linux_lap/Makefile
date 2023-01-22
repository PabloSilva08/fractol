SRCS	=	main.c help.c fractol.c set_color.c
PREFD	=	$(addprefix ./obj/, $(SRCS))
OBJF	=	$(PREFD:.c=.o)
SRCPATH	=	./src/
OBJPATH	=	./obj/
OB		=	./obj
INCPATH	=	./include/
NAME	=	fractol	
CC		= 	cc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror
AR 		=	ar -rcs
RM		=	rm -rf

$(OBJPATH)%.o: $(SRCPATH)%.c 
			$(CC) $(CFLAGS) -I$(INCPATH) -I/usr/include -Imlx_linux\
				-O3 -c $< -o $@

all:		$(NAME)

$(NAME): 	$(OB) $(OBJF)
			make -C ../ft_printf
			$(CC) $(CFLAGS) $(OBJF) -L../ft_printf/ -lftprintf -Lmlx_linux -lmlx_Linux -L/usr/lib\
				-Imlx_linux	-lXext -lX11 -lm -lz -o $(NAME)

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
