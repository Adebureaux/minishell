/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:05:12 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 13:05:13 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void *src, int c, size_t len)
{
	unsigned int	i;
	char			*destp;
	char			*srcp;

	i = 0;
	destp = (char *)dest;
	srcp = (char *)src;
	while (i < len)
	{
		destp[i] = srcp[i];
		if (srcp[i] == (char)c)
			return (destp + i + 1);
		i++;
	}
	return (NULL);
}
