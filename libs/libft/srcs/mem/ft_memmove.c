/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:04:43 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 13:04:44 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t len)
{
	unsigned int	i;
	char			*destp;
	char			*srcp;

	destp = (char *)dest;
	srcp = (char *)src;
	if (src == dest)
		return (dest);
	if (src < dest)
	{
		i = len;
		while (i-- > 0)
			destp[i] = srcp[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			destp[i] = srcp[i];
			i++;
		}
	}
	return (dest);
}
