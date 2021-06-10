#include "push_swap.h"

void					lib_str_to_stderr(char *str)
{
	while (*str)
		write(2, str++, 1);
}