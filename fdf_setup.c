#include "fdf.h"

void	free_stack(t_stack *stack, t_fdf *fdf)
{
	t_stack	*current;
	t_stack	*next_node;

	while (stack != NULL)
	{
		next_node = stack->next;
		free(stack->z);
		stack = next_node;
	}
	while (fdf->stack)
	{
		current = fdf->stack->next;
		free(fdf->stack);
		fdf->stack = current;
	}
}

void	print_info(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 0, \
				0xffffff, "Translate MAP : UP / DOWN / LEFT / RIGHT");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 20, \
				0xffffff, "Rotation X/Y/Z : x/y/z");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 40, \
				0xffffff, "ZOOM IN/OUT : p/m");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 60, \
				0xffffff, "ALTITUDE VARIATION : c/d");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 80, \
				0xffffff, "PROJECTION ISOMETRIC/PARALLEL : a/b");
}

void	initialize_camera(t_fdf *fdf)
{
	if (fdf->width >= 400)
		fdf->zoom = 1;
	else if (fdf->width >= 300)
		fdf->zoom = 5;
	else
		fdf->zoom = 20;
	fdf->x_pos = (WIDTH / 2) - (fdf->width / 2);
	fdf->y_pos = (HEIGHT / 2) - (fdf->height / 2);
	fdf->project = 1;
	fdf->altitude = 1;
	fdf->rotate = 0;
	fdf->def_ang = DEFAULT_ANG;
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->teta = 0;
}

void	fdf_init(t_fdf *fdf, char *filename, int *check_fd)
{
	t_stack	*stack;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error(1, fdf);
	check_filename(filename, fdf);
	fdf->stack = read_map(fd, &fdf->height, &fdf->width, check_fd, fdf);
	if (*check_fd == -1)
		print_error(3, fdf);
	else if (*check_fd == -2)
		print_error(4, fdf);
	stack = fdf->stack;
	fdf->matrix = create_matrix(fdf, stack);
	free_stack(fdf->stack, fdf);
	fdf->stack = NULL;
	initialize_camera(fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "FDF");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
}
