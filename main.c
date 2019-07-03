#include "corewar.h"
#include "libft/libft.h"

void	print_usage(void)
{
	ft_putstr("Usage: ");
	ft_putstr("./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...\n");
	exit(0);
}

void    init_vm(t_vm *vm)
{
    vm->dump = 0;
    vm->nmbr_players = 0;
}

void    parsing_args(int ac, char **av, t_vm *vm)
{
    int i;

    i = 1;
    init_vm(vm);
    while (i < ac)
    {
        if (!ft_strcmp("-dump", av[i]))
        {
            vm->dump = 1;
            if (i + 1 < ac && ft_isdigit(av[i + 1][0]))
                vm->dump_nmbr = ft_atoi(av[++i]);
            else
                print_usage();
        }
        else if (ft_strstr(av[i], ".cor") && ft_strlen(av[i]) > 4)
        {
            if (vm->nmbr_players < MAX_PLAYERS)
            {
                vm->nmbr_players += 1;
            }
            else
                print_usage();
        }
        else if (!ft_strcmp("-n", av[i]))
        {
            if (i + 1 < ac && ft_isdigit(av[i + 1][0]))
            {

            }
            else
                print_usage();
        }
        else
            print_usage();
        i++;
    }
}

int main(int ac, char **av)
{
    t_vm vm;

    if (ac == 1)
        print_usage();
    parsing_args(ac, av, &vm);
    ft_printf("%d", vm.nmbr_players);
}