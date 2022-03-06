/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intstr_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:28:22 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 13:28:23 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_int_str_new(int size)
{
	int	i;
	int	*result;

	result = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		result[i] = 0;
		i++;
	}
	return (result);
}
