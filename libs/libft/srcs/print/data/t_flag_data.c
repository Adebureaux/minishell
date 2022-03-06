/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_flag_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:03:56 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 13:03:57 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flag_data	create_flag_data(void)
{
	t_flag_data	result;

	result.sharp = false;
	result.zero = false;
	result.minus = false;
	result.plus = false;
	result.space = false;
	result.point = false;
	result.wildcard1 = false;
	result.wildcard2 = false;
	result.padding = 0;
	result.precision = 0;
	result.l_value = 0;
	result.h_value = 0;
	return (result);
}
