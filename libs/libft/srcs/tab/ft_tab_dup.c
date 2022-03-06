/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:55:17 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 02:42:08 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tab_dup(void **dst, void **src)
{
	int	index;

	index = 0;
	if (!dst || !src)
		return ;
	while (dst[index] || src[index] != NULL)
	{
		dst[index] = (void *)ft_strdup((void *)src[index]);
		index++;
	}
}
