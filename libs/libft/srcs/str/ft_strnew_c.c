/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 12:59:26 by mravily           #+#    #+#             */
/*   Updated: 2020/05/26 12:59:28 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew_c(size_t len, char c)
{
	char	*result;

	result = ft_strnew(len);
	ft_str_fill(result, c, len);
	return (result);
}
