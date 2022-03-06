/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:03:50 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 13:03:51 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	flag_sharp(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->sharp = true;
	return (1);
}

size_t	flag_zero(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	if (data->point == false)
		data->zero = true;
	else
		data->precision = 0;
	return (1);
}

size_t	flag_minus(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->minus = true;
	data->zero = false;
	return (1);
}

size_t	flag_plus(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->plus = true;
	return (1);
}

size_t	flag_space(t_flag_data *data, char *cmd, int i)
{
	(void)cmd;
	(void)i;
	data->space = true;
	return (1);
}
