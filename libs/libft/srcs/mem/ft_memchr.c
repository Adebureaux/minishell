/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:05:05 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 13:05:06 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *str, int c, size_t len)
{
	unsigned char	*tab;
	size_t			i;

	i = 0;
	tab = (unsigned char *)str;
	while (i < len)
	{
		if (tab[i] == (unsigned char)c)
			return (&tab[i]);
		i++;
	}
	return (NULL);
}
