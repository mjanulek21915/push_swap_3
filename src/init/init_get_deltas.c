#include "push_swap.h"

static void				igd_bzero(t_data *main_data)
{
	int i;

	i = main_data->main_list.count;
	while (i--)
		main_data->main_list.data[i].delta = 0;
}

static int				igd_get(t_data *main_data, int pos)
{
	int i;

	i = 0;
	while(i < main_data->main_list.count)
	{
		if (main_data->main_list.data[i].is_anchor)
		{
			if (main_data->main_list.data[pos].interval == main_data->main_list.data[i].upper)
				return (i - pos);
		}
		i++;
	}
}

void					init_get_deltas(t_data *main_data)
{
	int i;
	int temp_a;
	int temp_b;
	
	i = 0;
	while (i < main_data->main_list.count)
	{
		if (!main_data->main_list.data[i].is_anchor)
		{
			temp_a = igd_get(main_data, i);
			temp_b = main_data->main_list.count - lib_abs(temp_a);
			temp_b = (temp_a > 0) ? -temp_b : temp_b;
			main_data->main_list.data[i].delta = (lib_abs(temp_a) < lib_abs(temp_b)) ? temp_a : temp_b;
		}
		i++;
	}
}