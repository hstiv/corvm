NAME	    =	corewar

SRCS	    =	arena.c corvm.c  game.c new_vm.c op.c \
			    parse_champs.c parser.c rec_utils.c cor_sort.c  utils.c \
			    add_op.c bresenham.c init_mlx_args.c key_hooks.c run_window.c \
			    utils1.c check_live.c args_check.c mouse_press.c

OBJ		    =	$(SRCS:.c=.o)

CC		    =	-Wall -Wextra -Werror

LMLX        =   libmlx/

SRC_LMLX    =   -framework OpenGL -framework AppKit -L  $(LMLX) -lmlx


all: $(NAME)

$(NAME):
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling $(NAME)... Wait a sec."
	@make -C libft/ re
	@gcc $(CC) -c $(SRCS) -I includes
	@gcc -g -o $(NAME) $(OBJ) -L libft -lft $(SRC_LMLX)
	@echo "(•̀ᴗ•́)و $(NAME) generated!".

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)


fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all