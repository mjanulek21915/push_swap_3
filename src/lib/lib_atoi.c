#include "push_swap.h"

int						lib_atoi(t_data *data, char *str)
{
	long rst;
	long sign;

	rst = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9' || rst > INT_MAX)
			lib_exit(data, "lib_atoi: invalid value\n");
		rst = rst * 10;
		rst = rst + (*str) - 48;
		str++;
	}
	if ((rst = rst * sign) < INT_MIN)
		lib_exit(data, "lib_atoi: invalid value\n");
	return (int)(rst);
}