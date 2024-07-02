#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		check_fd;

	if (argc == 2)
	{
		check_fd = 0;
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		fdf_init(fdf, argv[1], &check_fd);
		free(fdf->stack);
		draw_map(fdf);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, WIDTH - 90, 0, \
				0xffffff, "FDF");
		mlx_hook(fdf->win_ptr, 2, 0L, esc_close, fdf);
		mlx_hook(fdf->win_ptr, 17, 0L, close_win, fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	else
		print_error(2);
	return (0);
}
