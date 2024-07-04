#include "fdf.h"
void	free_stack(t_stack *stack, t_fdf *fdf)
{
	t_stack	*ptr;
	t_stack	*suiv;

	while (stack != NULL)
	{
		suiv = stack->next;
		free(stack->z);
		stack = suiv;
	}
	while (fdf->stack)
	{
		ptr = fdf->stack->next;
		free(fdf->stack);
		fdf->stack = ptr;
	}
}

void	print_info(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, WIDTH - 90, 0, \
				0xffffff, "By Rigor");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 0, \
				0xffffff, "Translate MAP : UP / DOWN / LEFT / RIGHT");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 20, \
				0xffffff, "Rotation X/Y/Z AXSES : x/y/z");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 40, \
				0xffffff, "ZOOM IN/OUT : p/m");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 60, \
				0xffffff, "ALTITUDE VARIATION PLUS/MINUS : c/d");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 80, \
				0xffffff, "PROJECTION ISOMETRIC/PARALLEL : a/b");
}

void	initialize_camera(t_fdf *fdf)
{
	// Устанавливает значение увеличения (zoom) в зависимости от ширины карты (fdf->width)
	if (fdf->width >= 400)
		fdf->zoom = 1;	// Если ширина карты >= 400, устанавливается zoom = 1
	else if (fdf->width >= 300)
		fdf->zoom = 5;	// Если ширина карты >= 300, но < 400, устанавливается zoom = 5
	else
		fdf->zoom = 20;	// Если ширина карты < 300, устанавливается zoom = 20

	// Устанавливает начальную позицию по оси X (x_pos) так, чтобы карта была центрирована по горизонтали
	fdf->x_pos = (WIDTH / 2) - (fdf->width / 2);
	// Устанавливает начальную позицию по оси Y (y_pos) так, чтобы карта была центрирована по вертикали
	fdf->y_pos = (HEIGHT / 2) - (fdf->height / 2);
	// Устанавливает начальный тип проекции (project)
	fdf->project = 1;	//изометрическую проекцию
	// Устанавливает начальное значение высоты (altitude)
	fdf->altitude = 1;	// Устанавливается масштаб высоты равным 1
	fdf->rot = 0;
	// Устанавливает начальный угол камеры (def_ang)
	fdf->def_ang = DEFAULT_ANG; // DEFAULT_ANG - это константа, задающая начальный угол (30 градусов в радианах)
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->teta = 0;
}

void	fdf_init(t_fdf *fdf, char *filename, int *check_fd)
{
	t_stack *stack;
	int fd;

	// Открытие файла для чтения
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error(1); // Если файл не открылся, выводим ошибку

	// Проверка имени файла
	check_filename(filename);

	// Чтение карты из файла и сохранение данных в структуру
	fdf->stack = read_map(fd, &fdf->height, &fdf->width, check_fd);
	if (*check_fd == -1)
		print_error(3); // Ошибка при чтении карты
	else if (*check_fd == -2)
		print_error(4); // Другая ошибка при чтении карты

	stack = fdf->stack;

	// Создание матрицы на основе прочитанных данных
	fdf->matrix = create_matrix(fdf, stack);

	// Освобождение памяти, занятой стеком, и обнуление указателя
	free_stack(fdf->stack, fdf);
	fdf->stack = NULL;

	// Инициализация камеры (настройка начального состояния камеры)
	initialize_camera(fdf);

	// Инициализация графической библиотеки MiniLibX
	fdf->mlx_ptr = mlx_init();

	// Создание нового окна с заданной шириной, высотой и заголовком
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "Magic");

	// Создание нового изображения в памяти
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
}
