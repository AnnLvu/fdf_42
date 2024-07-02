#include "fdf.h"

int	close_win(t_fdf *param)
{
	// Уничтожаем изображение
	mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	// Уничтожаем окно
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	// Освобождаем память, выделенную для mlx_ptr
	free(param->mlx_ptr);
	// Завершаем программу
	exit(0);
}

int	esc_close(int key, t_fdf *param)
{
	// Проверяем, была ли нажата клавиша ESC
	if (key == ESC)
	{
		// Уничтожаем изображение
		mlx_destroy_image(param->mlx_ptr, param->img_ptr);
		// Уничтожаем окно
		mlx_destroy_window(param->mlx_ptr, param->win_ptr);
		// Освобождаем память, выделенную для mlx_ptr
		free(param->mlx_ptr);
		// Завершаем программу
		exit(0);
	}
	return (0);
}
