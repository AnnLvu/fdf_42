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

// Проекция точки с учетом поворотов и зума
t_point3D	*apply_projection(t_point3D *p, t_fdf *fdf)
{
	// Применяем зум к координатам
	p->x *= fdf->zoom;
	p->y *= fdf->zoom;
	// Применяем вращение по осям x, y и z
	x_rotation(&p->x, &p->y, &p->z, fdf->alpha);
	y_rotation(&p->x, &p->y, &p->z, fdf->beta);
	z_rotation(&p->x, &p->y, &p->z, fdf->teta);
	// Если выбранная проекция - изометрическая, применяем её
	if (fdf->project == 1)
		iso(&p->x, &p->y, p->z, fdf->def_ang);
	// Смещаем точку на заданные координаты
	p->x += fdf->x_pos;
	p->y += fdf->y_pos;
	return (p);
}

// Устанавливает цвет и рисует линию по оси x
void	draw_x_line(t_fdf *fdf, int x, int y)
{
	// Определение цвета текущей точки
	if (fdf->matrix[y][x].z.color == -1)
	{
		if (fdf->matrix[y][x].z.altitude != 0)
			fdf->color = 0xff0000; // Красный для ненулевой высоты
		else
			fdf->color = 0xffffff; // Белый для нулевой высоты
	}
	else
		fdf->color = fdf->matrix[y][x].z.color;
	// Рисуем линию по оси x
	bresnham(fdf, apply_projection(point_init(x, y, fdf), fdf), apply_projection(point_init(x + 1, y, fdf), fdf));
}

// Устанавливает цвет и рисует линию по оси y
void	draw_y_line(t_fdf *fdf, int x, int y)
{
	// Определение цвета текущей точки
	if (fdf->matrix[y][x].z.color == -1)
	{
		if (fdf->matrix[y][x].z.altitude != 0)
			fdf->color = 0xff0000; // Красный для ненулевой высоты
		else
			fdf->color = 0xffffff; // Белый для нулевой высоты
	}
	else
		fdf->color = fdf->matrix[y][x].z.color;
	// Рисуем линию по оси y
	bresnham(fdf, projection(point_init(x, y, fdf), fdf), projection(point_init(x, y + 1, fdf), fdf));
}

// Основная функция для рисования карты
void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	// Проходим по каждой точке матрицы
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				draw_x_line(fdf, x, y); // Рисуем линию по x
			if (y < fdf->height - 1)
				draw_y_line(fdf, x, y); // Рисуем линию по y
			x++;
		}
		y++;
	}
}