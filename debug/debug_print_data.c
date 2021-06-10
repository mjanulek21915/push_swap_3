#include "push_swap.h"

void debug_print_data(t_data *main_data)
{
	int i = 0;
// PRINT SORTED LIST
	// i = 0;

	// fprintf(stderr, "----main_data->sorted_list :\n");

	// while (i < main_data->sorted_list.count)
	// {
	// 	fprintf(stderr, "  pos : %d - value : %d\n", i, main_data->sorted_list.data[i]);
	// 	i++;
	// }
	// fprintf(stderr, "----main_data->sorted_list end\n");


// PRINT MAIN LIST

	i = 0;

	fprintf(stderr, "----main_data->main_list :\n");
	fprintf(stderr, "  main list best origin : %d\n", main_data->main_list.best_orig);

	while (i < main_data->main_list.count)
	{
		fprintf(stderr, "  pos : %d - value : %d - delta : %d - is_anchor : %d\n", i, main_data->main_list.data[i].value, main_data->main_list.data[i].delta, main_data->main_list.data[i].is_anchor);
		if (main_data->main_list.data[i].is_anchor)
			fprintf(stderr, "  upper : %d - lower : %d\n", main_data->main_list.data[i].upper, main_data->main_list.data[i].lower);
		else
			fprintf(stderr, "  interval : %d\n",main_data->main_list.data[i].interval);
		i++;
	}
	fprintf(stderr, "----main_data->main_list end\n");

// PRINT INTERVALS
	i = 0;
	fprintf(stderr, "----intervals :\n");
	fprintf(stderr, "  interval list count : %d\n", main_data->interval_list.count);

	while (i < main_data->interval_list.count)
	{
		fprintf(stderr, "  pos : %d - lower : %d - upper : %d - id : %d\n", i, main_data->interval_list.data[i].lower, main_data->interval_list.data[i].upper, main_data->interval_list.data[i].id);
		i++;
	}
	fprintf(stderr, "----intervals end\n");
}