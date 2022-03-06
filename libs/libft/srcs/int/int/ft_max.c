/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:28:41 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 13:28:42 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int nb_number, ...)
{
	int		result;
	int		tmp;
	int		i;
	va_list	params;

	va_start(params, nb_number);
	result = INT_MIN;
	i = 0;
	while (i < nb_number)
	{
		tmp = va_arg(params, int);
		if (tmp > result)
			result = tmp;
		i++;
	}
	va_end(params);
	return (result);
}
