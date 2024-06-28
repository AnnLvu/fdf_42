#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buf, size_t j, size_t i)
{
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		if (left_str != NULL)
			left_str[0] = '\0';
		else
			return (NULL);
	}
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buf)) + 1));
	if (str == NULL)
	{
		free(left_str);
		return (NULL);
	}
	while (left_str[++i] != '\0')
		str[i] = left_str[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[ft_strlen(left_str) + ft_strlen(buf)] = '\0';
	free(left_str);
	return (str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	d = dest;
	s = src;
	i = 0;
	if (src == 0 && dest == 0)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(ft_strlen((char *)s) + 1);
	if (str)
	{
		while (s[i] != '\0')
		{
			str[i] = s[i];
			i++;
		}
	}
	else
		return (0);
	str[i] = '\0';
	return (str);
}
