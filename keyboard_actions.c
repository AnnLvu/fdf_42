#include "fdf.h"

int	close_win(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	clean_all_for_fdf_struct(fdf);
	exit (1);
}

int	key_zoom(int key, t_fdf *fdf)
{
	if (key == 0x0070)
	{
		fdf->zoom += 2;
		fdf->x_pos -= 10;
		fdf->y_pos -= 10;
	}
	else if (key == 0x006d)
	{
		if (fdf->zoom < 2)
			fdf->zoom = 1;
		else
		{
			fdf->zoom -= 2;
			fdf->x_pos += 10;
			fdf->y_pos += 10;
		}
	}
	else if (key == 0xff1b)
		clean_up_resources_esc(fdf);
	return (0);
}

int	handle_keyboard(int key, t_fdf *fdf)
{
	key_zoom(key, fdf);
	translate_rot_map(key, fdf);
	altitude_and_proj(key, fdf);
	mlx_clear_window((fdf)->mlx_ptr, (fdf)->win_ptr);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	draw_map((fdf));
	mlx_put_image_to_window((fdf)->mlx_ptr, (fdf)->win_ptr, \
			(fdf)->img_ptr, 0, 0);
	print_info(fdf);
	return (0);
}

void	clean_up_resources_esc(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	clean_all_for_fdf_struct(fdf);
	exit(0);
}

void	clean_all_for_fdf_struct(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->height)
	{
		free(fdf->matrix[i]);
		i++;
	}
	free(fdf->matrix);
	free(fdf);
}
