#include "push_swap.h"

void					lib_str_to_stdout(char *str)
{
	while (*str)
		write(1, str++, 1);
}