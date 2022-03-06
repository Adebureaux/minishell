/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeburea <adeburea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:36:02 by mravily           #+#    #+#             */
/*   Updated: 2022/03/05 02:42:23 by adeburea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tab_len(void **tab)
{
	int	index;

	index = 0;
	if (tab == NULL)
		return (index);
	while (tab && tab[index] != NULL)
		index++;
	return (index);
}
