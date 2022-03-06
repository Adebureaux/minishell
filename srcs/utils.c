/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:45:19 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 01:52:37 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
** Calcule la taille de la chaine jusqu'au char contenu dans delim
** Renvoie la taille de la chaine trouvé jusqu'au char rencontrer dans delim
** Renvoie la taille complete de str si aucun delim trouver dans celle ci
** Renvoie 0 en cas d'erreur
*/
size_t	ft_strlen_delim(char *str, char *delim)
{
	size_t		len;
	size_t		y;

	if (!str || !delim)
		return (0);
	len = 0;
	while (str[len] != '\0')
	{
		y = 0;
		while (delim[y] != '\0')
		{
			if (str[len] == delim[y])
				return (len);
			y++;
		}
		len++;
	}
	return (len);
}

/*
* Concatenates 2 strings into a new string
* don't forget to free the new string after using it
*/
char	*ft_strappend(char *s1, char *s2)
{
	char			*new_str;
	unsigned int	i;
	unsigned int	j;
	unsigned int	s1_len;
	unsigned int	s2_len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = malloc(s1_len + s2_len + 1);
	while (i < s1_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}
