#include "fdf.h"

t_point3D	*point_init(int x, int y, t_fdf *fdf)
{
	t_point3D	*p;

	p = (t_point3D *)malloc(sizeof(t_point3D));
	if (!p)
		return (NULL);
	p->x = x;
	p->y = y;
	p->z = fdf->matrix[y][x].z.altitude * fdf->altitude;
	return (p);
}

t_point3D	*apply_projection(t_point3D *p, t_fdf *fdf)
{
	p->x *= fdf->zoom;
	p->y *= fdf->zoom;
	x_rotation(&p->x, &p->y, &p->z, fdf->alpha);
	y_rotation(&p->x, &p->y, &p->z, fdf->beta);
	z_rotation(&p->x, &p->y, &p->z, fdf->teta);
	if (fdf->project == 1)
		isometr(&p->x, &p->y, p->z, fdf->def_ang);
	p->x += fdf->x_pos;
	p->y += fdf->y_pos;
	return (p);
}

void	draw_x_line(t_fdf *fdf, int x, int y)
{
	if (fdf->matrix[y][x].z.color == -1)
	{
		if (fdf->matrix[y][x].z.altitude != 0)
			fdf->color = 0xFFA500;
		else
			fdf->color = 0x9370DB;
	}
	else
		fdf->color = fdf->matrix[y][x].z.color;
	bresenham_line(fdf, apply_projection(point_init(x, y, fdf), fdf), \
	apply_projection(point_init(x + 1, y, fdf), fdf));
}

void	draw_y_line(t_fdf *fdf, int x, int y)
{
	if (fdf->matrix[y][x].z.color == -1)
	{
		if (fdf->matrix[y][x].z.altitude != 0)
			fdf->color = 0xFFA500;
		else
			fdf->color = 0x9370DB;
	}
	else
		fdf->color = fdf->matrix[y][x].z.color;
	bresenham_line(fdf, apply_projection(point_init(x, y, fdf), fdf), \
	apply_projection(point_init(x, y + 1, fdf), fdf));
}

void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				draw_x_line(fdf, x, y);
			if (y < fdf->height - 1)
				draw_y_line(fdf, x, y);
			x++;
		}
		y++;
	}
}
