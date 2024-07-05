#include "fdf.h"

int	close_win(t_fdf *param)
{
	// Уничтожаем изображение
	mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	// Уничтожаем окно
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	mlx_destroy_display(param->mlx_ptr);

	// Освобождаем память, выделенную для mlx_ptr
	free(param->mlx_ptr);
	exit (1);
	// Завершаем программу
	return (0);
}
int	key_zoom(int key, t_fdf *param)
{
	if (key == 0x0070)
	{
		param->zoom += 2;
		param->x_pos -= 10;
		param->y_pos -= 10;
	}
	else if (key == 0x006d)
	{
		if (param->zoom < 2)
			param->zoom = 1;
		else
		{
			param->zoom -= 2;
			param->x_pos += 10;
			param->y_pos += 10;
		}
	}
	else if (key == 0xff1b)
	{
		mlx_destroy_image(param->mlx_ptr, param->img_ptr);
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		mlx_destroy_display(param->mlx_ptr);
		free(param->mlx_ptr);
		exit(0);
	}
	return (0);
}
int	translate_rot_map(int key, t_fdf *param)
{
	if (key == 0xff52)
		param->y_pos -= 20;
	else if (key == 0xff54)
		param->y_pos += 20;
	else if (key == 0xff51)
		param->x_pos -= 20;
	else if (key == 0xff53)
		param->x_pos += 20;
	else if (key == 0x0078)
	{
		param->rot = 1;
		param->alpha += 0.2;
	}
	else if (key == 0x0079)
	{
		param->rot = 2;
		param->beta += 0.2;
	}
	else if (key == 0x007a)
	{
		param->rot = 3;
		param->teta += 0.2;
	}
	return (0);
}

int	altitude_and_proj(int key, t_fdf *param)
{
	if (key == 0x0063)
	{
		param->altitude += 2;
	}
	else if (key == 0x0064)
	{
		param->altitude -= 2;
	}
	if (key == 0x0061)
	{
		param->project = 1;
	}
	else if (key == 0x0062)
	{
		param->project = 0;
	}
	return (0);
}

int	event_key(int key, t_fdf *param)
{
	key_zoom(key, param);
	translate_rot_map(key, param);
	altitude_and_proj(key, param);
	mlx_clear_window((param)->mlx_ptr, (param)->win_ptr);
	mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	param->img_ptr = mlx_new_image(param->mlx_ptr, WIDTH, HEIGHT);
	draw_map((param));
	mlx_put_image_to_window((param)->mlx_ptr, (param)->win_ptr, \
			(param)->img_ptr, 0, 0);
	print_info(param);
	return (0);
}
