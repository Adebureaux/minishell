/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 22:52:39 by mravily           #+#    #+#             */
/*   Updated: 2021/09/15 23:02:41 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_chr_index(const char *s, int c)
{
	int		i;

	i = -1;
	if (!s)
		return (0);
	if (c == 0)
		return (ft_strlen((char *)s));
	while (s[++i])
		if (s[i] == c)
			return (i + 1);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size)
	{
		nmemb = 1;
		size = 1;
	}
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*next_line(char *save, int readret)
{
	char	*line;
	int		i;

	if (readret < 0 || (readret == 0 && !save))
		return (NULL);
	line = ft_strdup(save);
	i = ft_chr_index(save, '\n');
	if (!i)
	{
		if (line[0] == 0)
		{
			free(line);
			return (NULL);
		}
		return (line);
	}
	line[i] = 0;
	return (line);
}

char	*get_save(char *save)
{
	int	i;

	if (!save)
		return (NULL);
	i = ft_chr_index(save, '\n');
	if (!i)
	{
		free(save);
		return (NULL);
	}
	save = ft_strsub(save, i, ft_strlen(save) - i);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*save = NULL;
	int			readret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	readret = read(fd, buf, BUFFER_SIZE);
	while (readret > 0)
	{
		buf[readret] = 0;
		save = ft_strjoin(save, buf);
		if (ft_chr_index(save, '\n'))
			break ;
		readret = read(fd, buf, BUFFER_SIZE);
	}
	line = next_line(save, readret);
	save = get_save(save);
	free(buf);
	return (line);
}
