#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		check_fd;

	if (argc == 2)
	{
		check_fd = 0;
		fdf = (t_fdf *)malloc(sizeof(t_fdf));
		if (!fdf)
		{
			print_error(3);
			exit (1);
		}
		fdf_init(fdf, argv[1], &check_fd);
		draw_map(fdf);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
		print_info(fdf);
		mlx_hook(fdf->win_ptr, 2, 1L << 0, handle_keyboard, fdf);
		mlx_hook(fdf->win_ptr, 17, 0L, close_win, fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	else
		print_error(2);
	return (0);
}
