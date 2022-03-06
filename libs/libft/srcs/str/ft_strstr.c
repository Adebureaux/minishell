/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:58:49 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 02:03:36 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Si find est trouver dans str
** Retourne str à partir du premier char de find
** Sinon return NULL
*/
char	*ft_strstr(char *str, char *find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!find[0])
		return ((char *)&str[i]);
	while (str[i])
	{
		while (find[j] && (str[i + j] == find[j]))
			j++;
		if (!find[j])
			return ((char *)&str[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
