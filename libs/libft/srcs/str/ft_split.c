/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:58:56 by mravily           #+#    #+#             */
/*   Updated: 2022/03/06 02:07:00 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_str(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	if (s[0] != c)
		count++;
	return (count);
}

static int	ft_str_len(char *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i + len] && s[i + len] != c)
	{
		len++;
	}
	return (len);
}

static char	**ft_tab(char *s, char c, char ***tab)
{
	int	count;

	if (!s)
		return (NULL);
	count = ft_count_str((char *)s, c);
	*tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!(*tab))
		return (NULL);
	return (*tab);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int		i[2];
	int		len;

	if (ft_tab((char *)s, c, &tab) == NULL)
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	while (s[i[0]] != '\0')
	{
		while (s[i[0]] != '\0' && s[i[0]] == c)
			i[0]++;
		if (s[i[0]])
		{
			len = ft_str_len(s, c, i[0]);
			tab[i[1]] = (char *)ft_memalloc(sizeof(char) * (len + 1));
			if (!tab[i[1]])
				return (NULL);
			ft_strncpy(tab[i[1]], (char *)(s + i[0]), len);
			i[0] = i[0] + len;
			i[1]++;
		}
	}
	tab[i[1]] = NULL;
	return (tab);
}
