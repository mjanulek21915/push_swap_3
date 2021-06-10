#include "push_swap.h"

static int				iga_get_score_fn(t_data *main_data, int orig)
{
	int pos;
	int temp;
	int rst;
	int i;

	pos = orig + 1;
	temp = main_data->main_list.data[orig].value;
	rst = 0;
	i = 0;

	while (i < main_data->main_list.count)
	{
		pos = pos - ((pos >= main_data->main_list.count) * main_data->main_list.count);
		if (main_data->main_list.data[pos].value > temp)
		{
			temp = main_data->main_list.data[pos].value;
			rst++;
		}
		pos++;
		i++;
	}
fprintf(stderr, "iga_get_score_fn : orig : %d score : %d\n", orig, rst);
	return (rst);
}

static void				iga_get_score(t_data *main_data)
{
	int i;
	int score;
	int score_r;
	int temp_score;
	int temp_r;

	i = 0;
	main_data->main_list.best_score = 0;
	while (i < main_data->main_list.count)
	{
		score = iga_get_score_fn(main_data, i);
		if (score > main_data->main_list.best_score)
		{
			main_data->main_list.best_orig = i;
			main_data->main_list.best_score = score;
		}
		i++;
	}
}

void					iga_set_anchors(t_data *main_data)
{
	int orig;
	int pos;
	int temp;
	int rst;
	int i;

	orig = main_data->main_list.best_orig;
	pos = orig + 1;
	temp = main_data->main_list.data[orig].value;
	main_data->main_list.data[orig].is_anchor = 1;
	rst = 0;
	i = 0;

	while (i < main_data->main_list.count)
	{
		pos = pos - ((pos >= main_data->main_list.count) * main_data->main_list.count);
		if (main_data->main_list.data[pos].value > temp)
		{
			temp = main_data->main_list.data[pos].value;
			main_data->main_list.data[pos].is_anchor = 1;
		}
		pos++;
		i++;
	}
}

void					init_get_anchors(t_data *main_data)
{
	iga_get_score(main_data);
	iga_set_anchors(main_data);
}