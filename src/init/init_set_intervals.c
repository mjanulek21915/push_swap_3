#include "push_swap.h"
//todo : verif si le compte des intervalles = 0
// si le compte est a 0, dois sortir et juste placer le stack a la position du premier

static int				isi_count(t_data *main_data)
{
	int i;
	int rst;

	i = 0;
	rst = 0;
	while (i < main_data->main_list.count)
		if (main_data->main_list.data[i++].is_anchor)
			rst++;
	return (rst);
}

static void				isi_set_lower(t_data *main_data)
{
	int i;
	int j;
	int lower;

	i = 0;
	j = main_data->main_list.best_orig;
	lower = 0;
	while (i < main_data->interval_list.count)
	{
		if (main_data->main_list.data[j].is_anchor)
		{
			main_data->interval_list.data[i].lower = lower;
			lower = main_data->main_list.data[j].value;
			main_data->interval_list.data[i].id = lower;
			i++;
		}
		j++;
		j = ((j < main_data->main_list.count) * j);
	}
	main_data->interval_list.data[0].lower = main_data->interval_list.data[i - 1].id;
}

static void				isi_set_upper(t_data *main_data)
{
	int i;
	int j;
	int upper;

	i = main_data->interval_list.count - 1;
	while (i)
	{
		upper = main_data->interval_list.data[i--].id;
		main_data->interval_list.data[i].upper = upper;
	}
	main_data->interval_list.data[main_data->interval_list.count - 1].upper = main_data->interval_list.data[0].id;
}

static void					isi_set_cell_intervals_anchors(t_data *main_data)
{
	int i;
	int j;

	i = 0;

	while (i < main_data->main_list.count)
	{
		if (main_data->main_list.data[i].is_anchor)
		{
			j = 0;
			while (j < main_data->interval_list.count)
			{
				if (main_data->interval_list.data[j].id == main_data->main_list.data[i].value)
				{
					main_data->main_list.data[i].upper = j;
					main_data->main_list.data[i].lower = ((j - 1) + (main_data->interval_list.count * ((j - 1) < 0)));
					break;
				}
				j++;
			}
		}
		i++;
	}

}

// static void					isi_set_cell_intervals_anchors(t_data *main_data)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = main_data->main_list.best_orig;
// 	while (i < main_data->interval_list.count)
// 	{
// 		if (main_data->interval_list.data[i].id == main_data->main_list.data[j].value)
// 		{
			
// 			main_data->main_list.data[j].upper = i;
// 			main_data->main_list.data[j].lower = ((i - 1) + (main_data->interval_list.count * ((i - 1) < 0)));
// 			i++;
// 		}
// 		j++;
// 	}
// }

static void					isi_set_cell_intervals_non_anchors(t_data *main_data)
{
	int i;
	int j;

	i = 0;
	while (i < main_data->main_list.count)
	{
		if (!main_data->main_list.data[i].is_anchor)
		{
			j = 0;
			while ( j < main_data->interval_list.count)
			{
				if (main_data->interval_list.data[j].id > main_data->interval_list.data[j].upper)
				{
					if (main_data->main_list.data[i].value > main_data->interval_list.data[j].id ||
					 main_data->main_list.data[i].value < main_data->interval_list.data[j].upper)
					 {
						main_data->main_list.data[i].interval = j;
						break;
					 }
				}



				else if (main_data->main_list.data[i].value > main_data->interval_list.data[j].id 
				&& main_data->main_list.data[i].value < main_data->interval_list.data[j].upper)
				{
					main_data->main_list.data[i].interval = j;
					break;

				}
				j++;
			}
		}
		i++;
	}
}

void					init_set_intervals(t_data *main_data)
{
	main_data->interval_list.count = isi_count(main_data);
	if (!(main_data->interval_list.data = malloc(sizeof(t_i_cell) * main_data->interval_list.count)))
		lib_exit(main_data, "init_set_intervals malloc fail\n");
	isi_set_lower(main_data);
	isi_set_upper(main_data);
	isi_set_cell_intervals_anchors(main_data);
	isi_set_cell_intervals_non_anchors(main_data);
}