#include "fdf.h"

void	print_error(int error)
{
	if (error == 1)
		write(2, "FILE ERROR.\n", 12);
	else if (error == 2)
		write(2, "Invalid Parameters.\n", 21);
	else if (error == 3)
		write(2, "Allocation Error.\n", 18);
	else if (error == 4)
		write(2, "Found wrong line length Exiting.\n", 33);
	exit(1);
}

int	check_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (filename[i - 1] != 'f')
	{
		print_error(1);
		exit(1);
	}
	return (0);
}