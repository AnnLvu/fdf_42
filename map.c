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

t_stack	*read_map(int fd, int *check_fd, t_fdf *fdf, int i)
{
	char	*tmp;
	t_stack	*stack;
	int		check;

	tmp = get_next_line(fd);
	if (tmp == NULL)
		print_error(1, fdf);
	stack = NULL;
	fdf->width = ft_words(tmp, ' ');
	while (tmp != NULL)
	{
		i++;
		check = process_line_data(tmp, &stack, &fdf->width, check_fd);
		free(tmp);
		if (check != 0)
		{
			cleanup_stack(stack);
			return (NULL);
		}
		tmp = get_next_line(fd);
	}
	fdf->height = i;
	free(tmp);
	close(fd);
	return (stack);
}

void	cleanup_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	while (current != NULL)
	{
		next = current->next;
		free(current->z);
		free(current);
		current = next;
	}
}
