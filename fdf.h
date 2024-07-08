#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"

# define WIDTH 1024
# define HEIGHT 768
# define DEFAULT_ANG 0.523599

typedef struct s_point_param
{
	int	altitude;
	int	color;
}	t_point_param;

typedef struct s_point3D
{
	int	x;
	int	y;
	int	z;
}	t_point3D;

typedef struct s_for_matrix
{
	t_point_param	z;
}	t_for_matrix;

typedef struct s_stack
{
	t_point_param	*z;
	struct s_stack	*next;
}	t_stack;

typedef struct s_line_param
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
}	t_line_param;

typedef struct s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	t_for_matrix	**matrix;
	t_stack			*stack;
	int				width;
	int				height;
	int				zoom;
	int				color;
	int				x_pos;
	int				y_pos;
	int				bonp;
	int				size_line;
	int				endian;
	int				altitude;
	int				project;
	int				rotate;
	double			def_ang;
	double			alpha;
	double			beta;
	double			teta;
}	t_fdf;

void			clean_all_for_fdf_struct(t_fdf *param);
char			**ft_split(char *s, char c);
int				ft_words(const char *str, char c);
int				ft_atoi(const char *str);
int				ft_atoi_hex(char *str);
void			fdf_init(t_fdf *fdf, char *filename, int *check_fd);
void			initialize_camera(t_fdf *fdf);
void			free_stack(t_stack *stack, t_fdf *fdf);
void			print_info(t_fdf *fdf);
int				main(int argc, char **argv);
int				check_filename(char *filename);
void			print_error(int error);
int				insert_stack_element(char **sec_split, t_stack **stack);
void			insert_at_top(t_stack **stack, t_stack *new);
int				process_line_data(char *line, t_stack **stack, int *width, \
int *check_fd);
int				check_line_width_error(int width, int i, int *check_fd, \
char **split);
void			free_string_tab(char **tab);
t_stack			*read_map(int fd, int *height, int *width, int *check_fd);
int				key_zoom(int key, t_fdf *fdf);
int				close_win(t_fdf *fdf);
int				handle_keyboard(int key, t_fdf *fdf);
int				altitude_and_proj(int key, t_fdf *fdf);
int				translate_rot_map(int key, t_fdf *fdf);
void			clean_up_resources_esc(t_fdf *fdf);
void			clean_all_for_fdf_struct(t_fdf *fdf);
void			draw_map(t_fdf *fdf);
void			draw_y_line(t_fdf *fdf, int x, int y);
void			draw_x_line(t_fdf *fdf, int x, int y);
t_point3D		*apply_projection(t_point3D *p, t_fdf *fdf);
t_point3D		*point_init(int x, int y, t_fdf *fdf);
void			bresenham_line(t_fdf *fdf, t_point3D *a, t_point3D *b);
t_line_param	*init_param(t_point3D *a, t_point3D *b);
void			put_pixel(t_fdf *fdf, int x, int y);
int				compare(int a, int b);
void			z_rotation(int *x, int *y, int *z, double teta);
void			y_rotation(int *x, int *y, int *z, double teta);
void			x_rotation(int *x, int *y, int *z, double teta);
void			isometr(int *x, int *y, int z, double teta);
t_for_matrix	**create_matrix(t_fdf *fdf, t_stack *stack);
void			fill_matrix_row(t_for_matrix *matrix, t_stack **stack, \
t_fdf *fdf);
#endif
