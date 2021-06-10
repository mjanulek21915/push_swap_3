#include "push_swap.h"

void					lib_exit(t_data *data, char *msg)
{
	lib_str_to_stderr(msg);
	exit(EXIT_FAILURE);
}