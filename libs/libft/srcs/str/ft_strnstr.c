/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:59:21 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 02:04:03 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *find, size_t len)
{
	size_t	i;
	char	*pstr;
	char	*pfind;

	if (*find == '\0')
		return ((char *)str);
	pstr = (char *)str;
	pfind = (char *)find;
	i = 0;
	while (pstr[i] != '\0' && i < (len - ft_strlen(pfind) + 1)
		&& ft_strlen(pfind) <= len)
	{
		if (ft_strncmp((pstr + i), pfind, ft_strlen(pfind)) == 0)
		{
			return (pstr + i);
		}
		i++;
	}
	return (NULL);
}
