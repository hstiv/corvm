NAME	=	corewar
SRCS	=	arena.c corvm.c dump_mem.c game.c new_vm.c op.c \
			parse_champs.c parser.c rec_utils.c cor_sort.c \
			add_op.c
OBJ		=	$(SRCS:.c=.o)
CC		=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft/ re
#	@make -C libvizu/ re
	@gcc $(CC) -c $(SRCS)
	@gcc -g -o $(NAME) $(OBJ) -L libft -lft

clean:
	@make -C libft/ clean
#	@make -C libvizu/ clean
	@rm -f $(OBJ)


fclean: clean
	@make -C libft/ fclean
#	@make -C libvizu/ fclean
	@rm -f $(NAME)

re: fclean all