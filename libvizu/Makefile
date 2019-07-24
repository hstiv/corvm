NAME = libvizu.a

SRC =   init_mlx.c run_window.c \
		key_hooks.c utils.c

OBJ =   init_mlx.o run_window.o \
        key_hooks.o utils.o

INCLUDES =  ../libft/

INC = ../

FLAGS = -Wall -Wextra -Werror

LMLX = .libmlx/


all: $(NAME)

$(NAME):
	@make -C $(INCLUDES) fclean && make -C $(INCLUDES)
	@gcc $(FLAGS) -c $(SRC) -I $(INCLUDES) -I $(LMLX) -I $(INC)
	@ar -r -c -s $(NAME) $(OBJ)

norm:
	norminette ft_*.c
	norminette *.h

clean:
	@rm -rf $(OBJ)
	@make -C $(INCLUDES) fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all
