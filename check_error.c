#include "fdf.h"

void	print_error(int error, t_fdf *fdf)
{
	if (error == 1)
		write(2, "Error: Unable to open file.\n", 28);
	else if (error == 2)
		write(2, "Error: Invalid input parameters.\n", 33);
	else if (error == 3)
		write(2, "Error: Memory allocation failed.\n", 33);
	else if (error == 4)
		write(2, "Error: Inconsistent line length in file. Exiting.\n", 50);
	if (fdf != NULL)
		free(fdf);
	exit(1);
}

int	check_filename(char *filename, t_fdf *fdf)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (filename[i - 1] != 'f')
	{
		print_error(1, fdf);
		exit(1);
	}
	return (0);
}
