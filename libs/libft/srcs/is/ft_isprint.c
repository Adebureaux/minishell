/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:06:36 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 02:00:06 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (true);
	return (false);
}

bool	ft_strisprint(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isprint(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}
