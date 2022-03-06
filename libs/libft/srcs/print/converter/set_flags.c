/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:04:13 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 02:02:47 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_wildcard(t_data *data, t_flag_data *flag_data)
{
	int	j;

	if (flag_data->wildcard1 == true)
	{
		j = va_arg(data->arg, int);
		if (flag_data->padding == 0)
			flag_data->padding = j;
		if (flag_data->padding < 0)
		{
			flag_data->minus = true;
			flag_data->padding *= -1;
		}
	}
	if (flag_data->wildcard2 == true && flag_data->precision <= 0)
	{
		j = va_arg(data->arg, int);
		if (flag_data->precision == 0)
			flag_data->precision = j;
	}
}

void	handle_padding(t_flag_data *flag_data, char **str2)
{
	char	*s2;

	if (flag_data->padding <= (int)(ft_strlen(*str2)))
		return ;
	s2 = ft_strnew_c(flag_data->padding - ft_strlen(*str2), ' ');
	if (flag_data->minus == true)
		ft_str_replace_back(str2, s2);
	else
		ft_str_replace_front(s2, str2);
	free(s2);
}

void	handle_padding_c(t_flag_data *flag_data, char **str2)
{
	char	*s2;

	if (flag_data->padding <= 1)
		return ;
	s2 = ft_strnew_c(flag_data->padding - 1, ' ');
	if (flag_data->minus == true)
		ft_str_replace_back(str2, s2);
	else
		ft_str_replace_front(s2, str2);
	free(s2);
}

void	handle_precision(t_flag_data *flag_data, char **str)
{
	char	*s2;

	if (flag_data->precision > (int)(ft_strlen(*str)))
	{
		s2 = ft_strnew_c(flag_data->precision - (int)(ft_strlen(*str)), '0');
		ft_str_replace_front(s2, str);
		free(s2);
	}
}

void	handle_padding_num(t_flag_data *flag_data, char **str2)
{
	char	*s2;

	if (flag_data->padding <= (int)(ft_strlen(*str2)))
		return ;
	if (flag_data->zero == true && flag_data->minus == false)
	{
		s2 = ft_strnew_c(flag_data->padding - (int)(ft_strlen(*str2)), '0');
		ft_str_replace_front(s2, str2);
		free(s2);
	}
	s2 = ft_strnew_c(flag_data->padding - (int)(ft_strlen(*str2)), ' ');
	if (flag_data->minus == true)
		ft_str_replace_back(str2, s2);
	else
		ft_str_replace_front(s2, str2);
	free(s2);
}
