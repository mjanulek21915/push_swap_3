#include "push_swap.h"

void					init(t_data *main_data, int ac, char **av)
{
	int i;

	i = 1;
	main_data->main_list.count = ac - 1;
	main_data->sorted_list.count = main_data->main_list.count;
	if (!(main_data->main_list.data = malloc(sizeof(t_cell) * main_data->main_list.count)))
		lib_exit(main_data, "init main list malloc fail");
	if (!(main_data->sorted_list.data = malloc(sizeof(int) * main_data->main_list.count)))
		lib_exit(main_data, "init main list malloc fail");

	while (i < ac)
	{
		main_data->main_list.data[i - 1].value = lib_atoi(main_data, av[i]);
		i++;
	}
	
	i = 0;

	while (i < main_data->main_list.count)
	{
		main_data->main_list.data[i].is_anchor = 0;
		i++;
	}

	init_sort(main_data);
	init_get_anchors(main_data);
	init_set_intervals(main_data);
	init_get_deltas(main_data);
}