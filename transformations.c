#include "fdf.h"

void	isometr(int *x, int *y, int z, double teta)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(teta);
	*y = (previous_x + previous_y) * sin(teta) - z;
}

void	x_rotation(int *x, int *y, int *z, double teta)
{
	(void)(x);
	*y = *y * cos(teta) + *z * sin(teta);
	*z = -(*y) * sin(teta) + *z * (cos(teta));
}

void	y_rotation(int *x, int *y, int *z, double teta)
{
	(void)(y);
	*x = *x * cos(teta) + *z * sin(teta);
	*z = -(*x) * sin(teta) + *z * (cos(teta));
}

void	z_rotation(int *x, int *y, int *z, double teta)
{
	(void)(z);
	*x = *x * cos(teta) - *y * sin(teta);
	*y = (*x) * sin(teta) + *y * (cos(teta));
}
