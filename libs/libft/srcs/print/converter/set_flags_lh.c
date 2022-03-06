/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags_lh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:04:07 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 02:02:26 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	handle_lh(t_data *data, t_flag_data *flag_data)
{
	long long	i;

	if (flag_data->l_value == 2)
		i = va_arg(data->arg, long long);
	else if (flag_data->l_value == 1)
		i = va_arg(data->arg, long);
	else if (flag_data->h_value == 2)
		i = (char)(va_arg(data->arg, int));
	else if (flag_data->h_value == 1)
		i = (short)(va_arg(data->arg, int));
	else
		i = va_arg(data->arg, int);
	return (i);
}

unsigned long long	handle_lh_unsigned(t_data *data, t_flag_data *flag_data)
{
	unsigned long long	i;

	if (flag_data->l_value == 2)
		i = va_arg(data->arg, unsigned long long);
	else if (flag_data->l_value == 1)
		i = (unsigned long long)va_arg(data->arg, unsigned long);
	else if (flag_data->h_value == 2)
		i = (unsigned char)(va_arg(data->arg, int));
	else if (flag_data->h_value == 1)
		i = (unsigned short)(va_arg(data->arg, int));
	else
		i = va_arg(data->arg, unsigned int);
	return (i);
}
