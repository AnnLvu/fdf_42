#include "get_next_line.h"

void	*handle_special_cases(int fd, char **current_line)
{
	if (fd == -1 || BUFFER_SIZE <= 0 || fd == -42)
	{
		if (fd == -42 && *current_line)
		{
			free(*current_line);
			*current_line = NULL;
		}
		return (NULL);
	}
	return (NULL);
}
