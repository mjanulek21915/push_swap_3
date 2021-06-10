#include "push_swap.h"

static int				init_sort_get_smallest(t_data *main_data)
{
	int i;
	int rst;

	rst = main_data->main_list.data[0].value;
	i = 1;
	while (i < main_data->main_list.count)
	{
		if (main_data->main_list.data[i].value < rst)
			rst = main_data->main_list.data[i].value;
		i++;
	}
	return (rst);
}

static int				init_sort_get_next(t_data *main_data, int current)
{
	int i;
	int rst;

	i = 0;
	rst = INT_MAX;
	while (i < main_data->main_list.count)
	{
		if (main_data->main_list.data[i].value > current && main_data->main_list.data[i].value <= rst)
			rst = main_data->main_list.data[i].value;
		i++;
	}
	return (rst);
}

static void				init_sort_set_links(t_data *main_data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < main_data->main_list.count)
	{
		main_data->main_list.data[i].is_anchor = 0;
		j = 0;
		while (j < main_data->main_list.count)
		{
			if (main_data->main_list.data[i].value == main_data->sorted_list.data[j])
			{
				j++;
				j = j - ((j >= main_data->main_list.count) * main_data->main_list.count);
				break;
			}
			j++;
		}
		i++;
	}
}

void					init_sort(t_data *main_data)
{
	int i;
	int cap;

	i = 1;
	main_data->sorted_list.data[0] = init_sort_get_smallest(main_data);
	main_data->main_list.smallest = main_data->sorted_list.data[0];
	if (main_data->main_list.count < 2)
		return;
	while (i < main_data->main_list.count)
	{
		main_data->sorted_list.data[i] = init_sort_get_next(main_data, main_data->sorted_list.data[i - 1]);
		i++;
	}
}