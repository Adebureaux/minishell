/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:04:31 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 13:04:32 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	converter_o(t_data *data, t_flag_data *flag_data)
{
	unsigned long long	i;
	char				*str;

	handle_wildcard(data, flag_data);
	i = handle_lh_unsigned(data, flag_data);
	if (i == 0 && flag_data->point == true && flag_data->precision == 0)
		str = ft_strnew(1);
	else
		str = ft_uitoa_base(i, 8);
	if (flag_data->sharp == true && str[0] != '0')
		ft_str_replace_front("0", &str);
	handle_precision(flag_data, &str);
	handle_padding_num(flag_data, &str);
	add_str_to_buffer(data, str);
	free(str);
}

void	converter_u(t_data *data, t_flag_data *flag_data)
{
	unsigned long long	i;
	char				*str;

	handle_wildcard(data, flag_data);
	i = handle_lh_unsigned(data, flag_data);
	if (i == 0 && flag_data->point == true && flag_data->precision == 0)
		str = ft_strnew(1);
	else
		str = ft_uitoa_base(i, 10);
	handle_precision(flag_data, &str);
	handle_padding_num(flag_data, &str);
	add_str_to_buffer(data, str);
	free(str);
}

void	converter_x(t_data *data, t_flag_data *flag_data)
{
	unsigned long long	i;
	char				*str;

	flag_data->plus = false;
	handle_wildcard(data, flag_data);
	i = handle_lh_unsigned(data, flag_data);
	if (i == 0 && flag_data->point == true && flag_data->precision == 0)
		str = ft_strnew(1);
	else
		str = ft_uitoa_base(i, 16);
	handle_precision(flag_data, &str);
	if (flag_data->sharp == true && flag_data->zero == false && i != 0)
		ft_str_replace_front("0x", &str);
	else if (flag_data->sharp == true && flag_data->zero == true && i != 0)
		flag_data->padding = flag_data->padding - 2;
	handle_padding_num(flag_data, &str);
	if (flag_data->sharp == true && flag_data->zero == true && i != 0)
		ft_str_replace_front("0x", &str);
	add_str_to_buffer(data, str);
	free(str);
}

void	converter_x_maj(t_data *data, t_flag_data *flag_data)
{
	unsigned long long	i;
	char				*str;

	flag_data->plus = false;
	handle_wildcard(data, flag_data);
	i = handle_lh_unsigned(data, flag_data);
	if (i == 0 && flag_data->point == true && flag_data->precision == 0)
		str = ft_strnew(1);
	else
		str = ft_uitoa_base(i, 16);
	handle_precision(flag_data, &str);
	if (flag_data->sharp == true && flag_data->zero == false && i != 0)
		ft_str_replace_front("0X", &str);
	else if (flag_data->sharp == true && flag_data->zero == true && i != 0)
		flag_data->padding = flag_data->padding - 2;
	handle_padding_num(flag_data, &str);
	if (flag_data->sharp == true && flag_data->zero == true && i != 0)
		ft_str_replace_front("0X", &str);
	ft_str_toupper(str);
	add_str_to_buffer(data, str);
	free(str);
}

void	converter_p(t_data *data, t_flag_data *flag_data)
{
	unsigned long long	i;
	char				*str;

	flag_data->plus = false;
	handle_wildcard(data, flag_data);
	i = va_arg(data->arg, unsigned long long);
	if (i == 0 && flag_data->point == true && flag_data->precision == 0)
		str = ft_strnew(1);
	else
		str = ft_uitoa_base(i, 16);
	handle_precision(flag_data, &str);
	if (flag_data->zero == false)
		ft_str_replace_front("0x", &str);
	else if (flag_data->zero == true)
		flag_data->padding = flag_data->padding - 2;
	handle_padding_num(flag_data, &str);
	if (flag_data->zero == true)
		ft_str_replace_front("0x", &str);
	add_str_to_buffer(data, str);
	free(str);
}
