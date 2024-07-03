#include "fdf.h"

void	free_string_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	check_line_width_error(int width, int i, int *check_fd, char **split)
{
	free_string_tab(split);
	if (width > i)
	{
		*check_fd = -2;
		return (1);
	}
	return (0);
}

int	process_line_data(char *line, t_stack **stack, int *width, int *check_fd)
{
	int		i;
	char	**split;
	char	**sec_split;

	split = ft_split(line, ' ');
	i = 0;
	while (split[i] != NULL)
	{
		sec_split = ft_split(split[i], ',');
		if (insert_stack_element(sec_split, stack))
		{
			free_string_tab(sec_split);
			free_string_tab(split);
			*check_fd = -1;
			return (1);
		}
		free_string_tab(sec_split);
		i++;
	}
	if (check_line_width_error(*width, i, check_fd, split))
		return (1);
	return (0);
}

t_stack	*read_map(int fd, int *height, int *width, int *check_fd)
{
	char	*tmp;
	t_stack	*stack;
	int		i;
	int		check;

	i = 0;
	tmp = get_next_line(fd);
	if (tmp == NULL)
		print_error(1);
	stack = NULL;
	*width = ft_words(tmp, ' ');
	while (tmp != NULL)
	{
		i++;
		check = process_line_data(tmp, &stack, width, check_fd);
		if (check != 0)
			return (NULL);
		free(tmp);
		tmp = get_next_line(fd);
	}
	*height = i;
	free(tmp);
	close(fd);
	return (stack);
}
