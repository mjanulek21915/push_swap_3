#include "push_swap.h"

int main(int ac, char **av)
{	
	int i;
	t_data main_data;
	if (ac < 2)
		lib_exit(NULL, "no arguments provided\n");
	init(&main_data, ac, av);
	debug_print_data(&main_data);
}