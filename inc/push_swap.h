#ifndef __PUSH_SWAP_H__
# define __PUSH_SWAP_H__
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

struct								s_cell;
typedef struct s_cell				t_cell;

struct								s_chain_cell;
typedef struct s_cell				t_chain_cell;

struct								s_i_cell;
typedef struct s_i_cell				t_i_cell;

struct								s_main_list;
typedef struct s_main_list			t_main_list;

struct								s_sorted_list;
typedef struct s_sorted_list		t_sorted_list;

struct								s_chained_list;
typedef struct s_chained_list		t_chained_list;

struct								s_interval_list;
typedef struct s_interval_list		t_interval_list;

struct								s_data;
typedef struct s_data				t_data;

struct								s_cell
{
	int value;
	int delta;
	int is_anchor;
	int upper;
	int lower;
	int interval;
};

struct								s_chain_cell
{
	int value;
	int delta;
	int is_anchor;
	int upper;
	int lower;
	int interval;
};

struct								s_i_cell
{
	int upper;
	int lower;
	int id;
};


struct								s_main_list
{
	int count;
	int smallest;
	int best_orig;
	int best_score;
	t_cell *data;
};

struct								s_interval_list
{
	int count;
	t_i_cell *data;
};

struct								s_sorted_list
{
	int count;
	int *data;
};

struct								s_data
{
	t_main_list main_list;
	t_sorted_list sorted_list;
	t_chain_cell *chained_list;
	t_interval_list interval_list;
};

// DEBUG
void debug_print_data(t_data *main_data);


int						lib_atoi(t_data *data, char *str);
void					lib_exit(t_data *data, char *msg);
void					lib_str_to_stderr(char *str);
void					lib_str_to_stdout(char *str);
int						lib_abs(int n);

void					init(t_data *main_data, int ac, char **av);
void					init_sort(t_data *main_data);
void					init_get_deltas(t_data *main_data);
void					init_get_anchors(t_data *main_data);
void					init_set_intervals(t_data *main_data);







#endif