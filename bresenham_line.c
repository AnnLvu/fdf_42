#include "fdf.h"

int	compare(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

void	put_pixel(t_fdf *fdf, int x, int y)
{
	char	*addr;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		fdf->img_data = mlx_get_data_addr(fdf->img_ptr \
				, &fdf->bonp, &fdf->size_line, &fdf->endian);
		addr = fdf->img_data + (y * fdf->size_line + x * (fdf->bonp / 8));
		*(unsigned int *)addr = fdf->color;
	}
}

t_line_param	*init_param(t_point3D *a, t_point3D *b)
{
	t_line_param	*param;

	param = (t_line_param *)malloc(sizeof(t_line_param));
	if (!param)
		return (NULL);
	param->dx = abs(b->x - a->x);
	param->sx = compare(a->x, b->x);
	param->dy = -abs(b->y - a->y);
	param->sy = compare(a->y, b->y);
	param->err = param->dx + param->dy;
	return (param);
}

void	bresenham_line(t_fdf *fdf, t_point3D *a, t_point3D *b)
{
	t_line_param	*param;

	param = init_param(a, b);
	while (1)
	{
		put_pixel(fdf, a->x, a->y);
		if (a->x == b->x && a->y == b->y)
			break ;
		param->e2 = 2 * param->err;
		if (param->e2 >= param->dy)
		{
			param->err += param->dy;
			a->x += param->sx;
		}
		if (param->e2 <= param->dx)
		{
			param->err += param->dx;
			a->y += param->sy;
		}
	}
	free(a);
	free(b);
	free(param);
}
