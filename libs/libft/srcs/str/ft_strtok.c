/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:02:15 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 02:08:45 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_chars(char *s, char *sep)
{
	int	i;
	int	chars;

	chars = 0;
	while (s[chars])
	{
		i = 0;
		while (sep[i])
		{
			if (s[chars] == sep[i++])
				return (chars);
		}
		chars++;
	}
	return (chars);
}

static int	count_parts(char *s, char *sep)
{
	int	i;
	int	parts;

	parts = 0;
	while (*s)
	{
		i = 0;
		while (sep[i])
		{
			if (*s == sep[i++])
				parts++;
		}
		s++;
	}
	return (parts + 1);
}

/*
** Split la chaine envoyer en params dés qu'il trouve un char présent dans sep
** Renvoi un tableau contenant les chaines split
*/

char	**ft_strtok(char *s, char *sep)
{
	char	**tok;
	int		parts;
	int		chars;
	int		i;
	int		j;

	parts = count_parts(s, sep);
	i = 0;
	tok = (char **)ft_memalloc(sizeof(char *) * (parts + 1));
	while (i < parts)
	{
		j = 0;
		if (s)
			chars = count_chars(s, sep);
		if (chars)
			s++;
		while (*s && j < chars && chars > 0)
			tok[i][j++] = *(s++);
		if (tok[i] || chars)
			i++;
		if (!*s)
			break ;
	}
	tok[i] = NULL;
	return (tok);
}
