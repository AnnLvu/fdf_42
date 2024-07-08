#include "fdf.h"

int	altitude_and_proj(int key, t_fdf *fdf)
{
	if (key == 0x0063)
	{
		fdf->altitude += 2;
	}
	else if (key == 0x0064)
	{
		fdf->altitude -= 2;
	}
	if (key == 0x0061)
	{
		fdf->project = 1;
	}
	else if (key == 0x0062)
	{
		fdf->project = 0;
	}
	return (0);
}

int	translate_rot_map(int key, t_fdf *fdf)
{
	if (key == 0xff52)
		fdf->y_pos -= 20;
	else if (key == 0xff54)
		fdf->y_pos += 20;
	else if (key == 0xff51)
		fdf->x_pos -= 20;
	else if (key == 0xff53)
		fdf->x_pos += 20;
	else if (key == 0x0078)
	{
		fdf->rotate = 1;
		fdf->alpha += 0.2;
	}
	else if (key == 0x0079)
	{
		fdf->rotate = 2;
		fdf->beta += 0.2;
	}
	else if (key == 0x007a)
	{
		fdf->rotate = 3;
		fdf->teta += 0.2;
	}
	return (0);
}
