#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
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
	int x;
	int y;
	int z;
} t_point3D;

typedef struct s_for_matrix
{
	t_point_param	z;
}	t_for_matrix;

typedef struct s_stack
{
	t_point_param *z;
	struct s_stack *next;
} t_stack;

typedef struct s_line_param
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;
} t_line_param;

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
	int				bpp;
	int				size_line;
	int				endian;
	int				altitude;
	int				project;
	int				rot;
	double			def_ang;
	double			alpha;
	double			beta;
	double			teta;
}	t_fdf;

char		**ft_split(char *s, char c);
int			ft_atoi(const char *str);
int			ft_atoi_hex(char *str);

#endif
